#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int next_pos = 1;
        for(int i = 1; i < n; ++i) {
            if(A[i] != A[next_pos - 1]) {
                A[next_pos] = A[i];
                ++next_pos;
            }
            else {
                if(next_pos == 1 || A[next_pos - 2] != A[i]) {
                    A[next_pos] = A[i];
                    ++next_pos;
                }
            }
        }
        return next_pos;
    }
};

int main() {

    int A[] = {1,2,3,4,4,4,5,5,};
    const int SIZE_INT = sizeof(int);

    Solution sol;
    int size = sol.removeDuplicates(A, sizeof(A) / SIZE_INT);
    cout << size << endl;
    for(int i = 0; i < size; ++i) {
        cout << A[i] << ' ';
    } 
    cout << endl;
    return 0;
}
