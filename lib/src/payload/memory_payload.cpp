#include "payload/memory_payload.hpp"

using std::string;
using std::pair;

namespace tcp_stream_assembler {

memory_payload::memory_payload(container_type data)
: m_payload(move(data))
{

}

memory_payload::memory_payload(const string& data)
: m_payload(data.begin(), data.end())
{

}

auto memory_payload::bounds() const -> pair<const_iterator, const_iterator>
{
    return { &*m_payload.data(), &*(m_payload.data() + m_payload.size()) };
}

} // tcp_stream_assembler
