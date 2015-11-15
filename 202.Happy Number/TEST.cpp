#define CATCH_CONFIG_MAIN
#include "Solution.h"
#include "../Catch/single_include/catch.hpp"

TEST_CASE("Two Sum", "[twoSum]")
{
    SECTION("1")
    {
        Solution sol;
        REQUIRE(sol.isHappy(19) == true);
        REQUIRE(sol.isHappy(1) == true);
        REQUIRE(sol.isHappy(68) == true);
        REQUIRE(sol.isHappy(101) == false);
    }
}
