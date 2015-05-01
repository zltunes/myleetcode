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
    vector<vector<int> > permute(vector<int> &num) {
        vvi ret;
        sort(num.begin(), num.end());
        do {
            ret.push_back(num); 
        } while(next_permutation(num.begin(), num.end()));
        return ret;
    }
};

void printVI(const vi & vec) {
    for(auto & item : vec) {
        cout << item << ' ';
    }
    cout << endl;
}

int main() {
    vi vec {1,2,3};
    Solution sol;
    vvi ret = sol.permute(vec); 
    for(auto & com : ret) {
        printVI(com);
    }
    return 0;
}
