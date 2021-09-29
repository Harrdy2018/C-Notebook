## npm ```nodeJS package management```

### 查看镜像源
* npm config get registry

### 设置镜像源
* npm config set registry https://registry.npm.taobao.org/

### 查看配置列表
* npm config list
* npm config list -l

### 查看安装的模块
* npm list 查看本地安装
* npm list -g 查看全局安装
* npm root 查看本地安装路径
* npm root -g 查看全局安装路径

### 安装与卸载模块
* npm install <package> 本地安装
* npm install -g <package> 全局安装
* npm uninstall <package> 卸载本地安装
* npm uninstall -g <package> 卸载全局安装
* npm install <package_name> --save 加一个实体到```package.json's dependencies```
* npm install <package_name> --save-dev 加一个实体到```package.json's devDependencies```
* npm install ``npm``工具会根据package.json中对各种依赖的定义去安装这些依赖

### npm初始化
* npm init 交互式初始化
* npm init --yes 一键初始化
