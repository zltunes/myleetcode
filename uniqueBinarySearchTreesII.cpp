#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef vector<TreeNode *> vT;

class Solution {
    typedef vector<TreeNode *> vT;
public:
    vector<TreeNode *> generateTrees(int n) {
        return worker(1, n);        
    }

    vT worker(int left, int right) {
        vT ret;      
        if(left > right) {
            ret.push_back(NULL);
        }
        else {
            for(int i = left; i <= right; ++i) {
                vT left_tree = worker(left, i - 1);
                vT right_tree = worker(i + 1, right);
                for(auto & left_node : left_tree) {
                    for(auto & right_node : right_tree) {
                        TreeNode *root = new TreeNode(i);
                        root->left = left_node;
                        root->right = right_node;
                        ret.push_back(root);
                    }
                }
            }
        }
        return ret;
    }
};

void printTree(const TreeNode *root) {
    vector<const TreeNode *> stk;
    const TreeNode *it = root;
    while(it != NULL || !stk.empty()) {
        if(it != NULL) {
            stk.push_back(it);
            it = it->left;
        }
        else {
            it = stk.back();
            stk.pop_back();
            cout << it->val << ' ';
            it = it->right;
        }
    }
    cout << endl;
}
int main() {
    Solution sol;
    vT ret = sol.generateTrees(0);
    
    for(auto &node : ret) {
        printTree(node);
    }
    return 0;
}
