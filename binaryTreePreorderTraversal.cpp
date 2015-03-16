#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

using vi = vector<int>;
using vT = vector<TreeNode *>;

class Solution {
    using vi = vector<int>;
    using vT = vector<TreeNode *>;
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vi ret;
        if(root == NULL) return ret;
        vT stk;
        TreeNode *it = root;
        while(!stk.empty() || it) {
            if(it) {
                stk.push_back(it);
                ret.push_back(it->val);
                it = it->left;
            }
            else {
                it = stk.back()->right;
                stk.pop_back();
            }
        } 
        return ret;
    }
};

int main() {
    BuildTree builder;
    TreeNode *test = builder.levelOrderBuildTree(vi {1,2,3,-1,5,6});

    builder.printLevelOrder(test);

    Solution sol;
    vi ret = sol.preorderTraversal(test);
    for(auto &item : ret) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}
