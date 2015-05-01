#include <iostream>
#include <vector>
using namespace std;

class Solution {
    using vi = vector<int>;
public:
    uint32_t reverseBits(uint32_t n) {
        vi temp;
        int cnt = 0;
        while(cnt < 32) {
            int t = n / 2;
            temp.push_back(n - t * 2);
            n = t;
            ++cnt;
        }
        int ret = 0;
        for(auto &item : temp) {
            ret *= 2;
            ret += item;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseBits(111) << endl;
    return 0;
}
