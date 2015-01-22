#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
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
    string test = "abal";
    Solution sol;
    cout << sol.longestPalindrome(test) << endl;
    return 0;
}
