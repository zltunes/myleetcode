#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;
public:
    int minDistance(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        vi t;
        t.resize(s2 + 1, 0);
        vvi dp;
        dp.resize(s1 + 1, t);
        for(int i = 0; i <= s2; ++i)
            dp[0][i] = i;
        for(int i = 0; i <= s1; ++i)
            dp[i][0] = i;

        for(int i = 1; i <= s1; ++i)
            for(int j = 1; j <= s2; ++j)
                dp[i][j] = word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;

        /*for(auto &row : dp) {
            for(auto &item : row)
                cout << item << ' ';
            cout << endl;
        }*/
        return dp[s1][s2];
    }
};

int main() {
    string word1 = "";
    string word2 = "";

    Solution sol;
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}
