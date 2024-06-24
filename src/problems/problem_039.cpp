#include "euler_utils.h"

i64 solve_problem_39()
{
    constexpr size_t perimeter = 1000;

    std::array<i64, perimeter> n_solutions = { 0 };
    for ( i64 a = 1; a < perimeter / 3; ++a ) {
        for ( i64 b = a; b < perimeter / 2; ++b ) {
            const i64 c = std::sqrt(a * a + b * b);
            if ( a * a + b * b == c * c && a + b + c <= perimeter ) {
                ++n_solutions[a + b + c];
            }
        }
    }

    i64 result = std::distance(n_solutions.begin(), std::max_element(n_solutions.begin(), n_solutions.end()));
    ASSERT_EQUAL(result, 840);
    return result;
}

REGISTER_PROBLEM(solve_problem_39, 39)
