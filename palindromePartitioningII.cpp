#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    using vi = vector<int>;
    using vb = vector<bool>;
    using vvb = vector<vb>;
public:
    int minCut(string s) {
        int size = s.size();
        if(size < 2) return 0;
        vvb isPalin(size, vb (size, false));

        for(int i = 0; i < size; ++i)
            for(int j = 0; j < size; ++j)
                if(i == j || i - 1 == j)
                    isPalin[i][j] = true;

        for(int i = 1; i < size; ++i)
            for(int j = 0; j + i < size; ++j)
                if(isPalin[j + 1][i + j - 1] && s[i + j] == s[j])
                    isPalin[j][i + j] = true;
        
        vi dp(size + 1, size);
        dp[0] = -1;

        for(int i = 1; i <= size; ++i)
            for(int j = 0; j < i; ++j)
                if(isPalin[j][i - 1])
                    dp[i] = min(dp[i], dp[j] + 1);

        /*for(auto &item : dp)
            cout << item << ' ';
        cout << endl;*/

        return dp[size];
    }
};

int main() {
    string test = "cabbbacd";
    Solution sol;
    cout << sol.minCut(test) << endl;

    return 0;
}
