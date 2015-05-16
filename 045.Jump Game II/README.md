045.Jump Game II
===========================
题目链接：[Jump Game II](https://leetcode.com/problems/jump-game-ii/)

> Given an array of non-negative integers, you are initially positioned at the first index of the array.
> 
> Each element in the array represents your maximum jump length at that position.
> 
> Your goal is to reach the last index in the minimum number of jumps.
> 
> For example:
> 
> Given array A = [2,3,1,1,4]
> 
> The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

题目的意思和[Jump Game](https://leetcode.com/problems/jump-game/)类似，每一个位子上的数字是你在当前位置可以跳跃的最远距离，让你求从第一个位置到最后一个位置的最少跳跃数。


先来说说我的各种尝试。首先是我**错误**地否定了我**Jump Game**所用方法的可行性，所以诞生了以下三种经典的TLE方法。

###TLE的解答0（BFS）

每一点的数字大小就是改点的下一个位置的范围，那么到达最后一点的最短路径就可以转化为一个搜索问题，怎样从第一个位置找到一条最短的到最后一个位置的路径。既然是要找**最短**的路径，那么有可以转化为基本的宽度优先搜索。

代码的思路也很简单，维护一个队列，一开始队列中只有第一个元素。队列中的元素包含三方面的信息，第一个是当前的最大跳跃数，第二个是当前的位置信息，第三了是到了当前位置所用的步数。

在每次遍历的时候，取出队首的元素，然后遍历当前位置可以到达的位置既

```cpp
for(int i = t.second; i < t.second + t.first; ++i)
```

将这些位置的数据，逐一加入队尾。结束的条件是检查每次取出的队首元素，如果当前元素的最大跳跃值已经超过了最终的位置，那么我们就可以认定当前位置的**已跳步数 + 1**就是起点到终点所需的最短跳跃数。

该算法的时间复杂度为每个位置的平均大小**O(l)**，再乘以位置个数**O(n)**，既**O(l) * O(n)**。当前复杂度会在中等数据集上就超时。显然，我们发现，其实许多的信息我们都没有必要加入队列中进行处理。

###TLE的解答1（倒推法）

思考这样一个问题，我们则么才能达到最后一点呢？一个个跳呗。如果正面的求解需要取找到所有的跳跃情况才能进行下一步的话，那么倒过来会不会简单一些呢？是的，的确会简单一些。我们有这样一个结论来帮祝我们简化算法。**每一次，能够跳到某一点的最远距离是可以求得。**所以我们只要去确定能够达到每一次终点的最远距离点就可以了。从后往前，找到这样的最远距离点就是下一次需要到达的终点，直到先要找的最远距离点到了**0**。

这种方法在中数据集和正常的大数据集上都有着很好的表现，但是存在一些特殊的数据集上，比如**递减的数据集**中，有着明显劣势，有许多不必要的计算。

```cpp
int jump_backward(int A[], int n) {
    int cnt = 0;
    int cur = n - 1;
    int pre = 0;
    while(pre != cur) {
        pre = cur;
        for(int i = pre - 1; i >= 0; --i) {
            if(A[i] + i >= pre) {
                if(i < cur) 
                    cur = i;
            }
        }
        ++cnt;
        if(cur == 0) return cnt;
    }
    return 0;
}
```

###TLE的解答2（DP）
DP方法就是倒推法的翻转。正面想这个问题，我们就是要求解到每个位置的步数的最小值。也就是说我们如果我们要求最后一个位置的最小步数，可以讲问题分解成**n**个小问题，每个问题都是一个求解最小步数的问题，而这样的解法在特殊的数据集上依然会超时。

```cpp
int jump_dp(int A[], int n) {
    int *dp = new int[n];
    dp[0] = 0;
    for(int i = 1; i < n; ++i) {
        dp[i] = INT_MAX;
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(j + A[j] >= i) {
                int t = dp[j] + 1;
                if(t < dp[i]) {
                    dp[i] = t;
                    break;
                }
            }
        }
    }
    return dp[n - 1];
}
```

###正确的解答（原来的思路）
最后，我的思路**递归**到了最初的状态。我查看了**Jump Game**的解题思路，似乎我们可以通过简单的添加状态的求这个问题。而不是另外想一个解法。

之前求解**Jump Game**，我们遍历每一个位置的数值，只要所有位置的最远距离不为**0**，那么我们认为他就是可以达到终点的。那么这一道题，除了维护原来那个最远距离的浮标，我们还需要怎样做才能获得最短距离呢？

**思考：**我们是不是只有在当前的最远距离不能满足我们的跳跃需求的时候才会进行跳跃操作，不然的话，一定存在一个跳跃来到达更远的点，使得当前跳跃需要额外的跳跃来达到那个点？

所以，对于当前遍历的点来说，除了维护之前需要的最远距离点时，我们还需要记录上一个最远距离点，每当浮标移动出了那个最大距离之后，我们就需要用跳跃来解决问题，而上一次的最远距离点之前，我们的操作均可以用当前跳跃来解决，并不需要额外的跳跃。


```cpp
class Solution {
public:
    int jump(int A[], int n) {
        int ret, last, curr;
        ret = last = curr = 0;
        for(int i = 0; i < n; ++i) {
            if(i > curr) return -1;
            if(i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, A[i] + i);
        }
        return ret;
    }
};
```
