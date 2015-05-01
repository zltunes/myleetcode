#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution {
    typedef vector<int> vi;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return worker(postorder, inorder.begin(), inorder.end()); 
    }

    TreeNode *worker(vi &postorder, vi::iterator left, vi::iterator right) {
        if(left >= right || postorder.empty()) return NULL;
        int root_val = postorder.back();
        auto it = find(left, right, root_val);
        TreeNode *root = NULL;
        if(it != right) {
            root = new TreeNode(root_val);
            postorder.pop_back();
            root->right = worker(postorder, it + 1, right);
            root->left = worker(postorder, left, it);
        }
        return root;
    }
};

int main() {

    return 0;
}
