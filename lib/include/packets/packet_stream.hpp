#ifndef TCP_STREAM_ASSEMBLER_PACKET_STREAM_HPP
#define TCP_STREAM_ASSEMBLER_PACKET_STREAM_HPP

#include <vector>
#include "packets/packet_specifications.hpp"

namespace tcp_stream_assembler {

class packet_stream {
public:
    packet_stream();

    void add_packet(packet_specifications packet);
    bool is_packet_available() const;
    packet_specifications next_packet();
private:
    std::vector<packet_specifications> m_packets;
    size_t m_vector_index;
};

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_PACKET_STREAM_HPP
