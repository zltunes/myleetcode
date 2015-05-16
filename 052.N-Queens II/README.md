052.N-Queens II
===========================
题目连接：[N Queens II](https://leetcode.com/problems/n-queens-ii/)

> Follow up for N-Queens problem.

> Now, instead outputting board configurations, return the total number of distinct solutions.

> ![n queens](http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png)

N皇后的第二道，leetcode上面两道N皇后都是**hard**难度。但是其实就是两道基本的回溯，如果知道解法的话，并不困难。

之前在**知乎**上面倒是看到了一个非常有趣的[问题](http://www.zhihu.com/question/28543312)。大概就是一个面试者在面一家创业公司的时候被问到了，如何用C++，在10行之内写出n皇后。很多大牛们都给出了自己的解答，不乏非常厉害的解答，有兴趣的可以去围观一下。

N皇后问题所求的就是一个**[1..n]**的序列。因为每一行和每一列都可能只存在一个所以，用数组的下标表示行，用值来表示列，列又不能相同，所以就是一个**[1..n]**的排列。

之后需要考虑的东西就是对角线的问题了。复杂度的话，应该是**O(n!)**

我使用的是递归的方法。

```cpp
class Solution {
    using vi = vector<int>;
public:
    int totalNQueens(int n) {
        if(count == -1) {
            max_size = n;
            count = 0;
        }
        if(n == 0) ++count;
        for(int i = 0; i < max_size; ++i) {
            if(!isValid(i)) continue;
            table.insert(table.begin(), i);
            totalNQueens(n - 1);
            table.erase(table.begin());
        }
        return count;
    }
    bool isValid(int col) {
        for(int i = 0; i < table.size(); ++i) {
            if(table[i] == col) return false;
            if(i + 1 == abs(table[i] - col)) return false;
        }
        return true;
    }
private:
    vi table;
    int max_size = 0;
    int count = -1;
};
```
