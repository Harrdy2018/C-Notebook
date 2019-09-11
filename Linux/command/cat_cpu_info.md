## 查看 CPU 信息
* 查看 CPU 个数
```shell
[harrdy@localhost Desktop]$ cat /proc/cpuinfo | grep 'physical id'
physical id	: 0
physical id	: 0
physical id	: 1
physical id	: 1
[harrdy@localhost Desktop]$ cat /proc/cpuinfo | grep 'physical id' | uniq | wc --lines
2
```
* 查看 CPU 核数
```shell
[harrdy@localhost Desktop]$ cat /proc/cpuinfo | grep 'cpu cores'
cpu cores	: 2
cpu cores	: 2
cpu cores	: 2
cpu cores	: 2
[harrdy@localhost Desktop]$ cat /proc/cpuinfo | grep 'cpu cores' | uniq
cpu cores	: 2
```
* 查看 CPU 型号
```shell
[harrdy@localhost Desktop]$ cat /proc/cpuinfo | grep 'model name'
model name	: Intel(R) Core(TM) i5-8400 CPU @ 2.80GHz
model name	: Intel(R) Core(TM) i5-8400 CPU @ 2.80GHz
model name	: Intel(R) Core(TM) i5-8400 CPU @ 2.80GHz
model name	: Intel(R) Core(TM) i5-8400 CPU @ 2.80GHz
[harrdy@localhost Desktop]$ cat /proc/cpuinfo | grep 'model name' | uniq
model name	: Intel(R) Core(TM) i5-8400 CPU @ 2.80GHz
```