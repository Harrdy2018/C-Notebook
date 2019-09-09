* 相同的字符串合为一个列表
* "abcd" "acbd" "abdc" 为相同的字符串
```py
info=["abcd","zesa","saze","abc","pqrst","cdab","bacd"]
def test(seq1,seq2):
    if(len(seq1)!=len(seq2)):
        return 0
    for x in seq1:
        if x not in seq2:
            return 0
    return 1
num=len(info)
rr=[]
while(len(info) != 0):
    for i in range(0,len(info)):
        res=[info[i]]
        for j in range(i+1,len(info)):
            if(test(info[i],info[j])):
                res.append(info[j])
        if(len(res)!=1):
            rr.append(res)
        for item in res:
            info.remove(item)
        break
print(rr)
```
```shell
$ py test.py
[['abcd', 'cdab', 'bacd'], ['zesa', 'saze']]
```