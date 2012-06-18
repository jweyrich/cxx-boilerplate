#pragma once

#include <algorithm>

namespace cxxboiler {

template<typename C, typename T>
inline bool contains(const C& container, const T& val) {
	return ::std::find(container.begin(), container.end(), val) != container.end();
}

} // namespace cxxboiler
