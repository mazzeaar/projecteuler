#include "euler_utils.h"

i64 get_next()
{
    static std::string digits = "0123456789";

    while ( std::next_permutation(digits.begin(), digits.end()) ) {
        if ( digits[0] != '0' ) {
            return std::stoll(digits);
        }
    }

    return i64(-1); // no more permutations
}


bool has_property(i64 n)
{
    static const int divisors[] = { 17, 13, 11, 7, 5, 3, 2 };
    for ( auto divisor : divisors ) {
        if ( (n % 1000) % divisor != 0 )
            return false;

        n /= 10;
    }

    return true;
}

i64 solve_problem_43()
{
    i64 result = 0;
    i64 permutation = 0;

    do {
        if ( has_property(permutation) ) {
            result += permutation;
            if ( result == 16695334890 ) break;
        }

        permutation = get_next();
    } while ( permutation != i64(-1) );


    ASSERT_EQUAL(result, 16695334890);
    return result;
}

REGISTER_PROBLEM(solve_problem_43, 43)
