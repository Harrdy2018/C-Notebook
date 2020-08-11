### function-like macro
```c
#define ASSERT(x) do {\
    if (!x) {\
        printf("assertion failed %s: %d: %s\n", \
            __FILE__, __LINE__, #x);\
    }\
} while (0)
int main(int argc, char *argv[])
{
    int ret = 0;
    ASSERT(ret);
    return 0;
}
```
* 预处理后 #x 相当于把变量标记变成字符串
```c
int main(int argc, char *argv[])
{
    int ret = 0;
    do { if (!ret) { printf("assertion failed %s: %d: %s\n", "./main.c", 13, "ret"); }} while (0);
    return 0;
}
```
### 宏没有独立的作用域，跟控制流语句配合时，很容易出错
* 使用 do {...} while (0)
* Linux和其它代码库里的宏都用do/while(0)来包围执行逻辑，因为它能确保宏的行为总是相同的，而不管在调用代码中使用了多少分号和大括号。
```c
#define __set_task_state(tsk, state_value)  \
    do {                                    \
        (tsk)->state = (state_value);       \
    } while(0)
struct task {
    int state;
} mytask ={0};

int main(int argc, char *argv[])
{
    printf("the status of mytask is %d\n", (&mytask)->state);
    __set_task_state(&mytask, 1);
    printf("the status of mytask is %d\n", (&mytask)->state);
    return 0;
}
```
### 尽可能使用函数代替函数式宏
* 函数式宏缺乏类型检查，不如函数调用严格
* 函数式宏难以调试、难以打断点、不利于定位问题
```c
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
int Max (int a, int b)
{
    return a > b ? a : b;
}
int main(int argc, char *argv[])
{
    unsigned int a = 1;
    int b = -1;
    // 由于宏缺乏类型检查，MAX中的a和b全部升为unsigned
    printf("macro %u %d max %d\n", a, b, MAX(a,b));//-1
    printf("func %u %d max %d\n", a, b, Max(a,b));//1
    return 0;
}
```
* 函数没有上述缺点，但是函数相比宏，最大的劣势就是执行效率不高(增加函数调用的开销和编译器优化的难度)
* 内联函数来了：内联函数跟宏类似，也是在调用点展开，不同之处在于内联函数是在编译时展开
#### 内联函数兼具函数和宏的优点
* 内联函数/函数执行严格的类型检查
* 内联函数/函数的入参求值只会进行一次
* 内联函数就地展开，没有函数调用的开销
* 内联函数比函数优化的更好
