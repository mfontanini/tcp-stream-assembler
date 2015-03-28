#ifndef TCP_STREAM_ASSEMBLER_GENERATED_SEGMENT_GROUP_HPP
#define TCP_STREAM_ASSEMBLER_GENERATED_SEGMENT_GROUP_HPP

#include <vector>
#include "segments/segment_group.hpp"
#include "segments/segment.hpp"

namespace tcp_stream_assembler {

class generated_segment_group : public segment_group {
public:
    using container_type = std::vector<segment>;
    
    generated_segment_group(std::string name);

    std::pair<const_iterator, const_iterator> bounds() const;
protected:
    virtual container_type generate_segments() = 0;
private:
    container_type m_segments;
};

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_GENERATED_SEGMENT_GROUP_HPP
