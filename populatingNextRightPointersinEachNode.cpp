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
        if(root->left == NULL) return;
        TreeLinkNode *pre = root;
        while(pre) {
            if(pre->left == NULL) return;
            TreeLinkNode *iter = pre;
            do {
                iter->left->next = iter->right;
                iter->right->next = iter->next ? iter->next->left : NULL;
                iter = iter->next;
            } while(iter);
            pre = pre->left;
        }
    }
};

int main() {

    return 0;
}
