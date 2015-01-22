#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printLists(ListNode * const l);

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        dummy = new ListNode(-1);
        ListNode *iter = dummy;
        bool isCarry = false;
        while(l1 && l2) {
            int sum_val = l1->val + l2->val;
            if(isCarry) {
                sum_val += 1;
                isCarry = false;
            }
            if(sum_val > 9) {
                sum_val -= 10;
                isCarry = true;
            }
            iter->next = new ListNode(sum_val);
            iter = iter->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1) {
            iter->next = l1;
        }
        else if(l2) {
            iter->next = l2;
        }
        else {
            if(isCarry) {
                iter->next = new ListNode(1);
            }
            return dummy->next;
        }
        while(iter->next && isCarry) {
            iter->next->val += 1;
            isCarry = false;
            if(iter->next->val > 9) {
                iter->next->val -= 10;
                isCarry = true;
            } 
            iter = iter->next;
        }
        if(isCarry) {
            iter->next = new ListNode(1);
        }
        return dummy->next;
    }

    virtual ~Solution() {
        if(dummy) {
            delete dummy;
        } 
    }
private:
    ListNode *dummy;
};

ListNode * generateNode(vector<int> & v) {
    if(v.size() == 0) return NULL;
    ListNode *dummy = new ListNode(-1);
    ListNode *iter = dummy;
    ListNode *ret = NULL;
    for(vector<int> :: iterator it = v.begin(); it != v.end(); ++it) {
        iter->next = new ListNode(*it);
        iter = iter->next;
    }
    ret = dummy->next;
    delete dummy;
    return ret;
}

void printLists(ListNode * const l) {
    ListNode *it = l;
    while(it) {
        cout << it->val << "->"; 
        it = it->next;
    }
    cout << endl;
}

int main() {
    vector<int> v1 {1,2,3};
    vector<int> v2 {9,7,6,9};
    ListNode * test1 = generateNode(v1);
    ListNode * test2 = generateNode(v2);
    printLists(test1);
    printLists(test2);

    Solution sol;
    printLists(sol.addTwoNumbers(test1, test2));
    return 0;
}
