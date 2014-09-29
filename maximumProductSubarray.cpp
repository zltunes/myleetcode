#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(int A[], int n) {
        if(n == 0) return 0;
        int maxpre = A[0];
        int minpre = A[0];
        int maxsofar = A[0];

        int maxhere, minhere;
        for(int i = 1; i < n; ++i) {
            maxhere = max(max(maxpre * A[i], minpre * A[i]), A[i]);
            minhere = min(min(maxpre * A[i], minpre * A[i]), A[i]);
            maxsofar = max(maxhere, maxsofar);
            maxpre = maxhere;
            minpre = minhere;
        }
        return maxsofar;
    }
};


int main() {
    Solution sol;
    int test[] = {2,0,11,6,-4,7,1};
    int res = sol.maxProduct(test, sizeof(test)/sizeof(int));
    cout << res << endl;
    return 0;
}

