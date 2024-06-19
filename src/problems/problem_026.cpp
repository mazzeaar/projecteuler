#include "euler_utils.h"

size_t long_division(const int numerator, const int denominator)
{
    std::vector<int> result;
    std::unordered_map<int, int> remainder_pos;

    int remainder = numerator;
    int position = 0;
    int cycle_start = -1;
    while ( remainder != 0 ) {
        remainder *= 10;
        int digit = remainder / denominator;
        result.push_back(digit);

        if ( remainder_pos.find(remainder) != remainder_pos.end() ) {
            cycle_start = remainder_pos[remainder];
            break;
        }

        remainder_pos[remainder] = position;
        remainder %= denominator;
        position++;
    }

    constexpr bool print = false;
    if ( print ) {
        std::cout << numerator << '/' << std::left << std::setw(3) << denominator << " = 0.";
        for ( int i = 0; i < result.size(); ++i ) {
            if ( i == cycle_start ) {
                std::cout << '(';
            }
            std::cout << result[i];
        }
        if ( cycle_start != -1 ) {
            std::cout << ')';
        }
        std::cout << std::endl;
    }

    if ( cycle_start == -1 ) {
        return 0;
    }
    else {
        return result.size() - 1 - cycle_start;
    }
}

size_t solve_problem_26()
{
    const size_t n = 1000;

    size_t result = 0;
    size_t max = 0;
    for ( int i = 2; i < n; ++i ) {
        if ( const size_t cycle = long_division(1, i); cycle > max ) {
            max = cycle;
            result = i;
        }
    }

    ASSERT_EQUAL(result, 983);
    return result;
}

REGISTER_PROBLEM(solve_problem_26, 26)