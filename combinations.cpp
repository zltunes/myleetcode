#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    typedef vector<int> vi;
    typedef vector<vi> vvi;
public:
    vector<vector<int> > combine(int n, int k) {
        vvi ret;
        vi temp;
        worker(ret, temp, k, n);
        return ret;
    }

    void worker(vvi & ret, vi & temp, int remain, int max) {
        if(remain == 0) {
            ret.push_back(temp);
        }
        int i;
        if(temp.empty()) i = 1;
        else i = temp.back() + 1;
        for(; i <= max; ++i) {
            temp.push_back(i);
            worker(ret, temp, remain - 1, max);
            temp.pop_back();
        }
    }
};

int main() {
    Solution sol;
    vvi ret = sol.combine(1, 2);
    for(auto & com : ret) {
        for(auto & item : com) {
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}
