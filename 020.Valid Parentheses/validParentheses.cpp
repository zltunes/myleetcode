#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isCorresponding(const char & ch1, const char & ch2) {
        if(ch1 == '[' && ch2 == ']') return true;
        if(ch1 == '(' && ch2 == ')') return true;
        if(ch1 == '{' && ch2 == '}') return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> stk;
        for(auto &chr : s) {
            if(stk.empty() || !isCorresponding(stk.top(), chr)) {
                stk.push(chr);
            }
            else {
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main() {
    string s = "";
    Solution sol;
    cout << sol.isValid(s) << endl;
    return 0;
}
