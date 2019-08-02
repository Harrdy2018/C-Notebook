## Git知识点
### 状态符号
* 红色?? 新建的文件。表示当前文件在工作区，还没有add进暂存区
* 红色M  表示暂存区的文件已经修改了
* 淡蓝色M 表示暂存区修改的文件已经进行add操作了
* 淡蓝色A 新建的文件已经进行add操作进了暂存区
***
### 其他问题
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
将暂存区储存起来
  git stash push -m "message"
  git stash save "message" 执行存储时，添加备注，方便查找，只有git stash 也要可以的，但查找时不方便识别。
  push方式可以指定路径，git stash push 目录/文件名 ,即使save方式指定路径，也是储存所有修改的文件
如何打补丁？
  将暂存区与本地仓的差异存在test.patch中
  git diff > test.patch
  验证补丁是否可用？验证补丁的时候，如果有的补丁你已经修改了，会出错，可以删除已经修改的补丁的内容。
  git apply --check test.patch
  应用补丁?
  git apply test.patch
修改了代码，又突然要更新代码？
  git stash save
  git pull
  git stash pop
常用git stash命令:
（1）git stash save "save message"
（2）git stash list 
（3）git stash show 
（4）git stash pop ：命令恢复之前缓存的工作目录，将缓存堆栈中的对应stash删除，并将对应修改应用到当前的工作目录下
（5）git stash drop stash@{$num} ：丢弃stash@{$num}存储，从列表中删除这个存储
（6）git stash clear ：删除所有缓存的stash
```