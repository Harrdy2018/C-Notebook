#### 抽象类
```java
/**
 *  在使用抽象类时需要注意几点：
 *          1、抽象类不能被实例化，实例化的工作应该交由它的子类来完成，它只需要有一个引用即可。
 *          2、抽象方法必须由子类来进行重写。
 *          3、只要包含一个抽象方法的抽象类，该方法必须要定义成抽象类，不管是否还包含有其他方法。
 *          4、抽象类中可以包含具体的方法，当然也可以不包含抽象方法。
 *          5、子类中的抽象方法不能与父类的抽象方法同名。
 *          6、abstract不能与final并列修饰同一个类。
 *          7、abstract 不能与private、static、final或native并列修饰同一个方法。、
 */
abstract class Animal{
    abstract void  cry();
    public void print(){
        // 4、抽象类中可以包含具体的方法，当然也可以不包含抽象方法。
        System.out.println("Animal class");
    }
}

class Cat extends Animal{
    @Override
    void cry(){
        System.out.println("Cat cry");
    }
}

class Dog extends Animal{
    @Override
    void cry(){
        System.out.println("Dog cry");
    }
}

public class Test {
    public static void main(String[] args){
        System.out.println("抽象类");
        Animal a1=new Cat();
        Animal a2=new Dog();
        a1.cry();
        a2.cry();
    }
}
```
#### 接口
```java
/**
 *  1、接口定义的所有方法默认都是public abstract的，当然你可以显示的声明为protected、private，但是编译会出错
 *  2、接口中可以定义“成员变量”，或者说是不可变的常量，因为接口中的“成员变量”会自动变为为public static final。可以通过类命名直接访问：ImplementClass.name。
 *  3、接口中不存在实现的方法。
 *  4、实现接口的非抽象类必须要实现该接口的所有方法(包括其接口的所有祖先的方法)。抽象类可以不用实现。
 *  5、不能使用new操作符实例化一个接口，但可以声明一个接口变量，该变量必须引用（refer to)一个实现该接口的类的对象。可以使用 instanceof 检查一个对象是否实现了某个特定的接口。例如：if(anObject instanceof Comparable){}。
 *  6、在实现多接口的时候一定要避免方法名的重复。
 */
interface A{
    public static final int age=0;
    public abstract void  A1();
    public abstract void  A2();
    public abstract void  A3();
}

interface B extends A{
    public abstract void  A1();
    public abstract void  B1();
    public abstract void  B2();
}

class C implements B{
    public void A1() {}
    public void A2() {}
    public void A3() {}
    public void B1() {}
    public void B2() {}

}

public class Test {
    public static void main(String[] args){
        System.out.println("接口");
        C c=new C();
    }
}
```