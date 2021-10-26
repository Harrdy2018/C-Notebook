#### 单例模式
##### 单例模式的实现----枚举类型
```java
enum GirlFriend{
    INSTANCE;
    public void PlayWithMe(){}
    public void ShoppingWithMe(){}
}

public class Test {
    public static void main(String[] args){
        System.out.println("单例模式的实现----枚举类型");
        GirlFriend girlFriendA=GirlFriend.INSTANCE;
        GirlFriend girlFriendB=GirlFriend.INSTANCE;
        System.out.println(girlFriendA); // INSTANCE
        System.out.println(girlFriendA==girlFriendB); // true
    }
}
```
##### 单例模式的实现----静态内部类
```java
class GirlFriend{
    private GirlFriend(){}

    public static GirlFriend getInstance(){
        return InnerClassHolder.instance;
    }

    public void playwithme(){}

    public void shoppingwithme(){}

    private static class InnerClassHolder{
        private static GirlFriend instance=new GirlFriend();
    }
}

public class Test {
    public static void main(String[] args){
        System.out.println("单例模式的实现----静态内部类");
        GirlFriend girlFriendA=GirlFriend.getInstance();
        GirlFriend girlFriendB=GirlFriend.getInstance();
        System.out.println(girlFriendA);
        System.out.println(girlFriendA==girlFriendB); // true
    }
}
```
##### 单例模式的实现----饿汉模式
```java
class GirlFriend{
    private GirlFriend(){}

    public static GirlFriend instance=new GirlFriend();

    public static GirlFriend getInstance(){
        return instance;
    }

    public void playwithme(){}

    public void shoppingwithme(){}
}

public class Test {
    public static void main(String[] args){
        System.out.println("单例模式的实现----饿汉模式");
        GirlFriend girlFriendA=GirlFriend.getInstance();
        GirlFriend girlFriendB=GirlFriend.getInstance();
        System.out.println(girlFriendA);
        System.out.println(girlFriendA==girlFriendB); // true
    }
}
```