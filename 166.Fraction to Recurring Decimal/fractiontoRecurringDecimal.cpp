#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

class Solution {
    using mpii = unordered_map<int, int>;
public:
    string fractionToDecimal(int numerator, int denominator) {
        assert(denominator != 0);
        string ret;
        long long ll_numerator = numerator;
        long long ll_denominator = denominator;
        bool isNegative = false;
        if(ll_numerator == 0) return to_string(0);
        if(ll_numerator < 0) {
            ll_numerator *= -1;
            isNegative = !isNegative;
        }
        if(ll_denominator < 0) {
            ll_denominator *= -1;
            isNegative = !isNegative;
        }
        long long integer = ll_numerator / ll_denominator;
        ret.append(to_string(integer));
        long long remain = ll_numerator - integer * ll_denominator;
        if(remain == 0) return isNegative ? '-' + ret : ret;
        ret.push_back('.');
        int pos = 0;
        mpii check;
        int size = ret.size();
        do {
            remain *= 10;
            auto it = check.find(remain);
            if(it == check.end()) check[remain] = pos;
            else {
                ret.insert(ret.begin() + size + it->second, '(');
                ret.push_back(')');
                break;
            }
            ++pos;
            long long ans = remain / ll_denominator;
            ret.push_back(ans + '0');
            remain = remain - ans * ll_denominator;
        } while(remain != 0);
        return isNegative ? '-' + ret : ret;
    }
};

int main() {
    Solution sol;
    cout << sol.fractionToDecimal(INT_MIN, -1) << endl;
    return 0;
}
