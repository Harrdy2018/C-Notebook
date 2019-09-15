* 1~100求和运算
```shell
#! /bin/bash
sum=0
for i in {1..100}
do
sum=$(($i+$sum))
done
echo "sum is $[sum]"
```