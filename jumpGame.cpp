#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 0 || n == 1) return true;
        int max_step = A[0];
        for(int i = 1; i < n; ++i) {
            if(max_step == 0) return false;
            max_step = max(max_step - 1, A[i]);
            if(max_step + i >= n - 1) return true;
        }
        return true;
    }
};

int main() {
    //int A[] = {2,0};
    int A[] = {3,2,1,0,4};
    const int SIZE_INT = sizeof(int);

    Solution sol;
    cout << sol.canJump(A, sizeof(A) / SIZE_INT) << endl;
    return 0;
}
