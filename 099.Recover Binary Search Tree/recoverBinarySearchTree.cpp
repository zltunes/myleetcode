#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;
using vi = vector<int>;

class Solution {
    using vi = vector<int>;
public:
    void recoverTree(TreeNode *root) {
        s1 = s2 = fore = NULL; 
        foreTraverse(root);
        fore = NULL;
        backTraverse(root);

        swap(s1->val, s2->val);
    }

    void foreTraverse(TreeNode *root) {
        if(root == NULL) return; 

        foreTraverse(root->left);
        if(s1) return;
        if(fore && fore->val > root->val) s1 = fore;
        fore = root;
        foreTraverse(root->right);
    }

    void backTraverse(TreeNode *root) {
        if(root == NULL) return;

        backTraverse(root->right);
        if(s2) return;
        if(fore && fore->val < root->val) s2 = fore;
        fore = root;
        backTraverse(root->left);
    }

private:
    TreeNode *s1, *s2, *fore;
};

int main() {
    BuildTree b;
    //auto root = b.levelOrderBuildTree(vi {4,1,6,2,3,5,7});
    //auto root = b.levelOrderBuildTree(vi {4,2,7,1,3,5,6});
    //auto root = b.levelOrderBuildTree(vi {6,2,4,1,3,5,7});
    auto root = b.levelOrderBuildTree(vi {7,-1,6});
    b.printLevelOrder(root);

    Solution sol;
    sol.recoverTree(root);
    b.printLevelOrder(root);

    return 0;
}
