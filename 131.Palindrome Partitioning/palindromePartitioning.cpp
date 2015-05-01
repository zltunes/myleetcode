#include <iostream>
#include <string>
#include <vector>
using namespace std;

using vs  = vector<string>;
using vvs = vector<vs>;

class Solution {
    using vs  = vector<string>;
    using vvs = vector<vs>;
public:
    vector<vector<string>> partition(string s) {
        vvs ret;
        vs temp;
        if(s.size() == 0) return ret;
        worker(ret, temp, s); 
        return ret;
    }

    void worker(vvs & ret, vs & temp, string s) {
        if(s.size() == 0) {
            ret.push_back(temp);
            return;
        }
        if(s.size() == 1) {
            temp.push_back(s);
            ret.push_back(temp);
            temp.pop_back();
            return;
        }
        for(int i = 1; i <= s.size(); ++i) {
            if(isPalindrome(s.substr(0, i))) {
                temp.push_back(s.substr(0, i));
                worker(ret, temp, s.substr(i));
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s) {
        int l, r;
        l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            ++l, --r;
        }
        return true;
    }
};

int main() {
    string test = "ab";
    Solution sol;
    vvs ret = sol.partition(test);

    for(auto &row : ret) {
        for(auto &item : row)
            cout << item << ' ';
        cout << endl;
    }
    return 0;
}
