#### 动态代理
* 一个简单的例子
```java
package com.cpdn.proxy;

public interface UserService {
    public abstract String login(String loginName, String password);

    public abstract void selectUsers();

    public abstract boolean deleteUsers();
}


package com.cpdn.proxy;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

public class ProxyUtil {
    // 这个<T>表示这个方法声明为泛型方法
    public static <T> T getProxy(T obj){
        return (T) Proxy.newProxyInstance(obj.getClass().getClassLoader(),
                obj.getClass().getInterfaces(), new InvocationHandler() {
            @Override
            public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
                long startTimer = System.currentTimeMillis();
                Object result = method.invoke(obj, args);
                long endTimer = System.currentTimeMillis();
                System.out.println(method.getName()+" cost time "+(endTimer-startTimer)/1000.0+"s");
                return result;
            }
        });
    }
}
```
```java
package com.cpdn.proxy;

public class UserServiceImpl implements UserService{
    @Override
    public String login(String loginName, String password) {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        if("admin".equals(loginName) && "1234".equals(password)){
            return "success";
        }
        return "failed";
    }

    @Override
    public void selectUsers() {
        try {
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("success select all users");
    }

    @Override
    public boolean deleteUsers() {
        try {
            Thread.sleep(1500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("success delete users");
        return true;
    }
}
```
```java
package com.cpdn.proxy;

public class TestProxy {
    public static void main(String[] args) {
        UserService userService = ProxyUtil.getProxy(new UserServiceImpl());
        System.out.println(userService.login("admin", "1234"));
        System.out.println(userService.deleteUsers());
        userService.selectUsers();
    }
}
```