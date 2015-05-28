003.Longest Substring Without Repeating Characters
===========================
> Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

其实这道题现在想想还挺简单的，为什么当时做的时候就觉得很复杂呢。

如果出现重复就只有一种情况就是找到前面一次出现的位置，然后从那里开始搜索，如果用两个`index`这道题就会变得非常简单。一个`i`表示最前，一个`j`表示最后，如果不出现重复的则`j`一直向后，而当出现重复的时候，`i`找到`j`出现重复的那一个然后放到他后面就行了。需要统计`max_length`就只会出现在两个时间点，一个是最后，一个是每当出现重复的时候。

我第一次的做法是记录每一个值的位置，然后其实没有必要，因为每一次都是一旦出现重复就会做修改i的操作，而那些需要从已出现列表中移除的就是你需要找到的那个位置的前面那些，所以顺序遍历就好啦。


