#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 0) return 0;
        int *dp = new int[ n + 1 ];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <=n; ++i) {
            int temp = 0;
            for(int k = 0; k < i; ++k) {
                temp += dp[k] * dp[i - 1 - k];
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    cout << sol.numTrees(6) << endl;
    return 0;
}
