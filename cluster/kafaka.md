### 配置文件配置
* ```/opt/module/kafka/config/server.properties```
```shell
############################# Server Basics #############################

# The id of the broker. This must be set to a unique integer for each broker.
broker.id=0 ## 集群服务器均需要配置 0,1,2


## 9092 kafka起来之后的监听端口
############################# Socket Server Settings #############################

# The address the socket server listens on. If not configured, the host name will be equal to the value of
# java.net.InetAddress.getCanonicalHostName(), with PLAINTEXT listener name, and port 9092.
#   FORMAT:
#     listeners = listener_name://host_name:port
#   EXAMPLE:
#     listeners = PLAINTEXT://your.host.name:9092
#listeners=PLAINTEXT://:9092

# Listener name, hostname and port the broker will advertise to clients.
# If not set, it uses the value for "listeners".
#advertised.listeners=PLAINTEXT://your.host.name:9092


############################# Log Basics #############################

# A comma separated list of directories under which to store log files
log.dirs=/opt/module/kafka/datas

# The default number of log partitions per topic. More partitions allow greater
# parallelism for consumption, but this will also result in more files across
# the brokers.
## topic的默认分区数
num.partitions=1
```
### 命令
```shell
# 启动
/opt/module/kafka/bin/kafka-server-start.sh -daemon /opt/module/kafka/config/server.properties
# 停止
/opt/module/kafka/bin/kafka-server-stop.sh
```
* 主题
```shell
# 列举所有主题
/opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --list
# 查看主题详细信息
/opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --topic first --describe
# 删除主题
/opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --topic second --delete
# 创建默认主题
[harrdy@hadoop102 conf]$ /opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --topic defaultConfigTopic --create
Created topic defaultConfigTopic.
[harrdy@hadoop102 conf]$ /opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --topic defaultConfigTopic --describe
Topic: defaultConfigTopic       TopicId: TUcwaYFaRCeSqIAsrSpexQ PartitionCount: 1       ReplicationFactor: 1    Configs:
        Topic: defaultConfigTopic       Partition: 0    Leader: 0       Replicas: 0     Isr: 0
# 创建指定配置主题(分区数，副本数)
[harrdy@hadoop102 conf]$ /opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --topic diytopic --create --partitions 2 --replication-factor 1
Created topic diytopic.
[harrdy@hadoop102 conf]$ /opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --topic diytopic --describe
Topic: diytopic TopicId: eQGyoGuLSBeHBswAvjXIag PartitionCount: 2       ReplicationFactor: 1    Configs:
        Topic: diytopic Partition: 0    Leader: 0       Replicas: 0     Isr: 0
        Topic: diytopic Partition: 1    Leader: 2       Replicas: 2     Isr: 2
# 修改主题配置
[harrdy@hadoop102 conf]$ /opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --topic diytopic --alter --partitions 3
[harrdy@hadoop102 conf]$ /opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --topic diytopic --describe
Topic: diytopic TopicId: eQGyoGuLSBeHBswAvjXIag PartitionCount: 3       ReplicationFactor: 1    Configs:
        Topic: diytopic Partition: 0    Leader: 0       Replicas: 0     Isr: 0
        Topic: diytopic Partition: 1    Leader: 2       Replicas: 2     Isr: 2
        Topic: diytopic Partition: 2    Leader: 2       Replicas: 2     Isr: 2
```
* 生产者与消费者
```shell
# 生产者向主题发送数据
/opt/module/kafka/bin/kafka-console-producer.sh --bootstrap-server hadoop102:9092 --topic first
# 消费者从主题拿数据并消费掉
/opt/module/kafka/bin/kafka-console-consumer.sh --bootstrap-server hadoop102:9092 --topic first

## 消费者从最早的消息开始消费
/opt/module/kafka/bin/kafka-console-consumer.sh --bootstrap-server hadoop102:9092 --from-beginning --topic first
```
* 系统主题```__consumer_offsets```
```shell
# 系统主题存放消费者消费的偏移数据,默认不让看，看的话需要修改配置文件
# /opt/module/kafka/config/consumer.properties
exclude.internal.topics=false

## 读取offset
### 创建主题
/opt/module/kafka/bin/kafka-topics.sh --bootstrap-server hadoop102:9092 --topic atguigu --create --partitions 2 --replication-factor 2
# 生产者
/opt/module/kafka/bin/kafka-console-producer.sh --bootstrap-server hadoop102:9092 --topic atguigu
# 带groupid的消费者 因为offset记录是以[组ID,topic,分区]作为key记录
/opt/module/kafka/bin/kafka-console-consumer.sh --bootstrap-server hadoop102:9092 --topic atguigu --group test
# 查看offset
/opt/module/kafka/bin/kafka-console-consumer.sh --topic __consumer_offsets --bootstrap-server hadoop102:9092 --consumer.config /opt/module/kafka/config/consumer.properties  --formatter "kafka.coordinator.group.GroupMetadataManager\$OffsetsMessageFormatter" --from-beginning
[test,atguigu,1]::OffsetAndMetadata(offset=0, leaderEpoch=Optional.empty, metadata=, commitTimestamp=1691905361461, expireTimestamp=None)
[test,atguigu,0]::OffsetAndMetadata(offset=3, leaderEpoch=Optional[0], metadata=, commitTimestamp=1691905361461, expireTimestamp=None)
[test,atguigu,1]::OffsetAndMetadata(offset=0, leaderEpoch=Optional.empty, metadata=, commitTimestamp=1691905366461, expireTimestamp=None)
[test,atguigu,0]::OffsetAndMetadata(offset=3, leaderEpoch=Optional[0], metadata=, commitTimestamp=1691905366461, expireTimestamp=None)
```