#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string str_num = to_string(num);
        string ret;
        string one = "IXCM";
        string five = "VLD";
        for(string::reverse_iterator it = str_num.rbegin(); it != str_num.rend(); ++it){
            string t;
            switch(*it) {
                case '0':
                    t = "";
                    break;
                case '1':
                    t = one[it - str_num.rbegin()];
                    break;
                case '2':
                    t = string(2, one[it - str_num.rbegin()]);
                    break;
                case '3':
                    t = string(3, one[it - str_num.rbegin()]);
                    break;
                case '4':
                    t = one[it - str_num.rbegin()];
                    t += five[it - str_num.rbegin()];
                    break;
                case '5':
                    t = five[it - str_num.rbegin()];
                    break;
                case '6':
                    t = five[it - str_num.rbegin()];
                    t += one[it - str_num.rbegin()];
                    break;
                case '7':
                    t = five[it - str_num.rbegin()] + string(2, one[it - str_num.rbegin()]);
                    break;
                case '8':
                    t = five[it - str_num.rbegin()] + string(3, one[it - str_num.rbegin()]);
                    break;
                case '9':
                    t = one[it - str_num.rbegin()];
                    t += one[it - str_num.rbegin() + 1];
                    break;
            }
            ret.insert(0, t); 
        }
        return ret; 
    }
};


int main() {
    Solution sol;
    cout << sol.intToRoman(644) << endl;
    return 0;
}
