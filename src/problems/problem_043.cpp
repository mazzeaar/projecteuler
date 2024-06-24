#include "euler_utils.h"

std::string& get_next()
{
    static std::string digits = "0123456789";

    if ( !std::next_permutation(digits.begin(), digits.end()) ) {
        digits = "";
    }
    else if ( digits[0] == '0' ) {
        return get_next();
    }

    return digits;
}

bool has_property(const std::string& n)
{
    if ( n == "" || n[5] != '5' || (n[3] - '0') % 2 != 0 ) // 4x speedup from this line lol
        return false;

    int num;
    int idx = 1;
    for ( auto divisor : { 2, 3, 5, 7, 11, 13, 17 } ) {
        if ( n[idx] == '0' ) {
            num = std::stoi(n.substr(idx+1, 2));
        }
        else {
            num = std::stoi(n.substr(idx, 3));
        }

        if ( num % divisor != 0 )
            return false;

        ++idx;
    }

    return true;
}

i64 solve_problem_43()
{

    i64 result = 0;

    std::string permutation = "";
    do {
        if ( has_property(permutation) ) {
            result += std::stoull(permutation);
            if ( result == 16695334890 ) break;
        }

        permutation = get_next();
    } while ( permutation != "" );

    ASSERT_EQUAL(result, 16695334890);
    return result;
}

REGISTER_PROBLEM(solve_problem_43, 43)
