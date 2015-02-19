#include <iostream>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n == 0 || n == 1) return true;
        return worker(A, 0, n);
    }

    bool worker(int A[], int first, int n) {
        if(first == n - 1) return true;
        if(A[first] == 0) return false;
        for(int i = 1; i <= A[first]; ++i) {
            if(worker(A, first + i, n)) {
                return true;
            }
        } 
        return false;
    }
};

int main() {
    int A[] = {2,0};
    //int A[] = {3,2,1,0,4};
    const int SIZE_INT = sizeof(int);

    Solution sol;
    cout << sol.canJump(A, sizeof(A) / SIZE_INT) << endl;
    return 0;
}
