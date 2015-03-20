#include <iostream>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for(auto &chr : s) {
            ret *= 26;
            ret += chr - 'A' + 1;
        }
        return ret;
    }
};

int main() {
    string test = "AB";
    Solution sol;
    cout << sol.titleToNumber(test) << endl;
    return 0;
}
