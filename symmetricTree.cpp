#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        leftVec.clear();
        rightVec.clear();
        visitLeft(root);
        visitRight(root);
        for(int i = 0; i < leftVec.size(); ++i) {
            if(leftVec[i] != rightVec[i])
                return false;
        }
        return true;
    }

    void visitLeft(TreeNode *node) {
        if(node == NULL) {
            leftVec.push_back(-1);   
            return;
        }
        visitLeft(node->left);
        leftVec.push_back(node->val);
        visitLeft(node->right);
    } 
    void visitRight(TreeNode *node) {
        if(node == NULL) {
            rightVec.push_back(-1);
            return;
        }
        visitRight(node->right);
        rightVec.push_back(node->val);
        visitRight(node->left);
    }
private:
    vector<int> leftVec;
    vector<int> rightVec;
};

int main() {
    

    return 0;
}
