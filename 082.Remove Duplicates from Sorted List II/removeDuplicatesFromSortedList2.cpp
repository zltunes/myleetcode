#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *node) {
    ListNode *t = node;
    while(t) {
        cout << t->val << " ";
        t = t->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *tHead, *tEnd;
        if(head == NULL) return head;
        ListNode *dummy = new ListNode(head->val);
        dummy->next = head;
        tHead = dummy;
        tEnd = dummy;
        int cnt = 0;
        while(tEnd->next) {
            if(tEnd->val != tEnd->next->val) {
                if(cnt <= 1) {
                    tHead->next = tEnd;
                    tHead = tEnd;
                }
                cnt = 0;
            }
            tEnd = tEnd->next;
            ++cnt;
        }
        if(cnt <= 1)
            tHead->next = tEnd;
        else
            tHead->next = tEnd->next;

        return dummy->next; 
    }
};

int main() {
    ListNode *node = new ListNode(0);
    ListNode *head = node;
    node->next = new ListNode(3);
    node = node->next;
    node->next = new ListNode(3);
    node = node->next;
    node->next = NULL;
    printList(head);
    Solution sol;
    printList(sol.deleteDuplicates(head));
    return 0;
}
