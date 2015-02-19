#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int zeros = countZero(num1) + countZero(num2);
        if(num1.size() < num2.size()) swap(num1, num2);
        string zero_cnt;
        string ret = "0";
        for(auto it = num2.rbegin(); it != num2.rend(); ++it) {
            string ans = singleMultiply(num1, *it);
            ans += zero_cnt;
            ret = add(ret, ans);
            zero_cnt.push_back('0');
        }
        for(int i = 0; i < zeros; ++i) {
            ret.push_back('0');
        }
        return ret;
    }
    string add(string num1, string num2) {
        if(num1.size() < num2.size()) swap(num1, num2);
        auto it1 = num1.rbegin();
        auto it2 = num2.rbegin();
        int carry = 0;
        string ret;
        while(it2 != num2.rend()) {
            int ans = *it1 - '0' + *it2 - '0' + carry;
            carry = 0;
            if(ans > 9) carry = 1;
            ret.insert(ret.begin(), ans % 10 + '0');
            ++it1, ++it2;
        }
        if(it1 != num1.rend()) {
            while(it1 != num1.rend()) {
                int ans = *it1 - '0' + carry;
                carry = 0;
                if(ans > 9) carry = 1;
                ret.insert(ret.begin(), ans % 10 + '0');
                ++it1;
            }
        }
        if(carry) ret.insert(ret.begin(), '1');
        return ret;
    }
    string singleMultiply(string num1, char chr) {
        int carry = 0;
        int num2 = chr - '0';
        string ret;
        for(auto it = num1.rbegin(); it != num1.rend(); ++it) {
            int res = (*it - '0') * num2 + carry;
            char bit1 = res % 10 + '0';
            ret.insert(ret.begin(), bit1);
            carry = res / 10;
        }
        if(carry) ret.insert(ret.begin(), carry + '0');
        return ret;
    }
    void swap(string & s1, string & s2) {
        string t = s1;
        s1 = s2;
        s2 = t;
    }
    int countZero(string & num) {
        int cnt = num.size() - 1;
        int origin_len = num.size();
        while(num[cnt] == '0') --cnt;
        cnt ++;
        num.erase(cnt);
        return origin_len - cnt;
    }
};

int main() {
    Solution sol;
    cout << sol.multiply("1", "99109") << endl;
    return 0;
}
