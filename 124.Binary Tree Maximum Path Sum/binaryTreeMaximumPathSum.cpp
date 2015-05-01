#include <iostream>
#include <vector>
#include <climits>
#include "TreeNode.h"
using namespace std;
using vi = vector<int>;

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int max_path_sum = INT_MIN;
        maxPathSum(root, max_path_sum);
        return max_path_sum;
    }

    int maxPathSum(TreeNode *root, int &max_path_sum) {
        if(root == NULL) return 0; 

        int left = maxPathSum(root->left, max_path_sum);
        int right = maxPathSum(root->right, max_path_sum);

        int ret = max(root->val, max(root->val + left, root->val + right));

        max_path_sum = max(max_path_sum, max(ret, root->val + left + right));
        return ret;
    }
};

int main() {
    BuildTree b;
    TreeNode *t = b.levelOrderBuildTree(vi {-3});
    
    Solution sol;
    cout << sol.maxPathSum(t) << endl;
    return 0;
}
