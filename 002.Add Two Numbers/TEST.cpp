#define CATCH_CONFIG_MAIN
#include "../Catch/single_include/catch.hpp" 
#include "Solution.h"

TEST_CASE("Add Two Numbers", "[addTwoNumbers]")
{
    SECTION("1")
    {
        ListNode *l1 = genRandomList(3, 9);
        ListNode *l2 = genRandomList(5, 9);
        printList(l1);
        printList(l2);
        Solution sol;
        printList(sol.addTwoNumbers(l1, l2));
    }
}



