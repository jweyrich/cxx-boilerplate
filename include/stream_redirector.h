#pragma once

#include <fstream>
#include <iostream>

namespace cppboiler {
namespace io {

class stream_redirector {
public:
    stream_redirector(std::ostream& dst, std::ostream& src)
        : src(src), sbuf(src.rdbuf())
    {
        src.rdbuf(dst.rdbuf());
    }
    ~stream_redirector() {
        src.rdbuf(sbuf);
    }
private:
    std::ostream& src;
    std::streambuf* const sbuf;
	stream_redirector(const stream_redirector&);
	stream_redirector& operator=(const stream_redirector&);
};

} } // namespace cppboiler::io
