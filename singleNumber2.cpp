#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0;
        for(int i = 0; i < n; ++i) {
            ones = (ones ^ A[i]) & ~twos;
            twos = (twos ^ A[i]) & ~ones;
            cout << A[i] << " " << ones << " " << twos << endl;
        }
        return ones;
    }
};

int main() {
    int A[] = {1,3,1,3,1,3,4,8,4,4};
    Solution sol;
    cout << sol.singleNumber(A, sizeof(A)/4);
    return 0;
}
