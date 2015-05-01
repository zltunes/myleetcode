#include <iostream>
#include <deque>
#include <vector>
#include "TreeNode.h"
using namespace std;

typedef vector<int> vi;

class Solution {
    typedef deque<TreeNode *> dT;
    typedef vector<TreeNode *> vT;
public:
    int minDepth(TreeNode *root) {
        if(root == NULL) return 0; 
        dT q {root};
        int level = 1;
        while(!q.empty()) {
            vT t {q.begin(), q.end()};
            q.clear();
            for(auto & node : t) {
                if(node->left == NULL && node->right == NULL) return level;
                if(node->left) q.push_back(node->left); 
                if(node->right) q.push_back(node->right); 
            } 
            ++level;
        }
        return level;
    }
};

int main() {
    vi i_tree {1,2,3,4,-1,-1,5};
    BuildTree builder;
    TreeNode *tree = builder.levelOrderBuildTree(i_tree);

    Solution sol;
    cout << sol.minDepth(tree) << endl;
    return 0;
}
