### 重构思路
```java
import java.util.*;

// 重构思路:多个状态下的集合固定
public enum TestType {
    ONE(1,1){
        @Override public List<Integer> getOwnTypes() {
            return Collections.unmodifiableList(Arrays.asList(1,11,111,1111,11111));
        }
    },
    TWO(2,2){
        @Override public List<Integer> getOwnTypes() {
            return Arrays.asList(2,22,222,2222,22222);
        }
    },
    DEFAULT(0,0){
        @Override public List<Integer> getOwnTypes() {
            return new ArrayList<>();
        }
    };

    private Integer produceType;

    private Integer produceSouce;

    TestType(Integer produceType, Integer produceSouce) {
        this.produceType = produceType;
        this.produceSouce = produceSouce;
    }

    public static TestType getEnum(Integer produceType, Integer produceSouce){
        for(TestType temp: TestType.values()){
            if(Objects.equals(temp.produceType, produceType) && Objects.equals(temp.produceSouce, produceSouce)){
                return temp;
            }
        }
        return DEFAULT;
    }

    public abstract List<Integer> getOwnTypes();

    public static void main(String[] args) {
        TestType testType = getEnum(1,1);
        System.out.println(testType.getOwnTypes());
    }
}
```