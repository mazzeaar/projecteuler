#ifndef MATH_H
#define MATH_H

namespace math {

    // counts the number of digits in a given i64
    inline size_t count_digits(i64 n)
    {
        size_t d = 0;
        for ( ; n != 0; n /= 10 ) ++d;
        return d;
    }

    // checks if a number in range [1, 987654321] is pandigital
    inline bool is_pandigital(i64 number)
    {
        assert(number > 0 && number <= 987654321 && "number is out of pandigital range");

        uint16_t digits = 0x0;
        uint8_t size = 0;
        for ( ; number != 0; number /= 10, ++size ) {
            digits |= (0x1 << (number % 10));
        }

        const uint16_t mask = (0xFFFF >> (15 - size) ^ 0x1);
        return digits == mask;
    }

} // namespace math

#endif // MATH_H