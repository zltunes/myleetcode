#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 0) return "";
        string temp = "1";
        for(int i = 1; i < n; ++i) {
            int pos = 0;
            int repeat = 1;
            while(pos < temp.length()) {
                if(pos + 1 < temp.length() && temp[pos] == temp[pos + 1]) {
                    repeat ++;
                }
                else{
                    temp.insert(pos, to_string(repeat));
                    temp.erase(pos - repeat + 1, repeat - 1);
                    pos = pos + 2 - repeat;
                    repeat = 1;
                }
                pos ++;
            }
        }
        return temp;
    }
};

int main() {
    Solution sol;
    cout << sol.countAndSay(1) << endl;

    return 0;
}
