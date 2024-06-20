#include "euler_utils.h"

i64 solve_problem_30()
{
    const size_t N = 5;
    std::array<i64, 10> powers;
    i64 upper_bound = 0;
    for ( int i = 0; i <= 10; ++i ) {
        powers[i] = std::pow(i, N);
        upper_bound += powers[i];
    }

    i64 result = 0;
    for ( i64 i = 2; i < upper_bound; ++i ) {
        i64 sum = 0;
        i64 num = i;
        while ( num != 0 ) {
            sum += powers[num % 10];
            num /= 10;
        }

        if ( sum == i ) {
            result += i;
        }
    }

    ASSERT_EQUAL(result, 443839);
    return result;
}

REGISTER_PROBLEM(solve_problem_30, 30)
