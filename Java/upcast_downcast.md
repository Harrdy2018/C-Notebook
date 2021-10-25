### 向上转型和向下转型
```java
class A {
    public void print(){
        System.out.println("A:print");
    }
}

class B extends A{
    public void print(){
        System.out.println("B:print");
    }
    public void funcB(){
        System.out.println("funcB");
    }
}

class C extends B{
    public void print(){
        System.out.println("C:print");
    }
    public void funcC(){
        System.out.println("funcC");
    }
}

public class Test {
    public static void func(A a){
        a.print();
        // 向下转型 : 通过父类对象(大范围)实例化子类对象(小范围),这种属于强制转换
        if(a instanceof B){
            B b=(B)a; // 向下转型,通过父类实例化子类
            b.funcB(); // 调用B类独有的方法
        }
        if(a instanceof C){
            C c=(C)a; // 向下转型,通过父类实例化子类
            c.funcC(); // 调用C类独有的方法
        }
    }
    public static void main(String[] args){
        // 向上转型 : 通过子类对象(小范围)实例化父类对象(大范围),这种属于自动转换
        // 通俗理解：某个实例属于B(子类)，那么他一定属于A(父类)
        // 可以看到打印的是class B的print,这是因为我们通过子类B去实例化的,所以父类A的print方法已经被子类B的print方法覆盖了.从而打印classB的print.
        // 这样做的意义在于:当我们需要多个同父的对象调用某个方法时,通过向上转换后,则可以确定参数的统一.方便程序设计
        System.out.println("分析向上转型");
        A a=new B();
        a.print(); // B:print

        System.out.println("向上转型的意义");
        func(new B()); // 等价于 A a=new B();
        func(new C()); // 等价于 A a=new C();

        System.out.println("分析向下转型");
        System.out.println(a instanceof A); // true
        System.out.println(a instanceof B); // true
        System.out.println(a instanceof C); // false
        func(new A());
        func(new B());
        func(new C());
    }
}
```