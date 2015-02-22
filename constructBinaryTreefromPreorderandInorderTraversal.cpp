#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include "TreeNode.h" 
using namespace std;

typedef vector<int> vi;
typedef deque<int> di;

class Solution {
    typedef vector<int> vi;
    typedef deque<int> di;
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        deque<int> d_preorder {preorder.begin(), preorder.end()};
        return worker(d_preorder, inorder.begin(), inorder.end());
    }

    TreeNode *worker(di &preorder, vi::iterator left, vi::iterator right) {
        if(left >= right || preorder.empty()) return NULL;
        int root_val = preorder.front();
        auto it = find(left, right, root_val);
        TreeNode *root = NULL;
        if(it != right) {
            root = new TreeNode(root_val);
            preorder.pop_front();
            root->left = worker(preorder, left, it);
            root->right = worker(preorder, it + 1, right);
        }
        return root;
    }
};

int main() {
    vi c_tree {1,2,3,-1,-1,4,-1,-1,5};
    //vc c_tree {'1','#','2','3'};

    cout << "printing tree 1" << endl;
    BuildTree builder;
    TreeNode *tree = builder.levelOrderBuildTree(c_tree);
    builder.printLevelOrder(tree);

    //vi preorder {1,2,3};
    //vi inorder {1,3,2};
    
    vi preorder {1,2,3,4,5};
    vi inorder {2,1,4,5,3};

    cout << "printing tree 2" << endl;
    Solution sol;
    TreeNode *tree2 = sol.buildTree(preorder, inorder);
    builder.printLevelOrder(tree2);

    cout << isSameTree(tree, tree2) << endl;
    return 0;
}
