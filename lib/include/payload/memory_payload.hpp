#ifndef TCP_STREAM_ASSEMBLER_MEMORY_PAYLOAD_HPP
#define TCP_STREAM_ASSEMBLER_MEMORY_PAYLOAD_HPP

#include <vector>
#include <string>
#include "payload_base.hpp"

namespace tcp_stream_assembler {

class memory_payload : public payload_base {
public:
    using container_type = std::vector<char>;

    template <typename ForwardIterator>
    memory_payload(ForwardIterator start, ForwardIterator end);
    memory_payload(container_type data);
    memory_payload(const std::string& data);
private:
    std::pair<const_iterator, const_iterator> bounds() const;

    container_type m_payload;
};

template <typename ForwardIterator>
memory_payload::memory_payload(ForwardIterator start, ForwardIterator end)
: m_payload(start, end)
{

}

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_MEMORY_PAYLOAD_HPP
