#include <algorithm>
#include <funcs.hpp>
#include <gtest/gtest.h>

TEST(funcs, vector_from_empty_set)
{
  auto vec = funcs::sorted_vector_from_set({});
  EXPECT_TRUE(vec.empty());
}

TEST(funcs, vector_from_four_element_set)
{
  auto vec = funcs::sorted_vector_from_set({5, 2, 4, 8});
  EXPECT_FALSE(vec.empty());
  EXPECT_TRUE(std::is_sorted(begin(vec), end(vec)));
  EXPECT_EQ(4u, vec.size());
  std::vector<int> expected_answer{2, 4, 5, 8};
  auto mismatch_pair = std::mismatch(begin(vec), end(vec), begin(expected_answer));
  EXPECT_EQ(end(vec), mismatch_pair.first);
  EXPECT_EQ(end(expected_answer), mismatch_pair.second);
}
