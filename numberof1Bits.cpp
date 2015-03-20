#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret, cnt;
        ret = 0, cnt = 0;
        while(cnt < 32 && n) {
            if(n % 2) ++ret;
            n /= 2;
        }
        return ret; 
    }
};

int main() {
    Solution sol;
    cout << sol.hammingWeight(3) << endl;
    return 0;
}
