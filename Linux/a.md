## 硬链接和软链接
* 创建文件
```linux
[harrdy@localhost Desktop]$ ll
total 0
drwxrwxr-x 2 harrdy harrdy 49 Aug 11 17:20 cDemo
[harrdy@localhost Desktop]$ touch myfile && echo "This is a plain text file." > myfile
[harrdy@localhost Desktop]$ ls -li
total 4
1390771 drwxrwxr-x 2 harrdy harrdy 49 Aug 11 17:20 cDemo
1390750 -rw-rw-r-- 1 harrdy harrdy 27 Aug 11 18:19 myfile
[harrdy@localhost Desktop]$ cat myfile 
This is a plain text file.
```
* 硬链接
```linux
[harrdy@localhost Desktop]$ ln myfile hard
[harrdy@localhost Desktop]$ ls -li
total 8
1390771 drwxrwxr-x 2 harrdy harrdy 49 Aug 11 17:20 cDemo
1390750 -rw-rw-r-- 2 harrdy harrdy 27 Aug 11 18:19 hard
1390750 -rw-rw-r-- 2 harrdy harrdy 27 Aug 11 18:19 myfile
```
```
在 ls 结果的最左边一列，是文件的 inode 值，你可以简单把它想成 C 语言中的指针。
它指向了物理硬盘的一个区块，事实上文件系统会维护一个引用计数，只要有文件指向这个区块，它就不会从硬盘上消失。
你也看到了，这两个文件就如同一个文件一样，inode 值相同，都指向同一个区块。
```
* 然后我们修改一下刚才创建的 hard 链接文件
```linux
[harrdy@localhost Desktop]$ echo "New line" >> hard
[harrdy@localhost Desktop]$ cat myfile 
This is a plain text file.
New line
```
* 软链接(符号链接)
```linux
[harrdy@localhost Desktop]$ ln -s myfile soft
[harrdy@localhost Desktop]$ ls -li
total 8
1390771 drwxrwxr-x 2 harrdy harrdy 49 Aug 11 17:20 cDemo
1390750 -rw-rw-r-- 2 harrdy harrdy 36 Aug 11 18:23 hard
1390750 -rw-rw-r-- 2 harrdy harrdy 36 Aug 11 18:23 myfile
 912472 lrwxrwxrwx 1 harrdy harrdy  6 Aug 11 18:25 soft -> myfile
```
***你会发现，这个软链接的 inode 竟然不一样啊，并且它的文件属性上也有一个 l 的 flag，这就说明它与之前我们创建的两个文件根本不是一个类型***
* delete myfile
```linux
[harrdy@localhost Desktop]$ rm myfile 
[harrdy@localhost Desktop]$ cat hard 
This is a plain text file.
New line
[harrdy@localhost Desktop]$ cat soft 
cat: soft: No such file or directory
```
```
之前的硬链接没有丝毫地影响，因为它 inode 所指向的区块由于有一个硬链接在指向它，所以这个区块仍然有效，并且可以访问到。
然而软链接的 inode 所指向的内容实际上是保存了一个绝对路径，当用户访问这个文件时，系统会自动将其替换成其所指的文件路径，然而这个文件已经被删除了，所以自然就会显示无法找到该文件了。
```
### Conclusion
* 硬链接： 与普通文件没什么不同，inode 都指向同一个文件在硬盘中的区块
* 软链接： 保存了其代表的文件的绝对路径，是另外一种文件，在硬盘上有独立的区块，访问时替换自身路径。