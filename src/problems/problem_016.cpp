#include "euler_utils.h"

size_t solve_problem_16()
{
    const int n = 1000;
    std::vector<int> num = { 1 };
    for ( int i = 0; i < n; ++i ) {
        int carry = 0;
        for ( int& i : num ) {
            carry += i * 2;
            i = carry % 10;
            carry /= 10;
        }

        while ( carry > 0 ) {
            num.push_back(carry % 10);
            carry /= 10;
        }
    }

    size_t result = 0;
    for ( int i : num ) {
        result += i;
    }

    ASSERT_EQUAL(result, 1366);
    return result;
}

REGISTER_PROBLEM(solve_problem_16, 16)
