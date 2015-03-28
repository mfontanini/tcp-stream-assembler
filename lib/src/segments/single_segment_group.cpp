#include "segments/single_segment_group.hpp"

using std::string;
using std::move;
using std::pair;

namespace tcp_stream_assembler {

single_segment_group::single_segment_group(string name, segment single_segment)
: segment_group(move(name)), m_segment(move(single_segment))
{

}

auto single_segment_group::bounds() const -> pair<const_iterator, const_iterator>
{
    return { &m_segment, &m_segment + 1 };
}

} // tcp_stream_assembler
