#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i, j;
        i = 0;
        j = s.size() - 1;
        while(i < j) {
            while(!isValid(s[i])) ++i;
            while(!isValid(s[j])) --j;
            if(i >= j) break;
            lowercase(s[i]);
            lowercase(s[j]);
            if(s[i] == s[j]) {
                ++i, --j;
            }
            else {
                return false;
            }
        }
        return true;
    }

    void lowercase(char &c) {
        assert(isValid(c)); 
        if(c <= 'Z' && c >= 'A')
            c = c - 'A' + 'a';
    }
    bool isValid(char c) {
        if(c <= '9' && c >= '0') return true;
        if(c <= 'Z' && c >= 'A') return true;
        if(c <= 'z' && c >= 'a') return true;
        return false;
    }
};

int main() {
    string test = "A man, a plan, a canal: Panama";

    Solution sol;
    cout << sol.isPalindrome(test) << endl;
    return 0;
}
