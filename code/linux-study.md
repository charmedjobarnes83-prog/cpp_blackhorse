查ip：ip -br addr
linux 没有盘符， 只有一个根目录 /
在win中，路径用\，如D:\home\zzx
在linux中，路径用/，如/home/zzx
命令格式:command [-options] [parameter]

ls命令
ls [-a -l -h] [linux路径]
ls:展开当前工作目录下的文件夹
ls -a :列出全部文件包括隐藏的
ls -l :以列表展开文件夹
ls -a-l   ls -al   ls -la 三种写法一样
ls -h :列出文件大小(跟着l一起用)

cd：切目录
pwd：打印当前工作目录
cd直接切回home，无需加路径
.   当前目录
..  上一级目录
~   home目录

绝对路径 ：cd /home/zzx/Test
相对路径 ：cd Test

mkdir 创建新的目录(文件夹)
语法：mkdir [-p] linux路径
        -p可选，表示自动创建不存在的父目录

touch 创建文件(文件，而非文件夹)
语法：touch linux路径

cat 查看文件内容(直接将内容全部显示出来)
语法：cat linux路径

more 查看文件内容(支持翻页)


ctrl+l ：清屏