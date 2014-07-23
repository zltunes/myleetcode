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
        if(head == NULL || head->next == NULL) return head;
        ListNode *tNode = new ListNode(0);
        tNode->next = head;
        head = tNode;
        while(tNode->next && tNode->next->next) {
            if(tNode->next->val == tNode->next->next->val) {
                int val = tNode->next->val;
                while(tNode->next != NULL && val == tNode->next->val) {
                    tNode->next = tNode->next->next;
                }
            }
            else {
                tNode = tNode->next;
            }
        }
        ListNode *del = head;
        head = head->next;
        delete del;
        return head;
    }
};

int main() {
    ListNode *node = new ListNode(0);
    ListNode *head = node;
    node->next = new ListNode(0);
    node = node->next;
    node->next = new ListNode(3);
    node = node->next;
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
