typedef int SElemType;
typedef struct tagStack{
    SElemType *base; /* 栈底指针 */
    SElemType *top;  /* 栈顶指针 */
    int capacity;    /* 栈的容量 */
}Stack;

typedef enum tagMyBool{
  my_false=0,
  my_true=1
}MyBool;

Stack *InitStack(int size);
void DestroyStack(Stack *obj);
void ClearStack(Stack *obj);
void TopEleOfStack(Stack *obj,SElemType *ele);
void TraverseStack(Stack *obj);
int LengthOfStack(Stack *obj);
MyBool IsFullStack(Stack *obj);
MyBool IsEmptyStack(Stack *obj);
MyBool PushStack(Stack *obj,SElemType ele);
MyBool PopStack(Stack *obj,SElemType *ele);