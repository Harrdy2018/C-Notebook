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
class CreateThreadOne implements Runnable {
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
        new Thread(new CreateThreadOne()).start();
    }
}
```
#### 使用Callable和Future创建线程
```java
import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

class Test implements Callable<String> {
    @Override
    public String call() throws Exception {
        return "hello child thread";
    }
}

public class Solution {
    public static void main(String[] args){
        Thread mainThread = Thread.currentThread();
        System.out.println("main name >>>"+mainThread.getName());
        System.out.println("main state >>>"+mainThread.getState());
        System.out.println("main ID >>>"+mainThread.getId());

        Callable<String> callable = new Test();
        try {
            FutureTask<String> futureTask = new FutureTask<>(callable);
            Thread thread = new Thread(futureTask);
            thread.run();
            System.out.println("thread ID "+thread.getId()+" return:"+futureTask.get());
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