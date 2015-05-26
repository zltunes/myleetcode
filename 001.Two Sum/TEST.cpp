#define CATCH_CONFIG_MAIN
#include <vector>
#include "Solution.h"
#include "../Catch/single_include/catch.hpp"

TEST_CASE("two sum are computed", "[twoSum]")
{
    SECTION("1")
    {
        std::vector<int> v {1,9,3,7,5};
        std::vector<int> ans {1,5};
        Solution sol;
        REQUIRE(sol.twoSum1(v, 6) == ans);
    }
}
