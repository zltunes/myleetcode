#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *temp = head;
        ListNode *half = head;
        bool flag = false;
        while(temp) {
            if(flag) half = half->next;
            temp = temp->next; 
            flag = ~flag;
        }
        ListNode *half_next = half->next;
        half->next = NULL;
        ListNode *l2 = reverseList(half_next);
        ListNode *l1 = head;
        while(l1 && l2) {
            ListNode *t1 = l1->next;
            l1->next = l2;
            ListNode *t2 = l2->next;
            l2->next = t1;
            l1 = t1;
            l2 = t2;
        }
        if(l1)

    }
    ListNode* reverseList(ListNode *head) {
        if(head == NULL) return;
        if(head->next == NULL) return;
        ListNode *before = new ListNode(0);
        before->next = head;
        ListNode *temp = head;
        ListNode *follow = head->next;
        
        while(follow) {
            temp->next = before;
            before = temp;
            temp = follow;
            follow = follow->next;
        }
        temp->next = before;
        before->next->next = NULL;
        delete before;
        return temp;
    }
};

void printList(ListNode *head) {
    ListNode *t = head;
    while(t) {
        cout << t->val << ' ';
        t = t->next;
    }
    cout << endl;
}
int main() {
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    temp->next = new ListNode(2);
    temp = temp->next;
    temp->next = new ListNode(3);
    temp = temp->next;
    temp->next = new ListNode(4);
    temp = temp->next;
    temp->next = NULL;
    Solution sol;
    sol.reorderList(head);
    printList(head);
    return 0;
}
