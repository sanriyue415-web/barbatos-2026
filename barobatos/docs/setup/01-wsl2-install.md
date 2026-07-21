  # W1 D1: WSL2 + Ubuntu 24.04 安装记录

  日期: 2026-07-19
  环境: Windows 11 24H2, Intel Ultra 5 225H, 32GB RAM

  ## 安装步骤

  1. PowerShell(管理员) 跑 `wsl --install -d Ubuntu-24.04`
  2. 期间自动装 WSL 2.7.10 + 启用 VirtualMachinePlatform
  3. 重启后自动装 Ubuntu-24.04
  4. 设置用户名 sanriyue

  ## 换源 (清华)

  - 备份 ubuntu.sources -> ubuntu.sources.bak
  - sed 替换 archive.ubuntu.com / security.ubuntu.com 为 mirrors.tuna.tsinghua.edu.cn

  ## 踩过的坑

  1. 第一次拼错 `wsl -install` (单横线)，正确是 `wsl --install`
  2. 复制多行 sed 命令时粘贴中间被换行截断，解决:先 cd 到目标目录再跑短命令
  3. WSL 默认在 /mnt/c/Users/xxx 打开,速度慢,应该 cd ~ 到 Linux 家目录

  ## 环境验证

  - WSL 版本: 2 (通过 wsl -l -v 确认)
  - 内核: 6.18.33.2-microsoft-standard-WSL2
  - 内存分配: 15Gi (物理 32GB 的一半)
  - 换源后 apt update / upgrade 正常
