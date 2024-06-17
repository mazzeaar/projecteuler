#include "print_helper.h"
#include <ostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    constexpr size_t elems_to_print = 7;
    const size_t n = vec.size();

    if ( n == 0 ) {
        return os << "[ ]";
    }

    os << "[ ";
    if ( n < 20 ) {
        for ( size_t i = 0; i < n-1; ++i ) {
            os << vec[i] << ", ";
        }
        return os << vec[n-1] << " ]";
    }

    for ( size_t i = 0; i < elems_to_print; ++i ) {
        os << vec[i] << ", ";
    }

    os << "(" << n - (2 * elems_to_print) << " more...), ";

    for ( size_t i = n - elems_to_print; i < n-1; ++i ) {
        os << vec[i] << ", ";
    }

    return os << vec[n-1] << " ]";
}