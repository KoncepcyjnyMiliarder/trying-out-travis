#include <funcs.hpp>

namespace funcs
{

std::vector<int>
sorted_vector_from_set(const std::set<int>& s)
{
  return {begin(s), end(s)};
}

} // namespace funcs
