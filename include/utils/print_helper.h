#ifndef PRINT_H
#define PRINT_H

#include <ostream>

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec);

#include "print_helper.hpp"

#endif // PRINT_H
