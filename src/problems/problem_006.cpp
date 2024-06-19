#include <iostream>
#include "euler_utils.h"

size_t solve_problem_006()
{
    const size_t n = 100;
    std::vector<int> squares = [ ] ()
    {
        std::vector<int> s(n+1, 0);
        for ( int i = 0; i <= n; ++i ) {
            s[i] = i * i;
        }
        return s;
    }();

    size_t squared_sum = (n * (n + 1) / 2) * (n * (n + 1) / 2);
    size_t summed_squares = 0;
    for ( int i = 0; i < squares.size(); ++i ) {
        summed_squares += squares[i];
    }

    size_t res = squared_sum - summed_squares;
    ASSERT_EQUAL(res, 25164150);
    return res;
}

REGISTER_PROBLEM(solve_problem_006, 6)
