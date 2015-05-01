#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL) return head;
        if(k == 0) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *iter = dummy;
        int move = k;
        while(k && iter->next) {
            iter = iter->next; 
            --k;
        }
        if(k || iter->next == NULL) {
            int len = move - k;
            k %= len;
            iter = dummy;
            while(k && iter->next) {
                iter = iter->next;
                --k;
            }
        } 
        ListNode *new_head = dummy;
        while(iter->next) {
            new_head = new_head->next;
            iter = iter->next;
        }
        iter->next = dummy->next;
        ListNode *ret = new_head->next;
        new_head->next = NULL;
        return ret; 
    }
};

ListNode *gen(int i) {
    ListNode *ret = new ListNode(-1);
    ListNode *iter = ret;
    while(i) {
        iter->next = new ListNode(i);
        i--;
        iter = iter->next;
    }
    return ret->next;
}

void printList(ListNode * l) {
    while(l) {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << endl;
}

int main() {
    ListNode *l = gen(3);
    printList(l);
    Solution sol;
    printList(sol.rotateRight(l, 2000000000));
    return 0;
}
