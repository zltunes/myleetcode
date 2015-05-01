#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *constructListFromVec(vector<int> &vec) {
    ListNode *vNode = new ListNode(0);
    ListNode *it = vNode;
    for(auto item : vec) {
        it->next = new ListNode(item);
        it = it->next;
    }
    it = vNode->next;
    delete vNode;
    return it;
}

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *newList = new ListNode(0);
        ListNode *it = newList;
        while(l1 && l2) {
            if(l1->val > l2-> val) {
                it->next = l2;
                l2 = l2->next;
            }
            else {
                it->next = l1;
                l1 = l1->next;
            }
            it = it->next;
        }
        if(l1) {
            it->next = l1;
        }
        if(l2) {
            it->next = l2;
        }
        return newList->next;
    }
};

int main() {
    vector<int> v1 = {};
    vector<int> v2 = {1,2,3,4};
    ListNode *l1 = constructListFromVec(v1);
    ListNode *l2 = constructListFromVec(v2);
    cout << "begin testing ..." << endl;
    Solution sol;
    ListNode *newList = sol.mergeTwoLists(l1, l2);
    while(newList) {
        cout << newList->val << endl;
        newList = newList->next;
    }
    return 0;
}
