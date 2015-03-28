#ifndef TCP_STREAM_ASSEMBLER_SEGMENT_HPP
#define TCP_STREAM_ASSEMBLER_SEGMENT_HPP

#include <memory>
#include "payload/payload_base.hpp"

namespace tcp_stream_assembler {

class segment {
public:
    using payload_pointer = std::shared_ptr<payload_base>;
    using const_iterator = payload_base::const_iterator;

    segment(payload_pointer payload, size_t start, size_t length);

    const_iterator begin() const;
    const_iterator end() const;
    size_t size() const;
private:
    payload_pointer m_payload;
    size_t m_start;
    size_t m_size;
};

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_SEGMENT_HPP
