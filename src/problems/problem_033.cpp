#include "euler_utils.h"
#include <numeric>

bool can_curious_cancel(int num, int den, int reduced_num, int reduced_den)
{
    const bool is_trivial = (num % 10 == 0) || (den % 10 == 0);
    const bool is_irreducible = (num == reduced_num) || (den == reduced_den);

    if ( is_trivial || is_irreducible ) return false;

    const int num_first = num / 10;
    const int num_second = num % 10;
    const int den_first = den / 10;
    const int den_second = den % 10;

    const double expected = (double) reduced_num / reduced_den;
    if ( num_second == den_second && (double) num_first / den_first == expected ) return true;
    if ( num_second == den_first && (double) num_first / den_second == expected ) return true;
    if ( num_first == den_second && (double) num_second / den_first == expected ) return true;
    if ( num_first == den_first && (double) num_second / den_second == expected ) return true;

    return false;
}

i64 solve_problem_33()
{
    int res_num = 1;
    int res_den = 1;
    for ( int den = 99; den > 9; --den ) {
        for ( int num = den - 1; num > 9; --num ) {
            const int gcd = std::gcd(num, den);
            if ( can_curious_cancel(num, den, num / gcd, den / gcd) ) {
                res_num *= num;
                res_den *= den;
            }
        }
    }

    i64 result = res_den / std::gcd(res_num, res_den);

    ASSERT_EQUAL(result, 100);
    return result;
}

REGISTER_PROBLEM(solve_problem_33, 33)
