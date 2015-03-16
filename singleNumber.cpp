#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        assert(n != 0);
        for(int i = 1; i < n; ++i) {
            A[0] ^= A[i]; 
        }
        return A[0];
    }
};

int main() {

    int A[] = {1,3,3};
    const int SIZE_INT = sizeof(int);

    Solution sol;
    cout << sol.singleNumber(A, sizeof(A) / SIZE_INT) << endl;

    return 0;
}
