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
#### 列选择
```sh
{"name": "Harrdy", "age":123}
{"name": "Harrdy", "age":123}
{"name": "Harrdy", "age":123}
{"name": "Harrdy", "age":123}
{"name": "Harrdy", "age":123}

# Alt+鼠标左键 鼠标左键用的时候最好点击一下
```
#### 更改同样的字段
```sh
"nuwa.switch"= "true"
"dsp.service.url.site3"= "http://dsp.url3.com"
"dsp.service.url.site7"= "http://dsp.url7.com"
"dsp.service.url.site8"= "http://dsp.url8.com"

# 将等号全部改为冒号
# 使用鼠标选中=
# Ctrl+Shift+L 改值
# 箭头 -> <- 向上 向下 也能移动光标
```