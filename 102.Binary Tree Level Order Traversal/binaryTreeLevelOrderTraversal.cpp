#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef deque<TreeNode *> dT;
typedef vector<TreeNode *> vT;
typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    typedef deque<TreeNode *> dT;
    typedef vector<TreeNode *> vT;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vvi ret;
        if(root == NULL) return ret;
        dT q;
        q.push_back(root);
        while(!q.empty()) {
            vT temp {q.begin(), q.end()};
            q.clear();
            vi nv;
            for(auto & node : temp) {
                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);
                nv.push_back(node->val);
            }
            ret.push_back(nv);
        }
        return ret;
    }
};

TreeNode *buidlTree(int n) {
    if(n == 0) return NULL;
    TreeNode *root = new TreeNode(n);
    root->left = buidlTree(n - 1);
    root->right = buidlTree(n - 1);
    return root;
}

int main() {
    TreeNode *tree = buidlTree(0);

    Solution sol;
    vvi ret = sol.levelOrder(tree);

    for(auto & row : ret) {
        for(auto & item : row) {
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}
