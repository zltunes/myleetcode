#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(m == n) return head;
        if(head == NULL) return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *it = dummy;
        ListNode *m_head, *n_head;
        // m_head points to the node before head
        // n_head points to the node that ends
        while(it->next) {
            --m, --n;
            if(m == 0) m_head = it;
            if(n == 0) {
                n_head = it->next;
                break;
            }
            it = it->next;
        }
        n_head = n_head->next;
        auto pLL = reverseList(m_head->next, n - m);
        m_head->next = pLL.first; 
        pLL.second->next = n_head;
        return dummy->next;
    }
    pair<ListNode*, ListNode*> reverseList(ListNode *head, int n) {
        ListNode *back = head;
        ListNode *it = head;
        ListNode *cur = NULL;
        ListNode *temp;
        while(n && it) {
            temp = it->next;
            it->next = cur;
            cur = it;
            it = temp;
            --n;
        }
        it->next = cur;
        pair<ListNode *, ListNode *> ret;
        ret.first = it;
        ret.second = back;
        return ret;
    }
};

ListNode * genList(int n) {
    ListNode *dummy = new ListNode(-1);
    ListNode *it = dummy;
    int cnt = 1;
    while(cnt <= n) {
        it->next = new ListNode(cnt);
        it = it->next;
        ++cnt;
    }
    return dummy->next;
}

void printList(const ListNode *l) {
    while(l) {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << endl;
}

int main() {
    ListNode *l = genList(4);
    printList(l);
    int m = 1;
    int n = 4;
    Solution sol;
    printList(sol.reverseBetween(l, m, n));
    return 0;
}
