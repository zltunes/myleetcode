#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        ++n;
        int a = 1, b = 1;
        while(n > 2) {
            b = a + b; 
            a = b - a;
            --n;
        }
        return b;
    }
};

int main() {

    Solution sol;
    cout << sol.climbStairs(1) << endl;
    return 0;
}
