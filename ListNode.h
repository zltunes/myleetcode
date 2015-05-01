#ifndef __LISTNODE__
#define __LISTNODE__

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(const ListNode *l) {
    while(l) {
        cout << l->val << ' ';
        l = l->next;
    }
    cout << endl;
}

ListNode *genRandomList(int num, int max = -1) {
    if(max == -1) max = num * 2;
    ListNode *ret = new ListNode(-1);
    ListNode *it = ret;
    while(num--) {
        it->next = new ListNode(rand() % max);
        it = it->next;
    }
    return ret->next;
}

ListNode* genList(int num, int interval, int begin = 0) {
    ListNode *dummy = new ListNode(-1);
    ListNode *iter = dummy;
    while(num--) {
        iter->next = new ListNode(begin);
        begin += interval;
        iter = iter->next;
    }
    return dummy->next;
}

#endif
