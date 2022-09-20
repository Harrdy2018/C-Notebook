## Google Gson用法详解
```sh
Gson（又称Google Gson）是Google公司发布的一个开放源代码的Java库，主要用途为序列化Java对象为JSON字符串，或反序列化JSON字符串成Java对象。
```
### 学习网站
* ```https://www.cnblogs.com/three-fighter/p/13019694.html```
### 依赖
```sh
<dependency>
    <groupId>com.google.code.gson</groupId>
    <artifactId>gson</artifactId>
    <version>2.8.5</version>
</dependency>
```
### 创建Gson实例
```java
// 使用 new Gson()
Gson gson = new Gson();
// 创建GsonBuilder实例，使用 create() 方法
GsonBuilder builder = new GsonBuilder();
Gson gson = builder.create();
```
### 序列化(将Java对象转换为其JSON表示形式)
* 实体类
```java
public class Employee {
    private int id;
    private String firstName;
    private String lastName;
    private String email;

    public Employee(int id, String firstName, String lastName, String email) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.email = email;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "id=" + id +
                ", firstName='" + firstName + '\'' +
                ", lastName='" + lastName + '\'' +
                ", email='" + email + '\'' +
                '}';
    }
}
```
```java
    @Test
    public void xuliehua(){
        Employee emp = new Employee(1001, "Lokesh", "Gupta", "howtodoinjava@gmail.com");
        Gson gson = new Gson();
        String jsonString = gson.toJson(emp);
        System.out.println(jsonString);
    }
```
* 漂亮的输出
```java
    @Test
    public void xuliehua1(){
        Employee emp = new Employee(1001, "Lokesh", "Gupta", "howtodoinjava@gmail.com");
        Gson gson = new GsonBuilder().setPrettyPrinting().create();
        String jsonString = gson.toJson(emp);
        System.out.println(jsonString);
    }
```
### 反序列化(将JSON字符串转换为Java对象)
```java
    @Test
    public void reverse_xuliehua(){
        String jsonString = "{'id':1001,'firstName':'Lokesh','lastName':'Gupta','email':'howtodoinjava@gmail.com'}";
        Gson gson = new Gson();
        Employee employee = gson.fromJson(jsonString, Employee.class);
        System.out.println(employee);
    }
```


