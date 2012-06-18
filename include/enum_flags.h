#pragma once

namespace cppboiler {

//
// Based on Qt's QFlags.
// http://qt-project.org/doc/qt-4.8/qflags.html
//
template <typename EnumType>
class enum_flags {
public:
	typedef EnumType enum_type;
	enum_flags() : i(0) {}
	enum_flags(EnumType f) : i(f) {}
	enum_flags(const enum_flags& f) : i(f.i) {}

	enum_flags& operator=(const enum_flags& f) { i = f.i; return *this; }
	enum_flags& operator&=(int mask) { i &= mask; return *this; }
	enum_flags& operator&=(unsigned int mask) { i &= mask; return *this; }
	enum_flags& operator|=(enum_flags f) { i |= f.i; return *this; }
	enum_flags& operator|=(EnumType f) { i |= f; return *this; }
	enum_flags& operator^=(enum_flags f) { i ^= f.i; return *this; }
	enum_flags& operator^=(EnumType f) { i ^= f; return *this; }
	enum_flags& operator+=(enum_flags f) { i += f.i; return *this; }
	enum_flags& operator+=(EnumType f) { i += f; return *this; }
	enum_flags& operator-=(enum_flags f) { i -= f.i; return *this; }
	enum_flags& operator-=(EnumType f) { i -= f; return *this; }

	operator int() const { return i; }
	bool operator!() const { return !i; }
	bool testFlag(EnumType f) const { return (i & f) == f && (f != 0 || i == int(f)); }

	enum_flags operator++() const { enum_flags g; g.i = i + 1; return g; }
	enum_flags operator--() const { enum_flags g; g.i = i - 1; return g; }
	enum_flags operator|(enum_flags f) const { enum_flags g; g.i = i | f.i; return g; }
	enum_flags operator|(EnumType f) const { enum_flags g; g.i = i | f; return g; }
	enum_flags operator^(enum_flags f) const { enum_flags g; g.i = i ^ f.i; return g; }
	enum_flags operator^(EnumType f) const { enum_flags g; g.i = i ^ f; return g; }
	enum_flags operator&(int mask) const { enum_flags g; g.i = i & mask; return g; }
	enum_flags operator&(unsigned int mask) const { enum_flags g; g.i = i & mask; return g; }
	enum_flags operator&(EnumType f) const { enum_flags g; g.i = i & f; return g; }
	enum_flags operator~() const { enum_flags g; g.i = ~i; return g; }
private:
	int i;
};

} // namespace cppboiler
