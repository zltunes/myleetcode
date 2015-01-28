#include <iostream>
#include <cmath>
#include <functional>
using namespace std;

class Solution {
    string getRomanString(int i, int bit) {
        string one = "IXCM";
        string five = "VLD";
        string t;
        switch(i) {
            case 0:
                t = "";
                break;
            case 1:
                t = one[bit];
                break;
            case 2:
                t = string(2, one[bit]);
                break;
            case 3:
                t = string(3, one[bit]);
                break;
            case 4:
                t = one[bit];
                t += five[bit];
                break;
            case 5:
                t = five[bit];
                break;
            case 6:
                t = five[bit];
                t += one[bit];
                break;
            case 7:
                t = five[bit] + string(2, one[bit]);
                break;
            case 8:
                t = five[bit] + string(3, one[bit]);
                break;
            case 9:
                t = one[bit];
                t += one[bit + 1];
                break;
        }
        return t;
    }
public:
    int romanToInt(string s) {
        int bit = 0;
        int ret = 0;
        int table[10] = {8,7,3,9,6,4,2,5,1,0};
        while(!s.empty()) {
            size_t pos = 0;
            for(int num = 0; num < 10; ++num) {
                string temp = getRomanString(table[num], bit);
                if(string::npos == (pos = s.rfind(temp))) {
                    continue;
                }
                ret += table[num] * pow(10, bit); 
                break;
            }
            s = s.substr(0, pos);
            ++bit;
        }
        return ret;
    }
};

int main() {
    string s = "CXI";
    Solution sol;
    cout << sol.romanToInt(s) << endl;
    return 0;
}
