file(
    GLOB 
    LIBRARY_SOURCES 
    "payload/*.cpp" 
    "segments/*.cpp"
    "packets/*.cpp" 
)

add_library(tcp_stream_assembler ${LIBRARY_SOURCES})
