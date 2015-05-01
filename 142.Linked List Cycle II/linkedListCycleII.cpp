#include <iostream>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL) return NULL;
            fast = fast->next;
            if(fast == slow) break;
        }
        if(fast == NULL) return NULL;
        ListNode *it = head;
        while(it != slow) {
            it = it->next;
            slow = slow->next;
        }
        return it;
    }
};

int main() {
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n2;


    Solution sol;
    ListNode *ret = sol.detectCycle(n1);
    if(ret == NULL) cout << "NULL" << endl;
    else 
        cout << ret->val << endl;
    return 0;
}
