085.Maximal Rectangle
===========================
题目链接：[Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)

> Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

题目的意思非常简单，但是想一下的话，如果使用暴力的解法，时间复杂度高的吓人。

![matrix](http://images.cnitblog.com/blog/466943/201307/20220216-6a5daf74280c4c929a3cf06e741943f6.png)

图片来自：[这里](http://blog.csdn.net/doc_sgl/article/details/11832965)

比如上面这张图，红色区域即为所求区域。但是我们怎么样去找到这个区域呢？一开始，我全无想法。

然后，我就去找题解了。也就是找到了该张图片的所在的这个[Blog](http://blog.csdn.net/doc_sgl/article/details/11832965)。我其实并没有直接看题解，但是我看到了一句话：**把这道题和[Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)放一起真是良苦用心。**

然后我就开始了痛苦的联想过程。

这两道题有什么样的联系呢？感觉表面上完全不想干。一个是一维的，一个是两维的，好像也不是什么直接的对称扩展。怎么样才能利用之前题目的结论，帮助我们解决这道题呢？

我们想看看图片中的Rectangle有哪些吧？首先我们考虑最基本的就是只包含一个**1**的那种。如果以**0**为坐标轴的开始，我们发现**[(0,2),(1,4),(2,1),(2,2),(2,3),(3,2),(3,3)]**都可以组成Rectangle。那之后呢？长条状的，那些有一条边是**1**的，有**[(1..3,3),(2,1..3),...]**，这些组合是怎么求出来的呢？包括最后的**(2..3,2..3)**。如果我们将每一行分开看呢？好像就组合不到一起了。那我们怎么才能把几个行的信息组合到一起去呢？每一行的考虑又应该怎么样呢？

假设我们考虑第一行作为底线，即这个matrix是一个**1 * 4**的。那么这道题是不是就和**Largest Rectangle in Histogram**一模一样了，并且还简单了不少，因为高之有可能是**1**。

我们再看第二行，好像和第一行并没有什么关系。

好吧，我们再看一下第三行。如果我们只考虑第三行，那么我们一定会少考虑这样一个元素**(3,1..2)**，这个Rectangle是我们必须考虑的，那这个问题怎么做呢？做法已经非常显然了，我们只需要把整张图上的可以从上一行继承的信息继承下来即可。那么怎么一个继承法呢？在遍历每一行的过程中，我们如果发现当前值是**0**，那么这个位置我们在做找最大Rectangle的时候，我们基本就不用考虑，也不用继承，因为最大的Rectangle不会出现在这一列上；如果当前值是**1**，那么我们就要讲上面的信息继承下来了，就比如上面有一个grid，那么这里的只就是上面的**1 + 1 = 2**。如果上方有连续的两个方格，那么这里的值就是**1 + 2 = 3**，以此类推。

最后我们就能得到一幅从上到下的**Histogram**，每一行，我们都需要做**Find Largest Rectangle**的操作，因为每一行都可能会出现那些最大的Rectangle，并且之间没有什么联系，上一行的最大方格也并不能预测道下一行的情况，所以需要遍历。但是我们在**[Largest Rectanle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)**中已经发现，这个操作的时间复杂度是**O(n)**，那么即时是有m行，我们整个算法的时间复杂度也能控制在**O(m * n)**中，这个远比我们之前思考的暴力枚举要来的好得多。

下面附上自己写的小代码。其实写的时候，主要的工作还是在上面一题。😓

```cpp
class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;
    using vc = vector<char>;
    using vvc = vector<vc>;
public:
    int largestRect(vi &histogram) {
        vi stk;
        histogram.push_back(0);
        int size = histogram.size();
        int max_rect = 0;

        int i = 0;
        while(i < size) {
            if(stk.empty() || histogram[stk.back()] <= histogram[i])
                stk.push_back(i++);
            else {
                int t = histogram[stk.back()]; stk.pop_back();
                int l = stk.empty() ? i : i - stk.back() - 1; 
                max_rect = max(max_rect, l * t); 
            }
        }

        return max_rect;
    }

    int maximalRectangle(vector<vector<char> > &matrix) {
        int height = matrix.size();
        if(height == 0) return 0;
        int width = matrix[0].size();
        if(width == 0) return 0;

        vi t;
        t.resize(width, 0);
        vvi dp;
        dp.resize(height, t);

        for(int i = 0; i < width; ++i)
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;

        for(int i = 0; i < width; ++i)
            for(int j = 1; j < height; ++j)
                dp[j][i] = matrix[j][i] == '1' ? dp[j - 1][i] + 1 : 0;

        int max_rect = 0;
        for(auto &row : dp) {
            int area = largestRect(row);
            max_rect = max(max_rect, area);
        }

        return max_rect;
    }
};
```
