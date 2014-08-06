#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt = 0;
        int len = s.length();
        while(cnt != len && s[cnt] == ')') ++cnt;
        if(cnt == len) return 0;
        stack<char> stk;
        int validLength = 0;
        int max = 0;
        stk.push(s[cnt++]);
        while(cnt != len) {
            if(s[cnt] == '(')
                stk.push(s[cnt]);
            else {
                if(!stk.empty()) {
                    stk.pop();
                    if(!stk.empty()) {
                        if(max < validLength)
                            max = validLength;
                        validLength = 0;
                    }
                    ++validLength;
                }
                else {
                    if(max < validLength)
                        max = validLength;
                    validLength = 0;
                }
            }
            ++cnt;
        }
        return validLength * 2;
    }
};

int main() {
    string s = "()(())";
    Solution sol;
    cout << sol.longestValidParentheses(s);
    return 0;
}
