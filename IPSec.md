## IPSec 相关配置
### IPSec 第一阶段的配置
* ike 提议的配置
```sh
# 默认的 ike 提议
[USG6000V1]display ike proposal 
2020-12-28 17:02:58.190 

Number of IKE Proposals: 1

-------------------------------------------
 IKE Proposal: Default
   Authentication Method      : PRE_SHARED # 认证方式 预共享秘钥
   Authentication Algorithm   : SHA2-512 SHA2-384 SHA2-256 # 认证算法
   Encryption Algorithm       : AES-256 AES-192 AES-128  # 加密算法
   Diffie-Hellman Group       : MODP-2048 
   SA Duration(Seconds)       : 86400   # ike sa 协商时间
   Integrity Algorithm        : HMAC-SHA2-256 
   Prf Algorithm              : HMAC-SHA2-256 
-------------------------------------------
# 自己创建一个
[USG6000V1]ike proposal 12
[USG6000V1-ike-proposal-12]dis this
#
ike proposal 12
 encryption-algorithm aes-256
 dh group14
 authentication-algorithm sha2-256
 authentication-method pre-share
 integrity-algorithm hmac-sha2-256
 prf hmac-sha2-256
#

# 查看
display ike proposal number 12
display ike proposal

# 对端也进行同样的配置
```
* FW1 配置 ike 对等体
```sh
[USG6000V1]ike peer fw2 
[USG6000V1-ike-peer-fw2]dis this
#
ike peer fw2
 undo version 2   # 使用 ike v1 版本
 pre-shared-key Huawei@123 # 不配 ping 不通
 ike-proposal 12  # 调用 ike 提议
 remote-address 101.1.1.1 # 指定远端地址
#

# 查看
[USG6000V1]display ike peer brief 
2020-12-28 17:21:26.750 
Current ike peer number: 1                                             
---------------------------------------------------------------------------
Peer name        Version  Exchange-mode   Proposal   Id-type   RemoteAddr
---------------------------------------------------------------------------
fw2              v1       main            12         IP        101.1.1.1
```
* FW2 配置 ike 对等体
```sh
[USG6000V1]ike peer fw1 
[USG6000V1-ike-peer-fw1]dis this
#
ike peer fw1
 undo version 2
 pre-shared-key Huawei@123 # 不配 ping 不通
 ike-proposal 12
 remote-address 202.1.1.1
#

# 查看
[USG6000V1]display ike peer brief 
2020-12-28 17:19:48.110 
Current ike peer number: 1                                                    
---------------------------------------------------------------------------
Peer name        Version  Exchange-mode   Proposal   Id-type   RemoteAddr
---------------------------------------------------------------------------
fw1              v1       main            12         IP        202.1.1.1
```
### IPSec 第二阶段的配置
* FW1 配置感兴趣流
```sh
[USG6000V1]acl 3000
[USG6000V1-acl-adv-3000]dis this
#
acl number 3000
 rule 5 permit ip source 192.168.1.0 0.0.0.255 destination 192.168.2.0 0.0.0.255
#
```
* FW2 配置感兴趣流
```sh
[USG6000V1]acl 3000
[USG6000V1-acl-adv-3000]dis this
#
acl number 3000
 rule 5 permit ip source 192.168.2.0 0.0.0.255 destination 192.168.1.0 0.0.0.255
#
```
* 注意 在ike v1版本中双方感兴趣流一定要互为镜像
* 配置 IPSec 安全提议
* FW1 配置 IPSec 安全提议
```sh
[USG6000V1]ipsec proposal 10
[USG6000V1-ipsec-proposal-10]dis this
#
ipsec proposal 10
 esp authentication-algorithm sha2-256
 esp encryption-algorithm aes-256
#

# 查看
[USG6000V1]display ipsec proposal name 10
IPSec proposal name: 10                                
 Encapsulation mode: Tunnel      #                           
 Transform         : esp-new     #
 ESP protocol      : Authentication SHA2-HMAC-256 
                     Encryption AES-256 
```
* FW2 配置 IPSec 安全提议
```sh
[USG6000V1]ipsec proposal 10
[USG6000V1-ipsec-proposal-10]dis this
#
ipsec proposal 10
 esp authentication-algorithm sha2-256
 esp encryption-algorithm aes-256
#
```
* FW1 配置 IPSec 策略
```sh
[USG6000V1]ipsec policy map1 1 isakmp 
[USG6000V1-ipsec-policy-isakmp-map1-1]dis this
#
ipsec policy map1 1 isakmp
 security acl 3000
 ike-peer fw2
 proposal 10
#
```
* FW2 配置 IPSec 策略
```sh
[USG6000V1]ipsec policy map2 1 isakmp 
[USG6000V1-ipsec-policy-isakmp-map2-1]dis this
#
ipsec policy map2 1 isakmp
 security acl 3000
 ike-peer fw1
 proposal 10
#
```
* FW1 在物理接口上调用
```sh
[USG6000V1-GigabitEthernet0/0/0]dis this
#
interface GigabitEthernet0/0/0
 undo shutdown
 ip address 202.1.1.1 255.255.255.0
 undo service-manage enable
 ipsec policy map1
#
```
* FW2 在物理接口上调用
```sh
[USG6000V1-GigabitEthernet0/0/0]dis this
#
interface GigabitEthernet0/0/0
 undo shutdown
 ip address 101.1.1.1 255.255.255.0
 undo service-manage enable
 ipsec policy map2
#
```
### 连通性检查并查看
* display ike sa
* display ipsec sa
* display ipsec statistics