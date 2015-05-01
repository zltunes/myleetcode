#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;
using uss = unordered_set<string>;
using umivs = unordered_map<int, vector<string>>;

class Solution {
    using uss = unordered_set<string>;
    using umivs = unordered_map<int, vector<string>>;
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty()) return false;
        umivs mp;
        uss unmatch;
        for(auto & str : dict) {
            if(str.size() == 0) continue;
            mp[str.size()].push_back(str);
        }
        return worker(s, mp, unmatch);
    }
    bool worker(string s, umivs &mp, uss &unmatch) {
        if(s.empty()) return true;
        for(auto &kv : mp) {
            string t = s.substr(0, kv.first);
            for(auto & word : kv.second) {
                if(word == t) {
                    string suffix = s.substr(kv.first);
                    if(unmatch.count(suffix) != 0) {
                        continue;
                    }
                    if(worker(suffix, mp, unmatch)) {
                        return true;
                    }
                    else {
                        unmatch.insert(suffix);
                    }
                }
            }
        }
        return false;
    }
};

int main() {
    string s = "leetcode";
    uss dict {"lee", "le", "l", "code"}; 

    Solution sol;
    cout << sol.wordBreak(s, dict) << endl;
    return 0;
}
