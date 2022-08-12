### 文本操作技巧
#### 超强替换
```sh
"nuwa.switch"= "true"
"dsp.service.url.site3"= "http://dsp.url3.com"
"dsp.service.url.site7"= "http://dsp.url7.com"
"dsp.service.url.site8"= "http://dsp.url8.com"

# 假设有很多替换成下面这样
"nuwa.switch": {{nuwa.switch}}
"dsp.service.url.site3": {{dsp.service.url.site3}}
"dsp.service.url.site7": {{dsp.service.url.site7}}
"dsp.service.url.site8": {{dsp.service.url.site8}}

# 解决
"(.*)"=(.*)
"$1": {{$1}}
```
```sh
"nuwa.switch"= "true"
"dsp.service.url.site3"= "http://dsp.url3.com"
"dsp.service.url.site7"= "http://dsp.url7.com"
"dsp.service.url.site8"= "http://dsp.url8.com"

# 假设有很多替换成下面这样
"nuwa.switch"= {{nuwa.switch}}
"dsp.service.url.site3"= {{dsp.service.url.site3}}
"dsp.service.url.site7"= {{dsp.service.url.site7}}
"dsp.service.url.site8"= {{dsp.service.url.site8}}

# 解决
"(.*)"=(.*)
"$1"= {{$1}}
```
```sh
"nuwa.switch"= "true"
"dsp.service.url.site3"= "http://dsp.url3.com"
"dsp.service.url.site7"= "http://dsp.url7.com"
"dsp.service.url.site8"= "http://dsp.url8.com"

# 假设有很多替换成下面这样
"nuwa.switch,dsp.service.url.site3,dsp.service.url.site7,dsp.service.url.site8"

# 解决
"(.*)"= "(.*)"\n
$1,
```