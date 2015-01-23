#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    typedef vector<char> vc;
    typedef vector<vc> vvc;
    string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        vc line;
        vvc mat(nRows, line);
        int cc = 0;
        bool direction = true;
        for(string :: iterator it = s.begin(); it < s.end(); ++it) {
            mat[cc].push_back(*it);
            cc += direction ? 1 : -1;
            if(cc == nRows - 1) {
                direction = false;
            }
            if(cc == 0 && it != s.begin()) {
                direction = true;
            }
        }
        string ret;
        for(vvc :: iterator it = mat.begin(); it != mat.end(); ++it) {
            ret += string(it->begin(), it->end());
        }
        return ret;
    }
    /*
    typedef vector<string> vs;
    string convert(string s, int nRows) {
        vs mat(nRows, "");
        int c_row_cnt = 0;
        int delta = 1;
        for(int i = 0; i < s.length(); ++i) {
            mat[c_row_cnt] += s[i];
            c_row_cnt += delta;
            if(c_row_cnt == nRows - 1) {
                delta = -1;
            }
            if(c_row_cnt == 0 && i != 0) {
                delta = 1;
            }
        }
        string ret = "";
        for(vs :: iterator it = mat.begin(); it != mat.end(); ++it) {
            ret += *it;
        }
        return ret;
    }*/
};

int main() {
    string test = "AB";
    Solution sol;
    //cout << (sol.convert(test, 1) == "PAHNAPLSIIGYIR") << endl;
    cout << sol.convert(test, 1) << endl;
    return 0;
}
