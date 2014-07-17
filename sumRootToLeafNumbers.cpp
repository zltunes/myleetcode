 /*************************************************************************
    > Author: yiyunyao
    > Mail: yiyunyao@sina.cn
    > Created Time: 2014年04月03日 星期四 11时04分20秒
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int sumNumbers( TreeNode *root ) {
            return sumNumbers_method1( root );
        }

        int sumNumbers_method1( TreeNode* root ) {
            int sum = 0;
            sumNumbers_re( root, 0, sum );
            return sum;
        }

        void sumNumbers_re( TreeNode* node, int to_num, int &sum ) {
            if( node == NULL ) return;
            to_num = to_num * 10 + node->val;
            if( node->left == NULL && node->right == NULL ) {
                sum += to_num;
                return;
            }
            
            sumNumbers_re( node->left, to_num, sum );
            sumNumbers_re( node->right, to_num, sum );
        }

        int sumNumbers_method2( TreeNode* root ) {
            if( root == NULL ) return 0;
            int sum = 0;
            queue< pair<TreeNode *, int> > nodeQueue;
            nodeQueue.push( make_pair( root, root->val ) );
            TreeNode *currentNode = NULL;
            while( nodeQueue.empty() == false ) {
                currentNode = nodeQueue.front().first;
                int to_num  = nodeQueue.front().second;
                if( !currentNode->left && !currentNode->right )
                    sum += to_num;
                else {
                    if( currentNode->left )
                        nodeQueue.push( make_pair( currentNode->left, to_num * 10 + currentNode->left->val ) );
                    if( currentNode->right )
                        nodeQueue.push( make_pair( currentNode->right, to_num * 10 + currentNode->right->val ) );

                }
                nodeQueue.pop();
            }
            return sum;
        }

};
