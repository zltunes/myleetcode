#ifndef __LISTNODE__
#define __LISTNODE__

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(const ListNode *l)
{
    while(l)
    {
        std::cout << l->val << ' ';
        l = l->next;
    }
    std::cout << std::endl;
}

ListNode *genRandomList(int num, int max = -1)
{
    if(max == -1) max = num * 2;
    ListNode *it, *ret;
    it = ret = new ListNode(-1);
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<> dis(0, max);
    while(num--)
    {
        it->next = new ListNode(dis(gen));
        it = it->next;
    }
    return ret->next;
}

ListNode* genList(int num, int interval = 1, int begin = 0)
{
    ListNode *it, *ret;
    it = ret = new ListNode(-1);
    while(num--)
    {
        it->next = new ListNode(begin);
        begin += interval;
        it = it->next;
    }
    return ret->next;
}

#endif
