#include "payload/file_payload.hpp"

using std::string;
using std::pair;

namespace tcp_stream_assembler {

file_payload::file_payload(const string& path) 
: m_file(path)
{

}

auto file_payload::bounds() const -> pair<const_iterator, const_iterator>
{
    const auto data = m_file.data();
    const auto size = m_file.size();

    return { data, data + size };
}


} //tcp_stream_assembler
