## uniq 去重复
```
Filter adjacent matching lines from INPUT (or standard input),writing to OUTPUT (or standard output).
  -c, --count           prefix lines by the number of occurrences
  -d, --repeated        only print duplicate lines, one for each group
  -D, --all-repeated[=METHOD]  print all duplicate lines
                          groups can be delimited with an empty line
                          METHOD={none(default),prepend,separate}
  -f, --skip-fields=N   avoid comparing the first N fields
      --group[=METHOD]  show all items, separating groups with an empty line
                          METHOD={separate(default),prepend,append,both}
  -i, --ignore-case     ignore differences in case when comparing
  -s, --skip-chars=N    avoid comparing the first N characters
  -u, --unique          only print unique lines
  -z, --zero-terminated  end lines with 0 byte, not newline
  -w, --check-chars=N   compare no more than N characters in lines
      --help     display this help and exit
      --version  output version information and exit
```
* 去掉连续的重复行
```shell
[harrdy@localhost Desktop]$ cat ip 
192.168.1.2
192.168.1.8
192.168.1.3
192.168.1.3
192.168.1.9
192.168.1.8
192.168.1.8
192.168.1.0
192.168.1.3
[harrdy@localhost Desktop]$ cat ip | uniq
192.168.1.2
192.168.1.8
192.168.1.3
192.168.1.9
192.168.1.8
192.168.1.0
192.168.1.3
```
* --unique 只保留唯一
```shell
[harrdy@localhost Desktop]$ cat ip | uniq --unique
192.168.1.2
192.168.1.8
192.168.1.9
192.168.1.0
192.168.1.3
```
* --count：计算每行出现的次数
```shell
[harrdy@localhost Desktop]$ cat ip | uniq --count
      1 192.168.1.2
      1 192.168.1.8
      2 192.168.1.3
      1 192.168.1.9
      2 192.168.1.8
      1 192.168.1.0
      1 192.168.1.3
[harrdy@localhost Desktop]$ cat --number ip
     1	192.168.1.2
     2	192.168.1.8
     3	192.168.1.3
     4	192.168.1.3
     5	192.168.1.9
     6	192.168.1.8
     7	192.168.1.8
     8	192.168.1.0
     9	192.168.1.3
```
* 可以用sort命令排序后，再去重复，得到的结果也是唯一的
```shell
[harrdy@localhost Desktop]$ sort ip | uniq --count
      1 192.168.1.0
      1 192.168.1.2
      3 192.168.1.3
      3 192.168.1.8
      1 192.168.1.9
```
* --repeated 只显示重复的行
```shell
[harrdy@localhost Desktop]$ cat ip | uniq --repeated
192.168.1.3
192.168.1.8
```