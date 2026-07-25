# D5-cpp-env
日期：2026-07-23
## 编译链条
 - 源代码->>编译器->>可执行文件{（机器语言）；（hellp.cpp-> g++-> hello）
### 编译方法：
 1. 手动g++ ：g++ 文件名.cpp -o 输出名(o为outpu即将cpp文件编译为可执行文件)
 2. CMake： 
  - CMake 可复用可同时编译多个文件
  - 三段式：CMakeLists.txt（cmake设定，名称不可更改）->> cmake生成Makefile ->> make调用g++
#### CMakeLists.txt文件说明
cmake_minimum_required(VERSION 3.10) //最低编译版本要求，防止中途编译报错
project(hello) //项目名称，存在cmake中，方便同时修改和同步
add_executable(hello hello.cpp) //输出的文件名和源代码
 - 每一行都必不可少
## out-of-source build 
 - 运行cmake 要在buil中
 1. git干净，没有乱七八糟的临时文件
 2. 秒回滚，rm -rf build后直接一键重新开始
 3. 多配置并存
## .gitignore
 - commit源代码而不是build/等编译文件
 1. 不同设备软件和系统会有出入，导致运行报错
 2. commit临时文件会导致内存占用冗余
## 错误清单
 ### 关于cpp的编写
  1. #include忘记导入
  2. 打印：std::cout 
  3. \n属于字符串，要在""内才会换行
 ### ./name
  - ./表示从当前目录开始运行为name的文件，默认是从path中找，不带./会找不到导致报错
