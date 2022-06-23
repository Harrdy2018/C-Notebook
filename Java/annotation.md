##### 注解
```sh
# Annotation 注解的顶级接口
package java.lang.annotation;

# AnnotatedElement 该接口定义了与注解解析相关的解析方法
```
#### 定义注解
```java
package com.cpdn;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

@Target({ElementType.TYPE, ElementType.METHOD})
@Retention(RetentionPolicy.RUNTIME)
public @interface Book {
    String value();

    double price() default 100;

    String[] author();
}
```
#### 解析注解
```java
package com.cpdn;

import java.lang.reflect.Method;
import java.util.Arrays;

@Book(value = "笑傲江湖", price = 99.9, author = {"Harrdy"})
class BookStore {
    @Book(value = "三少爷的剑", price = 199.9, author = {"古龙"})
    public void test(){

    }
}

public class Solution {
    public static void main(String[] args) {
        Class c = BookStore.class;
        if(c.isAnnotationPresent(Book.class) == true){
            Book book = (Book) c.getDeclaredAnnotation(Book.class);
            System.out.println(book.value());
            System.out.println(book.price());
            System.out.println(Arrays.toString(book.author()));
        }

        try {
            Method method = c.getDeclaredMethod("test");
            Book book = (Book) method.getDeclaredAnnotation(Book.class);
            System.out.println(book.value());
            System.out.println(book.price());
            System.out.println(Arrays.toString(book.author()));
        } catch (NoSuchMethodException e) {
            e.printStackTrace();
        }
    }
}
```