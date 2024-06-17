#include "euler_utils.h"

inline size_t generate_triangle_n(size_t n)
{
    return (n * (n + 1)) / 2;
}

size_t solve_problem_12()
{
    PrimeGenerator pg;
    size_t result = 0;
    size_t n = 10000;
    while ( true ) {
        const size_t triangle_number = n * (n + 1) / 2;

        const size_t num_divisors = pg.get_divisors(triangle_number).size();
        if ( num_divisors > 500 ) {
            result = triangle_number;
            break;
        }

        ++n;
    }

    ASSERT_EQUAL(result, 76576500);
    return result;
}

REGISTER_PROBLEM(solve_problem_12, 12)
