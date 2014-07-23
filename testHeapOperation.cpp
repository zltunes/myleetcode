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
        return NULL;
    }
};

void print_vec(vector<int> & vec) {
    for(vector<int> :: iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

}
int main() {

    vector<int> vec = {1,2,3,4,6,7,8};
    print_vec(vec);
    make_heap(vec.begin(), vec.end());
    print_vec(vec);
    pop_heap(vec.begin(), vec.end());
    print_vec(vec);
    vec.pop_back();
    print_vec(vec);
    vec.push_back(99);
    print_vec(vec);
    push_heap(vec.begin(), vec.end());
    print_vec(vec);
    sort_heap(vec.begin(), vec.end());
    print_vec(vec);
    return 0;
}
