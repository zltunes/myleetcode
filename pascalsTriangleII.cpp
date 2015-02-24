#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

class Solution {
    typedef vector<int> vi;
public:
    vector<int> getRow(int rowIndex) {
        vi ret {1};
        int cnt = 0;
        while(cnt < rowIndex) {
            for(auto it  = ret.begin(); it != ret.end() - 1; ++it) {
                *it += *(it + 1); 
            }
            ret.insert(ret.begin(), 1);
            ++cnt;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vi ret = sol.getRow(3);
    for(auto &item : ret) {
        cout << item << ' ';
    }
    cout << endl;
    return 0;
}
