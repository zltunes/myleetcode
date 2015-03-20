#include <iostream>
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
using vT = vector<TreeNode *>;

class BSTIterator {
    using vT = vector<TreeNode *>;
public:
    BSTIterator(TreeNode *root) {
        addToVec(root);
        iter = vec.begin();
    }

    void addToVec(TreeNode *node) {
        if(node == NULL) return;
        addToVec(node->left);
        vec.push_back(node);
        addToVec(node->right);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return iter != vec.end();
    }

    /** @return the next smallest number */
    int next() {
        return (*(iter++))->val;
    }

private:
    vT::iterator iter;
    vT vec;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    BuildTree builder;
    TreeNode *root = builder.levelOrderBuildTree(vi {4,2,6,1,3,5,7});
    BSTIterator i(root);

    while(i.hasNext()) {
        cout << i.next() << endl;
    }
    return 0;
}
