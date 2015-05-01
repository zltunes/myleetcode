#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 1) return n;
        int next_pos = 0;
        for(int i = 1; i < n; ++i) {
            if(A[i - 1] != A[i]) {
                A[++next_pos] = A[i];
            } 
        }
        return next_pos + 1;
    }
};

int main() {

    int A[] = {1, 2};
    Solution sol;
    int length = 0;
    cout << (length = sol.removeDuplicates(A, sizeof(A) / sizeof(int))) << endl;
    for(int i = 0; i < length; ++i) {
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}
