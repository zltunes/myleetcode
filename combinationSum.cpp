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
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        auto last = unique(candidates.begin(), candidates.end());
        candidates.erase(last, candidates.end());
        vi temp;
        vvi ret;
        worker(candidates, target, temp, ret);
        return ret;
    }

    void worker(vi &candidates, int target, vi &temp, vvi &ret) {
        if(target == 0) {
            ret.push_back(temp);
            return;
        }
        for(auto & item : candidates) {
            if(target - item >= 0) {
                if(temp.empty() || item >= temp.back()) {
                    temp.push_back(item);
                    worker(candidates, target - item, temp, ret);
                    temp.pop_back();
                }
            }
        }
    }
};

int main() {
    vi candidates {2, 3, 11};
    int target = 22;

    Solution sol;
    vvi ret = sol.combinationSum(candidates, target);
    for(auto & vec : ret) {
        for(auto item : vec) {
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}
