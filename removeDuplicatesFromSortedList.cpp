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
        if(head->next == NULL) return head;
        tHead = head;
        tEnd = head->next;
        while(tHead) {
            if(tEnd != NULL && tHead->val == tEnd->val) {
                tEnd = tEnd->next;
            }
            else {
                tHead->next = tEnd;
                tHead = tEnd;
                if(tEnd != NULL)
                    tEnd = tEnd->next;
            }
        }
        return head; 
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
