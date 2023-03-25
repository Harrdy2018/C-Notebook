## xargs
```shell
$ echo "11@22@33" | xargs --delimiter=@
11 22 33

## 使用 --max-args=3 之后表示一次传递给xargs后面的命令是3个参数，因为一共有10个参数，所以要执行4次，才能将参数用完
$ echo '11@22@33@44@55@66@77@88@99@00' | xargs --delimiter=@ --max-args=3
11 22 33
44 55 66
77 88 99
00

## 使用 --max-args=4 之后表示一次传递给xargs后面的命令是4个参数，因为一共有10个参数，所以要执行3次，才能将参数用完
$ echo '11@22@33@44@55@66@77@88@99@00' | xargs --delimiter=@ --max-args=4
11 22 33 44
55 66 77 88
99 00

## 这里-E实际上有搜索的作用，表示只取xargs读到的命令行参数前面的某些部分给命令执行。
$ echo '11 22 33' | xargs -E 33
11 22
$ echo '11 22 33' | xargs -E 22
11


## -i命令的使用
$ touch logdir/{1..100}.log
$ ls logdir/
### 重命名备份的时候在每个传递过来的文件名加上后缀.bak
### 为什么将“-i”选项划分在分批选项里面，因为它默认一个段就是一个批，每次传递一个批就是传递一个段到指定大括号{}位上
$ ls logdir/ | xargs -i mv ./logdir/{} ./logdir/{}.bak


## 想将数字1-10没三个数显示在start和end之间
$ echo {1..10} | xargs -n 3 | xargs -i echo "start {} end"
start 1 2 3 end
start 4 5 6 end
start 7 8 9 end
start 10 end
$ echo {1..10} | xargs --max-args=3 | xargs -i echo "start {} end"
start 1 2 3 end
start 4 5 6 end
start 7 8 9 end
start 10 end


### 调试命令
## -p 运行命令前提示，按"ENTER"会继续
$ echo '11@22@33@44@55@66@77@88@99@00' | xargs --delimiter=@ --max-args=3 -p
echo 11 22 33 ?...
echo 44 55 66 ?...
echo 77 88 99 ?...
echo 00
 ?...

## -t 选项是在每次执行xargs后面的命令都会先在stderr上打印一遍命令的执行过程然后才正式执行
$ echo '11@22@33@44@55@66@77@88@99@00' | xargs --delimiter=@ --max-args=3 -t
echo 11 22 33
11 22 33
echo 44 55 66
44 55 66
echo 77 88 99
77 88 99
echo 00
00

### xargs+find的使用 xargs原本就是为find而开发的。
## find命令将匹配到的文件传递给xargs命令，而xargs命令每次只获取一部分而不是全部。不像-exec选项那样，这样就可以先处理最先获取的一部分文件，然后是下一批
$ find logdir/ -name "*.bak" | xargs -n 10 grep "kang"
logdir/1.log.bak:kang
logdir/17.log.bak:qhwedhq  kang
logdir/17.log.bak:kang 2qe2
logdir/17.log.bak:  kang kang
logdir/6.log.bak:kangv qweq
```
