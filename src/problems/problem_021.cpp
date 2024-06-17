#include "euler_utils.h"
#include <set>

inline int get_sum(int num, std::vector<int>& memo)
{
    if ( memo[num] != 0 ) {
        return memo[num];
    }

    auto divisors = PrimeGenerator::get_divisors(num);

    memo[num] = 0;
    for ( size_t divisor : divisors ) {
        memo[num] += divisor;
    }
    memo[num] -= num;

    return memo[num];
}

size_t solve_problem_21()
{
    const size_t n = 10000;
    std::vector<int> memo(10 * n, 0);
    std::set<int> amicable;
    for ( int a = 2; a < n; ++a ) {
        const int b = get_sum(a, memo);
        const int c = get_sum(b, memo);

        if ( a == b ) {
            continue;
        }

        if ( get_sum(b, memo) == a ) {
            amicable.insert(a);
            amicable.insert(b);
        }
    }

    size_t result = 0;
    for ( int i : amicable ) {
        result += i;
    }

    ASSERT_EQUAL(result, 31626);
    return result;
}

REGISTER_PROBLEM(solve_problem_21, 21)
