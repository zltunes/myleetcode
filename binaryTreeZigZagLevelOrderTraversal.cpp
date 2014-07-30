#include <iostream>
#include <queue>
#include <stack>
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ret;
        if(root == NULL) return ret;
        queue<pair<TreeNode *, bool>> mQueue;
        stack<int> mStack;
        vector<int> mVec;
        mQueue.push(make_pair(root, true));
        while(!mQueue.empty()) {
            pair<TreeNode*, bool> f = mQueue.front();
            bool thisTurn = f.second;
            mVec.clear();
            while(!mQueue.empty() && f.second == thisTurn) {
                if(!thisTurn)
                    mStack.push(f.first->val);
                else
                    mVec.push_back(f.first->val);
                if(f.first->left) mQueue.push(make_pair(f.first->left, !thisTurn));
                if(f.first->right) mQueue.push(make_pair(f.first->right, !thisTurn));
                mQueue.pop();
                if(!mQueue.empty()) f = mQueue.front();
            } 
            if(!thisTurn) {
                mVec.clear();
                while(!mStack.empty()) {
                    mVec.push_back(mStack.top());
                    mStack.pop();
                }
            }
            ret.push_back(mVec);
        }
        return ret;
    }
};

int main() {
    TreeNode *root = new TreeNode(0);
    TreeNode *temp = root;
    temp->left = new TreeNode(1);
    temp->right = new TreeNode(2);
    temp = root->left;
    temp->left = new TreeNode(3);
    temp->right = new TreeNode(4);
    temp = root->right;
    temp->left = new TreeNode(5);
    temp->right = new TreeNode(6);
    Solution sol;
    vector<vector<int>> mVec = sol.zigzagLevelOrder(root);

    typedef vector<int> vint;
    for(vector<vint> :: iterator it = mVec.begin(); it != mVec.end(); ++it) {
        for(vint :: iterator inner_it = it->begin(); inner_it != it->end(); ++inner_it) {
            cout << *inner_it << " ";
        }
        cout << endl;
    }
    return 0;
}
