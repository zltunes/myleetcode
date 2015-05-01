#include <iostream>
#include <vector>
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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef deque<TreeNode *> dT;
typedef vector<TreeNode *> vT;

class Solution {
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef deque<TreeNode *> dT;
    typedef vector<TreeNode *> vT;
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vvi ret;
        if(root == NULL) return ret;  
        dT q {root};
        while(!q.empty()) {
            vT temp {q.begin(), q.end()};
            vi t;
            q.clear();
            for(auto & node : temp) {
                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);
                t.push_back(node->val);
            }
            ret.push_back(t);
        }
        return vvi {ret.rbegin(), ret.rend()};
    }
};

int main() {
    BuildTree builder;
    vi i_tree {1,2,3};
    TreeNode *tree = builder.levelOrderBuildTree(i_tree);
    cout << "build complete" << endl;
    Solution sol;
    vvi ret = sol.levelOrderBottom(tree);

    for(auto & row : ret) {
        for(auto & item : row) {
            cout << item << ' '; 
        }
        cout << endl;
    }
    return 0;
}
