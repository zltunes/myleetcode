#include <iostream>
#include <vector>
#include <deque>
#include "TreeNode.h"
using namespace std;

using vi = vector<int>;

class Solution {
    using vi = vector<int>;
public:
    vector<int> postorderTraversal(TreeNode *root) {
        return postorderTraversal_iterative_2(root);
    }
    //recursive
    void postorderTraversal_recursive(vi &ret, TreeNode *root) {
        if(root == NULL) return;
        postorderTraversal_recursive(ret, root->left); 
        postorderTraversal_recursive(ret, root->right); 
        ret.push_back(root->val);
    }
    //iterative
    vi postorderTraversal_iterative_1(TreeNode *root) {
        vi ret;
        if(root == NULL) return ret;
        vector<pair<TreeNode *, bool>> q;
        TreeNode *cur = root;
        while(!q.empty() || cur) {
            if(cur) {
                q.push_back(make_pair(cur, false));
                cur = cur->left;
            }
            else {
                auto &t = q.back();
                if(t.second) {
                    q.pop_back();
                    ret.push_back(t.first->val);
                }
                else {
                    t.second = true;
                    cur = t.first->right;
                }
            }
        }
        return ret;
    }

    vi postorderTraversal_iterative_2(TreeNode *root) {
        vi ret;
        if(root == NULL) return ret;
        vector<TreeNode *> q {root};
        TreeNode *pre;

        while(!q.empty()) {
            auto &cur = q.back();
            auto &l = cur->left;
            auto &r = cur->right;
            if(l == pre || r == pre || (l == NULL && r == NULL)) {
                ret.push_back(cur->val);
                q.pop_back();
                pre = cur;
            }
            else {
                if(r) q.push_back(r);
                if(l) q.push_back(l);
            }
        }
        return ret;
    }
};

int main() {
    BuildTree b;
    TreeNode *t = b.levelOrderBuildTree(vi {1});
    Solution sol;
    vi ret = sol.postorderTraversal(t);
    for(auto &item : ret)
        cout << item << ' ';
    cout << endl;
    return 0;
}
