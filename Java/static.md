### Java 静态与静态
#### staic 变量与方法
```java
package com.lukang.java;
// Java 中被 static 修饰的成员称为静态成员或类成员
// 它属于整个类所有，而不是某个对象所有，即被类的所有对象所共享
// 静态成员可以使用类名直接访问，也可以使用对象名进行访问
public class HelloWorld {
    static String hobby="imooc";
    String name = "oppo";

    public static void print(){
        System.out.println("使用static关键字申明静态方法！");
        // 无法从静态上下文中引用非静态
        // System.out.println(name);
    }

    public void pprint(){
        // 从非静态上下文中引用静态
        System.out.println("执行普通成员方法！！！");
        System.out.println(HelloWorld.hobby);
        System.out.println(name);
        System.out.println(this.name);
        System.out.println(this);// 类的实例 com.lukang.java.HelloWorld@1b6d3586
        print();
        this.print();
        HelloWorld.print();
    }

    public static void main(String[] args){
        System.out.println("HelloWorld");
        // 静态变量可以直接使用类名来访问，无须创建类的对象
        System.out.println(HelloWorld.hobby);
        // 直接使用类名调用静态方法
        HelloWorld.print();
        // 使用对象名来访问静态变量
        HelloWorld hello=new HelloWorld();
        System.out.println(hello.hobby);
        // 不推荐此方法调用静态方法
        hello.print();
        hello.pprint();
        // 使用对象名的形式来修改静态变量
        hello.hobby="爱慕课";
        // 再次使用类名访问静态变量，值已被修改
        System.out.println(HelloWorld.hobby);
    }
}
```
#### 静态块与非静态块
```java
package com.lukang.java;
// 在类的声明中，可以包含多个初始化块，当创建类的实例时，就会依次执行这些代码块。
// 如果使用 static 修饰初始化块，就称为静态初始化块
public class Test {
    String name;
    String sex;
    static int age;

    public Test(){
        System.out.println("通过构造方法初始化name");
        name="tom";
    }

    // 初始化块
    {
        System.out.println("通过初始化块初始化sex age");
        sex="man";
        age=18;
    }

    // 静态初始化块
    static {
        System.out.println("通过静态初始化块初始化sex age");
        // sex="woman"; // 无法从静态上下文中引用非静态
        age=20;
    }

    public void show(){
        System.out.println(name+" "+sex+" "+age);
    }

    public static void main(String[] args){
        Test first=new Test();
        first.show();

        Test two=new Test(); // 静态初始化块只在类加载时执行，且只会执行一次
        two.show();
        // 程序运行时静态初始化块最先被执行，然后执行普通初始化块，最后才执行构造方法
    }
}
```