#include <dirent.h>
#include "ourhdr.h"
int main(int argc,char *argv[]){
  /*
  DIR结构体,目录流对象数据类型,对于使用者来说,内部结构并不透明
  dp指针指向这个结构体
  */
  DIR *dp;
  /*
  dirent结构体,目录记录
  成员:
  unsigned short int d_reclen;
  unsigned char d_type;
  har d_name[256];	
  */
  struct dirent *dirp;
  if(argc != 2){
    err_quit("a single argument (the directory name) is required");
  }
  /*
  如果argc等于1 则argv[0]=程序名
  如果argc等于2 则argv[0]=程序名 argv[1]=后面你接的参数
  */
  printf("命令行参数的个数 %d \n",argc);
  printf("命令行参数列表 %s %s \n",argv[0],argv[1]);
  /*
  函数原型,DIR *opendir(const char *__name);
  参数目录名字,返回一个指向目录流的指针
  如果不能打开此目录,返回NULL
  */
  if((dp=opendir(argv[1]))==NULL){
    err_sys("can't open %s",argv[1]);
  }
  /*
  读目录
  函数原型,struct dirent *readdir(DIR *__dirp);
  参数DIRP
  返回指向目录记录的指针
  */
  while((dirp=readdir(dp))!=NULL){
    //d_reclen 这个结构体的大小length of this record
    //d_type文件类型,不是所有的系统支持
    printf("%p %d %c %s \n",dirp,dirp->d_reclen,dirp->d_type,dirp->d_name);
  }
  /*
  关闭目录流DIRP
  函数原型int closedir(DIR *__dirp);
  返回0成功,返回-1失败
  */
  closedir(dp);
  exit(0);
}
