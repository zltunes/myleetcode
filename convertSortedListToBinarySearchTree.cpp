#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {

    }
    ListNode *findMid(ListNode *head) {
        ListNode *it = head;
        ListNode *half = head;
        bool flag = false;
        while(it) {
            if(flag) {
                half = half->next;
            }
            it = it->next;
            flag = !flag;
        }
        return half;
    }
    TreeNode *constructTreeNode(ListNode *lNode) {
        ListNode *mid = findMid(lNode);
        TreeNode *root = new TreeNode(mid->val);
        
    }

};


int main() {


    return 0;
}
