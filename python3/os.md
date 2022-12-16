###
#### ```subprocess 阻塞```
```python
import subprocess

# 参数shell默认为False
subprocess.call(['ls','-l'], shell=False)
# 在shell设置为True时，可以直接传字符串:
subprocess.call('ls -l', shell=True)

# 以windows上面的记事本程序为例 C:\Windows\System32\notepad.exe
notepadPath = 'C:/Windows/System32/notepad.exe'
fileName = "a.txt"
subprocess.call([notepadPath, fileName], shell=False)
print("a.txt open success")
fileNameB = "b.txt"
openFile = 'C:/Windows/System32/notepad.exe {}'.format(fileNameB)
subprocess.call(openFile, shell=True)
print("b.txt open success")
```
####
```python
import os
# Linux用的是/分隔符，而Windows才用的是\
currentDir = os.getcwd()
print(currentDir)
# H:\development\learn-python
# os.path.join()的功能只是起到连接文件的作用，而不能生成文件
filePath = os.path.join("H:\\development\\learn-python\\", "test.txt")
print("filePath "+ filePath)
# filePath H:\development\learn-python\test.txt

if os.path.exists(os.path.join("H:\\development\\learn-python\\", "dev")):
    # 删除目录
    os.remove(os.path.join("H:\\development\\learn-python\\", "dev"))
else:
    # 创建 H:\\development\\learn-python\\dev目录
    os.mkdir(os.path.join("H:\\development\\learn-python\\", "dev"))

# 判断文件或文件夹是否存在
print(os.path.exists('user.py')) # False
print(os.path.exists('a.txt')) # True
print(os.path.exists(os.path.join("H:\\development\\learn-python\\", "dev"))) # True
```