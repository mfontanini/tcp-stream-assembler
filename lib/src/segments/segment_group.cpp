#include <algorithm>
#include "segments/segment_group.hpp"
#include "segments/segment.hpp"

using std::string;
using std::distance;

namespace tcp_stream_assembler {

segment_group::segment_group(string name)
: m_name(move(name))
{

}

size_t segment_group::segment_count() const
{
    const auto group_bounds = bounds();
    return distance(group_bounds.first, group_bounds.second);
}

const segment& segment_group::get_segment(size_t index) const
{
    return *(begin() + index);
}

auto segment_group::begin() const -> const_iterator
{
    return bounds().first;
}

auto segment_group::end() const -> const_iterator
{
    return bounds().second;
}

} // tcp_stream_assembler
