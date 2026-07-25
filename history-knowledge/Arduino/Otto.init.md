### Otto.init(val1,val2,val3,val4,bool,val5)
- Otto.init中的6个值是固定的，一个也不能少，多余的不需要的时候可以填入没有的引脚占用
#### 示例
<Otto.h>
Otto Robot1
const leftLeg = 2
const leftFoot = 3
const rightLeg = 4
const rightFoot = 5
const Buzzer = 13
void setup(){
	Otto.init(leftLeg,leftFoot,rightLeg,rightFoot,true,Buzzer);
}

