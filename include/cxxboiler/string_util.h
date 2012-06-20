#pragma once

#include <string>

namespace cxxboiler {
namespace string {

inline bool contains(const std::string& s1, const std::string& s2) {
	return s1.find(s2) != std::string::npos;
}

// Remove leading whitespaces
inline std::string& ltrim(std::string& s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
		std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

// Remove trailing whitespaces
inline std::string& rtrim(std::string& s) {
	s.erase(std::find_if(s.rbegin(), s.rend(),
		std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

// Remove whitespaces from both ends
inline std::string& trim(std::string& s) {
	return ltrim(rtrim(s));
}

// Check if a string begins with another string
inline bool begins_with(const std::string& s, const std::string& start) {
	return s.compare(0, start.length(), start) == 0;
}

// Check if a string ends with another string
inline bool ends_with(const std::string& s, const std::string& ending) {
	return ending.length() <= s.length() && s.substr(s.length() - ending.length()) == ending;
}

template <typename T>
std::string get_bits(T value) {
	size_t size = sizeof(value) * CHAR_BIT;
	std::string ret;
	ret.reserve(size);
	for (int i = size-1; i >= 0; --i)
		ret += (value & (1 << i)) == 0 ? '0' : '1';
	return ret;
}

std::string replace(const std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return str;
	std::string str_copy = str;
	str_copy.replace(start_pos, from.length(), to);
	return str_copy;
}

std::string replace_all(const std::string& str, const std::string& from, const std::string& to) {
	size_t start_pos = str.find(from);
	if (start_pos == std::string::npos)
		return str;
	std::string str_copy = str;
	const size_t from_length = from.length();
	const size_t to_length = to.length();
	while (start_pos != std::string::npos) {
		str_copy.replace(start_pos, from_length, to);
		start_pos = str_copy.find(from, start_pos + to_length);
	}
	return str_copy;
}

std::string copy_range(const std::string& data, const std::string& begin, const std::string& end) {
	size_t begin_found_at = data.find(begin);
	if (begin_found_at == std::string::npos)
		return "";
	size_t end_found_at = data.find(end, begin_found_at + begin.length());
	if (end_found_at == std::string::npos)
		return "";
	return data.substr(
		begin_found_at + begin.length(),
		end_found_at - begin_found_at - begin.length()
	);
}

std::string copy_range_inclusive(const std::string& data, const std::string& begin, const std::string& end) {
	size_t begin_found_at = data.find(begin);
	if (begin_found_at == std::string::npos)
		return "";
	size_t end_found_at = data.find(end, begin_found_at + begin.length() + 1);
	if (end_found_at == std::string::npos)
		return "";
	return data.substr(
		begin_found_at,
		end_found_at + end.length() - begin_found_at
	);
}

} } // namespace cxxboiler::string
