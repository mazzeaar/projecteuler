#include "euler_utils.h"
#include <cmath>
#include <vector>
#include <array>
#include <iostream>

static constexpr size_t max = 101;

class Trie {
private:
    struct TrieNode {
        bool found = false;
        std::array<std::vector<TrieNode*>, max> children;
        TrieNode() = default;
    };

    TrieNode* m_root;

public:
    Trie() : m_root(new TrieNode()) { }

    // returns true if the number is already contained
    bool contains(const std::vector<i64>& a, const int exp)
    {
        auto factors = to_array(a, exp);
        TrieNode* node = m_root;
        for ( size_t i = 0; i < factors.size(); ++i ) {
            if ( factors[i] == 0 ) {
                continue;
            }

            if ( node->children[i].size() <= factors[i] ) {
                node->children[i].resize(factors[i] + 1, nullptr);
            }

            if ( node->children[i][factors[i]] == nullptr ) {
                node->children[i][factors[i]] = new TrieNode();
            }

            node = node->children[i][factors[i]];
        }

        if ( node->found ) {
            return true;
        }
        else {
            node->found = true;
            return false;
        }
    }

private:

    // converts the number to an array of factors
    std::array<int, max> to_array(const std::vector<i64>& a, int exp)
    {
        // for a^b, where a = PROD p_i^x_i with p_n is a prime and x_n is its exponoent
        // a^b = (p1^x1 * p2^x2 * ...)^b
        // factors[p1] = x1 * b;
        std::array<int, max> factors = { 0 };

        for ( auto f : a ) {
            factors[f] += exp;
        }

        return factors;
    }
};

i64 solve_problem_29()
{
    std::vector<std::vector<i64>> prime_factors;

    for ( int i = 2; i < max; ++i ) {
        prime_factors.push_back(PrimeGenerator::get_prime_factors(i));
    }

    Trie trie;
    i64 result = 0;
    for ( const auto& a : prime_factors ) {
        for ( int exp = 2; exp < max; ++exp ) {
            result += !trie.contains(a, exp);
        }
    }

    ASSERT_EQUAL(result, 9183);
    return result;
}

REGISTER_PROBLEM(solve_problem_29, 29)
