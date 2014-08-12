#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *initNodeFromVec(vector<int> &vec) {
    ListNode *dummy = new ListNode(0);
    ListNode *it = dummy; 
    for(auto num : vec) {
        it->next = new ListNode(num);
        it = it->next;
    }
    it = dummy->next;
    delete dummy;
    return it;
}

void printList(const ListNode *const node) {
    const ListNode *it = node;
    while(it) {
        cout << it->val << " ";
        it = it->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(k == 0 || k == 1) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *it = head;
        head = dummy;
        int cnt = k;
        while(it) {
            cnt = k;
            ListNode *rec = it;
            while(--cnt && rec->next) {
                rec = rec->next; 
            }
            rec = rec->next;
            if(rec != NULL || cnt == 0) {
                ListNode *tail = reverse(it, k);
                if(tail)
                    tail->next = rec;
                dummy->next = it;
                dummy = tail;
            }
            it = rec;
        }
        return head->next;
    }
    ListNode* reverse(ListNode *&head, int num) {
        ListNode *dummy = new ListNode(0);
        ListNode *ret = head;
        dummy->next = head;
        ListNode *it = head;
        ListNode *follow = head->next;
        while(--num && follow) {
            it->next = dummy;
            dummy = it;
            it = follow;
            follow = follow->next;
        }
        it->next = dummy;
        head = it;
        delete ret->next;
        ret->next = NULL;
        return ret;
    }
};

int main() {
    vector<int> vec = {1,2,3,4};
    Solution sol;
    ListNode *list = initNodeFromVec(vec);
    printList(list);
    printList(sol.reverseKGroup(list, 3));
    
    return 0;
}
