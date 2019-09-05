#define MAXSIZE 16
typedef int SElemType;
typedef struct my_stack{
    SElemType data[MAXSIZE];
    int top;         /*用于栈顶指针*/
}Stack;
typedef enum my_bool{
  my_false=0,my_true
}my_bool;
void InitStack(Stack *S);
void DestroyStack(Stack *S);
void ClearStack(Stack *S);
void GetTop(Stack *S,SElemType *ele);
void TraverseStack(Stack *S);
int StackLength(Stack *S);
my_bool isFull(Stack *S);
my_bool isEmpty(Stack *S);
my_bool Push(Stack *S,SElemType ele);
my_bool Pop(Stack *S,SElemType *ele);