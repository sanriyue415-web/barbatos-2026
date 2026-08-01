# W2 REVIEW
日期：2026-08-01
## 学习内容
### C++
 1. class类
  - 基本写法： class 类名{}
  - 封装：禁止外部途径通过非法手段修改内部数据，在一般的class类与子类中将成员变量放入private中，父类有另外的说明
  - const：在函数条件和函数返回类型当中应用。具体表现为函数（const 类型 参数），此时可以防止参数被非法更改；函数（）const同为防止非法更改，且只能访问
  - 析构函数：~类名（）{}，进行删除的说明
 2. 指针与&：
  - 指针用法：类名 变量； 类名* p = &变量；//将变量的地址存进指针p中，且可更换地址与值
  - &用法：类名& 变量或者函数（类名& 变量），绑定不能更换与函数（类名 变量）避免拷贝构造的开销
 3. class分离：
  - 创建.h文件，首先进行基本框架的书写：#ifndef #define 内部 #endif；作出成员变量声明与构造函数以及函数声明其中函数不需要具体展开，返回类型 函数（）；即可
  - 创建.cpp文件，首先导入#include ".h"，之后进行函数实现的书写与列表的初始化
  - 创建main.cpp文件实现类的应用，导入#include ".h"，在main进行具体的调用，一般变量使用变量.函数，指针为变量->函数
 4. 栈与堆
  - 栈：一般的main中就是栈，在程序执行完毕后自动从后往前进行销毁
  - 堆：使用指针，类名* 指针 = new 类型（数值）或 = new 构造函数（）。最后需要delete 指针，否则不会自动销毁，造成内存泄露
 5. 虚函数：
  - 父类：可声明成员变量，构造通用函数，以及声明虚函数。虚函数：可以进行不同子类功能的不同书写，具体声明为 virtual 类型 函数（） const可加 =0;
  - 子类: .h:首先引入父类文件#include以及class 子类 ：public 父类，可进行子类变量声明,构造函数与函数声明，声明虚函数时末尾需要加override，可以在编译时识别是否与父类一致
          .cpp中引入子类.h，后进行具体函数的实现,其中进行函数实现的时候，要写明作用域即类名为父类还是子类，取决于使用哪个类中的具体函数。类型 类名::函数（）{}
  - 意义：可以实现多态，即同一函数的不用使用

###  学会的能力
 1. 能看懂 class MyNode : public rclcpp::Node 是什么意思
 2. 可以将多个文件同时编译，看到 undefined reference 知道是 CMakeLists 漏文件
 3. 可以将头文件进行分离以及指针的创建与引用
 4. 可以进行类的封装

### 自检问题
 1. 值传递和引用传递，什么时候必须用引用？
  Q1：什么时候必须用引用 —— 你答"不清楚"                                                                                                                             
  正确答案不是"省内存"，是：当你需要修改调用方的对象时。

  回想 D3 的实验：
  void drain_by_value(Robot r) { r.set_battery(0); }      // a 还是 100
  void drain_by_reference(Robot& r) { r.set_battery(0); }  // b 变成 0

  省拷贝是优化（可选）；改调用方是必需（无可替代）。两个层次别混：
  - Robot& → 我要改它
  - const Robot& → 我不改，只是不想拷贝

  ROS 回调全是第二种。
 2. const Robot& 三个部分（const / Robot / &）各自防止什么？：const防止被修改，Robot说明从哪里获取信息，&减少内存使用
 3. 栈上对象和 new 出来的对象，谁负责销毁？：栈上程序结束自动销毁，new的需要自己delete
 4. 基类析构函数为什么必须 virtual？
  Q4：基类析构为什么必须 virtual —— 你答"能够复写实现多态"

  错。析构函数不是拿来"多态调用"的，virtual 在这里解决的是内存泄漏。

  场景：
  Sensor* s = new TemperatureSensor("温度计", 20);
  delete s;   // s 的静态类型是 Sensor*

  - 没有 virtual：delete 只调 Sensor::~Sensor()，TemperatureSensor 的 name_（std::string，堆上有数据）不被析构 → 泄漏
  - 有 virtual：delete 先调 TemperatureSensor::~TemperatureSensor()，再调 Sensor::~Sensor() → 干净

  规则：只要一个类可能被继承 + 用基类指针 delete，析构就必须 virtual。你的 Sensor 恰好符合。
 5. .h 和 .cpp 各放什么？为什么 CMakeLists 只写 .cpp？ :.h进行声明，.cpp进行具体实现；.cpp中的include就是将.h的内容复制过来了
 6. 纯虚函数 = 0 意味着什么？
  Q6：= 0 是什么 —— 你答"没有特殊含义"

  错，含义很重。= 0 三件事：
  1. 基类不提供实现（不是空实现，是根本没有）
  2. 子类必须实现，否则子类也是抽象类,即全部实现，不能漏
  3. 该类变成抽象类，不能实例化

### 最大问题
 1. 刻意简化，没有将以前的学习内容全部应用过来
 2. 应用与含义不够熟练
 3. setter 里混进 std::cout——职责边界感

### 时间统计
 - W2约使用30h比35要少，对于简单内容花费时间较少，比较轻松，困难内容理解时间加长

### github 
253d99a W2 D6: inheritance + polymorphism, sensor driver pattern
ec0d785 W2 D5 header/impl split with CMake multi-file build
9e3082d W2 D4 pointer basics, heap vs stack, classic pitfalls
58328c4 W2 D3: encapsulation, reference and const-ref
28a710f W2 D2: constructor with initializer list and destructor
0552947 W2 D1: first C++ class - Robot with member vars and methods
