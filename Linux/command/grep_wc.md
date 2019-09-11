## grep
* 在每一个文件中搜索字符串
* -i参数 忽略大小写
```linux
l50004174@NKGY6L500041741 MINGW64 ~/Desktop/test
$ cat test
vim abd
VIM

l50004174@NKGY6L500041741 MINGW64 ~/Desktop/test
$ grep "vim" test
vim abd

l50004174@NKGY6L500041741 MINGW64 ~/Desktop/test
$ grep -i "vim" test
vim abd
VIM

l50004174@NKGY6L500041741 MINGW64 ~/Desktop/test
$ grep vim test
vim abd

l50004174@NKGY6L500041741 MINGW64 ~/Desktop/test
$ cat test | grep vim
vim abd
```
## wc
* word count 单词统计
* -c 打印字节数
* -m 打印字符数
* -l 打印行数
* -w 打印单词数
***
***一般情况下字节数等于字符数，因为char类型一个字节***
```linux
l50004174@NKGY6L500041741 MINGW64 ~/Desktop/test
$ wc -c test
12 test

l50004174@NKGY6L500041741 MINGW64 ~/Desktop/test
$ wc -m test
12 test

l50004174@NKGY6L500041741 MINGW64 ~/Desktop/test
$ wc -l test
2 test

l50004174@NKGY6L500041741 MINGW64 ~/Desktop/test
$ wc -w test
3 test
```
### 工作中统计自己的工作量
* cat test | grep vim | wc -l
