047.Permutations II
===========================
题目连接：[Permutations II](https://leetcode.com/problems/permutations-ii/)

> Given a collection of numbers that might contain duplicates, return all possible unique permutations.

> For example,
> 
> [1,1,2] have the following unique permutations:
> 
> [1,1,2], [1,2,1], and [2,1,1].

相比于之前的[Permutations](https://leetcode.com/problems/permutations/)，出现了重复元素。原生**algorithm**库中，**next_permutation**函数就是去重的，这里的每一次去重不是通过**set**，也不是通过和相邻元素的比较，去重的方式是直接通过对求下一项函数，也就是**next_permutation**的改写。

需要注意的就是我们在寻找从后往前找的时候，我们所要找的是一个**非降序序列**，而不是一个升序序列，找到从后往前的第一个下降点之后，我们需要在非降序序列中，找到一个刚好**大于**他的数，然后进行两数的交换，再反转后面的非降序序列。

```cpp
class Solution {
    using vi = vector<int>;
    using vvi = vector<vi>;
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vvi ret { num };
        while(my_next_permutation(num.begin(), num.end())) {
            ret.push_back(num); 
        }
        return ret;
    }

    bool my_next_permutation(vi::iterator begin, vi::iterator end) {
        if(begin == end || begin >= end - 1) return false;
        if(*(end - 1) > *(end - 2)) {
            swap(*(end - 1), *(end - 2));
            return true;
        }
        auto iter = end - 2;
        while(iter != begin && *iter >= *(iter + 1)) {
            --iter;
        }
        if(*iter >= *(iter + 1)) return false;
        auto iter2 = end - 1;
        while(iter2 != begin && *iter2 <= *iter) --iter2;
        swap(*iter2, *iter);
        auto i = iter + 1;
        auto j = end - 1;
        while(i <= j) {
            swap(*i, *j);
            ++i, --j;
        }
        return true;
    }
};
```
