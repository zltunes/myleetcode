001.Two Sum
===========================
> Given an array of integers, find two numbers such that they add up to a specific target number.

> The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

> You may assume that each input would have exactly one solution.

> Input: numbers={2, 7, 11, 15}, target=9

> Output: index1=1, index2=2

看到这道题之后，第一个想法是先用pairs给数组里面的数据编号，然后再用快牌把数组排好，最后从两头开始遍历，如果之和大了就让大的那头往小的移，如果小了就让小的那头往大的移。

这个解法的时间复杂度为`O(Nlog(N) + 2N)`也就是快排的时间复杂度。

具体实现是通过`make_pair`和带有比较函数的`sort`来完成。

第二个解法的时间复杂度也是`O(Nlog(N))`，具体做法是把数据构造成一颗红黑树，然后在通过红黑树顺序查找`target - value[i]`，这种解法需要注意的事，找到的解必须保证不是自己，也就是说要保证如果`target == 2 * value[i]`的时候是链两个不同的数字而不是一个数。

红黑树的插入和查找都是`O(logN)`，然后插N次，查N次，所以是`O(2NlogN)` 应该还是上面一种解法要好一些。

我用的是`std::unordered_map`来做的，如果从Abstract Data Type的角度来说，这道题就是`O(N)`.


