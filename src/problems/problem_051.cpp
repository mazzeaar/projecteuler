#include "euler_utils.h"

/*
replace the masked digits
so: replace(12345, 0b00101, 7) -> 12747
*/
inline i64 replace(i64 prime, i64 mask, int replacement_digit)
{
    static int pow10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
    i64 ret = 0;
    int shift = 0;
    while ( prime > 0 ) {
        if ( mask & 0x1 ) {
            ret += pow10[shift] * replacement_digit;
        }
        else {
            ret += pow10[shift] * (prime % 10);
        }

        ++shift;
        mask >>= 1;
        prime /= 10;
    }

    return ret;
}

std::vector<i64> generate_masks(int num_digits, int max_set_bits)
{
    std::vector<i64> masks;
    for ( i64 mask = 1; mask < (1 << num_digits); ++mask ) {
        if ( __builtin_popcount(mask) <= 3 ) {
            masks.push_back(mask);
        }
    }
    return masks;
}

i64 solve_problem_51()
{
    const i64 target = 8;

    const i64 upper_b = 1000000;        // prime upper bound
    const i64 lower_b = upper_b / 10;   // prime lower bound (only makes sense to test numbers with same amount of digits)
    const i64 n_digits = std::log10(upper_b);

    const auto primes = PrimeGenerator::get_primes(upper_b);
    const auto masks = generate_masks(n_digits, 3);

    i64 result = 0;
    for ( i64 p : primes ) {
        if ( p < lower_b ) {
            continue;
        }

        for ( i64 mask : masks ) {
            int count = 0;
            i64 min = upper_b + 1;

            // try all digits
            for ( int i = 0; i < 10; ++i ) {
                i64 new_num = replace(p, mask, i);

                if ( new_num < lower_b ) { // to avoid xxx3 & 0b1110 -> 0003
                    continue;
                }

                if ( PrimeGenerator::is_prime(new_num) ) {
                    min = std::min(min, new_num);
                    ++count;
                }
                else if ( (10 - i - 1) + count < target ) { // early exit
                    break;
                }
            }

            if ( count == target ) {
                result = min;
                break;
            }
        }

        if ( result != 0 ) {
            break;
        }
    }

    ASSERT_EQUAL(result, 121313);
    return result;
}

REGISTER_PROBLEM(solve_problem_51, 51)
