## Review
日期：2026-07-25

### 知识点清单＋回顾

#### Linux基础命令
##### l系列
 1. ls 查询当前目录下的文件 
 2. ls -l显示详情信息，修改时间、用户等
 3. ls -la 显示默认隐藏的文件
 4. ls -alF == ll 显示隐藏加文件类型
##### 导航（TAB可补全文件或目录名）
 1. cd cd~ 都是回家，即根目录下
 2. cd /为绝对地址 cd 相对地址 
 3. cd .. 返回上一级目录
##### 删除
 1. rm 路径+文件名
 2. rm -f 强制删除
 3. rm -rf 强制删目录
##### 阅读与搜索
 1. grep 关键词 文件 可查询指定文件里关键词出现的次数以及内容
 2. head -n 文件 查询文件前n行
 3. tail -n 文件 查询文件后n行
 4. cat 文件 展示文件内容
##### 组合
 1. 管道| 可将前后内容进行传递
 2. 追加内容A > 文件B 重定向（覆盖原有内容）
 3. A >> B 追加，不覆盖
 4. chmod +x 文件 更改文件权限
##### 操作
 1. mv 移动或改名
 2. touch 创建文件
 3. mkdir -p 创建目录，没有会自动补充
#### git
##### 仓库创建
 1. 身份配置
  - git config --global user.name / user.email
  - git config --global core.editer "nano" git打开编辑器时用nano
  - git config --global init.defaulBranch main
  - git的账户必须和GitHub一致，否则commit不关联，即commit后没用
 2. ssh密钥创建与应用
  - SSH keygen -t ed25519 -C "邮箱" 生成密钥对，并在github主页中添加ssh公钥
  - git remote -v 查看当前URL地址，为HTTP格式还是SSH
  - git remote set-url origin git@github:USER/REPO.git
##### git常用命令
 git status == gs 检查当前修改以及同步状态
 git add 加入暂存区
 git commit -m "" 提交至本地仓库
 git push 提交至远程仓库
 git mv 改名同步到仓库
#### cpp的手动编译 
 1. 命令行g++  g++ 源文件 -o 可执行文件名
 2. CMake 
  - CMakeLists.txt ：cmake_minimum_required(VERSION 3.10) // project(项目名) // add_executable(可执行文件名 源文件)
  - 隔离后依次输入 cmake make 就会编译成功
#### 环境变量path
 - 系统寻找文件的默认路径，每一个冒号为一个分支
 - echo "打印字符串并输出命令结果"
 - echo '全部识别为字符串'
 - 更改内容后 resource ~/文件 更新
### 困难以及疑惑
 - 学习的命令不全部都常用，常用的能够基础，用一次后续基本就不会用的还需要特意去记下嘛？因为记了如果不用时间长了也会忘记
 - 卡点目前还没有，都是基础性的东西
 - W2 计划——C++ 两周硬核，打算每天花4h左右，每天学完要产出最基础的应用或者自己手打几遍
 - W1按计划完成
