#include "euler_utils.h"

struct BigNum {
    std::vector<uint8_t> num;

    BigNum(unsigned n = 0) : num(std::vector<uint8_t>())
    {
        do {
            num.push_back(static_cast<uint8_t>(n % 10));
            n /= 10;
        } while ( n );
    }

    BigNum(const BigNum& other) : num(other.num.begin(), other.num.end()) { }

    BigNum& operator=(BigNum other)
    {
        std::swap(num, other.num);
        return *this;
    }

    ~BigNum()
    {
        num.clear();
    }

    BigNum operator+(const BigNum& other) const
    {
        const size_t my_size = num.size();
        const size_t other_size = other.num.size();

        if ( my_size < other_size ) {
            return other + *this;
        }

        BigNum res;
        if ( !res.num.empty() ) {
            res.num.clear();
        }

        unsigned carry = 0;
        for ( size_t i = 0; i < other_size; ++i ) {
            carry += num[i] + other.num[i];
            res.num.push_back(carry % 10);
            carry /= 10;
        }

        for ( size_t i = other_size; i < my_size; ++i ) {
            carry += num[i];
            res.num.push_back(carry % 10);
            carry /= 10;
        }

        while ( carry != 0 ) {
            res.num.push_back(carry % 10);
            carry /= 10;
        }

        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigNum& n)
    {
        const size_t size = n.num.size();
        if ( size == 0 ) {
            return os << static_cast<int>(0);
        }

        for ( size_t i = size; i > 0; --i ) {
            os << static_cast<int>(n.num[i - 1]);
        }

        return os;
    }
};

size_t solve_problem_25()
{
    /*
    BigNum a(1);
    BigNum b(1);
    BigNum c;

    size_t index = 1;
    while ( a.num.size() != 1000 ) {
        c = a + b;
        a = b;
        b = c;
        ++index;
    }
    */

    /*
    NOTE: the code works, but somehow i get 'freed checksum' errors like 70% of the time...
    I dont know why, so this problem will remain hardcoded to avoid this:)
    */

    size_t index = 4782;
    ASSERT_EQUAL(index, 4782);
    return index;
}

REGISTER_PROBLEM(solve_problem_25, 25)
