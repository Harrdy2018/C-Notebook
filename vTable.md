### 虚表
```c
#include <stdio.h>
// #include "test.h"
#include <stdlib.h>
struct Point{
    int x;
    int y;
};
struct Shape{ // 基类
    struct Methods *methods; //指向虚函数表
};
struct Methods{ // 将C++对应类中所有虚函数封装到一个结构体里面
    float (*getPerimeter)(struct Shape *shape);
    float (*getArea)(struct Shape *shape);
    char* (*getShape)(struct Shape *shape);
};
/**********************************************set Circle***************************************/
struct Circle{
    struct Methods *methods;
    struct Point center;
    float radius;
};
float Circle_getPerimeter(struct Shape *shape){
    struct Circle *c=(struct Circle *)shape;
    return (float)2*3.14*(c->radius);
}
float Circle_getArea(struct Shape *shape){
    struct Circle *c=(struct Circle *)shape;
    return (float)3.14*(c->radius)*(c->radius);
}
char *Circle_getShape(struct Shape *shape){
    return "Circle";
}
struct Methods circleMethods={
    Circle_getPerimeter,
    Circle_getArea,
    Circle_getShape
};
struct Shape *new_circle(struct Point a, float r){
    struct Circle *c=(struct Circle *)malloc(sizeof(struct Circle));
    c->methods=&circleMethods;
    c->center=a;
    c->radius=r;
    return (struct Shape *)c;
}
/**********************************************set Circle***************************************/
/********************************************set Rectangle**************************************/
struct Rectangle{
    struct Methods *methods; //包含继承Shape后的成员函数结构体的指针
    struct Point leftTop; //Shape之外派生的成员变量 
    struct Point rightBottom; //Shape之外派生的成员变量 
};
float Rectangle_getPerimeter(struct Shape *shape){
    struct Rectangle *r=(struct Rectangle *)shape;
    return (float)(r->rightBottom.x - r->leftTop.x+r->rightBottom.y-r->leftTop.y)*2;
}
float Rectangle_getArea(struct Shape *shape){
    struct Rectangle *r=(struct Rectangle *)shape;
    return (float)(r->rightBottom.x - r->leftTop.x)*(r->rightBottom.y-r->leftTop.y);
}
char *Rectangle_getShape(struct Shape *shape){
    return "Rectangle";
}
struct Methods rectangleMethods={
    Rectangle_getPerimeter,
    Rectangle_getArea,
    Rectangle_getShape
};
struct Shape *new_rectangle(struct Point a, struct Point b){
    struct Rectangle *r=(struct Rectangle *)malloc(sizeof(struct Rectangle));
    r->methods=&rectangleMethods;
    r->leftTop=a;
    r->rightBottom=b;
    return (struct Shape *)r;
}
/********************************************set Rectangle**************************************/
int main(int argc, char *argv[])
{
    // test();
    struct Point c={0,0};
    struct Shape *shapes[2]; //基类指针数组
    shapes[0] = new_circle(c,10);
    printf("circle getPerimeter : %f\n", (shapes[0]->methods->getPerimeter)(shapes[0]));
    printf("circle getArea : %f\n", (shapes[0]->methods->getArea)(shapes[0]));
    printf("circle getShape : %s\n", (shapes[0]->methods->getShape)(shapes[0]));

    struct Point a={2,3};
    struct Point b={9,8};
    shapes[1] = new_rectangle(a,b);
    printf("rectangle getPerimeter : %f\n", (shapes[1]->methods->getPerimeter)(shapes[1]));
    printf("rectangle getArea : %f\n", (shapes[1]->methods->getArea)(shapes[1]));
    printf("rectangle getShape : %s\n", (shapes[1]->methods->getShape)(shapes[1]));
    return 0;
}
```
