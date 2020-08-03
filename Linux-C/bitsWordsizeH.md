## include <bits/wordsize.h>
### 字长的宏定义
* ifdef && if defined 的区别后者可以组成复杂的预编译条件
```c
int main(int argc, char *argv[])
{
    #if defined __x86_64__ && !defined __ILP32__
	#define __WORDSIZE 64
	printf("%s\n", "CPU 字长64位");//CPU 字长64位
	#else
	#define __WORDSIZE 32
	printf("%s\n", "CPU 字长32位");
	#endif

	return 0;
}
```
* 补充字长(数据)模型---编译器用来确定基本数据类型长度
```
LP64，ILP64，LLP64是64位平台上的字长模型，ILP32和LP32是32位平台上的字长模型
根据命名，L-long，P-pointer，LL-longlong，64-上述类型字长64，32-上述类型字长32

type              LP32      ILP32          LP64        ILP64          LLP64
char                8          8             8            8              8
short              16         16            16           16             16
int                16         32            32           64             32
long               32         32            64           64             32
long long          64         64            64           64             64
pointer            32         32            64           64             64
```
