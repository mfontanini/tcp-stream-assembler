#ifndef TCP_STREAM_ASSEMBLER_FILE_PAYLOAD_HPP
#define TCP_STREAM_ASSEMBLER_FILE_PAYLOAD_HPP

#include <string>
#include <boost/iostreams/device/mapped_file.hpp>
#include "payload/payload_base.hpp"

namespace tcp_stream_assembler {

class file_payload : public payload_base {
public:
    file_payload(const std::string& path);
private:
    std::pair<const_iterator, const_iterator> bounds() const;

    boost::iostreams::mapped_file_source m_file;
};

} // tcp_stream_assembler

#endif // TCP_STREAM_ASSEMBLER_FILE_PAYLOAD_HPP
