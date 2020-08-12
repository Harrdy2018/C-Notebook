### realpath
* char *realpath(const char *path, char *resolved_path)
* realpath()用来将参数path所指的相对路径转换成绝对路径后存于参数resolved_path所指的字符串数组或指针中
```c
#include <stdio.h>
#include <limits.h> /* PATH_MAX */
#include <stdlib.h> /* realpath */
int main(int argc, char *argv[])
{
    printf("%d\n", PATH_MAX); // 4096
    char realPath[PATH_MAX + 1] = {0};
    char *realPointer = realpath("./test.txt", realPath);
    printf("%s\n", realPath);
    return 0;
}
```
