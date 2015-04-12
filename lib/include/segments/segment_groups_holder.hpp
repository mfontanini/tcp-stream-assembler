#ifndef TCP_STREAM_ASSEMBLER_SEGMENT_GROUPS_HOLDER_HPP
#define TCP_STREAM_ASSEMBLER_SEGMENT_GROUPS_HOLDER_HPP

#include <vector>
#include <memory>
#include <map>
#include "segments/segment_group.hpp"

namespace tcp_stream_assembler {

class segment_groups_holder {
public:
    using segment_group_pointer = std::unique_ptr<segment_group>;
    using container_type = std::vector<segment_group_pointer>;

    segment_groups_holder(container_type groups);

    const segment_group& find_segment_group(const std::string& name) const;
private:
    void create_index();

    container_type m_segment_groups;
    std::map<std::string, size_t> m_names_index;
};

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_SEGMENT_GROUPS_HOLDER_HPP
