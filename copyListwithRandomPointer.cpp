#include <iostream>
#include <unordered_map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
    using uRR = unordered_map<RandomListNode *, RandomListNode *>;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *dummy = new RandomListNode(-1);
        RandomListNode *iter, *iter_head;
        uRR mp;
        iter = dummy;
        iter_head = head;
        while(iter_head) {
            iter->next = new RandomListNode(iter_head->label);
            iter = iter->next;
            mp[iter_head] = iter;
            iter_head = iter_head->next;
        }
        
        iter = dummy->next;
        while(head) {
            iter->random = head->random ? mp[head->random] : NULL;
            iter = iter->next;
            head = head->next;
        } 
        return dummy->next;
    }
};

void printSituation(RandomListNode *n) {
    while(n) {
        cout << "label : " << n->label << ' ';
        cout << "random : " << (n->random ? n->random->label : -1) << endl;
        n = n->next;
    }
}

int main() {
    RandomListNode *i1 = new RandomListNode(1);
    RandomListNode *i2 = new RandomListNode(2);
    RandomListNode *i3 = new RandomListNode(3);
    RandomListNode *i4 = new RandomListNode(4);

    i1->next = i2;
    i2->next = i3;
    i3->next = i4;

    i1->random = i3;
    i4->random = i2;

    printSituation(i1);
    cout << endl;

    Solution sol;
    RandomListNode *l = sol.copyRandomList(i1);
    printSituation(l);

    return 0;
}
