#include "packets/packet_stream.hpp"

using std::move;

namespace tcp_stream_assembler {

packet_stream::packet_stream()
: m_vector_index(0)
{

}

void packet_stream::add_packet(packet_specifications packet)
{
    m_packets.emplace_back(move(packet));
}

// TODO: modify when packet conditions are introduced
bool packet_stream::is_packet_available() const
{
    return m_vector_index != m_packets.size();
}

packet_specifications packet_stream::next_packet()
{
    return m_packets[m_vector_index++];
}

} // tcp_stream_assembler
