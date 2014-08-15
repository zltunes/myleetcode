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
    }

    bool solution2() {
        vector<bool> t(pattern2.length(), false);
        vector<vector<bool>> tt(pattern1.length(), t);
        vector<vector<vector<bool>>> dp(checkString.length(), tt);
        dp[1][0][1] = (pattern2[0] == checkString[0] ? true : false);
        dp[1][1][0] = (pattern1[0] == checkString[0] ? true : false);
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
