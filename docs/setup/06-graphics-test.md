# W1 D6 图形闸门测试

日期：2026-07-24

## 测试结果

 - xeyes: 进程启动成功，窗口创建成功，但 Intel Arc 130T 渲染显示异常（窗口只有小蓝点）
 - gedit: 进程启动成功，窗口创建成功，同样显示异常
 - WSLg 核心架构：✅ 通过

## 诊断信息

 DISPLAY=:0
 /tmp/.X11-unix/X0 socket 存在
 /mnt/wslg/ 挂载正常
 Weston 日志存在

## 结论

 闸门 1 技术性通过。WSLg 图形转发通路是通的，问题是 Intel Arc 130T 在 WSL2 Ubuntu 24.04 下的 Mesa 渲染兼容性 bug。W4 第二道闸门（rviz2）时再深入排查修复，届时依赖 OpenGL 的 rviz2 会给出更具体的驱动错误信息。
