#include <iostream>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if(root == NULL) return false;
        return worker(root, sum);
    }


    bool worker(TreeNode *root, int sum) {
        if(root->left == NULL && root->right == NULL) {
            if(sum == root->val) return true;
            return false;
        }
        
        return (root->left && worker(root->left, sum - root->val)) || (root->right && worker(root->right, sum - root->val));
    }
};

int main() {
    
    vector<int> i_tree = {1,2};
    int target = 1;

    BuildTree builder;
    TreeNode *tree = builder.levelOrderBuildTree(i_tree);
    builder.printLevelOrder(tree);

    Solution sol;
    cout << sol.hasPathSum(tree, target) << endl;
    return 0;
}
