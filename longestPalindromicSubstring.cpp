#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        return manacherSolution(s);
    }

    string manacherSolution(string &s) {
        string s_m = "$";
        for(auto &chr : s) {
            s_m.push_back('#');
            s_m.push_back(chr);
        }
        s_m.push_back('#');

        int mx = 0, id = 0;
        int max = 0, max_cnt = 0;
        int size = s_m.size();
        vector<int> p(size + 1, 0);
        p.push_back(0);

        for(int i = 1; i <= size; ++i) {
            if(i < mx)
                p[i] = min(p[2 * id - i], mx - i);
            else
                p[i] = 1;
            while(s_m[i - p[i]] == s_m[i + p[i]]) ++p[i];

            if(i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            if(p[i] > max) {
                max = p[i];
                max_cnt = i;
            }
        } 

        string ret;
        for(int i = max_cnt - max + 1; i < max_cnt + max; ++i)
            if(s_m[i] != '#')
                ret.push_back(s_m[i]);

        return ret;
    }
    string dpSolution(string &s) {
        if(s.length() <= 1) return s;
        int max_length = 1, max_i = 0;
        bool isPalidrome[1001][1001];
        for(int i = 0; i < s.length(); ++i) {
            for(int j = 0; j < s.length(); ++j) {
                if(i >= j)
                    isPalidrome[i][j] = true;
                else
                    isPalidrome[i][j] = false;
            }
        }
        for(int j = 1; j < s.length(); ++j) {
            for(int i = 0; i < j; ++i) {
                if(s[i] == s[j]) {
                    isPalidrome[i][j] = isPalidrome[i + 1][j - 1]; 
                    if(isPalidrome[i][j] && j - i + 1 > max_length) {
                        max_length = j - i + 1;
                        max_i = i;
                    }
                }
                else {
                    isPalidrome[i][j] = false;
                }
            }
        }
        return s.substr(max_i, max_length);
    }
};

int main() {
    string test = "aba";
    Solution sol;
    cout << sol.longestPalindrome(test) << endl;
    return 0;
}
