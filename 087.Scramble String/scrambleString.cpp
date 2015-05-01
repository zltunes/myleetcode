#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;
    using vvvi = vector<vvi>;
public:
    /*int size1 = s1.size();
      assert(size1 == s2.size());

      if(size1 == 1) return s1 == s2;
      else if(size1 == 2) return s1 == s2 || (s1[0] == s2[1] && s1[1] == s2[0]);
      else {
      for(int i = 1; i < size1; ++i)
      if(isScramble(s1.substr(0, i), s2.substr(0, i)))        
      return true;
      }
      return false;*/

    bool isScramble(string s1, string s2) {
        assert(s1.size() == s2.size());
        int size = s1.size();
        vi t;
        t.resize(size + 1, 0);
        vvi tt;
        tt.resize(size, t);
        vvvi dp;
        dp.resize(size, tt);

        for(int k = 1; k <= size; ++k) {
            for(int i = 0; i <= size - k; ++i) {
                for(int j = 0; j <= size - k; ++j) {
                    if(k == 1) dp[i][j][k] = (s1[i] == s2[j]);
                    else
                        for(int cnt = 1; cnt < k; ++cnt)
                            if((dp[i][j][cnt] && dp[i + cnt][j + cnt][k - cnt]) || 
                                    (dp[i + cnt][j][k - cnt] && dp[i][j + k - cnt][cnt])) {
                                dp[i][j][k] = 1;
                                break;
                            }
                }
            }
        }
        return dp[0][0][size];
    }
};

int main() {
    string test1 = "abb";
    string test2 = "bba";

    Solution sol;
    cout << sol.isScramble(test1, test2) << endl;
    return 0;
}
