084.Largest Rectangle in Histogram
===========================
题目链接：[Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)

> Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

> ![histogram.png](http://www.leetcode.com/wp-content/uploads/2012/04/histogram.png)

> Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

> ![histogram_area.png](http://www.leetcode.com/wp-content/uploads/2012/04/histogram_area.png)

> The largest rectangle is shown in the shaded area, which has area = 10 unit.

> For example,
> 
> Given height = [2,1,5,6,2,3],
> 
> return 10.

题目的意思，和图里需要表达的意思，基本一致。我们需要在这样一个Histogram中，找到最大的长方形。

##最直接的解法(TLE)

通过两根指针进行搜索，一定可以找到解，但是很明显，算法中有许多可以被优化的地方。比如，最小值的利用，第二个位置如果比之间小的话，可以证明以他为开始的长方形一定小于之前的解。

在这些优化后，我没有尝试能不能通过。但是很明显，在许多特殊用例下，依然是一个**O(n2)**的算法。

##我没有想出来的解法

最终的解法，是我在看了题解之后想出来。但是我依旧不能解释这个想法是怎么想出来的。

具体的讲，我们需要维护以非降序的连续的序列。为什么呢？因为我们发现如果一个连续的非降序序列，如果他的最小值大于前后的最小值的话，他的最大最小值是不受前后影响的。

所以每当一个连续的非降序序列将要被破坏时，我们就可以对当前的这个区间其中，最小值也大于前后最小值的部分进行讨论，因为所求的最大值就出现在这样的区域中。

像这个图一样：

![histogram](http://img.blog.csdn.net/20130518123957109)

图片来自[这篇博客](http://www.cnblogs.com/avril/archive/2013/08/24/3278873.html)。

我们在每次连续非降序序列将要被破坏时，我们统计之前满足条件的非降序区间，并且更新最大值。图片中红色是第一个求的非降序的最大值，也就是只有一个，绿色是第二个，不要忘记整个区间最后需要求的，也就是粉红色的部分，这个操作，我们可以通过手动在输入**heights**之后，加入一个**0**，来实现。

统计每一个区间的最大值中，我在编码中犯了一个很简单的错误，但是查的时候，浪费了一个早上的时间。

每次当我们要统计区间内部最大的长方形时，我们需要一个高，一个宽，但是其实我们需要的高和宽并不是同一个立柱上的，看似可以用当前立柱的宽，其实不能。我们需要的宽度，其实是之前一颗立柱上的。

下面付一下自己写的挫挫的小代码，利用pair的方式组合了高度和位置。

```cpp
class Solution {
    using pii = pair<int, int>;
    using vpii = vector<pii>;
public:
    int largestRectangleArea(vector<int> &height) {
        vpii stk; 
        height.push_back(0);

        int max_rect = 0;
        int size = height.size();

        for(int i = 0; i < size; ++i) {
            if(stk.empty() || height[i] >= stk.back().first)
                stk.push_back(make_pair(height[i], i));
            else {
                while(!stk.empty() && stk.back().first > height[i]) {
                    auto t = stk.back(); stk.pop_back();
                    int width = stk.empty() ? i : (i - stk.back().second - 1);
                    max_rect = max(max_rect, width * t.first);
                }
                stk.push_back(make_pair(height[i], i));
            } 
        }
        return max_rect;
    }
};
```
