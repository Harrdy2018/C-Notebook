### 配置文件配置
* ```/opt/module/zookeeper-3.5.7/conf/zoo.cfg```
```shell
# dataDir：指定用于存储数据和状态的文件系统目录
dataDir=/opt/module/zookeeper-3.5.7/zkData

# server.xx：指定ZooKeeper集群中的服务器信息，包括IP地址、端口和Leader选举端口
server.2=hadoop102:2888:3888
server.3=hadoop103:2888:3888
server.4=hadoop104:2888:3888
```
* ```/opt/module/zookeeper-3.5.7/zkData/myid```
```shell
# myid文件的作用是确保zookeeper集群中每个节点的唯一标识符，以便节点可以在集群内互相通信和协调。
# 当一个zookeeper节点启动时，它会读取myid文件，获取自己的标识符，并通过与其它节点通信建立连接，参与到集群协作中去。
# 如果myid文件中的标识符与集群中其他节点的标识符相同，该节点将无法加入集群，因为这将导致数据混乱和丢失。
2 # 集群设备1
3 # 集群设备2
4 # 集群设备3
```
### 命令
```shell
# /opt/module/zookeeper-3.5.7/bin/zkServer.sh [--config <conf-dir>] {start|start-foreground|stop|restart|status|print-cmd}
/opt/module/zookeeper-3.5.7/bin/zkServer.sh start
/opt/module/zookeeper-3.5.7/bin/zkServer.sh restart
/opt/module/zookeeper-3.5.7/bin/zkServer.sh stop
/opt/module/zookeeper-3.5.7/bin/zkServer.sh status

# 客户端连接服务端
/opt/module/zookeeper-3.5.7/bin/zkCli.sh -server hadoop103:2181

## 客户端连接上之后获取帮助
[zk: hadoop103:2181(CONNECTED) 3] h
ZooKeeper -server host:port cmd args
        addauth scheme auth
        close
        config [-c] [-w] [-s]
        connect host:port
        create [-s] [-e] [-c] [-t ttl] path [data] [acl]
        delete [-v version] path
        deleteall path
        delquota [-n|-b] path
        get [-s] [-w] path
        getAcl [-s] path
        history
        listquota path
        ls [-s] [-w] [-R] path
        ls2 path [watch]
        printwatches on|off
        quit
        reconfig [-s] [-v version] [[-file path] | [-members serverID=host:port1:port2;port3[,...]*]] | [-add serverId=host:port1:port2;port3[,...]]* [-remove serverId[,...]*]
        redo cmdno
        removewatches path [-c|-d|-a] [-l]
        rmr path
        set [-s] [-v version] path data
        setAcl [-s] [-v version] [-R] path acl
        setquota -n|-b val path
        stat [-w] path
        sync path
Command not found: Command not found h

## 查看根路径有哪些节点
[zk: hadoop103:2181(CONNECTED) 4] ls /
[harrdy, kafka, sanguo, youku, zookeeper]

## 再获取节点的数据值
[zk: hadoop103:2181(CONNECTED) 17] ls /kafka/brokers/topics/diytopic222
[partitions]
[zk: hadoop103:2181(CONNECTED) 18] get /kafka/brokers/topics/diytopic222
{"removing_replicas":{},"partitions":{"2":[1],"5":[1],"12":[0],"8":[1],"15":[0],"18":[0],"7":[2],"1":[2],"17":[1],"4":[2],"11":[1],"14":[1],"6":[0],"0":[0],"9":[0],"16":[2],"10":[2],"3":[0],"19":[2],"13":[2]},"topic_id":"McZM_uPoQZmvSqcFaYC_vg","adding_replicas":{},"version":3}

## 查看在zookeeper的服务端存储的Kafka的相关信息
## 记录有哪些服务器
[zk: hadoop103:2181(CONNECTED) 22] ls /kafka/brokers/ids
[0, 1, 2]

## 记录谁是leader,有哪些服务器可用
[zk: hadoop103:2181(CONNECTED) 26] get /kafka/brokers/topics/diytopic222/partitions/1/state
{"controller_epoch":2,"leader":2,"version":1,"leader_epoch":0,"isr":[2]}

## 记录辅助选举Leader
[zk: hadoop103:2181(CONNECTED) 28] get /kafka/controller
{"version":2,"brokerid":1,"timestamp":"1691803811823","kraftControllerEpoch":-1}
```