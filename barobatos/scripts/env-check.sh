#!/bin/bash
echo "1.当前的用户名为："  
echo $USER
echo "2.当前主机名:" 
hostname
echo "3.系统内核信息（Linux 版本、架构）:" 
uname -a
echo "4.系统发行版信息（Ubuntu 24.04）:" 
lsb_release -a
echo "5.内存使用情况:" 
free -h
echo "6.磁盘使用情况（根目录 /）:" 
df -h /
echo "7.当前 shell 是什么:" 
echo $SHELL
echo '8.$PATH 内容:' 
echo $PATH
echo "9.git 的版本、g++ 的版本:"
git --version ;g++ --version
echo "10.当前时间:"  
date
