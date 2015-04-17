#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
    using vi = vector<int>;
public:
    int maxProfit(int k, vector<int> &prices) {
        int size = prices.size();
        if(k >= size) return tooManyK(prices);
        vi max_local(k + 1, 0);
        vi max_global(k + 1, 0);


        for(int i = 1; i < size; ++i) {
            int diff = prices[i] - prices[i - 1];
            for(int j = k; j >= 1; --j) {
                max_local[j] = max(max_global[j - 1] + max(diff, 0), max_local[j] + diff);
                max_global[j] = max(max_local[j], max_global[j]);
            }
        }

        return max_global[k];
    }

    int tooManyK(vi &prices) {
        int profits = 0;
        int size = prices.size();
        for(int i = 1; i < size; ++i) {
            int diff = prices[i] - prices[i - 1];
            profits += max(diff, 0);
        }
        return profits;
    }
};

int main() {
    //vi vec {6,1,3,2,4,7};
    vi vec {1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,1,2,4,2,5,7,2,4,9,0,};
    int times = 100000;
    Solution sol;
    cout << sol.maxProfit(times, vec) << endl;

    return 0;
}
