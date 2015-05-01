#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

using vs = vector<string>;

class Solution {
    using vi = vector<int>;
public:
    int evalRPN(vector<string> &tokens) {
        vi stk;
        for(auto &str : tokens) {
            if(str.size() > 1) {
                stk.push_back(stoi(str));
            }
            else {
                char symbol = str.front();
                if(symbol >= '0' && symbol <= '9') {
                    stk.push_back(symbol - '0');
                }
                else {
                    int num1, num2;
                    assert(!stk.empty());
                    if(!stk.empty()) {
                        num2 = stk.back();
                        stk.pop_back();
                    }
                    assert(!stk.empty());
                    if(!stk.empty()) {
                        num1 = stk.back();
                        stk.pop_back();
                    }
                    switch(symbol) {
                        case '+':
                            stk.push_back(num1 + num2);
                            break;
                        case '-':
                            stk.push_back(num1 - num2);
                            break;
                        case '*':
                            stk.push_back(num1 * num2);
                            break;
                        case '/':
                            stk.push_back(num1 / num2);
                            break;
                    }
                }
            }
        }
        return stk.back();
    }
};

int main() {
    //vs test {"2", "1", "+", "3", "*"};    
    vs test {"4", "13", "5", "/", "+"};    
    Solution sol;

    cout << sol.evalRPN(test) << endl;
    return 0;
}
