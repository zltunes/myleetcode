032.Longest Valid Parentheses
===========================
题目：[Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)

> Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.
> 
> For `"(()"`, the longest valid parentheses substring is `"()"`, which has length = 2.
> 
> Another example is `")()())"`, where the longest valid parentheses substring is `"()()"`, which has length = 4.

题目的意思是在一个只有做括号`"("`，和右括号`")"`的字符串中，找到一组最长的合法的左右括号的字符串。

###错误的解法一
拿到之后，没有想太多，就直接开始敲了，完全当做了检查这个字符串是否合法来做。我想是不是只要在断掉的地方（不合法发生之后），统计到当前这个连续字符串的长度，并且维护一个最大值就可以了。

如果是这个思路的话，我们就会发现断掉的地方只会出现在`")"`的地方出现，因为`"("`的情况下，一定是合法的。那么我们会很快发现有以下问题。

```
012345678
(()())(()
```

这个字符串的最大长度应该是**6**，但是用上述方法求解之后，在**6**位置的左括号并不能断开，所以最后的计算结果会是**8**

###错误的解法二

之后我又想到了[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)这道题。然后二话没说，我又开始敲了。敲着敲着，我就发现虽然动态规划的递推式是一样的，但是，这个问题中有一个不完全一样的地方，就是这道题目中，除了这一个递推式是不够的，我们需要考虑在找到两个位置之间是否是合法的括号串后，还要考虑两个合法的串合在一起后还是一个更长的合法串。并且我并不需要记录每两个点之间的是否是合法串这个信息，也就是我们不需要一个**2维**的动态规划来考虑这个问题。所以就下面这个正确的解法。

###正确的解法一

还是通过动态规划的方法思考这道题，因为一个固定长度的括号串的最长的合法串并不会收到前后增加的括号而边长（当然是在同一段区间中）。

之后，我们可以选择控制一端来考虑这个问题。从前后都可以，这边我们假设从后端开始考虑计算每一个位置到末尾位置所组成的括号串的最长合法串的长度（必须考虑包含当前自符，不然之后我的在动态规划的过程中，我们就无法考虑两个合法串连载一起的问题了）。我们通过一个一维数组来记录这些我们计算过的位置的最长合法串的长度。

那么我们可以发现`dp[s.size() - 1] = 0`，之后每一个位置的最长的合法串可以通过下面两个方面来考虑了。

- 首先这个字符必须是`"("`，不然的话，并不能构成以这个为首的和合法串。
- 假设当前的字符处在`i`，之后我们可以去找`i + 1`位置的最长合法串，如果在加上这个合法串的长度后，后面跟着的那个位置为`")"`，既
 
 ```cpp
 s[i + dp[i + 1] + 1] == ')'
 ```
 
那我们可以的出当前位置的这个最大合法串的长度至少为`dp[i + 1] + 2`

- 我们现在就可以考虑之前一直提到的那个两个相连的合法串的问题了。当我们考虑完上面的情况后，如果`i + dp[i + 1] + 1`仍然没有超过最后的最大位置，那么我们就要把以这个位置为首的最长合法串的长度加进来了。即

```cpp
if(i + dp[i + 1] + 2 < s.size())
    len += dp[i + dp[i + 1] + 2];
```

然后在这一过程中，我们维护一个最大值就可以了。

贴一下我写的小代码，莫名的加了一些预处理：

```cpp
class Solution {
    using vi = vector<int>;
public:
    int longestValidParentheses(string s) {
        int i = 0, j = s.size() - 1;
        while(s[i] == ')') ++i;
        while(s[j] == '(') --j;
        s = s.substr(i, j - i + 1);
        vi dp;
        dp.resize(s.size(), 0);
        int indice = s.size() - 2;
        int max_len = 0;
        int pos = indice;
        for(; indice >= 0; --indice) {
            if(s[indice] == ')') continue;
            int j = indice + 1 + dp[indice + 1];
            int temp = 0;
            if(j < s.size() && s[j] == ')') {
                temp = dp[indice + 1] + 2;
                if(j + 1 < s.size())
                    temp += dp[j + 1];
            }
            if(temp > max_len) {
                max_len = temp;
                pos = indice;
            }
            dp[indice] = temp;
        }
        return max_len;
    }
};
```
