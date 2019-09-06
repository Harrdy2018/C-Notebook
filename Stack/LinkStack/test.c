//中缀表达式转后缀表达式
/**
 * 中缀表达式 9+(3-1)*3+10/2
 * 后缀表达式 931-3*+102/+
*/
#include <stdio.h>
#include <string.h>
#include "Stack.h"
int Priority(char ch){
    switch(ch){
        case '(': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default : return 0;
    }
}
int cal(int down,char ope,int up){
    if(ope=='+'){
        return down+up;
    }
     if(ope=='-'){
        return down-up;
    }
     if(ope=='*'){
        return down*up;
    }
     if(ope=='/'){
        return down/up;
    }
}
my_bool isSymbol(char chr){
    return chr=='+' || chr=='-' || chr=='*' || chr=='/' || chr=='(' || chr==')';
}
/**
 * 判断一个表达式有效的操作数和操作符的数目
 * 操作符的数目用numSign带入
 * 虽然括号也算操作符，但是后缀表达式是不需要括号的
*/
int numEffective(char *str,int *numSign){
    int len=strlen(str);
    char *slow=str;
    char *fast=str;
    char *end=str+len-1;
    int count=0;
    int count_sign=0;
    while(fast<=end){
        if(isSymbol(*fast) && *fast != '(' && *fast != ')'){
            count_sign++;
            if(fast==slow){
                count++;
                fast++;
                slow=fast;
            }else{
                count=count+2;
                fast++;
                slow=fast;
            }
        }else{
            //如果最后一个字符不是符号  1+2
            if(fast==end){
                count++;
            }
            fast++;
        }
    }
    *numSign=count_sign;
    return count;
}
/**
 * 中缀表达式转后缀表达式
 * 中缀表达式全部存在 expression[]中，其中操作符用0表示
 * 真实的操作符用于存在 opt[] 里面
*/
void infix_to_suffix(char *str,int expression[],int numEffect,char opt[],int numSign,LinkStack *obj_opt){
    int i=0;
    int tmp=0;
    int index_expre=0;
    int index_sign=0;
    while(str[i] != '\0'){     
        if(!isSymbol(str[i])){
            tmp=tmp*10+str[i]-'0';
            i++;
            //1+2  2的时候，它的下一个为空，直接退出
            if(isSymbol(str[i]) || str[i] == '\0'){
                expression[index_expre]=tmp;
                index_expre++;
                tmp=0;
                if(str[i]=='\0') break;
            }
        }
        //操作符进栈和出栈
        else{
            //当栈为空时，直接进栈
            if(isEmpty(obj_opt))
            {
                Push(obj_opt,str[i]);
                i++;
                continue;
            }
            //操作符进来的时候，栈中有内容
            else{
                //获取当前栈顶操作符
                int ele;
                GetTop(obj_opt,&ele);
                /**
                 * 栈不为空的时候，进栈情况
                 * 当前操作符的优先级>栈顶操作符优先级,可以压进来
                 * 栈顶是 '(' ,但是当前操作符号不是 ')' 都可以进栈
                */
                if( ele=='(' && str[i] != ')' || Priority(str[i])>Priority(ele)){
                    Push(obj_opt,str[i]);
                    i++;
                    continue;
                }
                //栈顶为'(',表达式为')',直接出栈，不用考虑
                if(ele=='(' && str[i]==')'){
                    int e;
                    Pop(obj_opt,&e);
                    i++;
                    continue;
                }
                //表达式为')',匹配括号出栈
                if(ele != '(' && str[i] ==')'){
                    while(ele != '('){
                        int pope=0;
                        Pop(obj_opt,&pope);
                        expression[index_expre]=0;
                        opt[index_sign]=(char)pope;
                        index_expre++;
                        index_sign++;
                        GetTop(obj_opt,&ele);
                    }
                    int pope=0;
                    Pop(obj_opt,&pope);
                    i++;
                    continue;
                }
                /**
                 * 最后这种情况
                 * 当前操作符的优先级 <= 栈顶操作符优先级,栈顶元素非'(',表达式非')'
                 * 可以解释为什么要将 '(' 优先级设置为最高
                 * 一直弹出直到，可以压进去，然后就将当前操作符压进去
                */
                if(Priority(str[i])<=Priority(ele)){
                    int popf=0;
                    while(!isEmpty(obj_opt)){
                        Pop(obj_opt,&popf);
                        expression[index_expre]=0;
                        opt[index_sign]=(char)popf;
                        index_expre++;
                        index_sign++;
                        GetTop(obj_opt,&ele);                        
                        if(ele == '('){
                            break;
                        }
                        if(Priority(str[i])>Priority(ele)){
                            Push(obj_opt,str[i]);
                            i++;
                            break;
                        }
                    }
                    Push(obj_opt,str[i]);
                    i++;
                    continue;
                }
            }
        }   
    }
    while(!isEmpty(obj_opt)){
        int abc=0;
        Pop(obj_opt,&abc);
        expression[index_expre]=0;
        opt[index_sign]=(char)abc;
        index_expre++;
        index_sign++;
    }
}
int calucate(int expression[],int numEffect,char opt[],int numSign,LinkStack *obj_num){
    int count=0;
    int res=0;
    for(int i=0;i<numEffect;i++){
        if(expression[i] != 0){
            Push(obj_num,expression[i]);
        }else{
            int top=0;
            Pop(obj_num,&top);
            int down=0;
            Pop(obj_num,&down);
            res=cal(down,opt[count],top);
            Push(obj_num,res);
            count++;
        }
    }
    return res;
}
int main(void){
    //char *str="9+(3-1)*3+10/2";
    //char *str="(2*(1-3)+56)/3";
    LinkStack *obj_opt=InitLinkStack();
    char str[100];
    scanf("%s",str);
    int tmp=0;
    int numSign=0;
    int num=numEffective(str,&numSign);
    printf("%d  %d\n",num,numSign);
    int expression[num];
    char opt[numSign];
    infix_to_suffix(str,expression,num,opt,numSign,obj_opt);
    //遍历表达式
    for(int i=0;i<num;i++){
        printf("%2d",expression[i]);
    }
    printf("\n");
    //遍历操作符1
    for(int i=0;i<numSign;i++){
        printf("%2c",opt[i]);
    }
    printf("\n");

    //计算
    LinkStack *obj_num=InitLinkStack();
    int res=calucate(expression,num,opt,numSign,obj_num);
    printf("%d\n",res);
    return 0;      
}