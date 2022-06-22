### 反射
* 反射是在运行时获取类的字节码文件对象,然后可以解析类中的全部成分。
#### 如何得到Class对象
```java
package com.cpdn;

public class Test {
    public static void main(String[] args) {
        try {
            Class c = Class.forName("com.cpdn.Student");
            System.out.println(c);

            Class c1 = Student.class;
            System.out.println(c1);

            Class c2 = new Student().getClass();
            System.out.println(c2);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
}
```
#### 如何获取构造器对象
```sh
getConstructors  # 返回所有构造器对象的数组(只能拿public)
getDeclaredConstructors # 返回所有构造器对象的数组(存在就能拿到)
getConstructor # 返回单个构造器对象(只能拿public)
getDeclaredConstructor # 返回单个构造器对象(存在就能拿到)
```
```java
package com.cpdn;

import java.lang.reflect.Constructor;

public class Test {
    public static void main(String[] args) throws NoSuchMethodException {
        Class c1 = Student.class;
        Constructor constructors[] = c1.getConstructors();
        for (Constructor constructor : constructors) {
            System.out.println(constructor.getName()+"===>"+constructor.getParameterCount());
        }
        System.out.println("---------------------");
        Constructor cs[] = c1.getDeclaredConstructors();
        for (Constructor constructor : cs) {
            System.out.println(constructor.getName()+"===>"+constructor.getParameterCount());
        }
        System.out.println("---------------------");
        // Constructor ca = c1.getConstructor();
        // Constructor ca = c1.getConstructor(String.class, int.class);
        Constructor ca = c1.getDeclaredConstructor(String.class, int.class);
        System.out.println(ca.getName()+"===>"+ca.getParameterCount());
    }
}
```
#### 创建对象
```sh
# 如果是非public的构造器，需要打开权限(暴力反射),然后再创建对象
constructor.setAccessible(true);
```
```java
package com.cpdn;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

public class Test {
    public static void main(String[] args){
        Class c1 = Student.class;
        try {
            Constructor constructor = c1.getDeclaredConstructor(String.class, int.class);
            // 把这一次的private权限打开
            constructor.setAccessible(true);
            Student s = (Student)constructor.newInstance("oppo", 12);
            System.out.println(s.getName()+" "+s.getAge());
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
    }
}
```
##### 可变长参数列表
```java
package com.cpdn;

public class Test {
    public static void dealArray(int ...intArray){
        for(int i : intArray){
            System.out.print(i+" ");
        }
        System.out.print(System.lineSeparator());
    }

    public static void main(String[] args){
        System.out.println("可变长参数");
        dealArray(1,2,3,4,4,5);
    }
}
```
#### 获取成员变量并赋值和取值
```java
package com.cpdn;

import java.lang.reflect.Field;

public class Test {

    public static void main(String[] args){
        Class c1 = Student.class;
        Field fields[]=c1.getDeclaredFields();
        for(Field field : fields){
            System.out.println(field.getName()+"===>"+field.getType());
        }

        try {
            // 赋值
            Student s = new Student();
            Field fieldName = c1.getDeclaredField("name");
            System.out.println(fieldName.getName()+"===>"+fieldName.getType());
            fieldName.setAccessible(true);
            fieldName.set(s, "oppo");

            // 取值
            System.out.println((String) fieldName.get(s));
        } catch (NoSuchFieldException | IllegalAccessException e) {
            e.printStackTrace();
        }
    }
}
```
#### 获取方法对象
```java
package com.cpdn;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class Test {

    public static void main(String[] args){
        Class c1 = Student.class;
        Method[] methods=c1.getDeclaredMethods();
        for(Method m: methods){
            System.out.println(m.getName()+"  "+m.getReturnType()+" "+m.getParameterCount());
        }

        try {
            Method m = c1.getDeclaredMethod("setAge", int.class);
            System.out.println(m.getName()+"  "+m.getReturnType()+" "+m.getParameterCount());

            // 触发
            Student s = new Student();
            m.setAccessible(true);
            m.invoke(s, 12);
            System.out.println(s);
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
    }
}
```
#### 反射作用
* 可以在运行时得到一个类的全部成分然后操作
* 可以破坏封装性
* 也可以破坏泛型的约束性
* 做Java高级框架
```java
package com.cpdn;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.lang.reflect.Field;

public class MybatisUtil {
    public static void save(Object obj){
        try {
            PrintStream ps = new PrintStream(new FileOutputStream("data.txt", true));
            Class c = obj.getClass();
            ps.println("==================="+c.getSimpleName()+"=====================");
            Field fileds[] = c.getDeclaredFields();
            for(Field field : fileds){
                String name = field.getName();
                field.setAccessible(true);
                String value = field.get(obj)+"";
                ps.println(name+" "+value);
            }
            ps.close();
        } catch (IllegalAccessException | FileNotFoundException e) {
            e.printStackTrace();
        }
    }
}
```