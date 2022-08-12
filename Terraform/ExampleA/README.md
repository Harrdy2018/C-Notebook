## 使用template provider 生成文件
```sh
Outputs:

exec_shell = <<EOT
#! /bin/bash
curl -X POST \
   http://localhost:8500 \
  -H 'Content-Type: application/json' \
  -H 'cache-control: no-cache' \
  -d '{
  "name":"dalong",
  "age": "444",
  "platform":"mobile",
  "id":"f11d2735-aa75-9b09-7e39-7052b07c4ffc"
}'
EOT
```