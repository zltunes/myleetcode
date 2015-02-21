#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class Solution {
    typedef vector<int> vi;
public:
    vector<int> grayCode(int n) {
        vi ret;
        ret.push_back(0);
        if(n == 0) return ret;
        ret.push_back(1);
        int cnt = 1;
        int add = 2;
        while(cnt < n) {
            int size = ret.size();
            for(int i = size - 1; i >= 0; --i) {
                ret.push_back(ret[i] + add); 
            }
            add *= 2;
            ++cnt;
        }
        return ret; 
    }
};

int main() {
    Solution sol;
    vi ret = sol.grayCode(3);
    for(auto & item : ret) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}
