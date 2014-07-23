#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        if(head->next == NULL) return false;
        ListNode *tNode = head;
        while(tNode) {
            if(tNode->next == tNode) return true;
            ListNode *temp = tNode->next;
            tNode->next = tNode;
            tNode = temp;
        }
        return false;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    ListNode *tNode = head;
    tNode->next = new ListNode(2);
    tNode = tNode->next;
    tNode->next = new ListNode(2);
    tNode = tNode->next;
    tNode->next = new ListNode(2);
    tNode = tNode->next;
    tNode->next = NULL;

    Solution sol;

    cout << sol.hasCycle(head) << endl;
    return 0;
}
