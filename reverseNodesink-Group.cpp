#include <iostream>
#include <stack>
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k <= 1 || head == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *iter = dummy;
        dummy->next = head;
        while(enoughNodes(iter, k)) {
            iter->next = reverse(iter, k); 
            int t = k;
            while(t--) {
                iter = iter->next;
            }
        }
        return dummy->next;
    }
    bool enoughNodes(const ListNode *iter, int k) {
        while(k--) {
            if(iter->next == NULL) {
                return false;
            }
            iter = iter->next;
        }
        return true;
    }
    ListNode *reverse(ListNode *iter, int k) {
        stack<ListNode *> lnstk;
        ListNode *head = iter;
        while(k--) {
            lnstk.push(iter->next);
            iter = iter->next;
        }
        head->next = iter;
        iter = iter->next;
        ListNode *temp = NULL;
        while(!lnstk.empty()) {
            temp = lnstk.top();
            lnstk.pop();
            if(!lnstk.empty())
                temp->next = lnstk.top();
        }
        temp->next = iter;
        return head->next;
    }
};

int main() {
    Solution sol;
    printList(sol.reverseKGroup(genList(8,1,1), 7));
    return 0;
}
