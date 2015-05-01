#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        return (root == NULL) || (root && isSymmetric(root->left, root->right));
    }

    bool isSymmetric(TreeNode *l_tree, TreeNode *r_tree) {
        return (l_tree == NULL && r_tree == NULL) || (l_tree && r_tree && l_tree->val == r_tree->val && isSymmetric(l_tree->left, r_tree->right) && isSymmetric(l_tree->right, r_tree->left));
    }
};

int main() {
    

    return 0;
}
