#ifndef TCP_STREAM_ASSEMBLER_SEGMENT_GROUP_HPP
#define TCP_STREAM_ASSEMBLER_SEGMENT_GROUP_HPP

#include <string>
#include <boost/iterator/iterator_facade.hpp>

namespace tcp_stream_assembler {

class segment;

class segment_group {
public:
    // TODO: use a nice iterator here.
    using const_iterator = const segment*;

    segment_group(std::string name);

    virtual ~segment_group() = default;

    const segment& get_segment(size_t index) const;
    size_t segment_count() const;
    const_iterator begin() const;
    const_iterator end() const;
    const std::string& name() const;
private:
    virtual std::pair<const_iterator, const_iterator> bounds() const = 0;

    const std::string m_name;
};

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_SEGMENT_GROUP_HPP
