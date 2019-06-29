#include <errno.h>
#include <stdarg.h>
#include "ourhdr.h"

static void 
err_doit(int,const char *,va_list);
void 
err_quit(const char *fmt,...){
  va_list ap;
  va_start(ap,fmt);
  err_doit(0,fmt,ap);
  va_end(ap);
  exit(1);
}
void 
err_sys(const char *fmt,...){
  va_list ap;
  va_start(ap,fmt);
  err_doit(1,fmt,ap);
  va_end(ap);
  exit(1);
}
/*
函数原型char *strerror(int __errnum);
参数错误号,通常就是errno,宏,返回错误号
返回错误描述信息的字符串

格式化输出
******sprintf******
int main(int argc,char *argv[]){
  char exam[80];
  sprintf(exam,"you are a bitch %s , %d","hahhaha",123);
  puts(exam);//you are a bitch hahhaha , 123
  return 0;
}
*******************
*******vsprintf****
使用参数列表,格式化输出到指定的字符串
#include <stdio.h>
#include <stdarg.h>
char buffer[80];
void testVsprintf(char *format,...){
  va_list valist;
  va_start(valist,format);
  vsprintf(buffer,format,valist);
  va_end(valist);
}
int main(int argc,char *argv[]){
  int i=23;
  float f=27.0;
  char str[50]="lukang";
  testVsprintf("%d %f %s",i,f,str);
  puts(buffer);//23 27.000000 lukang
  return 0;
}
******************************
*********fflush*************
刷新缓冲区,刷新缓冲流,如果参数为null,刷新所有流
fflush(stdin)的前世今生 
由Microsoft官方提供的MSDN 文档里也清楚地写着：
fflush on input stream is an extension to the C standard（fflush 操作输入流是对 C 标准的扩充，注意啊，是Extension！）
即C 标准中根本没有定义 fflush(stdin)，最新的C 11直接删去了曾经打擦边球的fflush(stdin)
******************************
*/
static void 
err_doit(int errnoflag,const char *fmt,va_list ap){
  int errno_save;
  char buf[MAXLINE];

  errno_save=errno;
  printf("打印出错误号:%d\n",errno);
  vsprintf(buf,fmt,ap);
  if(errnoflag){
    sprintf(buf+strlen(buf),": %s",strerror(errno_save));
  }
  strcat(buf,"\n");
  fflush(stdout);
  fputs(buf,stderr);
  fflush(NULL);
  return;
}
