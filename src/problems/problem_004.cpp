#include <iostream>
#include "euler_utils.h"

bool is_palindrome_number(int n)
{
    std::string num = std::to_string(n);
    const size_t size = num.size();
    for ( size_t i = 0; i <= size / 2; ++i ) {
        if ( num[i] != num[size - 1 - i] ) {
            return false;
        }
    }

    return true;
}

size_t solve_problem_004()
{
    const int min = 100;
    const int max = 999;

    int res = std::numeric_limits<int>::min();
    for ( int i = max; i >= min; --i ) {
        for ( int j = i; j >= min; --j ) {
            if ( is_palindrome_number(i * j) ) {
                res = std::max(res, i * j);
            }
        }

        if ( i * i < res ) {
            break;
        }
    }

    ASSERT_EQUAL(res, 906609);
    return res;
}

REGISTER_PROBLEM(solve_problem_004, 4)
