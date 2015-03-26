#include "payload/memory_payload.hpp"

using std::pair;

namespace tcp_stream_assembler {

memory_payload::memory_payload(container_type data)
: m_payload(move(data))
{

}

auto memory_payload::bounds() const -> pair<const_iterator, const_iterator>
{
    return { &*m_payload.data(), &*(m_payload.data() + m_payload.size()) };
}

} // tcp_stream_assembler
