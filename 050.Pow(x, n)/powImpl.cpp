#include <iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        bool isNega = n < 0 ? true : false;
        double result = 1.0;
        if(x == 0) return 0;
        if(x == 1) return 1;
        if(x == -1) return n & 1 ? -1 : 1;
        if(isNega) n = -n;
        while(n) {
            if(n & 1) {
                result *= x;
                --n;
            }
            x *= x;
            n>>=1;
        }
        if(isNega) result = 1 / result;
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.pow(3,-5) << endl;
    return 0;
}
