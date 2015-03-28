#include "segments/generated_segment_group.hpp"

using std::string;
using std::move;
using std::pair;

namespace tcp_stream_assembler {


generated_segment_group::generated_segment_group(string name)
: segment_group(move(name))
{
    
}

auto generated_segment_group::bounds() const -> pair<const_iterator, const_iterator>
{
    return { m_segments.data(), m_segments.data() + m_segments.size() };
}

} // tcp_stream_assembler
