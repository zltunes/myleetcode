#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if(length == 0) return 0;
        vector<int> dp(length + 1, 0);
        if(length == 1 && s[0] == '0') return 0;
        dp[0] = 1;
        if(s[0] == '0')
            dp[1] = 0;
        else
            dp[1] = 1;
        for(int i = 1; i < length; ++i) {
            int one, two;
            if(s[i] == '0') {
                one = 0;
            }
            else {
                one = dp[ i ];
            }
            if(s[i - 1] == '1') {
                two = dp[i - 1];
            }
            else if(s[i - 1] == '2' && s[i] >= '0' && s[i] < '7') {
                two = dp[i - 1];
            }
            else
                two = 0;
            dp[i + 1] = one + two;  
        }
        return dp[length];
    }
};

int main() {
    Solution sol;
    cout << sol.numDecodings("20");
    return 0;
}
