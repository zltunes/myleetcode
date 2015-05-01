#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_a, length_b;
        length_a = length_b = 0;
        ListNode *it_a, *it_b;
        it_a = headA;
        it_b = headB;
        while(headA) {
            headA = headA->next;
            ++length_a;
        }
        while(headB) {
            headB = headB->next;
            ++length_b;
        }
        int abs_val = 0;
        if(length_a < length_b) {
            abs_val = length_b - length_a; 
            while(abs_val--) {
                it_b = it_b->next;
            }
        }
        else {
            abs_val = length_a - length_b; 
            while(abs_val--) {
                it_a = it_a->next;
            }
        }

        while(it_a != it_b) {
            it_a = it_a->next;
            it_b = it_b->next;
        }
        return it_a; 
    }
};

int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n5->next = n6;
    n6->next = n4;

    Solution sol;
    cout << sol.getIntersectionNode(n1, n5)->val << endl;
    return 0;
}
