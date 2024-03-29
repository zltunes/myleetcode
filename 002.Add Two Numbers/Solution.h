#include "../ListNode.h"

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *dummy, *iter;
        iter = dummy = new ListNode(-1);
        bool isCarry = false;
        while(l1 && l2)
        {
            int sum_val = l1->val + l2->val;
            if(isCarry)
            {
                sum_val += 1;
                isCarry = false;
            }
            if(sum_val > 9)
            {
                sum_val -= 10;
                isCarry = true;
            }
            iter->next = new ListNode(sum_val);
            iter = iter->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1)
            iter->next = l1;
        else if(l2)
            iter->next = l2;
        else
        {
            if(isCarry)
                iter->next = new ListNode(1);
            return dummy->next;
        }
        while(iter->next && isCarry)
        {
            iter->next->val += 1;
            isCarry = false;
            if(iter->next->val > 9)
            {
                iter->next->val -= 10;
                isCarry = true;
            } 
            iter = iter->next;
        }
        if(isCarry)
            iter->next = new ListNode(1);
        return dummy->next;
    }
};
