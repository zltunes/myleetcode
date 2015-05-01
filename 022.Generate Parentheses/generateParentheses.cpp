#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    typedef vector<string> vs;
    vector<string> generateParenthesis(int n) {
        vs ret;
        addValidPStr(n - 1, n, "(", ret);
        return ret;
    }
    void addValidPStr(int left, int right, string next, vs & ret) {
        if(left == 0 && right == 0) {
            ret.push_back(next);
            return;
        }
        if(left > 0)
            addValidPStr(left - 1, right, next + '(', ret);
        if(right > 0 && right > left)
            addValidPStr(left, right - 1, next + ')', ret);
    }
};

void printVS(const vector<string> & v) {
    for(auto &s : v) {
        cout << s << ' ';
    }
    cout << endl;
}

int main() {
    int n = 5;
    Solution sol;
    vector<string> expected {"(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"};
    sort(expected.begin(), expected.end());
    vector<string> res = sol.generateParenthesis(n);
    sort(res.begin(), res.end());
    cout << (expected == res) << endl;
    //printVS(expected);
    printVS(res);
    return 0;
}
