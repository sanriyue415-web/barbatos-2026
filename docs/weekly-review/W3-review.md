# W4 review

日期：2026-08-15

## 时间统计：

### 时间没有具体的去算过，对于我来说比较难的学习部分也就是花费时间长的地方有lambda和布置的程序任务，要我写如sensormanager这样的我第一时间想不出来，会花很多时间去构思，甚至想不出来；

## 最大的问题：

### 最大的问题是知识的遗忘，如clear不知道是个bug会影响信息，自检问题都是比较笼统

## 是否延期：

### 已经延期了，今天已经是耽误了时间后的一周左右了，上一次review是8.08开学是9.05，所以明天继续W5

## 完成： 

###   智能指针

1. unique_ptr
2. shared_ptr

  ### 容器vector

  ### 地图map

### 回调lambda

- 自动执行，输出相应的语句与运算：lambda（name，val）一般为

### project分离

- 将一个程序进行src与app的分类以及相应的编译

### 整体知识的调用以及ros的开头

## 问题自检：

  Q1 unique_ptr 消灭了 W2 D4 三坑（泄漏 / 悬垂 / 空指针）里的哪几个？哪个没消灭，为什么？

  Q2 一个函数要接收 sensor：shared_ptr<Sensor> / const shared_ptr<Sensor>& / Sensor* / const Sensor& 各在什么情况下选？

  Q3（最难，要推理） vector<shared_ptr<Sensor>> 扩容时，被搬动的是什么？Sensor 对象本身被拷贝了吗？引用计数变了吗？

  我的理解（你跑实验验证我）：被搬动的是 shared_ptr 对象本身，move 构造只交换内部指针，引用计数不变（因为 move 没有 atomicincrement/decrement）。但这是不是永远成立，要看 move 构造是不是 noexcept——如果编译器觉得 move 可能抛，它会退化用 copy 构造，copy 就会让计数 +1
  然后 -1（虽然最终值一样但有原子操作）。shared_ptr 的 move 是 noexcept 所以不会退化，但你写别的不确定 noexcept 的类型就要小心。

  验证方法：use_count() 在 reserve 前后打印。如果不变，move 路径生效。

  Q4 map["不存在的key"] 的坑是什么？在你的 read_all() 里存值用 [] 还是别的？为什么这里恰好不算坑？

  Q5 值捕获 [x] / 引用捕获 [&x] / [this] 按悬垂风险从高到低排序，说理由。

  Q6 undefined reference 三种病因 + 哪条命令验证第三种。

  Q7 改 .cpp 和改 .h 的编译代价差别，根本原因。

  Q8 一句话：为什么 SensorManager 算「极简 ROS 节点」？举三个对应关系。

Q1：
Unique 指针是不会造成泄露悬垂和空指针的。如果使用 get 获取到了裸指针，并对裸指针进行一系列的操作，就可能造成泄露悬垂和空指针等一系列问题。
Q2:
Shared 指针是拥有一份所有权，修改的话就一并改动。 const shared 用就是只能看也增加计数，可以进行改动，但是不能切换。裸指针的创建拿到的是裸地址，但是比 const shared 的引用更弱。实例对象的 const 引用就是只读引用，不能进行修改，不能为空。
Q3:Vector 扩容时，被搬动的就是它存放的这块内存大小， Sensor 对象本身没有被拷贝，引用计数也没有变

Q4:。Q4 中 map了一个不存在的 key， 那么它就会自己创建一个新的值，让它的值等于 0，名字就叫这个不存在的 key。 在我的 read_all()里用的存值是中括号，因为我用的是循环，可以保证每个读取的都是有是有的， 

Q5:[this]>[&x]>[x]，其中this是创建对应的裸指针，与外界相互独立

Q6：nm -C 路径 |grep 符号名 一种是声明了但没有没有去写，一种是在子类中声明了但是我没有把它搞进去。还有一种是直接就在子类没写

Q7：当中改 cpp只需要改具体内容，但是如果点改点 h 就需要「所有 #include 它的 .cpp的预处理输入变了，等于源码变了，所以全部重编」

Q8：add_sensor就是ros里的添加订阅，on_reading就是数据处理，共享指针就是例如[this](Image::SharedPtr msg),共享信息 
