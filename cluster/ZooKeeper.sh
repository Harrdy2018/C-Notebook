#! /bin/bash
cat << EOF
====================================================================
start)   Start ZooKeeper
stop)    Stop ZooKeeper
status)  Query status of the ZooKeeper
other)   Quit
=====================================================================
EOF
read -p "请输入你要执行的操作[ start | stop | status | other ]: " Action
case $Action in
    "start"){
        echo "Start ZooKeeper..."
        for i in hadoop102 hadoop103 hadoop104
        do
            echo "---------------ZooKeeper $i start ------------------------"
            ssh $i "/opt/module/zookeeper-3.5.7/bin/zkServer.sh start"
        done
    };;
    "stop"){
        echo "Stop ZooKeeper..."
        for i in hadoop102 hadoop103 hadoop104
        do
            echo "---------------ZooKeeper $i stop ------------------------"
            ssh $i "/opt/module/zookeeper-3.5.7/bin/zkServer.sh stop"
        done
    };;
    "status"){
        echo "Query status of the ZooKeeper..."
        for i in hadoop102 hadoop103 hadoop104
        do
            echo "---------------ZooKeeper $i status ------------------------"
            ssh $i "/opt/module/zookeeper-3.5.7/bin/zkServer.sh status"
        done
    };;
    *){
        echo "WANING: $0 请不要乱输入...."
        exit
    }
esac