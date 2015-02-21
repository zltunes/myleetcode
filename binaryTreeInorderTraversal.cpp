#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<TreeNode *> vT;

class Solution {
    typedef vector<int> vi;
    typedef vector<TreeNode *> vT;
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vi ret;
        if(root == NULL) return ret;
        TreeNode *iter = root;
        vT stk;
        while(iter != NULL || !stk.empty()) {
            if(iter != NULL) {
                stk.push_back(iter);
                iter = iter->left;
            }
            else {
                iter = stk.back();
                stk.pop_back();
                ret.push_back(iter->val);
                iter = iter->right;
            }
        }
        return ret;
    }
};

TreeNode * buildTree(vc &vec) {
    if(vec.empty()) return NULL;
    TreeNode *root = new TreeNode(vec[0]);
    auto it = vec.begin() + 1;
    TreeNode *iter = root;
    bool left_is_visited = false;
    bool right_is_visited = false;
    vT stk;
    while(it != vec.end()) {
        if(iter->left == NULL && left_is_visited == false) {
            if(*it != '#') {
                iter->left = new TreeNode(*it);
            }
            left_is_visited = true;
            ++it;
        }
        else if(right_is_visited == false) {
            if(*it != '#') {
                iter->right = new TreeNode(*it);
            }
            right_is_visited = true;
            ++it;
        }
        else {
            stk.push_back(iter);
            if(iter->left) iter = iter->left;
            else if(iter->right) iter = iter->right;
            else {
                if(stk.empty()) break;
                iter = stk.back()->right;
                stk.pop_back();
            }
            left_is_visited = false;
            right_is_visited = false;
        }
    }
    return root;
}

TreeNode *buildTree(int i) {
    if(i == 0) return NULL;
    TreeNode *root = new TreeNode(i);
    root->left = buildTree(i - 1);
    root->right = buildTree(i - 1);
    return root;
}

void printVI(const vi &vec) {
    for(auto & item : vec) {
        cout << item << ' ';
    }
    cout << endl;
}

int main() {
    TreeNode *root = buildTree(3);
    cout << "finish building" << endl;
    Solution sol;
    printVI(sol.inorderTraversal(root));
    return 0;
}
