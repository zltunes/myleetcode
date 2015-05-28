#define CATCH_CONFIG_MAIN
#include <iostream>
#include "Solution.h"
#include "../Catch/single_include/catch.hpp"
using namespace std;

TEST_CASE("Longest Substring Without Repeating Characters", "[lengthOfLongestSubstring]")
{
    SECTION("1")
    {
        string s = "wcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfyk";
        Solution sol;
        REQUIRE(sol.lengthOfLongestSubstring_new(s) == 12);
        REQUIRE(sol.lengthOfLongestSubstring(s) == 12);
    }
    SECTION("2")
    {
        string s = "abcabcbb";
        Solution sol;
        REQUIRE(sol.lengthOfLongestSubstring_new(s) == 3);
        REQUIRE(sol.lengthOfLongestSubstring(s) == 3);
    }
}
