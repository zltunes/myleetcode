#include <iostream>
using namespace std;

class Solution {
public:
    int sqrt(int x) {
        return solution2(x);
    }
    int solution2(int x) {
    }
    int solution1(int x) {
        if(x == 1) return x;
        long long begin = 0;
        long long end = x / 2;
        while(begin < end) {
            long long mid = (begin + end) / 2;
            if(mid * mid > x) end = mid - 1;
            if(mid * mid < x) begin = mid + 1;
            if(mid * mid == x) return mid;
        }
        if(begin * begin > x)
            --begin;
        return begin;
    }
};
int main() {
    Solution sol;
    cout << sol.sqrt(17) << endl;
    return 0;
}
