## Git知识点
### 状态符号
* 红色?? 新建的文件。表示当前文件在工作区，还没有add进暂存区
* 红色M  表示暂存区的文件已经修改了
* 红色UU 表示工作区冲突的文件，即都修改了的文件
* 淡蓝色M 表示暂存区修改的文件已经进行add操作了
* 淡蓝色A 新建的文件已经进行add操作进了暂存区
***
### 各种撤销
* checkout
```
checkout适合我们在暂存区修改之后的文件，这样的文件一旦被修改，就到达了工作区，但是没有进行add操作
git checkout file.fix 撤销单个文件的修改
git checkout .        撤销所有文件的修改，会递归目录
```
* reset 有时候，进行了错误的提交，但是还没有push到远程分支，想要撤销本次提交，可以使用git reset –-soft/hard命令
```
git reset --soft 版本号
回退到某个版本。但是错误提交的版本会在暂存区体现，错误版本之后的新建的文件，修改的文件都不会被冲刷掉
git reset --hard 版本号
回退到某个版本。但是错误提交的版本以及，错误版本提交后修改的文件都会被冲刷掉，错误版本之后的新建的文件没事
```
* git push origin --force
```
强推，什么叫强推？
情形一：本地仓超于远程仓，正常push即可；
情形二：远程仓超于本地仓，强推即可，这样会以本地仓为主，远程仓上会删除所有超越本地仓的提交；
情形三：远程仓之前的某个版本超于本地仓之前的某个版本，强推即可，同样这样会以本地仓为主，远程仓上会删除所有超越本地仓的提交；
```
* git revert -n 版本号
```
git revert是用于“反做”某一个版本，以达到撤销该版本的修改的目的。比如，我们commit了三个版本（版本一、版本二、 版本三），
突然发现版本二不行（如：有bug），想要撤销版本二，但又不想影响撤销版本三的提交，就可以用 git revert 命令来反做版本二，
生成新的版本四，这个版本四里会保留版本三的东西，但撤销了版本二的东西。
重做版本步骤：
git revert -n 版本号  对此版本反做，将此版本的提交全部退回到暂存区，但是git log中的记录不会回退，不会变。
修改错误版本的内容
git add *
git commit -m "revert a haha" 这样会在git log后面新加一个commit记录
```
### 更新本地仓问题
* git pull=git fetch origin + git merge
```
如果更新成功，更新添加的内容自动加到本地仓里面去了，不存在修改的问题。

-----------产生冲突的条件，修改了同一文件的同一部分-------------------
如果有冲突，在工作区会出现文件状态为红色UU的冲突文件，这个就是冲突文件，他的意思是both modified
先根据情况更改冲突的文件，
git add *
文件状态变为淡蓝色的M
git commit -m "fix conflict"
此时更新并解决冲突才算完成

-----------git自己可以解决的冲突，修改了同一文件的不同一部分-------------------
解决方法git pull=======git fetch origin+git merge
第一步：git fetch origin  可以正常的
第二步：git merge         弹出要你写你为什么要merge
*****************************************************************************
# Please enter a commit message to explain why this merge is necessary,
# especially if it merges an updated upstream into a topic branch.
#
# Lines starting with '#' will be ignored, and an empty message aborts
# the commit.
************************************************************************************
第三步：
Auto-merging 冲突文件
Merge made by the 'recursive' strategy.
最后状态查看：git log
相当于提交了两次，第一次提一个update 冲突文件(远程仓代码更新到工作区)，第二个进行自动的merge
```
### 查看提交历史
* git log
* git log -2     加上 -2 来仅显示最近两次提交
* git log -p -2  一个常用的选项是 -p，用来显示每次提交的内容差异。 你也可以加上 -2 来仅显示最近两次提交
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