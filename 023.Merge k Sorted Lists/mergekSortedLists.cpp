#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printLists(const ListNode *l);

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        deque<ListNode *> d_lists {lists.begin(), lists.end()};
        while(d_lists.size() != 1) {
            ListNode *l1 = d_lists[0];
            ListNode *l2 = d_lists[1];
            d_lists.pop_front();
            d_lists.pop_front();
            d_lists.push_back(mergeTwo(l1, l2));
        }
        return d_lists[0];
    }

    ListNode *mergeTwo(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *dummy = new ListNode(-1);
        ListNode *iter = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                iter->next = l1;
                l1 = l1->next;
            }
            else {
                iter->next = l2;
                l2 = l2->next;
            }
            iter = iter->next;
        }
        if(l1) {
            iter->next = l1;
        }
        if(l2) {
            iter->next = l2;
        }
        return dummy->next;
    }
};

ListNode *genList(int num, int interval, int begin = 0) {
    int val = begin;
    ListNode *dummy = new ListNode(-1);
    ListNode *iter = dummy;
    while(num--) {
        iter->next = new ListNode(val);
        iter = iter->next;
        val += interval;
    }
    return dummy->next;
}

void printLists(const ListNode *l) {
    while(l) {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << endl;
}

int main() {
    vector<ListNode *> vL {genList(3,1), genList(4,2,1), genList(2,0,-1)};
    for(auto & l : vL) {
        printLists(l);
    }
    Solution sol;
    printLists(sol.mergeKLists(vL));
    return 0;
}
