#ifndef __TREENODE_H__
#define __TREENODE_H__

#include <iostream>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BuildTree {
public:
    TreeNode *levelOrderBuildTree(const vector<int> &vec) {
        TreeNode *root = NULL;
        if(vec.empty() || vec.front() == -1) return root;
        root = new TreeNode(vec.front());
        vector<TreeNode *> pre_level {root};
        auto it = vec.begin() + 1;
        while(!pre_level.empty()) {
            vector<TreeNode *> temp;
            for(auto &node : pre_level) {
                if(it != vec.end()) {
                    if(*it != -1) {
                        node->left = new TreeNode(*it);
                        temp.push_back(node->left);
                    }
                    ++it;
                }
                if(it != vec.end()) {
                    if(*it != -1) {
                        node->right = new TreeNode(*it);
                        temp.push_back(node->right);
                    }
                    ++it;
                }
            }
            pre_level = temp;
        }
        return root;
    }

    void printLevelOrder(TreeNode *root) {
        if(root == NULL) return;
        deque<TreeNode *> q { root };
        while(!q.empty()) {
            vector<TreeNode *> t { q.begin(), q.end() };
            q.clear();
            for(auto &item : t) {
                cout << item->val << ' ';
                if(item->left) q.push_back(item->left);
                if(item->right) q.push_back(item->right);
            }
            cout << endl;
        }
        cout << endl;
    }
};

bool isSameTree(TreeNode *t1, TreeNode *t2) {
    return (t1 == NULL && t2 == NULL) || (t1 && t2 && t1->val == t2->val && isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right));
}

#endif //__TREENODE_H__


