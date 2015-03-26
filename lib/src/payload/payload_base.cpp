#include <algorithm>
#include "payload/payload_base.hpp"

using std::distance;

namespace tcp_stream_assembler {

auto payload_base::begin() const -> const_iterator 
{
    return bounds().first;
}

auto payload_base::end() const -> const_iterator
{
    return bounds().second;
}

size_t payload_base::size() const
{
    const auto bounds_pair = bounds();
    return distance(bounds_pair.first, bounds_pair.second);
}

} // tcp_stream_assembler
