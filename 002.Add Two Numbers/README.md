002.Add Two Numbers
===========================
> You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

> Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
>
> Output: 7 -> 0 -> 8

一道list的题，主要考验细心吧。一般好习惯是把要新建的list先做一个dummynode，然后再把后继的node加到这个上面去。最后返回`dummy->next`。
我的做法是在两者都有的情况下，使用一个新的list作为return，把两者加完的值放新的list中。

讨论分为三种情形，前两种是对称的。就是当短的那个list加完之后，把新list的尾部接到长list的当前项。这里要注意，carry要过继，然后判断的时候以`iter->next`，不然回不了头。之后还要处理carry连续进位。

另一种情况就是正好都结束，这个比较简单，直接处理就可以了，有carry就最后再加一个node。


