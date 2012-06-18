#pragma once

namespace cxxboiler {
namespace lambda {

template <typename T>
struct delete_ptr : public std::unary_function <T*, bool> {
	bool operator()(T* ptr) const {
		delete ptr;
		return true;
	}
};

template <typename T>
struct delete_array : public std::unary_function <T*, bool> {
	bool operator()(T* ptr) const {
		delete[] ptr;
		return true;
	}
};

} } // namespace cxxboiler::lambda
