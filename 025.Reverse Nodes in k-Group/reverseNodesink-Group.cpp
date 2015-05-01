#include <iostream>
#include <vector>
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
    ListNode *reverseKGroup(ListNode *l, int k) {
        ListNode *dummy = new ListNode(-1);
        ListNode *it = dummy;
        vector<ListNode *> stk;
        for(;;) {
            for(int i = 0; i < k; ++i) {
                if(l) {
                    stk.push_back(l);
                    l = l->next;
                }
                else break;
            }
            if(stk.size() == k) {
                while(!stk.empty()) {
                    it->next = stk.back();
                    stk.pop_back();
                    it = it->next;
                }
                it->next = l;
            }
            else break;
        }
        return dummy->next;
    }
};

int main() {
    Solution sol;
    printList(sol.reverseKGroup(genList(8,1,1), 3));
    return 0;
}
