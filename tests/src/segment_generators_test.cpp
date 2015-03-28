#include <gtest/gtest.h>
#include "segments/segment_group_generators.hpp"
#include "payload/memory_payload.hpp"

using std::make_shared;
using std::string;

using namespace tcp_stream_assembler;

class segment_group_generators_test : public testing::Test {
public:
    static segment::payload_pointer payload;
};

segment::payload_pointer segment_group_generators_test::payload = 
    make_shared<memory_payload>("hello this is a test string");

TEST_F(segment_group_generators_test, fixed_segment_generator1) {
    fixed_segment_generator_impl generator(payload, 0, 10, 3);
    auto results = generator();
    ASSERT_EQ(4, results.size());
    EXPECT_EQ("hel", string(results[0].begin(), results[0].end()));
    EXPECT_EQ("lo ", string(results[1].begin(), results[1].end()));
    EXPECT_EQ("thi", string(results[2].begin(), results[2].end()));
    EXPECT_EQ("s ", string(results[3].begin(), results[3].end()));
}

TEST_F(segment_group_generators_test, fixed_segment_generator2) {
    fixed_segment_generator_impl generator(payload, 6, 9, 4);
    auto results = generator();
    ASSERT_EQ(1, results.size());
    EXPECT_EQ("this", string(results[0].begin(), results[0].end()));
}
