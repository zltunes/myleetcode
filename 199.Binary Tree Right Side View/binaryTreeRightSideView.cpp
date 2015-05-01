#include <iostream>
#include <vector>
#include <deque>
#include "TreeNode.h"
using namespace std;
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
using vi = vector<int>;

class Solution {
    using vi = vector<int>;
    using pTi = pair<TreeNode *, int>;
public:
    vector<int> rightSideView(TreeNode *root) {
        vi ret;
        if(root == NULL) return ret;
        deque<TreeNode *> q { root };
        while(!q.empty()) {
            ret.push_back(q.back()->val);
            vector<TreeNode *> temp { q.begin(), q.end() };
            q.clear();
            for(auto &cur : temp) {
                if(cur->left) q.push_back(cur->left); 
                if(cur->right) q.push_back(cur->right); 
            }
        }
        return ret;
    }
};

int main() {
    BuildTree b;
    TreeNode *t = b.levelOrderBuildTree(vi {1});
    b.printLevelOrder(t);

    Solution sol;
    vi ret = sol.rightSideView(t);

    for(auto &item : ret) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}
