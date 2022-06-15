### java创建线程的几种方式
#### 继承Thread类重写run方法
```java
class CreateThreadOne extends Thread {
    @Override
    public void run() {
        Thread currentThread = Thread.currentThread();
        System.out.println("name "+currentThread.getName());
        System.out.println("state "+currentThread.getState());
        System.out.println("ID "+currentThread.getId());
    }
}

public class Solution {
    public static void main(String[] args){
        Thread mainThread = Thread.currentThread();
        System.out.println("main name >>>"+mainThread.getName());
        System.out.println("main state >>>"+mainThread.getState());
        System.out.println("main ID >>>"+mainThread.getId());
        CreateThreadOne threadOne = new CreateThreadOne();
        threadOne.start();
    }
}
```
#### 实现Runnable接口创建线程
```java
package com;

class CreateThreadOne implements Runnable {
    @Override
    public void run() {
        Thread currentThread = Thread.currentThread();
        System.out.println(currentThread.getName()+" "+currentThread.getState()+" "+currentThread.getId());
    }
}

public class Solution {
    public static void main(String[] args){
        Thread mainThread = Thread.currentThread();
        System.out.println(mainThread.getName()+" "+mainThread.getState()+" "+mainThread.getId());
        new Thread(new CreateThreadOne(), "new_thread").start();
    }
}
```
#### 使用Callable和Future创建线程
```java
package com;

import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

class Task implements Callable<String> {
    private int startNum;

    private int endNum;

    public Task(int startNum, int endNum) {
        this.startNum = startNum;
        this.endNum = endNum;
    }

    @Override
    public String call() throws Exception {
        int sum = 0;
        for(int i=startNum;i<=endNum;i++){
            sum+=i;
        }
        return "子线程执行的结果是: "+sum;
    }
}

public class Solution {
    public static void main(String[] args){
        Thread mainThread = Thread.currentThread();
        System.out.println(mainThread.getName()+" "+mainThread.getState()+" "+mainThread.getId());
        try {
            FutureTask<String> futureTask = new FutureTask<>(new Task(2,2000));
            Thread t = new Thread(futureTask, "new_thread");
            t.start();
            System.out.println(t.getName()+" "+t.getState()+" "+t.getId()+" return:"+futureTask.get());
        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
```
#### 使用线程池创建线程
```java
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class NumberThread implements Runnable {
    @Override
    public void run() {
        for(int i=1;i<=1000;i++){
            if(i%2==0){
                System.out.println(Thread.currentThread().getName()+":"+i);
            }
        }
    }
}

class NumberThread1 implements Runnable {
    @Override
    public void run() {
        for(int i=1;i<=1000;i++){
            if(i%2==0){
                System.out.println(Thread.currentThread().getName()+":"+i);
            }
        }
    }
}

public class Solution {
    public static void main(String[] args){
        ExecutorService service = Executors.newFixedThreadPool(10);
        service.execute(new NumberThread());
        service.execute(new NumberThread1());
        service.shutdown();
    }
}
```
### 可缓存线程池
```java
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
// newCachedThreadPool的线程池为无限大，当执行第二个任务时第一个任务已经完成，会复用执行第一个任务的线程，而不用每次新建线程.
class TestRunnable implements Runnable{
    private Integer index;

    public TestRunnable(Integer index) {
        this.index = index;
    }

    @Override
    public void run() {
        System.out.println(this.index+"我被执行了"+Thread.currentThread().getName());
    }
}

public class Solution {
    public static void main(String[] args){
        ExecutorService cachedThreadPool = Executors.newCachedThreadPool();
        for(int i=1;i<=50;i++){
            final int index = i;
            cachedThreadPool.execute(new TestRunnable(index));
        }
        cachedThreadPool.shutdown();
    }
}
```
#### 线程安全问题-取钱
```java
package com;

class Account {
    private String cardId;

    private long money;

    public Account(String cardId, long money) {
        this.cardId = cardId;
        this.money = money;
    }

    public Account() {
    }

    public String getCardId() {
        return cardId;
    }

    public void setCardId(String cardId) {
        this.cardId = cardId;
    }

    public double getMoney() {
        return money;
    }

    public void setMoney(long money) {
        this.money = money;
    }

    public void drawMoney(long money){
        String name = Thread.currentThread().getName();
        if(this.money>=money){
            System.out.println(name+" 来取钱，吐出 "+money);
            this.money-=money;
        }else{
            System.out.println(name+" 来取钱，余额不足！");
        }
    }
}

class Task implements Runnable {
    private Account account;

    public Task(Account account) {
        this.account = account;
    }

    @Override
    public void run() {
        account.drawMoney(100000L);
    }
}

public class Solution {
    public static void main(String[] args){
        Account account = new Account("ICBC-1111", 100000);
        new Thread(new Task(account), "thread_xiaoming").start();
        new Thread(new Task(account), "thread_xiaohua").start();
    }
}
```
#### 线程同步的核心思想
* 加锁:把共享资源进行上锁,每次只能一个线程进入访问完毕以后解锁，然后其他线程才能进来
* 同步代码块
```sh
# 作用:把出现线程安全问题的核心代码给上锁
synchronized(同步锁对象){
    操作共享资源的代码
}
```
* 同步代码块解决
```java
public void drawMoney(long money){
    String name = Thread.currentThread().getName();
    // 快捷键 ctrl+alt+t
    synchronized (this) {
        if(this.money>=money){
            System.out.println(name+" 来取钱，吐出 "+money);
            this.money-=money;
            System.out.println(name+" 取钱后，余额剩余: "+this.money);
        }else{
            System.out.println(name+" 来取钱，余额不足！");
        }
    }
}
```
* 同步方法解决
```java
public synchronized void drawMoney(long money){
    String name = Thread.currentThread().getName();
    if(this.money>=money){
        System.out.println(name+" 来取钱，吐出 "+money);
        this.money-=money;
        System.out.println(name+" 取钱后，余额剩余: "+this.money);
    }else{
        System.out.println(name+" 来取钱，余额不足！");
    }
}
```
* Lock锁
```java
package com;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Account {
    private final Lock lock = new ReentrantLock();

    private String cardId;

    private long money;

    public Account(String cardId, long money) {
        this.cardId = cardId;
        this.money = money;
    }

    public Account() {
    }

    public String getCardId() {
        return cardId;
    }

    public void setCardId(String cardId) {
        this.cardId = cardId;
    }

    public double getMoney() {
        return money;
    }

    public void setMoney(long money) {
        this.money = money;
    }

    public void drawMoney(long money){
        String name = Thread.currentThread().getName();
        lock.lock();
        try {
            if(this.money>=money){
                System.out.println(name+" 来取钱，吐出 "+money);
                this.money-=money;
                System.out.println(name+" 取钱后，余额剩余: "+this.money);
            }else{
                System.out.println(name+" 来取钱，余额不足！");
            }
        } finally {
            lock.unlock();
        }
    }
}

class Task implements Runnable {
    private Account account;

    public Task(Account account) {
        this.account = account;
    }

    @Override
    public void run() {
        account.drawMoney(100000L);
    }
}

public class Solution {
    public static void main(String[] args){
        Account account = new Account("ICBC-1111", 100000);
        new Thread(new Task(account), "thread_xiaoming").start();
        new Thread(new Task(account), "thread_xiaohua").start();
    }
}
```