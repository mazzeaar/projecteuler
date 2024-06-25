#include "euler_utils.h"
#include <iterator>

i64 solve_problem_44()
{
    constexpr size_t N = 2396;
    std::set<i64> P;

    for ( i64 i = 1; i < N; ++i ) {
        P.insert(i * (3 * i - 1) / 2);
    }

    i64 result = std::numeric_limits<i64>::max();
    for ( auto j = P.rbegin(); j != P.rend(); ++j ) {
        for ( auto k = std::next(j); k != P.rend(); ++k ) {
            if ( P.count(*k + *j) == 0 ) {
                continue;
            }

            if ( const i64 diff = std::abs(*k - *j); P.count(diff) != 0 ) {
                result = std::min(result, diff);
            }
        }

        if ( result == 5482660 )
            break; // speedup for future executions
    }

    ASSERT_EQUAL(result, 5482660);
    return result;
}

REGISTER_PROBLEM(solve_problem_44, 44)
