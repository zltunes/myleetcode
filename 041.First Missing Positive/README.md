041.First Missing Positive
===========================
题目链接：[First Missing Positive](https://leetcode.com/problems/first-missing-positive/)

> Given an unsorted integer array, find the first missing positive integer.
> 
> For example,
>
> Given [1,2,0] return 3,
>
> and [3,4,-1,1] return 2.
> 
> Your algorithm should run in O(n) time and uses constant space.

题目的意思是在一组无序的数中，找到一个第一个没有出现的正整数。题目要求最好能够用`O(n)`的时间复杂度和`O(1)`的空间复杂度。

本身这道题并不难，如果用**hash**的话，也可以很容易的到达`O(n)`的时间复杂度，难点在于如何只用常数时间来接这道题。

经过思考，有限个的临时变量对题目的帮助都不是很大，所以我决定从本身给出的数组入手。

###调换的解法

考虑让每个位置放对应的数字，如果我们能够调换顺序，并且将出现的数字在可以放置的情况下，全部放到合理的位置，那么在最后，我们只需要遍历一边数组就可以把第一个没有出现的正整数找出来，既如果该位置`i`，`A[i] != i + 1`，那么就返回这个数。

所以我们现在需要解决的就是怎么将可以放的数字都放好的这个问题。考虑以下三点：

- 将当前位置上的数字`i`，让他去应该出现的位置，既使得`A[A[i] - 1] = A[i]`
- 尽量保证当前位置的数字`i`，使得`A[i] == i + 1`
- 如果出现当前数字无关紧要，比如`A[i] <= 0`，或者`A[i] - 1 >= n`，那么我们无法判断因该讲他们移动到哪儿，就放在这里，这种位置就是可能出现**First Missing Positive**的地方。

有了上面思路，基本上算法的框架爷就出来了，我们可以遍历每一个位置，然后根据上述策略进行位置变换，即可保证，出现的数字，并且能够移动到相应位置的数字都放到了该放的位置。

```cpp
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        if(n == 0 || A == NULL) return 1;
        for(int i = 0; i < n; ++i) {
            while(A[i] != i + 1) {
                if(A[i] - 1 >= n || A[i] <= 0 || A[i] == A[A[i] - 1]) break;
                swap(A[i], A[A[i] - 1]);
            }
        }
        for(int i = 0; i < n; ++i) {
            if(A[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};
```
