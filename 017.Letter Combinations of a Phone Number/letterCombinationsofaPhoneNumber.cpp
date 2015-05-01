#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

class Solution {
    using vs = vector<string>;
    using ds = deque<string>;
public:
    vs letterCombinations(string digits) {
        int size = digits.size();
        vs ret {""};
        vs table {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < size; ++i) {
            if(digits[i] == '1') continue;
            vs temp {ret.begin(), ret.end()};
            ret.clear();
            for(auto &s : temp)
                for(auto &chr : table[digits[i] - '0'])
                    ret.push_back(s + chr);
        }
        return ret;
    }
};

void printVS(const vector<string> & vs) {
    for(auto &str : vs) {
        cout << str << ' ';
    }
    cout << endl;
}

int main() {
    string test = "294";    
    Solution sol;
    printVS(sol.letterCombinations(test));
    return 0;
}
