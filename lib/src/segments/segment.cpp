#include "segments/segment.hpp"

namespace tcp_stream_assembler {

segment::segment(payload_pointer payload, size_t start, size_t length)
: m_payload(move(payload)), m_start(start), m_size(length)
{

}

auto segment::begin() const -> const_iterator
{
    return m_payload->begin() + m_start;
}

auto segment::end() const -> const_iterator
{
    return begin() + size();
}

size_t segment::size() const
{
    return m_size;
}

} // tcp_stream_assembler
