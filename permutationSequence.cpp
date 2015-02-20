#include <iostream>
#include <vector>
using namespace std;

class Solution {
    typedef vector<int> vi;
public:
    string getPermutation(int n, int k) {
        vi seq;
        string ret;
        int product = 1;
        for(int i = 1; i <= n; ++i) {
            seq.push_back(i);
            product *= i;
        }
        int div = n;
        --k;
        while(div) {
            product /= div;
            int temp = k / product;
            ret.push_back(seq[temp] + '0');
            seq.erase(seq.begin() + temp);
            --div;
            k %= product;
        }
        return ret; 
    }
};

int main() {
    Solution sol;
    cout << sol.getPermutation(2, 2) << endl;
    for(int i = 1; i < 25; ++i) {
        cout << sol.getPermutation(4, i) << endl;
    }
    return 0;
}
