#pragma once

#include <cstddef>

namespace cxxboiler {
namespace array {

template <typename T, std::size_t N>
size_t size(T (&array)[N]) {
    (void)(array);
    return N;
}

template <typename T, std::size_t N>
T* begin(T (&array)[N]) {
    return &array[0];
}

template <typename T, std::size_t N>
T* end(T (&array)[N]) {
    return &array[N];
}

} } // namespace cxxboiler::array
