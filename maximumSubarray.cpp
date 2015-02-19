#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0) return 0;
        int max_sum = A[0], sum = A[0];
        for(int i = 1; i < n; ++i) {
            if(sum < 0) sum = 0;
            sum += A[i];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};

int main() {
    int A[] = {1};
    const int SIZE_INT = sizeof(int);
    
    Solution sol;
    cout << sol.maxSubArray(A, sizeof(A) / SIZE_INT) << endl;
    return 0;
}
