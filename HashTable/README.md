## HashTable
***哈希表的实现比较简单，难点在于hash函数的实现***
### leetcode 705 设计哈希集合
```c
哈希表的两个关键:
一、哈希函数的设计
二、哈希搜索的设计

牺牲内存空间，换取搜索时间
内存给的刚刚好，那么搜索时间增加
如果hash表没有删除操作，那么搜索时间又可以精简

不使用任何内建的哈希表库设计一个哈希集合
具体地说，你的设计应该包含以下的功能
add(value)：向哈希集合中插入一个值。
contains(value) ：返回哈希集合中是否存在这个值。
remove(value)：将给定值从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
示例:
MyHashSet hashSet = new MyHashSet();
hashSet.add(1);         
hashSet.add(2);         
hashSet.contains(1);    // 返回 true
hashSet.contains(3);    // 返回 false (未找到)
hashSet.add(2);          
hashSet.contains(2);    // 返回 true
hashSet.remove(2);          
hashSet.contains(2);    // 返回  false (已经被删除)
注意：
所有的值都在 [1, 1000000]的范围内。
操作的总数目在[1, 10000]范围内。
不要使用内建的哈希集合库。
```
