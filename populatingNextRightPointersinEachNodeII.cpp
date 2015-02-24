#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        TreeLinkNode *pre = root;
        while(pre) {
            TreeLinkNode *iter = NULL;
            TreeLinkNode *pre_iter = pre;
            iter = findNext(iter, pre_iter); 
            pre = iter;
            while(iter) {
                iter->next = findNext(iter, pre_iter);
                iter = iter->next;
            }
        }
    }

    TreeLinkNode* findNext(TreeLinkNode* iter, TreeLinkNode *&pre) {
        TreeLinkNode *ret = NULL;
        while(pre) {
            if(pre->left && pre->left != iter) {
                ret = pre->left;
                break;
            }
            if(pre->right && pre->right != iter) {
                ret = pre->right;
                pre = pre->next;
                break;
            }
            pre = pre->next;
        }
        return ret;
    }
};

int main() {
    TreeLinkNode * root = new TreeLinkNode(1);
    TreeLinkNode * t2 = new TreeLinkNode(2);
    TreeLinkNode * t3 = new TreeLinkNode(3);
    TreeLinkNode * t4 = new TreeLinkNode(4);
    TreeLinkNode * t5 = new TreeLinkNode(5);
    TreeLinkNode * t6 = new TreeLinkNode(6);
    TreeLinkNode * t7 = new TreeLinkNode(7);

    t2->left = t4;
    t3->left = t6;

    Solution sol;
    sol.connect(root);

    return 0;
}
