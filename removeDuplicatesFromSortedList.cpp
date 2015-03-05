#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *tHead, *tEnd;
        if(head == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        tHead = dummy;
        tEnd = dummy;
        while(tEnd->next) {
            if(tHead->next->val != tEnd->next->val) {
                tHead->next = tEnd;
                tHead = tEnd;
            }
            tEnd = tEnd->next;
        }
        tHead->next = tEnd;
        tHead = tEnd;
        return dummy->next; 
    }
};

void printNode(ListNode *head) {
    ListNode *tNode = head;
    while(tNode) {
        cout << tNode->val << " ";
        tNode = tNode->next;
    }
    cout << endl;
}

int main() {
    ListNode *tNode = new ListNode(1);
    ListNode *head = tNode;
    tNode->next = new ListNode(1);
    tNode = tNode->next;
    tNode->next = new ListNode(2);
    tNode = tNode->next;
    tNode->next = new ListNode(3);
    tNode = tNode->next;
    tNode->next = new ListNode(3);
    tNode = tNode->next;

    printNode(head);
    Solution sol;
    printNode(sol.deleteDuplicates(head));
    return 0;
}
