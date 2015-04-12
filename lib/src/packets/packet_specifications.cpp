#include "packets/packet_specifications.hpp"
#include "segments/segment_group.hpp"
#include "segments/segment_groups_holder.hpp"

using std::string;
using std::move;

using boost::optional;

namespace tcp_stream_assembler {

packet_specifications::packet_specifications(string segment_group_name)
: m_segment_group_name(move(segment_group_name))
{

}

const segment_group& packet_specifications::extract_segment_group(
    segment_groups_holder& holder) const
{
    return holder.find_segment_group(m_segment_group_name);
}

void packet_specifications::set_delay(delay_type value)
{
    m_delay = move(value);
}

auto packet_specifications::delay() -> const optional<delay_type>&
{
    return m_delay;
}

} // tcp_stream_assembler
