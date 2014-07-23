#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return makeTreeFromVector(num.begin(), num.end());
    }
    TreeNode *makeTreeFromVector(const vector<int> :: iterator &begin, const vector<int> :: iterator &end) {
        if(begin == end) return NULL;
        vector<int> :: iterator mid = begin + (end - begin) / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = makeTreeFromVector(begin, mid);
        root->right = makeTreeFromVector(mid + 1, end);
        return root;
    }
};

int main() {
    vector<int> vec = {2};
    Solution sol;
    TreeNode *root = sol.sortedArrayToBST(vec);
    cout << root->val << endl; 
    return 0;
}
