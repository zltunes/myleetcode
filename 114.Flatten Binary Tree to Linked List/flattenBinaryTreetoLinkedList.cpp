#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode *pre = NULL;
    void flatten(TreeNode *root) {
        if(root == NULL) return;
        TreeNode *r_right = root->right;
        if(pre) {
            pre->right = root;
            pre->left = NULL;
        }
        pre = root;
        flatten(root->left);
        flatten(r_right);
    }
};

void printTreeRight(const TreeNode *root) {
    while(root) {
        cout << root->val << ' ';
        root = root->right;
    }
    cout << endl;
}

int main() {
    vector<int> i_tree {1,-1,2}; 

    BuildTree builder;
    TreeNode *tree = builder.levelOrderBuildTree(i_tree);

    cout << "start flatten" << endl;
    Solution sol;
    sol.flatten(tree);
    cout << "flatten complete" << endl;
    printTreeRight(tree);
    return 0;
}
