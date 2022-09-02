#! /bin/bash
cat << EOF
====================================================================
start)   Start Kafka
stop)    Stop Kafka
status)  Query status of the Kafka
other)   Quit
=====================================================================
EOF
read -p "请输入你要执行的操作[ start | stop | status | other ]: " Action
case $Action in
    "start"){
        echo "Start Kafka..."
        for i in hadoop102 hadoop103 hadoop104
        do
            echo "---------------Kafka $i start ------------------------"
            ssh $i "/opt/module/kafka/bin/kafka-server-start.sh -daemon /opt/module/kafka/config/server.properties"
        done
    };;
    "stop"){
        echo "Stop Kafka..."
        for i in hadoop102 hadoop103 hadoop104
        do
            echo "---------------Kafka $i stop ------------------------"
            ssh $i "/opt/module/kafka/bin/kafka-server-stop.sh"
        done
    };;
    "status"){
        echo "Query status of the Kafka..."
        for i in hadoop102 hadoop103 hadoop104
        do
            echo "---------------Kafka $i status ------------------------"
            ssh $i "jps -l | grep kafka"
        done
    };;
    *){
        echo "WANING: $0 请不要乱输入...."
        exit
    }
esac
