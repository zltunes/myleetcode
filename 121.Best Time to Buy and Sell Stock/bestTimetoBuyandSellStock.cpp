#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1) return 0;
        int top_price = INT_MIN;
        int max_profit = 0;
        for(auto it = prices.rbegin(); it != prices.rend(); ++it) {
            if(*it > top_price) {
                top_price = *it;
            }
            if(top_price - *it > max_profit) {
                max_profit = top_price - *it;
            }
        }
        return max_profit;
    }
};

int main() {
    vi vec {6,1,3,2,4,7};
    
    Solution sol;
    cout << sol.maxProfit(vec) << endl;
    return 0;
}
