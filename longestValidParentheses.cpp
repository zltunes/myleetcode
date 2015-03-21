#include <iostream>
#include <vector>
using namespace std;

class Solution {
    using vi = vector<int>;
public:
    int longestValidParentheses(string s) {
        int i = 0, j = s.size() - 1;
        while(s[i] == ')') ++i;
        while(s[j] == '(') --j;
        s = s.substr(i, j - i + 1);
        vi dp;
        dp.resize(s.size(), 0);
        int indice = s.size() - 2;
        int max_len = 0;
        int pos = indice;
        for(; indice >= 0; --indice) {
            if(s[indice] == ')') continue;
            int j = indice + 1 + dp[indice + 1];
            int temp = 0;
            if(j < s.size() && s[j] == ')') {
                temp = dp[indice + 1] + 2;
                if(j + 1 < s.size())
                    temp += dp[j + 1];
            }
            if(temp > max_len) {
                max_len = temp;
                pos = indice;
            }
            dp[indice] = temp;
        }
        return max_len;
    }
};

int main() {
    string s = "))))(((";
    Solution sol;
    cout << sol.longestValidParentheses(s) << endl;
    return 0;
}
