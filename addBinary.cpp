#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()) swap(a, b);
        int carry = 0; 
        auto it1 = a.rbegin();
        auto it2 = b.rbegin();
        string ret;
        while(it2 != b.rend()) {
            int temp = *it1 - '0' + *it2 - '0' + carry;
            carry = 0;
            if(temp == 3) {
                ret.insert(ret.begin(), '1');
                carry = 1;
            }
            else if(temp == 2) {
                ret.insert(ret.begin(), '0');
                carry = 1;
            }
            else if(temp == 1) {
                ret.insert(ret.begin(), '1');
            }
            else {
                ret.insert(ret.begin(), '0');
            }
            ++it1, ++it2;
        }
        if(it1 != a.rend()) {
            if(carry) {
                while(it1 != a.rend()) {
                    int temp = *it1 - '0' + carry;
                    carry = 0;
                    if(temp == 2) {
                        ret.insert(ret.begin(), '0');
                        carry = 1;
                    }
                    else {
                        ret.insert(ret.begin(), '1');
                        ++it1;
                        break;
                    }
                    ++it1;
                }
            }
            if(it1 != a.rend()) {
                ret = a.substr(0, a.rend() - it1) + ret;
            }
        }
        if(carry) {
            ret.insert(ret.begin(), '1');
        }
        return ret;
    }
};

int main() {
    string a = "0";
    string b = "0";
    Solution sol;
    cout << sol.addBinary(a, b) << endl;
    return 0;
}
