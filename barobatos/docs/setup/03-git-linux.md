# Git身份配置+SSH+vim基础
日期：2026-07-21
## git身份配置
 - git config --global user.name / user.email
 - git config --global core.editer "nano" git打开编辑器时用nano
 - git config --global init.defaulBranch main
 - git的账户必须和GitHub一直，否则commit不关联，即commit后没用
## SSH key
 - SSH keygen -t ed25519 -C "邮箱" 生成密钥对（Ed25519为现代标准）
 - 私钥： ~/.ssh/id_ed25519 绝对不可以外传
 - 公钥： ~/.ssh/id_ed25519.pub 加到github -> setting -> SSH key 
 - 测试认证： ssh -T git@githun.com
## remote 改为ssh标准的URL地址
 - git remote -v 查看当前URL地址，为HTTP格式还是SSH
 - git remote set-url origin git@github:USER/REPO.git
## git 三区模型
 - 工作区 --add--> 暂存区 --commit--> 本地仓库 --push--> 远程仓库
 - git status  查看当前状态
 - git add -u  暂存所有已跟踪项目的变更（含删除）
 - git add <路径> 暂存到指定文件或者目录
 - git commit -m "消息" 提交到本地仓库
 - git push 提交到远程仓库
## commit message 规范
 格式: 类型: 简短描述 (英文小写, 动词开头, 50 字符内)
 类型: feat / fix / docs / refactor / chore
## vim 实用10键
 - Esc （无论什么时候按Esc都是回到普通模式即阅读模式）
 - i （进入插入模式，可以进行输入和修改）
 - hjkl （上下左右移动光标）
 - dd （删除上一行）
 - u （撤销）
 - /word （搜索）
 - ：wq （保存并退出）
 - ：w （保存）
 - ：q （退出） 
 - ：q！（强制退出，恢复进入时的样子）
## D3踩的坑
 1. 直接mv会使仓库不认识，要用git mv 才会识别出改名移动操作，否则会识别为老文件删除，新文件新增。git add 之后靠内容相似度会自动识别为 rename
 2. 命令行意外把 poem.txt 当搜索模式（少了 pattern 参数）→ Ctrl+C 救
 3. 顶层两个中文名规划文件在 rename 检测时未过阈值,记为 delete,历史里可用 git show <commit>:<file> 回捞
## 感受
  ai都给我模板了，会不会降低我的学习效果？
  中途用到许多没讲过的命令，还没有详细的解释，我应该记住吗？
