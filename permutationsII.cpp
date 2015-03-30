#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vvi ret { num };
        while(my_next_permutation(num.begin(), num.end())) {
            /*for(auto &item : num) {
                cout << item << ' ';
            }
            cout << endl;*/
            ret.push_back(num); 
        }
        return ret;
    }

    bool my_next_permutation(vi::iterator begin, vi::iterator end) {
        if(begin == end || begin >= end - 1) return false;
        if(*(end - 1) > *(end - 2)) {
            swap(*(end - 1), *(end - 2));
            return true;
        }
        auto iter = end - 2;
        while(iter != begin && *iter >= *(iter + 1)) {
            --iter;
        }
        if(*iter >= *(iter + 1)) return false;
        auto iter2 = end - 1;
        while(iter2 != begin && *iter2 <= *iter) --iter2;
        swap(*iter2, *iter);
        auto i = iter + 1;
        auto j = end - 1;
        while(i <= j) {
            swap(*i, *j);
            ++i, --j;
        }
        return true;
    }
};

int main() {
    vi test {1,1,2,3};

    Solution sol;
    vvi ret = sol.permuteUnique(test);
    for(auto &row : ret) {
        cout << "line 1 : ";
        for(auto &item : row)
            cout << item << ' ';
        cout << endl;
    }
    return 0;
}
