#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        pattern1.clear();
        pattern2.clear();
        checkString.clear();
        pattern1 = s1;
        pattern2 = s2;
        checkString = s3;
        return solution2();
    }

    bool solution2() {
        vector<bool> t(pattern2.length(), false);
        vector<vector<bool>> tt(pattern1.length(), t);
        vector<vector<vector<bool>>> dp(checkString.length(), tt);
        dp[0][0][0] = true;
        for(int i = 1; i < pattern2.length(); ++i) {
            dp[i][0][i] = dp[i - 1][0][i - 1] && checkString[i - 1] == pattern2[i - 1];
            cout << checkString[i - 1] << " " << pattern2[i - 1] << " " << dp[i][0][i] << endl;
        }
        for(int i = 1; i < pattern1.length(); ++i) {
            dp[i][i][0] = dp[i - 1][i - 1][0] && checkString[i - 1] == pattern1[i - 1];
            cout << checkString[i - 1] << " " << pattern1[i - 1] << " " << dp[i][i][0] << endl;
        }
        for(int i = 1; i < pattern1.length(); ++i) {
            for(int j = 1; j < pattern2.length(); ++j) {
                dp[i + j][i][j] = (dp[i + j - 1][i][j - 1] && checkString[i + j - 1] == pattern2[j - 1]) || (dp[i + j - 1][i - 1][j] && checkString[i + j - 1] == pattern1[i - 1]);
            }
        }
        return dp[checkString.length() - 1][pattern1.length() - 1][pattern2.length() - 1];
    }
    bool solution1() {
        if(checkNext(0, 0, 0)) {
            return true;
        }
        return false;
    }
    bool checkNext(int p1, int p2, int cnt) {
        if(cnt == checkString.length()) return true;
        if(checkString[cnt] == pattern1[p1]) {
            if(checkNext(p1 + 1, p2, cnt + 1)) {
                return true;
            }
        } 
        if(checkString[cnt] == pattern2[p2]) {
            if(checkNext(p1, p2 + 1, cnt + 1)) {
                return true;
            }
        }
        return false;
    }
private:
    string pattern1;
    string pattern2;
    string checkString;
};

int main() {
    vector<string> vec = {"aabcc", "dbbca", "aadbbbaccc"};
    Solution sol;
    cout << sol.isInterleave(vec[0], vec[1], vec[2]);

    return 0;
}
