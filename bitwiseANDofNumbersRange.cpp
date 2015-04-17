#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bits, cnt;
        bits = cnt = 1;
        int ret = m;
        while(m < n) {
            m |= bits;
            ret &= -1 - bits;
            bits <<= 1;
        }
        return ret;
    }
};

int main() {

    int m = INT_MAX - 1, n = INT_MAX;
    Solution sol;
    cout << sol.rangeBitwiseAnd(m, n) << endl;
    cout << INT_MAX - 1 << endl;
    return 0;
}
