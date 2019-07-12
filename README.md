# C-Notebook
## 每天学一点C哈
### 数据结构与算法
* [ls命令的主要实现部分](./ls-Command)
* [线性表的实现](./SequenceList)
* [单链表的实现](./SingleLinkTable)
* [双链表的实现](./DoubleLinkTable)
* [排序](./Sort)
### 基础进阶
* [遍历二维数组](./a.md)
### Git知识点
```
本地仓和远程仓现在是同步的，我在本地仓删除base分支，怎么同步到远程仓去?
  git checkout master
  git branch --delete base
  git push origin :base
本地仓和远程仓现在是同步的，我在本地仓创建base分支，怎么同步到远程仓去?
  git checkout -b base
  如果在新分支上新建、编辑文件，你现在处于暂存区，只有在新分支上add,commit之后，这个文件才会到base分支上去；
  master分支只可以看到master分支的东西，其他分支可以看到master和自己分支上的东西。
  将创建的本地的base分支推送到origin
  git push origin base 
```
