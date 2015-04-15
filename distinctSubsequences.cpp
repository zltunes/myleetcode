#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;
public:
    int numDistinct(string S, string T) {
        int height = S.size(), width = T.size(); 
        vi dp(width + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= height; ++i) {
            for(int j = width; j >= 1; --j) {
                if(S[i - 1] == T[j - 1])
                    dp[j] += dp[j - 1];
            }
        }

        return dp[width];
    }
};

int main() {
    string S = "rabbbit";
    string T = "rabbit";

    Solution sol;
    cout << sol.numDistinct(S, T) << endl;
    return 0;
}
