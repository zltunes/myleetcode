#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void printVI(vi &t);

class Solution {
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    vector<vector<int> > threeSum(vector<int> &num) {
        vvi ret; 
        vi vec;
        if(num.size() <= 2) return ret;
        sort(num.begin(), num.end());
        if(num.front() > 0) return ret;
        if(num.back() < 0) return ret;
        if(num.front() == 0 && num.back() == 0) {
            ret.push_back(vi {0,0,0});
            return ret;
        }
        int current_value = num[0];
        for(int cnt = 0; cnt < num.size() - 2; ++cnt) {
            if(cnt && current_value == num[cnt]) {
                continue;
            }
            int i = cnt + 1;
            int j = num.size() - 1;
            while(i < j) {
                int two_sum = num[i] + num[j];
                if(two_sum > -num[cnt]) --j;
                if(two_sum < -num[cnt]) ++i;
                if(two_sum + num[cnt] == 0) {
                    vec.push_back(num[cnt]);
                    vec.push_back(num[i]);
                    vec.push_back(num[j]);
                    if(ret.empty() || ret.back() != vec) {
                        ret.push_back(vec);
                    }
                    vec.clear();
                    ++i, --j;
                }
            }
            current_value = num[cnt];
        }
        return ret;
    }
};

void printVI(vi &t) {
    for(vi::iterator it2 = t.begin(); it2 < t.end(); ++it2) {
        cout << *it2 << ' ';
    }
    cout << endl;
}

void printVVI(vvi & t) {
    for(vvi::iterator it = t.begin(); it < t.end(); ++it) {
        for(vi::iterator it2 = it->begin(); it2 < it->end(); ++it2) {
            cout << *it2 << ' ';
        }
        cout << endl;
    }
}

int main() {
    vi test = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    Solution sol;
    vvi res = sol.threeSum(test);
    printVVI(res);
    return 0;
}
