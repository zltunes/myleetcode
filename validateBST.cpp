#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int leftMax = INT_MIN;
        int rightMin = INT_MAX;
        return isValidBSTWorker(root, leftMax, rightMin);
    }

    bool isValidBSTWorker(TreeNode *root, int leftMax, int rightMin) {
        if(root == NULL) return true;
        if(root->val > leftMax && root->val < rightMin) {
            return isValidBSTWorker(root->left, leftMax, min(rightMin, root->val)) && isValidBSTWorker(root->right, max(leftMax, root->val), rightMin);
        }
        return false;
    }
};

int main() {
    TreeNode *root = new TreeNode(87);
    root->left = new TreeNode(84);
    root->right = new TreeNode(94);
    TreeNode *temp = root->left;
    temp->left = new TreeNode(79);
    temp = temp->left;
    temp->left = new TreeNode(77);
    temp = temp->left;
    temp->left = new TreeNode(-82);
    temp = temp->left;
    temp->left = new TreeNode(70);
    temp = temp->left;
    Solution sol;
    cout << sol.isValidBST(root);
    return 0;
}
