#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head) {
    ListNode *t = head;
    while(t) {
        cout << t->val << ' ';
        t = t->next;
    }
    cout << endl;
}

class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL) return;
        if(head->next == NULL) return;
        ListNode *temp = head->next;
        ListNode *half = head;
        bool flag = false;
        while(temp->next) {
            if(flag) half = half->next;
            temp = temp->next; 
            flag = !flag;
        }
        ListNode *half_next = half->next;
        half->next = NULL;
        ListNode *l2 = reverseList(half_next);
        ListNode *l1 = head;
        //printList(l1);
        //printList(l2);
        temp = l1;
        flag = true;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        while(l1 && l2) {
            //printList(head);
            if(flag) {
                t1 = l1->next;
                temp->next = l2;
                //cout << "temp :" << temp->val << endl;
                //cout << "l2 :" << l2->val << endl;
                l1 = t1;
            }
            else {
                t2 = l2->next;
                temp->next = l1;
                //cout << "temp :" << temp->val << endl;
                //cout << "l1 :" << l1->val << endl;
                l2 = t2;
            }
            temp = temp->next;
            flag = !flag;
            //getchar();
        }
    }
    ListNode* reverseList(ListNode *head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        ListNode *before = new ListNode(0);
        ListNode *vHead = before;
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
        vHead->next->next = NULL;
        delete vHead;
        return temp;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    ListNode *temp = head;
    temp->next = new ListNode(2);
    temp = temp->next;
    temp->next = new ListNode(3);
    temp = temp->next;
    temp->next = NULL;
    Solution sol;
    sol.reorderList(head);
    printList(head);
    return 0;
}
