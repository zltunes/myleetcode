#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        string STR_MAX = to_string(INT_MAX);
        string STR_MIN = to_string(INT_MIN);
        STR_MIN = STR_MIN.substr(1, STR_MIN.length() - 1);
        bool isNega = false;
        if(x < 0) {
            isNega = true;
            x *= -1;
        }
        string str_x = to_string(x); 
        string reverse_x = string(str_x.rbegin(), str_x.rend());
        if(!isNega && reverse_x.length() <= STR_MAX.length()) {
            if(reverse_x.length() == STR_MAX.length() && reverse_x > STR_MAX)
                return 0;
            return stringToInt(reverse_x);
        }
        if(isNega && reverse_x.length() <= STR_MIN.length()) {
            if(reverse_x.length() == STR_MIN.length() && reverse_x > STR_MIN)
                return 0;
            return (-1) * stringToInt(reverse_x);
        }
        return 0;
    }
    int stringToInt(string num) {
        int sum = 0;
        for(int i = 0; i < num.length(); ++i) {
            sum *= 10;
            sum += num[i] - '1' + 1; 
        } 
        return sum;
    }
    
};

int main() {
    Solution sol;
    cout << sol.reverse(-2110001) << endl;
    return 0;
}
