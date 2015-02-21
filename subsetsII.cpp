#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef set<vi> svi;
public:
    vector<vector<int> > subsetsWithDup2(vector<int> &S) {
        vvi ret;
        vi temp;
        sort(S.begin(), S.end());
        worker(ret, temp, S, 0);
        return ret;
    }

    void worker(vvi &ret, vi &temp, vi &S, int level) {
        ret.push_back(temp);

        for(int i = level; i < S.size(); ++i) {
            if(i != level && S[i] == S[i - 1]) continue;
            temp.push_back(S[i]);
            worker(ret, temp, S, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        svi ret; 
        int size = S.size();
        sort(S.begin(), S.end());
        int times = pow(2, size);
        vi temp;
        for(int i = 0; i < times; ++i) {
            int t = i;
            for(int j = 0; j < size; ++j) {
                if(t & 1) {
                    temp.push_back(S[j]);
                }
                t >>= 1;
            }
            ret.insert(temp);
            temp.clear();
        }
        return vvi {ret.begin(), ret.end()};
    }
};

int main() {
    vi vec {1,2,2};
    Solution sol;
    vvi ret = sol.subsetsWithDup2(vec);
    cout << ret.size() << endl;
    for(auto & row : ret) {
        for(auto & item : row) {
            cout << item << ' ';
        }
        cout << endl;
    }
    return 0;
}
