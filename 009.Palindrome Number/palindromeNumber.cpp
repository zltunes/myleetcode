#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x < 10) return true;
        int length = 0;
        int lr = x, rl = x;
        while(x != 0) {
            x /= 10;
            ++length;
        }
        int i = 0, j = length - 1;
        while(i < j) {
            int l = lr % 10;
            int r = static_cast<int>(rl / pow(10, j)) % 10;
            if(l != r) return false;
            lr /= 10;
            ++i, --j;
        }
        return true;
    }
};


int main() {
    int x = 1100;
    Solution sol;
    cout << sol.isPalindrome(x) << endl;
    return 0;
}
