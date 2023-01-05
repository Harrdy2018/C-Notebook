### jar包里面替换class
```sh
# 解压jar包，执行之后包含生成的jar包原件
jar -xvf sohu-common-1.0.3.jar

# 找到要替换的class文件，直接覆盖替换掉，要保证不破环原有的目录结构
cp New.class com/haha/model/New.class

# 保证执行命令的文件夹中尽量没有其他不必要的文件
jar -cfM0 sohu-common-1.0.3.jar ./
```