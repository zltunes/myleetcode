#include <iostream>
#include "ListNode.h"
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head;
/*
        ListNode *temp = head;
        while(temp) {
            cout << temp->val << ' ';
            temp = temp->next;
        }
        cout << endl;
        getchar();
*/
        bool flag = false;
        while(fast) {
            fast = fast->next;
            if(fast) {
                fast = fast->next;
                if(flag) slow = slow->next;
                if(!flag) flag = true;
            }
        }
        ListNode *right = sortList(slow->next);
        slow->next = NULL;
        ListNode *left = sortList(head);
        ListNode *ret = new ListNode(-1);
        ListNode *it = ret;
        while(left && right) {
            if(left->val > right->val) {
                it->next = right;
                right = right->next;
            }
            else {
                it->next = left;
                left = left->next;
            }
            it = it->next;
        }
        if(left) {
            it->next = left;
        }
        if(right) {
            it->next = right;
        }
        return ret->next;
    }
};

int main() {
    srand(time(NULL));
    ListNode *test = genRandomList(3);
    printList(test);

    Solution sol;
    ListNode *ret = sol.sortList(test);

    printList(ret);
    return 0;
}
