#include <iostream>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        long long div, ll_n;
        div = 5;
        ll_n = n;
        int ret = 0;
        while(div <= ll_n) {
            ret += ll_n / div; 
            div *= 5;
        }
        return ret; 
    }
};

int main() {

    Solution sol;
    cout << sol.trailingZeroes(INT_MAX) << endl;
    return 0;
}
