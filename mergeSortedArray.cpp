#include <iostream>
using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        for(int i = m - 1; i >= 0; --i) {
            A[i + n] = A[i];
        } 
        int i = n, j = 0;
        int pos = 0;
        while(i < m + n && j < n) {
            if(A[i] < B[j]) {
                A[pos] = A[i];  
                ++i;
            }
            else {
                A[pos] = B[j];
                ++j;
            }
            ++pos;
        }
        while(j < n) {
            A[pos] = B[j];
            ++j, ++pos;
        }
        while(i < m + n) {
            A[pos] = A[i];
            ++i, ++pos;
        }
    }
};

int main() {
    int A[] = {};
    int B[] = {};

    const int SIZE_INT = sizeof(int);
    int size_B = sizeof(B) / SIZE_INT;
    int size_A = sizeof(A) / SIZE_INT - size_B; 

    cout << size_A << endl;
    cout << size_B << endl;

    Solution sol;
    sol.merge(A, size_A, B, size_B);
    
    for(int i = 0; i < size_A + size_B; ++i) {
        cout << A[i] << ' ';
    }
    cout << endl;
    return 0;
}
