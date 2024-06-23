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

} // namespace math

#endif // MATH_H