#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        return solution1(x);
    }
    int solution1(int x) {
        if(x == 1) return x;
        long long begin = 0;
        long long end = x / 2;
        while(begin <= end) {
            long long mid = (begin + end) / 2;
            if(mid * mid > x) end = mid - 1;
            if(mid * mid < x) begin = mid + 1;
            if(mid * mid == x) return mid;
        }
        return end;
    }
};
int main() {
    Solution sol;
    for(int i = 0; i < 100; ++i) {
        cout << i << ' ' << sol.sqrt(i) << endl;
    }
    return 0;
}
