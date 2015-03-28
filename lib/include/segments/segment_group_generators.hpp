#ifndef TCP_STREAM_ASSEMBLER_SEGMENT_GROUP_GENERATORS_HPP
#define TCP_STREAM_ASSEMBLER_SEGMENT_GROUP_GENERATORS_HPP

#include "segments/generated_segment_group.hpp"
#include "segments/segment.hpp"

namespace tcp_stream_assembler {

class fixed_segment_generator_impl {
public:
    fixed_segment_generator_impl(segment::payload_pointer payload, size_t start,
        size_t end, size_t chunk_size);

    generated_segment_group::container_type operator()() const;
private:
    segment::payload_pointer m_payload;
    size_t m_start;
    size_t m_end;
    size_t m_chunk_size;
};

template <typename Generator>
class concrete_generated_segment_group : public generated_segment_group {
public:
    concrete_generated_segment_group(const std::string& name, Generator&& generator)
    : generated_segment_group(name), m_generator(std::move(generator))
    {

    }
private:
    container_type generate_segments()
    {
        return m_generator();
    }

    Generator m_generator;
};


using fixed_segment_generator = concrete_generated_segment_group<
    fixed_segment_generator_impl
>;


} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_SEGMENT_GROUP_GENERATORS_HPP
