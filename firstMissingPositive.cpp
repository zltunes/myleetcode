#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n == 0 || A == NULL) return 1;
        for(int i = 0; i < n; ++i) {
            while(A[i] != i + 1) {
                if(A[i] - 1 >= n || A[i] <= 0 || A[i] == A[A[i] - 1]) break;
                swap(A[i], A[A[i] - 1]);
            }
        }
        for(int i = 0; i < n; ++i) {
            if(A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

int main() {
    int A[] = {-1,4,2,1,9,10};
    int size = sizeof(A) / sizeof(int);

    Solution sol;
    cout << sol.firstMissingPositive(A, size) << endl;
    return 0;
}
