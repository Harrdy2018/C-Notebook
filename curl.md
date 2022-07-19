### curl ```CommandLine Uniform Resource Locator```
* curl - transfer a URL
#### 命令
* 默认发送get请求
```sh
[root@ECS desktop]# curl http://httpbin.org/get
{
  "args": {},
  "headers": {
    "Accept": "*/*",
    "Host": "httpbin.org",
    "User-Agent": "curl/7.29.0",
    "X-Amzn-Trace-Id": "Root=1-62d58d81-363badb323302b3767f2f26c"
  },
  "origin": "47.96.251.225",
  "url": "http://httpbin.org/get"
}

# 重定向
[root@ECS desktop]# curl http://httpbin.org/get > res.txt
```
* ```-X```指定请求方法
```sh
[root@ECS desktop]# curl -X GET http://httpbin.org/get
[root@ECS desktop]# curl -X POST http://httpbin.org/post
[root@ECS desktop]# curl -X PUT http://httpbin.org/put
```
* ```-I```只返回请求的头信息
```sh
[root@ECS desktop]# curl --head --request GET http://httpbin.org/get
HTTP/1.1 200 OK
Date: Mon, 18 Jul 2022 16:50:37 GMT
Content-Type: application/json
Content-Length: 254
Connection: keep-alive
Server: gunicorn/19.9.0
Access-Control-Allow-Origin: *
Access-Control-Allow-Credentials: true
```
* ```-d```以POST方法请求url，并发送相应的参数
```sh
[root@ECS desktop]# curl --request POST --data "a=1&b=2&c=3" http://httpbin.org/post
{
  "args": {},
  "data": "",
  "files": {},
  "form": {
    "a": "1",
    "b": "2",
    "c": "3"
  },
  "headers": {
    "Accept": "*/*",
    "Content-Length": "11",
    "Content-Type": "application/x-www-form-urlencoded",
    "Host": "httpbin.org",
    "User-Agent": "curl/7.29.0",
    "X-Amzn-Trace-Id": "Root=1-62d5903b-139db85e7f86d53e00755d7b"
  },
  "json": null,
  "origin": "47.96.251.225",
  "url": "http://httpbin.org/post"
}

# 如果<data>的内容以符号 @ 开头，其后的字符串将被解析为文件名
[root@ECS desktop]# curl --request POST --data @./res.txt http://httpbin.org/post
```
* ```-A```设置user-agent
```sh
[root@ECS desktop]# curl --user-agent "Harrdy20220719" --request GET http://httpbin.org/get
{
  "args": {},
  "headers": {
    "Accept": "*/*",
    "Host": "httpbin.org",
    "User-Agent": "Harrdy20220719",
    "X-Amzn-Trace-Id": "Root=1-62d59286-65e6b10464adbe5f4cbd91fa"
  },
  "origin": "47.96.251.225",
  "url": "http://httpbin.org/get"
}
```
* ```-O, --remote-name   Write output to a file named as the remote file```
```sh
# 下载文件并以远程的文件名保存
[root@ECS desktop]# curl --remote-name http://httpbin.org/image/jpeg
```
* ```-o, --output FILE   Write output to <file> instead of stdout```
```sh
# 下载文件并以指定的文件名保存
curl --output new.jpeg http://httpbin.org/image/jpeg
```
* ```-H, --header LINE   Custom header to pass to server (H)```
```sh
# 设置头信息
[root@ECS desktop]# curl --request GET --header "Name:Harrdy" --header "Age:18" http://httpbin.org/get
{
  "args": {},
  "headers": {
    "Accept": "*/*",
    "Age": "18",
    "Host": "httpbin.org",
    "Name": "Harrdy",
    "User-Agent": "curl/7.29.0",
    "X-Amzn-Trace-Id": "Root=1-62d6c7df-704671e92abfa7ee23ee5d68"
  },
  "origin": "47.96.251.225",
  "url": "http://httpbin.org/get"
}
```