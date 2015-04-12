#include "segments/segment_groups_holder.hpp"

using std::move;
using std::string;

namespace tcp_stream_assembler {

segment_groups_holder::segment_groups_holder(container_type groups)
: m_segment_groups(move(groups))
{
    create_index();
}

void segment_groups_holder::create_index()
{
    for (size_t i = 0; i < m_segment_groups.size(); ++i) {
        m_names_index[m_segment_groups[i]->name()] = i;
    }
}

const segment_group& segment_groups_holder::find_segment_group(
    const string& name) const
{
    return *m_segment_groups[m_names_index.at(name)];
}

} // tcp_stream_assembler
