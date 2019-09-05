#define MAXSIZE 5
#define SIZEINCREMENT 5
typedef int SElemType;
typedef struct my_stack{
    SElemType *data;
    int top;         /*用于栈顶指针*/
    int capacity;    /*栈的容量*/
}Stack;
typedef enum my_bool{
  my_false=0,my_true
}my_bool;
Stack *InitStack();
void DestroyStack(Stack *S);
void ClearStack(Stack *S);
void GetTop(Stack *S,SElemType *ele);
void TraverseStack(Stack *S);
int StackLength(Stack *S);
my_bool isFull(Stack *S);
my_bool isEmpty(Stack *S);
my_bool Push(Stack *S,SElemType ele);
my_bool Pop(Stack *S,SElemType *ele);