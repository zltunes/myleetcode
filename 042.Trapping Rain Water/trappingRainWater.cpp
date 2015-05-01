#include <iostream>
using namespace std;

class Solution {
public:
    int trap(int A[], int n) {
        if(n == 0 || A == NULL) return 0;
       
        int *t = new int[n];
        int cur = A[0];
        for(int i = 0; i < n; ++i) {
            if(A[i] >= cur) cur = A[i];
            t[i] = cur;
        }

        cur = A[n - 1];
        int ret = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(A[i] >= cur) cur = A[i];
            int min_val = min(cur, t[i]);
            ret += min_val - A[i];
        }
        return ret;
    }
};

int main() {
    //int test[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int test[] = {3, 1,0,2};
    int size = sizeof(test) / sizeof(int);
    Solution sol;
    cout << sol.trap(test, size) << endl;
    return 0;
}
