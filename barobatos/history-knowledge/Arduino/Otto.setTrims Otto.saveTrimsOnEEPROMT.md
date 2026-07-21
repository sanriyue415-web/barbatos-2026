### Otto.setTrims() 
- 用于微调初始偏移量
### Otto.saveTrimsOnEEPROMT
- 用于存储setTrims的调整即断电后重新连接仍然保持修改后的参数

### 示例
- Otto.setTrims(val1,val2,val3,val4)
- Otto.home() //调整之后舵机home就会变为90+valx度