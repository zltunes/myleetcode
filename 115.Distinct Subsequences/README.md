115.Distinct Subsequences
===========================
题目链接：[Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)

> Given a string S and a string T, count the number of distinct subsequences of T in S.

> A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

> Here is an example:
> 
> S = "rabbbit", T = "rabbit"

> Return 3.

题目意思是要找给定**S串**中存在的**T串**的个数。就如同题目中给定的例子，**rabbbit**中的**b**可以删除其中的任意一个，从而形成**T**。所以说**S**中存在**3**个**T**。

###递归的思路

其实这个题我感觉基本属于没有做过类似的题目基本想不出最优思路的那种。一开始感觉和[Edit Distance](https://leetcode.com/problems/edit-distance/)很像，但是没有他这么复杂，而且递推式明显不是取最小值。

所以我们先思考下能不能通过约减的思路来把问题化简为小问题来逐一解决。

- 如果两个位置上的字母是相同的话，我们需要考虑两种情况。当前值其实是这两种情况的加和：
    - 在**T**中，除了当前匹配的字符，剩下的字符有多少种匹配方式。
    - 当然，我们也需要考虑，如果包含当前字符，既我们考虑在**S**中，去掉匹配字符，和**T**的匹配情况。
- 如果字母不相同的话，我们就需要取找到相同的字符，如果找不到，那么就说明当前状态下，没有一个匹配方案。

根据上面的分析，如果我们从尾部开始匹配。例子的情况，可以做出如下的分解：

```
(rabbbit, rabbit)
(rabbbi, rabbi), (rabbbi, rabbit)
(rabbb, rabb), (rabbb, rabbi)
(rabb, rab), (rabb, rabb)
(rab, ra), (rab, rab), (rab, rab), (rab, rabb)
...
```

会发现，其实当我们使用回溯求解的时候，在有重复字符的情况下，许多状态是重复的，并且是会被多次调用的。上面这个思路在大数据的情况下，会超时。所以自然而然的我们就会想到去用动态规划优化这个解法。

###动态规划

根据上面的分析，其实我们只需要倒过来递推这个问题就可以了。我们需要做的就是把上面这些通过函数调用的方法表示的一个个状态转化成具体的数据，存下来，让后面的状态用，利用空间换时间即可。

从而，我们可以想到，每一个状态其实就表示**S[0..i]**中**T[0..j]**可以表示的subsequence数。我们先来考虑简单情况，如果**T**中没有字符，是一个空串的情况下，我们的解是**1**，因为只有把所有的字符都删掉这一种方法可以完成匹配。那么之后呢？考虑**T**含有一个字符的情况，如果和当前字符匹配，我们就要考虑当**T**包含匹配字符和不包含匹配字符两种情况，既**dp[i - 1][j - 1]**和**dp[i - 1][j]**；当当前字符不匹配的时候，那么我们只能借助上一层包含**T**的当前字符的结论了，也就是**dp[i - 1][j]**

所以，我们可以整理一下所有的条件：

1. 初始条件：**dp[i][0] = 1;**
2. 递推条件：**dp[i][j] = S[i - 1] == T[j - 1] ? dp[i - 1][j] + dp[i - 1][j - 1] : dp[i - 1][j]**
3. 返回值：**dp[S.size()][T.size()]**

###空间优化

其实，我们在编码的过程中可以发现，**dp[i][j]**只和**dp[i - 1][j]**与**dp[i - 1][j - 1]**有关，这意味着我们可以简化掉一维。但是我们发现，在优化的过程中，**dp[i - 1][j]**很好搞，直接抄下来即可，但是**dp[i - 1][j - 1]**在正向循环的时候，已经被修改过了，不再是上一轮的值了。我们应该怎么做呢？很简单，如果正向的修改会使得上次的值丢失，那么我们就可以倒过来。倒过来的遍历其实是完全一样的过程，因为只依赖于**dp[i - 1][j - 1]**，所以只需要修改一下遍历顺序，去掉一维即可。

下面附上带空间优化的动态规划小代码。

```cpp
class Solution {
    using vi = vector<int>;
public:
    int numDistinct(string S, string T) {
        int height = S.size(), width = T.size(); 
        vi dp(width + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= height; ++i) {
            for(int j = width; j >= 1; --j) {
                if(S[i - 1] == T[j - 1])
                    dp[j] += dp[j - 1];
            }
        }

        return dp[width];
    }
};
```
