#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *initListWithVec(vector<int> &vec) {
    ListNode *dummy = new ListNode(0);
    ListNode *temp  = dummy;
    for(auto item : vec) {
        temp->next = new ListNode(item);
        temp = temp->next;
    }
    temp = dummy->next;
    delete dummy;
    return temp;
}

void printList(ListNode *head) {
    ListNode *temp = head;
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *tNode = dummy;
        ListNode *it    = dummy;
        bool isMoved;
        while(tNode->next) {
            it = dummy;
            isMoved = false;
            while(tNode->next != it->next) {
                if(tNode->next->val < it->next->val) {
                    ListNode *t = tNode->next;
                    tNode->next = tNode->next->next;
                    t->next     = it->next;
                    it->next    = t;
                    isMoved     = true;
                    break;
                }
                else {
                    it = it->next;
                }
            }
            if(!isMoved)
                tNode = tNode->next; 
        }
        return dummy->next;
    }
};

int main() {
    vector<int> vec = {};
    ListNode *head = initListWithVec(vec);
    Solution sol;
    printList(sol.insertionSortList(head));
    return 0;
}
