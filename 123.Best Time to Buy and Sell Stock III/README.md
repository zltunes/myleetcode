123.Best Time to Buy and Sell Stock III
===========================
题目链接：[Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)

> Say you have an array for which the ith element is the price of a given stock on day i.

> Design an algorithm to find the maximum profit. You may complete at most two transactions.

> Note:
> 
> You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

###最直接的想法

因为之前做过前面做过[Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)和[Best Time to Buy and Sell Stock II ](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)这两道题，所以做这道题时的思路会尽量想这两道题的思路上去靠。比如，我们在做第二道题题目的时候，选取了所有的上升的阶段，并将他们的差价全部加了起来作为了最大利润。那么这道题的限制两次，难道不就是直接维护两个最大的上升区间这么简单吗？从而就有了如下代码。

直到我们遇到了这个测试用例：

```
1,2,4,2,5,7,2,4,9,0
```

很明显如果使用我们的算法就会采集道**[2,7]**和**[2,9]**两段，但是实际上的最大利润为**[1,7]**和**[2,9]**。

```cpp
class Solution {
    using vi = vector<int>;
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
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
        return max_profit1 + max_profit2; 
    }
};
```

###动态规划

上面思路最大的问题在于，他没法总体的观看这一串数，我们所有的选取策略，类似与来一个数，做一次有关操作，而并没有办法利用到全局的信息，和上一个数，甚至上上个数对来数的影响。所以，我们必须换一个思路。

考虑这个问题是不是和第一道[Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)有更多的相同之处呢？但是第一题的做法很难让我们直接联想到解法，所以我们先思考一下第一题的各种做法吧。

####正过来推和倒过来算

这两种方法其实都是一样的。一个是维护一个最小值，而后者则是维护一个最大值。如果我们只考虑一段数中的一次最大利润，那么其实只需要记录最大利润即可，既不用记录每一个位置的最大利润。具体算法只需要维护一个目前最小值(如果是从后往前，就是最大值)和当前的最大利润。

考虑当前问题，题目要求必须当前只能持有一个股票，也就是说两段一定是分开的，最多最多有可能，**在抛出的当天，我就买进**。我们现在需要的其实是两段的最大利润，并且，我们最终优化条件是两段的利润加起来最大。那么如果能找到**分届点**，并且以该点为分界的两段，可以**保证两段加起来的利润最大**，那么我们只需要分别在这两段中跑一遍上述任意一个算法就可以找到这个利润了。

但是我并不能通过什么**神奇**的方法找到上述分界点，所以，我们就只能一个个遍历了。具体方法就是，我们先找到所有从左开始的，也就是数组的**前缀**的最大利润，通过一个数组存放；然后我们需要的只是和他能拼成一块的一个数组，仔细看也就是数组的**后缀**，所以我们再从后面开始遍历，然后直接维护**倒过来算**算法的两个变量，利用之前保存的信息，**顺便**维护总体的最大利润。即我们通过**正过来推**算法，算出了所有的数组前缀的最大利润，并且存了下来，之后，我们又通过**倒过来算**算法，算出了所有的数组后缀的最大利润，并且结合之前的信息，我们维护了一个总体的最大利润，即为我们需要的解。

最后还是惯例，附上自己的小代码，希望大家喜欢。

```cpp
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
        }
        return ret;
    }
};
```
