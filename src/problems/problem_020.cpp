#include "euler_utils.h"

constexpr int MAX_DIGITS = 200;

struct BigInt {
    std::array<int, MAX_DIGITS> digits = { 0 };

    constexpr BigInt() = default;

    constexpr BigInt(unsigned long long num)
    {
        int i = 0;
        while ( num > 0 ) {
            digits[i++] = num % 10;
            num /= 10;
        }
    }

    constexpr BigInt& operator+=(const BigInt& other)
    {
        int carry = 0;
        for ( int i = 0; i < MAX_DIGITS; ++i ) {
            int sum = digits[i] + other.digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        return *this;
    }

    constexpr BigInt operator+(const BigInt& other) const
    {
        BigInt result = *this;
        result += other;
        return result;
    }

    constexpr BigInt operator*(const BigInt& other) const
    {
        BigInt result;
        for ( int i = 0; i < MAX_DIGITS; ++i ) {
            for ( int j = 0; j + i < MAX_DIGITS; ++j ) {
                int product = digits[i] * other.digits[j];
                result.digits[i + j] += product;
                if ( result.digits[i + j] >= 10 ) {
                    result.digits[i + j + 1] += result.digits[i + j] / 10;
                    result.digits[i + j] %= 10;
                }
            }
        }
        return result;
    }

    void removeTrailingZeroes()
    {
        for ( int i = 0; i < MAX_DIGITS; ++i ) {
            if ( digits[i] == 0 ) {
                digits[i] = 1;
                break;
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInt& num)
    {
        int i = num.digits.size() - 1;
        for ( ; i >= 0; --i ) {
            if ( num.digits[i] != 0 ) {
                break;
            }
        }

        for ( ; i >= 0; --i ) {
            os << num.digits[i];
        }
        return os;
    }
};

template <size_t N>
struct factorial {
    static constexpr BigInt value = factorial<N-1>::value * BigInt(N);
};

template <>
struct factorial<0> {
    static constexpr BigInt value = BigInt(1);
};

size_t solve_problem_20()
{
    size_t result = 0;

    BigInt factorial100 = factorial<100>::value;

    for ( int i = 0; i < factorial100.digits.size(); ++i ) {
        result += factorial100.digits[i];
    }

    ASSERT_EQUAL(result, 648);
    return result;
}

REGISTER_PROBLEM(solve_problem_20, 20)
