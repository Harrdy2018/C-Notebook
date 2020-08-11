### 语句
#### switch语句要有default分支
* 保证在遗漏case的情况下，有一个缺省的处理行为
* switch的条件变量是枚举类型，并且case覆盖了所有取值，则加上default多余
```c
// 现在编译器可以检查这种行为，有warning提示(不知道真的假的)
enum Color {
    RED,
    BLUE
};
int main(int argc, char *argv[])
{
    enum Color color;
    color = 2;
    switch (color) {
        case RED:
            printf("RED");
            break;
        case BLUE:
            printf("BLUE");
            break;
    }
    return 0;
}
```
