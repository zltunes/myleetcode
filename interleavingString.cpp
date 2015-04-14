#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;
public:
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size();
        int size2 = s2.size();
        if(size1 + size2 != s3.size()) return false;

        vi t; t.resize(size2 + 1, 0);
        vvi dp; dp.resize(size1 + 1, t);

        dp[0][0] = 1;
        /*for(int i = 0; i < size1; ++i)
          dp[i][0] = 1;*/

        for(int i = 0; i <= size1; ++i)
            for(int j = 0; j <= size2; ++j)
                if((i && s3[i + j - 1] == s1[i - 1] && dp[i - 1][j])
                        || (j && s3[i + j - 1] == s2[j - 1] && dp[i][j - 1]))
                    dp[i][j] = 1;

        return dp[size1][size2];
    }
};

int main() {
    string t1 = "aabcc";
    string t2 = "dbbca";
    string good = "aadbbcbcac";
    string bad = "aadbbbaccc";
    Solution sol;
    cout << sol.isInterleave(t1, t2, good) << endl;
    return 0;
}
