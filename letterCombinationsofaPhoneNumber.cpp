#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;

class Solution {
public:
    typedef vector<string> vs;
    typedef deque<string> dqs;
    vector<string> letterCombinations(string digits) {
        dqs ret {""};
        vs mapping {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(string::npos != digits.find('1')) {
            digits.erase(remove(digits.begin(), digits.end(), '1'), digits.end());
        }
        if(digits.length() < 1) return vs{""};
        int pos = 0;
        do {
            string f = ret.front();
            if(f.length() != pos) {
                pos = f.length();
            }
            ret.pop_front();
            auto chars = mapping[digits[pos] - '0'];
            for(auto it = chars.begin(); it != chars.end(); ++it) {
                ret.push_back(f + *it);
            }
        } while(ret.front().size() != digits.length());
        return vs {ret.begin(), ret.end()};
    }
};

void printVS(const vector<string> & vs) {
    for(auto &str : vs) {
        cout << str << ' ';
    }
    cout << endl;
}

int main() {
    string test = "0194";    
    Solution sol;
    printVS(sol.letterCombinations(test));
    return 0;
}
