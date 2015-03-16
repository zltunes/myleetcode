#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1) return 0;
        int before, min_now;
        before = min_now = prices.front();
        int max_profit = 0;
        for(auto it = prices.begin() + 1; it != prices.end(); ++it) {
            if(*it < before) {
                max_profit += before - min_now;
                min_now = *it;
            }
            before = *it;
        }
        max_profit += before - min_now;
        return max_profit;
    }
};

int main() {
    vi vec {6,1,3,2,4,7};
    Solution sol;
    cout << sol.maxProfit(vec) << endl;
    return 0;
}
