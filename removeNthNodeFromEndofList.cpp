#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL) return head;
        ListNode *t = head;
        for(int i = 0; i < n; ++i) {
            t = t->next; 
        }
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *s = dummy;
        while(t) {
            s = s->next;
            t = t->next;
        }
        s->next = s->next->next;
        return dummy->next;
    }
};

ListNode* listGen(int num) {
    ListNode *dummy = new ListNode(-1);
    ListNode *iter = dummy;
    for(int i = 0; i < num; ++i) {
        iter->next = new ListNode(i);
        iter = iter->next;
    }
    return dummy->next;
}

void printList(const ListNode *l) {
    while(l) {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << endl;
}

int main() {
    ListNode *test = listGen(1);
    Solution sol;
    printList(test);
    printList(sol.removeNthFromEnd(test, 1));
    return 0;
}
