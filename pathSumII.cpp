#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<TreeNode *> vT;

class Solution {
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef pair<int, vi> pivi;
    typedef pair<TreeNode *, pivi> pTpivi;
    typedef vector<TreeNode *> vT;
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vvi ret;
        if(root == NULL) return ret; 
        vector<pTpivi> stk;
        stk.push_back(make_pair(root, make_pair(root->val, vi {root->val})));
        while(!stk.empty()) {
            pTpivi cur = stk.back(); 
            TreeNode *t = cur.first;
            pivi &info = cur.second;
            stk.pop_back();
            if(t->left == NULL && t->right == NULL && info.first == sum) {
                ret.push_back(info.second);
            }
            if(t->right) {
                pivi t_info;
                t_info.first = info.first + t->right->val;
                t_info.second = info.second;
                t_info.second.push_back(t->right->val);
                stk.push_back(make_pair(t->right, t_info));
            }
            if(t->left) {
                pivi t_info;
                t_info.first = info.first + t->left->val;
                t_info.second = info.second;
                t_info.second.push_back(t->left->val);
                stk.push_back(make_pair(t->left, t_info));
            }
        }
        return ret;
    }
};

int main() {
    vi i_tree {};
    int target = 5;
    BuildTree builder;
    TreeNode *tree = builder.levelOrderBuildTree(i_tree);

    Solution sol;
    vvi ret = sol.pathSum(tree, target);

    for(auto & row : ret) {
        for(auto & item : row) {
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}
