#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    typedef vector<int> vi;
    typedef vector<vi> vvi;
public:
    vector<vector<int> > generate(int numRows) {
        vvi ret;
        if(numRows == 0) return ret;
        vi temp {1};
        ret.push_back(temp);
        if(numRows == 1) return ret;
        int cnt = 1;
        while(cnt < numRows) {
            vi &pre = ret.back();
            vi temp = {1};
            for(auto it = pre.begin(); it != pre.end() - 1; ++it) {
                temp.push_back(*it + *(it + 1));
            }
            temp.push_back(1);
            ret.push_back(temp);
            ++cnt;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vvi ret = sol.generate(4);

    for(auto &row : ret) {
        for(auto &item : row) {
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}
