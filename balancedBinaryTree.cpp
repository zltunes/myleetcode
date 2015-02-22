#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

typedef vector<int> vi;

class Solution {
    typedef pair<bool, int> pbi;
public:
    bool isBalanced(TreeNode *root) {
        return worker(root).first;        
    }

    pbi worker(TreeNode *root) {
        pbi ret {true, 0};
        if(root == NULL) return ret;
        pbi left = worker(root->left);
        pbi right = worker(root->right);
        ret.first = left.first && right.first && (left.second - right.second) < 2 && (left.second - right.second) > -2;
        if(ret.first) {
            ret.second = 1 + max(left.second, right.second);
        }
        return ret;
    }
};

int main() {
    vi i_tree {6,4,-1,3,5};
    BuildTree builder;
    TreeNode *tree = builder.levelOrderBuildTree(i_tree);
    
    Solution sol;
    cout << sol.isBalanced(tree) << endl;
    return 0;
}
