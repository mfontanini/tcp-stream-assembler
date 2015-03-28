#ifndef TCP_STREAM_ASSEMBLER_PAYLOAD_BASE_HPP
#define TCP_STREAM_ASSEMBLER_PAYLOAD_BASE_HPP

#include <cstddef>
#include <utility>

namespace tcp_stream_assembler {

class payload_base {
public:
    using value_type = char;
    // TODO: use nice iterator here.
    using const_iterator = const value_type*;

    virtual ~payload_base() = default;

    const_iterator begin() const;
    const_iterator end() const;
    size_t size() const;
protected:
    virtual std::pair<const_iterator, const_iterator> bounds() const = 0;
private:

};

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_PAYLOAD_BASE_HPP
