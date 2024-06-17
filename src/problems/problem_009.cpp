#include "euler_utils.h"

size_t solve_problem_9()
{
    size_t res = 0;
    for ( size_t a = 100; a < 1000; ++a ) {
        const size_t a2 = a * a;
        for ( size_t b = a+1; b < 1000; ++b ) {
            const size_t b2 = b * b;
            const size_t a2b2 = a2 + b2;
            for ( size_t c = b+1; c < 1000 && a+b+c <= 1000; ++c ) {
                if ( c * c == a2b2 && a+b+c == 1000 ) {
                    res = (a * b * c);
                    a = 1000;
                    b = 1000;
                    c = 1000;
                }
            }
        }
    }

    ASSERT_EQUAL(res, 31875000);
    return res;
}

REGISTER_PROBLEM(solve_problem_9, 9)
