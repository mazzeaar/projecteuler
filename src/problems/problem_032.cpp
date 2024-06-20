#include "euler_utils.h"

bool is_pandigital(int a, int b, int c)
{
    int count = 0;
    int digits = 0;

    // asserts that we dont have a zero in our number and counts the digits
    auto check = [&digits, &count] (int n) -> bool
    {
        for ( ; n != 0; n /= 10 ) {
            const int mod = n % 10;
            if ( mod == 0 ) {
                return false;
            }

            ++count;
            digits |= (1 << mod);
        }

        return true;
    };

    return (check(a) && check(b) && check(c))   // no zeros
        && count == 9                           // 9 digits
        && digits == 0x3FE;                     // using all numbers
}

i64 solve_problem_32()
{
    std::vector<bool> memo(10000, false);
    i64 result = 0;
    for ( size_t a = 1; a < 100; ++a ) {    // a can be 1 or 2 digits
        for ( size_t b = a; b < 10000 / a; ++b ) {  // b can be 4 digits
            const size_t prod = a * b;

            if ( memo[prod] ) {
                continue;
            }

            if ( is_pandigital(a, b, prod) ) {
                memo[prod] = true;
                result += prod;
            }
        }
    }

    ASSERT_EQUAL(result, 45228);
    return result;
}

REGISTER_PROBLEM(solve_problem_32, 32)
