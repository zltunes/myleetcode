#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class BigInt {
public:
    BigInt() {
        isNegative = false;
    }
    BigInt(int num) {
        number = to_string(num); 
        if(number[0] == '-') {
            number.erase(0,1);
            isNegative = true;
        }
        else {
            isNegative = false;
        }
    }
    bool isGreaterThan(const BigInt &bi) {
        if(isNegative && !bi.isNegative) return false;
        if(!isNegative && bi.isNegative) return true;
        if(bi.number.length() > number.length()) {
            return isNegative ? true : false;
        } 
        else if(bi.number.length() < number.length()) {
            return isNegative ? false : true;
        }
        else {
            return isNegative ? !(bi.number >= number) : (bi.number >= number);
        }
     }
    bool isNega() const { return isNegative; }
private:
    string number;
    bool isNegative;
};

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isNegative = false;
        if(divisor == INT_MIN) {
            if(dividend == INT_MIN) return 1;
            return 0;
        }
        if(divisor == 1) return dividend;
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if(divisor == -1) return -dividend;
        string str_dividend = to_string(dividend);
        string str_divisor = to_string(divisor);
        if(str_dividend[0] == '-') {
            str_dividend.erase(0, 1);
            isNegative = !isNegative;
        }
        if(str_divisor[0] == '-') {
            divisor = -divisor;
            isNegative = !isNegative;
        }
        int i_dividend = 0;
        int remain = 0;
        string ret;
        while(i_dividend < str_dividend.length()) {
            long long temp = 0;
            int number = 0;
            string t_str;
            do {
                ++number;
                t_str = str_dividend.substr(i_dividend, number);
                if(remain == 0)
                    temp = stoll(t_str);
                else
                    temp = stoll(to_string(remain) + t_str);
                ret.push_back('0');
            } while(i_dividend + number < str_dividend.length() && temp != 0 && temp < divisor);
            ret.pop_back();
            if(temp == 0) {
                ret.push_back('0');
                ++i_dividend;
                continue;
            }
            //cout << "this turn : " << temp << endl;
            int sum = 0;
            int i;
            for(i = 0; i < 10; ++i) {
                if(sum > temp - divisor) {
                    break;
                }
                sum += divisor;
                //cout << "sum : " << sum << endl;
            }
            //cout << "this insert : " << i << endl;
            ret.push_back(i + '0');
            remain = temp - sum;
            //cout << "remain : " << remain << endl;
            //cout << "ret : " << ret << endl;
            i_dividend += number;
        }

        return isNegative ? -stoi(ret) : stoi(ret);
    }
};


bool test() {
    int dividend = -2147483648;
    int divisor = -1017100424;
    /*int dividend = 1211741350;
    int divisor =  1149444949;*/
    if(divisor == 0) return true;
    cout << "dividend:" << dividend << endl;
    cout << "divisor:" << divisor << endl;
    cout << dividend / divisor << endl;
    Solution sol;
    cout << sol.divide(dividend, divisor) << endl;
    bool isEqual = (sol.divide(dividend, divisor) == (dividend / divisor));
    cout << isEqual << endl;

    return isEqual;
}

int main() {
    srand(time(0));
    test();
    return 0;
}
