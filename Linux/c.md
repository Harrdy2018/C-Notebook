## vim 基本配置
* vim 配置文件
```
在命令行模式下 :version 可以找到它的配置文件 下面以linux系统为标准
系统配置指的是，你修改了配置文件以后，任何用户都适用！
system vimrc file: "/etc/vimrc"
    user vimrc file: "$HOME/.vimrc"
2nd user vimrc file: "~/.vim/vimrc"
```
## 配置详细信息
* 1、支持中文不乱码
```
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
encoding选项用于缓存的文本、寄存器、Vim 脚本文件等；
fileencoding选项是Vim写入文件时采用的编码类型；
termencoding选项表示输出到终端时采用的编码类型。
```
* 2、显示行号
```
set nu
set number
```
* 3、突出显示当前行
```
set cul 
set cursorline
```
* 4、突出显示当前列
```
set cuc 
set cursorcolumn
```
* 5、启用鼠标
```
set mouse=a
set selection=exclusive
set selectmode=mouse,key
```
* 6、搜索
```
set showmatch
光标遇到圆括号、方括号、大括号时，自动高亮对应的另一个圆括号、方括号和大括号。
set hlsearch
搜索时，高亮显示匹配结果。
set incsearch
输入搜索模式时，每输入一个字符，就自动跳到第一个匹配的结果。
set ignorecase
搜索时忽略大小写。
set smartcase
如果同时打开了ignorecase，那么对于只有一个大写字母的搜索词，将大小写敏感；其他情况都是大小写不敏感。比如，搜索Test时，将不匹配test；搜索test时，将匹配Test。
```
* 7、设置缩进
```
'设置Tab长度为4空格'
set tabstop=4
set shiftwidth=4
'继承前一行的缩进方式，适用于多行注释，按下回车键后，下一行的缩进会自动跟上一行的缩进保持一致。'
set autoindent
由于 Tab 键在不同的编辑器缩进不一致，该设置自动将 Tab 转为空格
set expandtab
Tab 转为多少个空格
set softtabstop=4
```
* 8、设置粘贴模式
```
set paste
```
* 9、显示空格和tab键
```
set listchars=tab:>-,trail:-
```
* 10、显示状态栏和光标当前位置
```
'总是显示状态栏'
set laststatus=2
'显示光标当前位置'
set ruler
```
* 11、打开文件类型检测
```
filetype plugin indent on
```
## 配置文件
```sh
[harrdy@localhost ~]$ cat ./.vimrc
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
set number
set cursorline
set mouse=a
set selection=exclusive
set selectmode=mouse,key
set showmatch
set hlsearch
set incsearch
set ignorecase
set tabstop=4
set shiftwidth=4
set autoindent
set expandtab
set softtabstop=4
set paste
set listchars=tab:>-,trail:-
set laststatus=2
set ruler
filetype plugin indent on
```