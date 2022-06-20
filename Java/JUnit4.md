#### JUnit4
```java
package com.xuhongchuan.util;

import org.junit.*;

public class MathTest {
    @Before
    public void testBefore(){
        System.out.println("start execute before test...");
    }

    @After
    public void testAfter(){
        System.out.println("start execute after test...");
    }

    @BeforeClass
    public static void testBeforeClass(){
        System.out.println("start execute before class test...");
    }

    @AfterClass
    public static void testAfterClass(){
        System.out.println("start execute After class test...");
    }

    @Test
    public void testEqual() throws Exception {
        Assert.assertEquals(120, 120);
    }

    @Test
    public void testNotEqual() throws Exception{
        Assert.assertNotEquals(12, 13);
    }

    @Test
    public void testTrue() throws Exception{
        Assert.assertTrue("it is not true",true);
    }

    @Test
    public void testFalse() throws Exception{
        Assert.assertFalse("it is not false",false);
    }

    @Test
    public void testNull() throws Exception{
        Assert.assertNull("it is not null",null);
    }

    @Test
    public void testNotNull() throws Exception{
        Assert.assertNotNull("it is null",new Integer(0));
    }

    @Test
    public void testArrayEqual() throws Exception{
        Assert.assertArrayEquals("it is not equal", new int[]{1,2,3,4,5}, new int[]{1,2,3,4,5});
    }

    @Test
    public void testSame() throws Exception{
        // 比较对象地址
        Assert.assertSame(5, 5);
        Assert.assertSame("abc", "abc");
    }
}
```