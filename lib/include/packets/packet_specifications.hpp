#ifndef TCP_STREAM_ASSEMBLER_PACKET_SPECIFICATIONS_HPP
#define TCP_STREAM_ASSEMBLER_PACKET_SPECIFICATIONS_HPP

#include <string>
#include <chrono>
#include <boost/optional.hpp>

namespace tcp_stream_assembler {

class segment_group;
class segment_groups_holder;

class packet_specifications {
public:
    using delay_type = std::chrono::microseconds;

    packet_specifications(std::string segment_group_name);

    const segment_group& extract_segment_group(segment_groups_holder& holder) const;

    void set_delay(delay_type value);
    const boost::optional<delay_type>& delay();
private:
    std::string m_segment_group_name;
    boost::optional<delay_type> m_delay;
};

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_PACKET_SPECIFICATIONS_HPP
