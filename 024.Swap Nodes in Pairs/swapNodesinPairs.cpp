#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(const ListNode *l) {
    while(l) {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << endl;
}

ListNode *genList(int num, int interval, int begin = 0) {
    int val = begin;
    ListNode *dummy = new ListNode(-1);
    ListNode *iter = dummy;
    while(num--) {
        iter->next = new ListNode(val);
        iter = iter->next;
        val += interval;
    }
    return dummy->next;
}

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *iter = dummy;
        while(iter->next && iter->next->next) {
            ListNode *n1 = iter->next;
            ListNode *n2 = iter->next->next;
            n1->next = n2->next;
            n2->next = n1;
            iter->next = n2;
            iter = iter->next->next;
        }
        return dummy->next;
    }
};

int main() {
    Solution sol;
    printList(sol.swapPairs(genList(100,1,1)));
    return 0;
}
