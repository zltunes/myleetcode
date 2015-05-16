044.Wildcard Matching
===========================
题目链接：[Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)

> Implement wildcard pattern matching with support for '?' and '*'.

> ```
> '?' Matches any single character.
> '*' Matches any sequence of characters (including the empty sequence).

> The matching should cover the entire input string (not partial).

> The function prototype should be:
bool isMatch(const char *s, const char *p)

> Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
```

初看题目，感觉除了符号不同之外，要求几乎和[Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)一样，果断修改了**一个字符**后提交，然后就果断错了。

显然没有这么简单，但是如果通过了**Regular Expression Matching**之后，显然应该也没有**hard**的难度了。

###读懂题意

关键在于你要把**Widcard**和**Regular Expression**的区别搞懂。除了在**字符**上有区别，一个使用**'?'**，一个使用**'.'**。另一个真正影响到算法本身的是他们对另一个符号**'*'**的不同理解。

在之前做过的正则表达式的匹配中，**'*'**作为一个辅助表达有[0,n]个被修饰字符的表达式，那么他之前的必须有一个被修饰的字符，也就是说，**'*'和被修饰字符是一个整体，不能分开**。

而在**Wildcard Matching**中，**'*'**，作为一个独立的存在。他并不与其他任何字符组合，他本身的意思就是一个任意字符的[0,n]个重复。其实这种方式可以大大简化非递归逻辑的编写，所以接下来，我就给大家分享两个我的解答。

###递归（类似正则表达式匹配）

思路和正则表达式的匹配完全一样，代码改动也非常少。这里仅有两点需要**额外注意**。

1. 当我们遇到连续的**'*'**时，这些连续的**'*'**的效果其实是一样的，我们并不需要去考虑每一个，因为他们和一个**'*'**的效果是一样的。
2. 当我们通过**'*'**匹配完最后一个字符的时候，我们还要匹配如果这个**'*'**将最后一个字符也吃掉的情况，因为可能当前的**'*'**也是**pattern**串的最后一个字符，我们不能漏掉这样一个**matching**。

```cpp
bool isMatch_recursive(const char *s, const char *p) {
    if(*p == 0) return (*s == 0);
    if(*p == '*') {
        while(*(p + 1) == '*') ++p;
        while(*s != 0) {
            if(isMatch(s, p + 1))
                return true;
            s++;
        }
        return isMatch(s, p + 1);
    }
    else {
        if(*s != 0 && (*s == *p || *p == '?')) {
            return isMatch(s + 1, p + 1);
        }
    }
    return false;
}
```

###非递归
犹豫**'*'**属性的意义简化，通过顺序的迭代判断来完成这一匹配过程。犹豫迭代的过程中肯定存在回溯，而回溯的时候，两个串的位置都需要回溯，也就是说，我们需要两个指针来维护这一过程。

- 在遇到正常的字符时，不需要过多思考，因为后面的字符和当前字符的匹配毫不相关。
- 当遇到**'*'**时，我们需要记下**pattern**的这一位置，和**string**的开始匹配位置。因为之后的匹配一旦不成功我们就需要考虑多**吞**一个字符的情况，直到所有的匹配可以成功完成，那么记录回溯的位置就是必要的。
- 当我们遇到不能匹配的情况，也就是上述两种情况均为发生，那么我们就要考虑回溯了，如果当前的位置已经不能再吃掉字符，既**string**已经被吃到了末尾，那么匹配失败，不然的话，我们就再多吃一个字符试一下。

最后再将末尾多余的**'*'**去掉，如果两串均达到末尾，则两串匹配。

讲到这里，肯定会有人问这样一个问题。如果后面那个**'*'**，把前面的**'*'**的回溯信息覆盖了，如果后面匹配不上，该怎么办？

结果是如果出现这种情况，那么 该字符串一定不能匹配。

但是这个问题的证明我还没有想通，而网上的资料也相对较少，如果能够理解的同学希望能在博客中和我交流。

```cpp
bool isMatch(const char *s, const char *p) {
    const char *record_s, *star;
    record_s = NULL;
    star = NULL;
    while(*s != 0) {
        if(*s == *p || *p == '?') {
            ++s, ++p;
        }
        else if(*p == '*') {
            star = p;
            record_s = s;
            ++p;
        }
        else if(star != NULL) {
            p = star + 1;
            s = record_s + 1;
            ++record_s;
        }
        else
            return false;
    }
    while(*p == '*') ++p;
    return *p == 0;
}
```
