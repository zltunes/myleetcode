#include <iostream>
#include <vector>
using namespace std;

using vi = vector<int>;

class Solution {
    using vi = vector<int>;
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size <= 1) return 0;
        vi maxFromHead(size, 0);

        int min_price, max_profit;
        min_price = prices.front();
        max_profit = 0;
        for(int i = 1; i < size; ++i) {
            min_price = min(min_price, prices[i]); 
            if(prices[i] - min_price > max_profit) 
                max_profit = prices[i] - min_price;
            maxFromHead[i] = max_profit;
        }

        int ret = 0;
        int max_price = prices.back();
        max_profit = 0;
        for(int i = size - 1; i >= 0; --i) {
            max_price = max(max_price, prices[i]); 
            if(max_price - prices[i] > max_profit)
                max_profit = max_price - prices[i];
            ret = max(ret, max_profit + maxFromHead[i]);
            cout << max_profit << ' ' << i << ' ' << maxFromHead[i] << endl;
        }
        return ret;
    }
};
/*if(prices.size() <= 1) return 0;
  int min_low, before, max_profit1, max_profit2;
  min_low = before = prices.front();
  max_profit1 = max_profit2 = 0;

  prices.push_back(-1);
  for(auto it = prices.begin() + 1; it != prices.end(); ++it) {
  if(*it < before) {
  int profit = before - min_low;
  if(profit > max_profit2) {
  max_profit2 = profit;
  if(max_profit2 > max_profit1) swap(max_profit1, max_profit2);
  }
  min_low = *it;
  } 
  before = *it;
  }
  return max_profit1 + max_profit2; */

int main() {
    vi test {1,2,4,2,5,7,2,4,9,0};
    //vi test {1,5};

    Solution sol;
    cout << sol.maxProfit(test) << endl;

    return 0;
}
