### ```with open ... as ```
```python
import os
# with open ... as 处理文件方式会自动关闭流
# 写模式 ab 以二进制格式打开一个文件进行追加；如果文件不存在，新创建
with open(os.path.join("H:\\development\\learn-python\\", "d.txt"),'ab') as f1:
    f1.write(bytes("aAbBcC 123", encoding = "utf8"))

# 读模式 rb 以二进制格式打开一个文件只读
with open(os.path.join("H:\\development\\learn-python\\", "d.txt"),'rb') as f1:
    print(f1.read())
```
