#include "euler_utils.h"

bool is_dec_palindrome(int n)
{
    int original = n;
    int reversed = 0;
    for ( ; n != 0; n /= 10 ) {
        reversed = reversed * 10 + n % 10;
    }
    return reversed == original;
}

bool is_binary_palindrome(int n)
{
    int reversed = 0;
    int original = n;
    while ( n > 0 ) {
        reversed = (reversed << 1) | (n & 1);
        n >>= 1;
    }
    return reversed == original;
}

i64 solve_problem_36()
{
    const int N = 1000000;

    i64 result = 0;

    for ( int i = 1; i < N; i += 2 ) {
        if ( i % 10 == 0 ) {
            continue;
        }

        if ( is_dec_palindrome(i) && is_binary_palindrome(i) ) {
            result += i;
        }
    }

    ASSERT_EQUAL(result, 872187);
    return result;
}

REGISTER_PROBLEM(solve_problem_36, 36)
