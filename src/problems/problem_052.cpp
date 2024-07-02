#include "euler_utils.h"

inline bool is_permuted_multiple(i64 n)
{
    auto get_freq = [ ] (i64 n)
    {
        uint16_t freq = 0;
        for ( ; n > 0; n /= 10 ) {
            freq |= (0b1 << (n % 10));
        }

        return freq;
    };

    const uint16_t base_freq = get_freq(n);
    for ( i64 mult = 2; mult <= 6; ++mult ) {
        if ( get_freq(mult * n) != base_freq ) {
            return false;
        }
    }
    return true;
}

i64 solve_problem_52()
{
    i64 result = 0;
    for ( i64 digits = 4; digits < 10; ++digits ) {
        // check from [10^x, 10^(x+1)/6]
        const i64 lower = std::pow(10, digits);
        const i64 upper = std::pow(10, digits+1) / 6;

        for ( i64 i = lower; i <= upper; ++i ) {
            if ( is_permuted_multiple(i) ) {
                result = i;
                break;
            }
        }

        if ( result != 0 ) {
            break;
        }
    }

    ASSERT_EQUAL(result, 142857);
    return result;
}

REGISTER_PROBLEM(solve_problem_52, 52)
