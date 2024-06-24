#include "euler_utils.h"

int64_t concatenated_product(int n)
{
    // to not use std::pow(10, product) all the time
    static int pow10[10] = {
        1, 10, 100, 1000, 10000,
        100000, 1000000, 10000000,
        100000000, 1000000000
    };

    int64_t concatenated = 0;
    int factor = 1;
    while ( concatenated < 1e8 ) {
        int product = n * factor;
        int product_digits = math::count_digits(product);

        concatenated *= pow10[product_digits]; // shift to the left to make room for the next concatenation
        concatenated += product;    // append new number
        ++factor;
    }

    if ( concatenated >= 1e9 ) {
        return 0;
    }

    return concatenated;
}

i64 solve_problem_38()
{
    i64 best_candidate = 0;
    for ( int n = 192; n < 10000; ++n ) {
        int64_t candidate = concatenated_product(n);

        if ( candidate < 1 || candidate > 987654321 ) {
            continue;
        }
        if ( candidate <= 987654321 && math::is_pandigital(candidate) && candidate > best_candidate ) {
            best_candidate = candidate;
        }
    }

    ASSERT_EQUAL(best_candidate, 932718654);
    return best_candidate;
}

REGISTER_PROBLEM(solve_problem_38, 38)
