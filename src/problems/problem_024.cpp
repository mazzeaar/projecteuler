#include "euler_utils.h"

std::string get_nth_permutation(std::string& s, int n)
{
    std::sort(s.begin(), s.end());
    n -= 1;
    const size_t size = s.size();
    std::string permutation = "";
    for ( int i = 0; i < size; ++i ) {
        size_t f = runtime_small_factorial(size - 1 - i);
        size_t idx = n / f;
        n %= f;
        permutation += s[idx];
        s.erase(s.begin() + idx);
    }

    return permutation;
}

size_t solve_problem_24()
{
    std::string s = "0123456789";
    const int n = 1000000;
    const std::string nth_perm = get_nth_permutation(s, n);
    size_t result = std::stoull(nth_perm);

    ASSERT_EQUAL(result, 2783915460);
    return result;
}

REGISTER_PROBLEM(solve_problem_24, 24)


/*
012
021
102
*/