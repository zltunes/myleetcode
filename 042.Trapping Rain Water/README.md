042.Trapping Rain Water
===========================
题目链接：[Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

> Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
>
> For example, 
> 
> Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
> 
> ![rainwatertrap](http://www.leetcode.com/wp-content/uploads/2012/08/rainwatertrap.png)
>
> The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

题目的意思基本和上述配图基本一致，要计算给出数组所构成的图形能够装多少雨水。

###思考
题目没有让我下个太久就有了一个比较好的解法。难道是我之前做过？

**怎么样才能接住雨水？**

如果两个高点之间有凹陷，那么水就可以被存储，存储的最高限就是两个高点中较低的那一个。

我们观察被水淹没后的图形，是十分有特征的。淹没完之后的图形是一个凸多边形。并且如果我们能够得知最后淹没完之后的图形，我们只需要再遍历一边数组，每个位置依次相减就可以求得这个图形可以盛多少水了。

**很自然的想法**

因为我们观察之后的图形的凸多边形特性，那么我们只要找到一个最高点，然后向两边找其余的高点，然后将他们之间的位置全部设成，第二高度值，然后再找下一个高度，如此递归，即可找到那个凸多边形。

明显这不是一个很好的想法，每次找到第二个高度都需要再去将剩下的位置填上。我们是否能找到一个一遍顺序遍历或者常数次顺序遍历即可解决的方法呢？

###优化
当前一点的最高水位决定于什么？他的左边最高水位和他右边最高水位的最小值，但是这两个值其实我们都可以保存下来的，那么是不是就是说，我们其实**并不需要同时知道这两个值**。那么怎么求来自左侧的最大值呢？从左侧遍历，如果没有大于当前最小值的，就直接赋为最小值？右侧也是相同的，在右侧便利的同时，我们就可以得到最小值了，有了最小值，我们就可以通过与原图形的差值，得到盛水量。

而我们发现盛水量其实也可以放在当前的这趟遍历中完成，所以，其实这道题只需要左右两趟遍历即可完成。以下是我的小代码。

```cpp
class Solution {
public:
    int trap(int A[], int n) {
        if(n == 0 || A == NULL) return 0;
       
        int *t = new int[n];
        int cur = A[0];
        for(int i = 0; i < n; ++i) {
            if(A[i] >= cur) cur = A[i];
            t[i] = cur;
        }

        cur = A[n - 1];
        int ret = 0;
        for(int i = n - 1; i >= 0; --i) {
            if(A[i] >= cur) cur = A[i];
            int min_val = min(cur, t[i]);
            ret += min_val - A[i];
        }
        return ret;
    }
};
```
