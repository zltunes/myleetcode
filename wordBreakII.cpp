#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using mivs = unordered_map<int, vs>;
using uss = unordered_set<string>;

class Solution {
    using vs = vector<string>;
    using vi = vector<int>;
    using vvi = vector<vi>;
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int size = s.size();
        vvi dp(size + 1, vi ());
        dp[0].push_back(-2);

        for(int i = 1; i <= size; ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j][0] != -1) {
                    auto t = s.substr(j, i - j);
                    if(wordDict.count(t))
                        dp[i].push_back(j);
                }
            }
            if(dp[i].empty())
                dp[i].push_back(-1);
        }

        /*for(auto &pos : dp) {
            for(auto &item : pos)
                cout << item << ' ';
            cout << endl;
        }*/
        vs ret;
        vs temp;
        constructRets(ret, temp, s, size - 1, dp); 
        return ret;
    }

    void constructRets(vs &ret, vs &temp, string &origin, int i, vvi &dp) {
        if(dp[i + 1][0] < 0) {
            string t;
            for(auto &s : temp)
                t = s + " " + t;
            if(!t.empty())
                ret.push_back(t.substr(0, t.size() - 1));
            return;
        }
        for(auto &item : dp[i + 1]) {
            temp.push_back(origin.substr(item, i + 1 - item)); 
            constructRets(ret, temp, origin, item - 1, dp);
            temp.pop_back();
        }
    }
};

int main() {
    string s = "a";
    uss dict {""};
    Solution sol;

    auto vec = sol.wordBreak(s, dict);
    cout << vec.size() << endl;
    for(auto &item : vec)
        cout << item << endl;
     
    return 0;
}
