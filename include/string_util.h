#pragma once

#include <string>

namespace cppboiler {
namespace string {

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

} } // namespace cppboiler::string
