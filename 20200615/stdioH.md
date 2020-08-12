### sprintf
* sprintf(buffer, "%d", 123456);
* sprintf的作用是将一个格式化的字符串输出到一个目的字符串中。执行后buffer指向字符串"123456"
```c
int main(int argc, char *argv[])
{
    char buffer[10];
    char *a = "1234";
    char *b = "5678";
    int num = sprintf(buffer, "%s %s", a, b);
    printf("%s %d\n", buffer, num);//1234 5678    9
    return 0;
}
```
### snprintf
* snprintf(buffer, 3, "%d", 12345);
* n 表示拷贝的字节数
* 如果格式化后的字符串长度小于等于 size，全部带过去，并给其后添加一个字符串结束符 \0；
* 如果格式化后的字符串长度大于 size，超过 size 的部分会被截断，只将其中的 (size-1) 个字符复制到 str 中，并给其后添加一个字符串结束符 \0，
* 返回值为欲写入的字符串长度。
```c
int main(int argc, char *argv[])
{
    char buffer[10];
    char *str = "abcdefg";
    int num = snprintf(buffer, 2, "%s", str);
    printf("%s %d\n", buffer, num);//a 7
    num = snprintf(buffer, 8, "%s", str);
    printf("%s %d\n", buffer, num);//abcdefg 7
    num = snprintf(buffer, 9, "%s", str);
    printf("%s %d\n", buffer, num);//abcdefg 7
    return 0;
}
```
### fprintf
* fprinf(stream, "%s", "we");
* 发送格式化字符串到流 stream 中
```c
#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *fp = fopen("./test.txt", "w+");
    int num = fprintf(fp,"%s %s %s %d", "we", "are", "in", 2020);
    printf("%d\n", num); // 14
    fclose(fp);
    return 0;
}
```
