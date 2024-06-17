#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <cmath>
#include <vector>


#include "utils/problem_list.h"

#include "utils/print_helper.h"
#include "utils/primes.h"
#include "utils/factorial.h"
#include "utils/fib.h"
#include "utils/math.h"


#include <sstream>
#define ASSERT_EQUAL(calculated, expected) \
    do { \
        if ((calculated) != (expected)) { \
            std::ostringstream oss; \
            oss << "Assertion failed: (" #calculated " == " #expected ") at " << __FILE__ << ":" << __LINE__ << "\n" \
                << "  Expected: " << (expected) << "\n" \
                << "  Got:      " << (calculated) << "\n"; \
            std::cerr << oss.str(); \
            std::exit(EXIT_FAILURE); \
        } \
    } while (0)

#endif // UTILS_H
