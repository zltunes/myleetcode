#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string ret;
        while(n) {
            int t = n % 26;
            n /= 26;
            ret.insert(ret.begin(), t == 0 ? 'Z' : t + 'A' - 1);
            if(t == 0) --n;
        }
        return ret;
    }
};

int main() {
    int number = 26;
    Solution sol;
    for(int i = 990; i < 1000; ++i)
        cout << sol.convertToTitle(i) << endl;
    return 0;
}
