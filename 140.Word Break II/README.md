140.Word Break II
===========================
题目链接：[Word Break II](https://leetcode.com/problems/word-break-ii/)

> Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

> Return all such possible sentences.

> For example, given
> s = "catsanddog",
> dict = ["cat", "cats", "and", "sand", "dog"].

> A solution is ["cats and dog", "cat sand dog"].

题目的意思和 [Word Break](https://leetcode.com/problems/word-break/) 的意思基本一致，主要的不同是，我们需要给出所有的分解方式，并且以每个词中添加空格的方式返回。

###回溯
之前的 [Word Break](https://leetcode.com/problems/word-break/) 是可以通过简单的回溯搞定的。每次回溯就可以验证单词是否在字典里，并且完成对单词的分割记录。可以通过对单词长度的分类，加快 **Word Break** 的速度，为了方便起见，使用了一个 **vector** 对当前被分割的单词进行了存储，在最后一格格地加起来。

这种解法有明显的重复求解过程和无效运算，会在大数据的情况下超时。所以，我们想到了使用动态规划来完成寻找单词的过程，然后再通过回溯构造最后的解。


```cpp
class Solution {
    using vs = vector<string>;
    using mivs = unordered_map<int, vs>;
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        mivs mp;
        for(auto &item : wordDict) {
            if(item.size() == 0) continue;
            mp[item.size()].push_back(item);
        }
        vs ret;
        vs temp;
        worker(ret, temp, s, mp); 
        return ret;
    }

    void worker(vs &ret, vs &temp, string s, mivs &dict) {
        if(s.size() == 0) {
            string t;
            for(auto &item : temp)
                t += item + ' ';
            ret.push_back(t.substr(0, t.size() - 1));
            return;
        }

        for(auto &kv : dict) {
            int size = kv.first;
            auto &v = kv.second;
            string t = s.substr(0, size);
            auto it = find(v.begin(), v.end(), t);
            if(it != v.end()) {
                temp.push_back(*it);
                worker(ret, temp, s.substr(size), dict);
                temp.pop_back();
            }
        }
    }
};
```

###动态规划

动态规划的思路就是把已经计算过的情况记录下来，之后在运算的过程中直接使用结果即可，减少重复运算。构造动态规划的方法主要分为三步。

####表示状态

由于这道题需要找到最后的分解情况，所以我们不能单纯地记录出现的个数，必须要记录一些有关位置的信息，以方便之后在回溯构造的过程中，能够快速地构造出最后的答案。

这里我选择使用了记录前面一个位置的方式。使用这种策略，只需要在最后递归地从后往前构造单词就可以了。

**dp[i]** 是一个 **vector**。里面存储着 **i** 位置之前的所有可能的位置值，这个位置到 **i**，正好可以找到一个在字典里的单词。如果该位置并不能构造出单词，那么里面就存一个**-1**。

####递推公式

每一个位置的情况其实都和之前所有位置的分解情况有关。每次确定当前位置的解时，我们都要向前看，找到那些位置 **j** 上不是**-1**的情况，也就是之前在这个位置已经构造了解，然后对位置 **j** 进行讨论，如果从位置 **j** 起一直到当前位置，我们可以在字典里找到一个字符串与它相匹配，那么我们就可以在当前位置的 **vector** 里面添加 **j**。

####初始条件

初始条件就只有在**0**个字符的情况下，是一个开始，字典里没有相应的字符与**空串**匹配。(字典里面应该是不会出现**空串**的，因为如果出现空串，就可以在任意位置增加空格了)

这样我们就已经统计出所有可以构造的位置了。之后，就可以构造出最后需要返回的字符串了。

####构造过程

构造的时候，基本和之前的回溯的思路一样。**Base Case** 就是当我们发现构造到头了，那么我们就停下，然后将 **vector** 中的所有单词连接在一起。如果没有到头，就遍历当前位置下的 **vector** 中每一个位置的情况。

最后是动态规划的代码。欢迎交流。

```cpp
class Solution {
    using vs = vector<string>;
    using vi = vector<int>;
    using vvi = vector<vi>;
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int size = s.size();
        vvi dp(size + 1, vi ());
        dp[0].push_back(-2);

        for(int i = 1; i <= size; ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j][0] != -1) {
                    auto t = s.substr(j, i - j);
                    if(wordDict.count(t))
                        dp[i].push_back(j);
                }
            }
            if(dp[i].empty())
                dp[i].push_back(-1);
        }

        vs ret;
        vs temp;
        constructRets(ret, temp, s, size - 1, dp); 
        return ret;
    }

    void constructRets(vs &ret, vs &temp, string &origin, int i, vvi &dp) {
        if(dp[i + 1][0] < 0) {
            string t;
            for(auto &s : temp)
                t = s + " " + t;
            if(!t.empty())
                ret.push_back(t.substr(0, t.size() - 1));
            return;
        }
        for(auto &item : dp[i + 1]) {
            temp.push_back(origin.substr(item, i + 1 - item)); 
            constructRets(ret, temp, origin, item - 1, dp);
            temp.pop_back();
        }
    }
};
```
