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