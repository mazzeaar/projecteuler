#include "euler_utils.h"

i64 solve_problem_46()
{
    std::vector<i64> squares;
    for ( size_t i = 0; i < 40; ++i ) {
        squares.push_back(2 * i * i);
    }

    i64 num = 0;
    for ( num = 3; num < 10000; num += 2 ) {
        if ( PrimeGenerator::is_prime(num) ) {
            continue;
        }

        bool ok = false;
        for ( auto sq : squares ) {
            if ( num < sq ) {
                break;
            }

            if ( PrimeGenerator::is_prime(num - sq) ) {
                ok = true;
                break;
            }
        }

        if ( !ok ) {
            break;
        }
    }

    ASSERT_EQUAL(num, 5777);
    return num;
}

REGISTER_PROBLEM(solve_problem_46, 46)
