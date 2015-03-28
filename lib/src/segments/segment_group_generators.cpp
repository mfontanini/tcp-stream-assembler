#include <algorithm>
#include "segments/segment_group_generators.hpp"

using std::min;

namespace tcp_stream_assembler {

fixed_segment_generator_impl::fixed_segment_generator_impl(segment::payload_pointer payload, 
    size_t start, size_t end, size_t chunk_size)
: m_payload(move(payload)), m_start(start), m_end(end + 1), m_chunk_size(chunk_size)
{

}

generated_segment_group::container_type fixed_segment_generator_impl::operator()() const
{
    generated_segment_group::container_type output;
    auto first = m_start;
    while (first < m_end) {
        output.emplace_back(
            m_payload, 
            first, 
            min(m_chunk_size, m_end - first)
        );
        first += m_chunk_size;
    }
    return output;
}

} // tcp_stream_assembler
