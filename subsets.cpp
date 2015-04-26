#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    typedef vector<int> vi;
    typedef vector<vi> vvi;
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vvi ret;
        vi temp;
        sort(S.begin(), S.end());
        worker(ret, temp, 0, S);
        return ret;
    }

    void worker(vvi & ret, vi & temp, int level, vi & S) {
        if(level == S.size()) {
            ret.push_back(temp);
            return;
        }
        worker(ret, temp, level + 1, S);
        temp.push_back(S[level]);
        worker(ret, temp, level + 1, S);
        temp.pop_back();
    }
};

int main() {
    vi vec {1,2,3};
    Solution sol;
    vvi ret = sol.subsets(vec);
    for(auto & subset : ret) {
        for(auto & item : subset)
            cout << item << ' '; 
        cout << endl;
    }
    return 0;
}
