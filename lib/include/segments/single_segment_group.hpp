#ifndef TCP_STREAM_ASSEMBLER_SINGLE_SEGMENT_GROUP_HPP
#define TCP_STREAM_ASSEMBLER_SINGLE_SEGMENT_GROUP_HPP

#include "segments/segment_group.hpp"
#include "segments/segment.hpp"

namespace tcp_stream_assembler {

class single_segment_group : public segment_group {
public:
    single_segment_group(std::string name, segment single_segment);
private:
    std::pair<const_iterator, const_iterator> bounds() const;

    segment m_segment;
};

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_SINGLE_SEGMENT_GROUP_HPP
