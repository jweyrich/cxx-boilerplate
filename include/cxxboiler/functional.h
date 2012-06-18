#pragma once

#include <functional>

namespace cxxboiler {
namespace functional {

template<typename T, typename M, template<typename> class C = std::less>
struct member_comparer : std::binary_function<T, T, bool> {
	explicit member_comparer(M T::*p) : _p(p) { }

	bool operator ()(T const& lhs, T const& rhs) const {
		return C<M>()(lhs.*_p, rhs.*_p);
	}

private:
	M T::*_p;
};

template<typename T, typename M>
member_comparer<T, M> make_member_comparer(M T::*p) {
	return member_comparer<T, M>(p);
}

template<template<typename> class C, typename T, typename M>
member_comparer<T, M, C> make_member_comparer_ex(M T::*p) {
	return member_comparer<T, M, C>(p);
}

template<typename T, typename M, template<typename> class C = std::less>
struct method_comparer : std::binary_function<T, T, bool> {
	explicit method_comparer(M (T::*p)() const) : _p(p) { }

	bool operator ()(T const& lhs, T const& rhs) const {
		return C<M>()((lhs.*_p)(), (rhs.*_p)());
	}

private:
	M (T::*_p)() const;
};

template<typename T, typename M>
method_comparer<T, M> make_method_comparer(M (T::*p)() const) {
	return method_comparer<T, M>(p);
}

template<template<typename> class C, typename T, typename M>
method_comparer<T, M, C> make_method_comparer_ex(M (T::*p)() const) {
	return method_comparer<T, M, C>(p);
}

} } // namespace cxxboiler::functional


