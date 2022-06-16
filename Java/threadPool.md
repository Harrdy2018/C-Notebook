#### 线程池
* 代表线程池的接口 ExecutorService
```java
public interface ExecutorService extends Executor

# 实现类创建线程池对象
public class ThreadPoolExecutor extends AbstractExecutorService
    public abstract class AbstractExecutorService implements ExecutorService

public ThreadPoolExecutor(
    int corePoolSize, // 指定线程池的线程数量(核心线程)
    int maximumPoolSize, // 指定线程池可支持的最大线程数    参数>=核心线程数量
    long keepAliveTime, // 指定临时线程的最大存活时间
    TimeUnit unit,   // 指定存活时间的单位(秒、分、时、天)
    BlockingQueue<Runnable> workQueue, // 指定任务队列
    ThreadFactory threadFactory, // 指定用哪个线程工厂创建线程
    RejectedExecutionHandler handler // 指定线程忙，任务满的时候，新任务来了怎么办
)

# 临时线程什么时候创建?
新任务提交时发现核心线程都在忙，任务队列也满了，并且还可以创建临时线程，此时才会创建临时线程

# 什么时候会开始拒绝任务？
核心线程和临时线程都在忙，任务队列也满了，新的任务过来的时候才会开始任务拒绝

# 使用Executors(线程池的工具类)调用方法返回不同特点的线程池
```
* 实现Runnable接口
```java
package com;

import java.util.concurrent.*;

class Task implements Runnable {
    @Override
    public void run() {
        for(int i=0;i<5;i++){
            System.out.println(Thread.currentThread().getName()+"===>"+i);
        }
        try {
            System.out.println(Thread.currentThread().getName()+"本任务与线程绑定了，线程进入休眠了~~~~");
            Thread.sleep(10000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class TestThreadPool {
    public static void main(String[] args) {
        ExecutorService pool = new ThreadPoolExecutor(3, 5,6,
                TimeUnit.SECONDS, new ArrayBlockingQueue<>(5), Executors.defaultThreadFactory(),
                new ThreadPoolExecutor.AbortPolicy());

        pool.execute(new Task());
        pool.execute(new Task());
        pool.execute(new Task());

        pool.execute(new Task());
        pool.execute(new Task());
        pool.execute(new Task());
        pool.execute(new Task());
        pool.execute(new Task());

        // 创建临时线程
        pool.execute(new Task());
        pool.execute(new Task());

        // 不创建，触发拒绝机制
        pool.execute(new Task());


        // pool.shutdownNow() // 立即关闭，即使任务没有完成，会丢失任务
        // pool.shutdown()   // 会等待全部任务执行完毕之后关闭
    }
}
```
* 实现Callable接口
```java
package com;

import java.util.concurrent.*;

class Task implements Callable<Integer> {
    private int startNum;

    private int endNum;

    public Task(int startNum, int endNum) {
        this.startNum = startNum;
        this.endNum = endNum;
    }

    @Override
    public Integer call() {
        int sum = 0;
        for(int i=startNum;i<=endNum;i++){
            sum+=i;
        }
        System.out.println(Thread.currentThread().getName()+" return "+sum);
        return sum;
    }
}

public class TestThreadPool {
    public static void main(String[] args) throws ExecutionException, InterruptedException {
        ExecutorService pool = new ThreadPoolExecutor(3, 5,6,
                TimeUnit.SECONDS, new ArrayBlockingQueue<>(5), Executors.defaultThreadFactory(),
                new ThreadPoolExecutor.AbortPolicy());

        Future<Integer> futureTask1 = pool.submit(new Task(1,100));
        Future<Integer> futureTask2 = pool.submit(new Task(1,100));
        Future<Integer> futureTask3 = pool.submit(new Task(1,100));

        Future<Integer> futureTask4 = pool.submit(new Task(1,100));
        Future<Integer> futureTask5 = pool.submit(new Task(1,100));
        Future<Integer> futureTask6 = pool.submit(new Task(1,100));
        Future<Integer> futureTask7 = pool.submit(new Task(1,100));
        Future<Integer> futureTask8 = pool.submit(new Task(1,100));

        // 临时线程
        Future<Integer> futureTask9 = pool.submit(new Task(1,100));

        System.out.println(futureTask1.get());
        System.out.println(futureTask2.get());
        System.out.println(futureTask3.get());
        System.out.println(futureTask4.get());
        System.out.println(futureTask5.get());
        System.out.println(futureTask6.get());
        System.out.println(futureTask7.get());
        System.out.println(futureTask8.get());
        System.out.println(futureTask9.get());
    }
}
```