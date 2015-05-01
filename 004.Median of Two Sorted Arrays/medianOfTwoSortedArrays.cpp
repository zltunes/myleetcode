#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int SIZE_INT = sizeof(int);

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        this->total_length = m + n;
        return findMedianWorkhorse(A, B, max(total_length / 2 - n, 0), min(total_length / 2, m - 1), m, n);
    }

    double findMedianWorkhorse(int A[], int B[], int left, int right, int lengthA, int lengthB) {
        if(left > right)
            return findMedianWorkhorse(B, A, 
                    max(total_length / 2 - lengthA, 0),
                    min(total_length / 2, lengthB - 1), lengthB, lengthA);

        int i = (left + right) / 2;
        int j = (total_length) / 2 - i;
        if((j == 0 || A[i] >= B[j - 1]) && (j == lengthB || A[i] <= B[j])) {
            if(total_length & 1) {
                return A[i];
            }
            else if(j != 0){
                return (A[i] + max(A[i - 1], B[j - 1])) / 2.0;
            }
            else {
                return (A[i] + A[i - 1]) / 2.0;
            }
        }
        else if(A[i] > B[j] && j != lengthB) {
            return findMedianWorkhorse(A, B, left, i - 1, lengthA, lengthB); 
        }
        else {
            return findMedianWorkhorse(A, B, i + 1, right, lengthA, lengthB);
        }
    }
private:
    int total_length;
};

int main() {
    Solution sol;
    int B[] = {1,2,3,4,5};
    int A[] = {};
    cout << sol.findMedianSortedArrays(A, sizeof(A) / SIZE_INT, B, sizeof(B) / SIZE_INT) << endl;
    return 0;
}
