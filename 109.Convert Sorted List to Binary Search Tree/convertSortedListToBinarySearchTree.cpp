#include <iostream>
#include "TreeNode.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *iter = head;
        bool flag = false;
        ListNode *dummy = new ListNode(-1);;
        dummy->next = head;
        ListNode *half = dummy;
        while(iter->next) {
            iter = iter->next;
            if(flag) half = half->next;
            flag = !flag;
        }
        TreeNode *root = NULL;
        root = new TreeNode(half->next->val);
        root->right = sortedListToBST(half->next->next);
        half->next = NULL;
        root->left = sortedListToBST(dummy->next);
        return root;
    }
};

ListNode *genList(int n) {
    ListNode *dummy = new ListNode(-1);
    ListNode *it = dummy;
    int i = 0;
    while(i < n) {
        it->next = new ListNode(i);
        ++i;
        it = it->next;
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
    ListNode *l = genList(3);
    printList(l);    

    Solution sol;
    TreeNode *tree = sol.sortedListToBST(l);

    BuildTree builder;
    builder.printLevelOrder(tree);

    return 0;
}
