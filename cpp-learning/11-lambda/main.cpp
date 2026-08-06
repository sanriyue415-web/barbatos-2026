#include <memory>
#include "temperature_sensor.h"
#include "distance_sensor.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <typeinfo>
void print_reading(Sensor* t)
{
	std::cout<<"I am "<<t->name()<<" ----->val: "<<t->read()<<std::endl;
}
void vector_map(std::vector<std::shared_ptr<Sensor>> v6,std::map<std::string,double>& m6)
{
	for(const auto& k :v6)
	{
		m6[k->name()] = k->read();
	}
	for (const auto& p :m6)
	{
		std::cout<<p.first<<"："<<p.second<<std::endl;
	}
}
void insert_f(std::function<void(int) > f)
{
	f(1);
	f(2);
}


int main()
{
	/*std::cout<<"<--task1-->\n";
	int i = 0;
	std::vector<int> v1;
	std::cout<<v1.size()<<std::endl;
	std::cout<<v1.empty()<<std::endl;;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	std::cout<<v1.size()<<std::endl;
	for(size_t i = 0; i < v1.size();++i)
	{
		std::cout<<"下标循环第"<<i<<"个数值是："<<v1[i]<<std::endl;
	}
	for(int x : v1)
	{
		i +=1; 
		std::cout<<"for-range循环第"<<i<<"个数值是："<<x<<std::endl;
	}
	v1.clear();
	std::cout<<v1.size()<<std::endl;
	std::cout<<v1.empty()<<std::endl;
	std::cout<<"<--task2-->\n";
	std::vector<int> v2 {12,123,1234};
	//std::cout<<"v2[10]="<<v2[10]<<std::endl;
	//std::cout<<"v2.at(10)="<<v2.at(10)<<std::endl;
	std::cout<<"我认为在UB中，使用at更好，虽然写的多了几个符号，但是报错是确定性的，知道执行到哪一行不对；虽然[]在一定情况下更直观简洁，但是运气不好就不一定了\n";
	std::cout<<"<--task3-->\n";
	std::vector<int> v3 {100,200,300};
	for (int x : v3)
	{
		x=99;
	}
	for (int x : v3)
	{
		std::cout<<"int x 修改后的数值是："<<x<<std::endl;
	}
	for (int& x:v3)
	{
		x=99;
	}
	for (int x : v3)
	{
		std::cout<<"int& x 修改后的数值是："<<x<<std::endl;
	}
	for (const int& x :v3)
	{
		std::cout <<"标准只读const int& x的值为："<< x<<std::endl;
	}
	std::cout<<"只改元素用&，只读很小直接int x（拷贝），很大用const int& x（不拷贝）\n";
	std::cout<<"<--task4-->\n";
	std::vector<std::string> v4 {"val1","val2"};
	for (std::string x:v4)
	{
		std::cout<<x<<std::endl;
	}
	for (const auto& x:v4)
	{
		std::cout<<x<<std::endl;
	}
	std::cout<<"<----task5-main---->\n";
	std::vector<std::shared_ptr<Sensor>> sensor;
	std::cout<<"sensor.size "<<sensor.size()<<std::endl;
	sensor.push_back(std::make_shared<TemperatureSensor>("温度计1",34));
	sensor.push_back(std::make_shared<TemperatureSensor>("温度计2",37));
	sensor.push_back(std::make_shared<DistanceSensor>("传感器1",100));
	std::cout<<"size: "<<sensor.size()<<std::endl;
	for (const auto& x:sensor)
	{
		print_reading(x.get());
	}
        std::cout<<"1.则是再在push_back(std::make_shared<子类名字>(val))\n";
        std::cout<<"<--task6-->\n";
        std::vector<int> v6;
	for (i=0;i<20;++i)
	{
		v6.push_back(i);
		std::cout<<"size = "<<v6.size()<<" capacity = "<<v6.capacity()<<std::endl;
	}
	std::cout<<"capacity是按照2的n-1次方进行扩容的；如果将图像进行push则会直接复制进去，导致内存使用大，运行卡顿，所以会用共享指针存入容器，更快捷\n";
	std::cout<<"<----task7---->\n";
	std::vector<int> v7;
	std::cout<<"reserve之前："<<v7.capacity()<<std::endl;
	v7.reserve(100);
	std::cout<<"reserve之后："<<v7.capacity()<<std::endl;
	for (i=0;i<20;++i)
        {
                v7.push_back(i);
                std::cout<<"size = "<<v7.size()<<" capacity = "<<v7.capacity()<<std::endl;
        }
	std::cout<<"main结束\n";
	//D4
	std::cout<<"<--task1-->\n";
	std::map<std::string, double> readings;
	std::cout<<"readings size = "<<readings.size()<<std::endl;
	readings["温度计1"]=32.15;
	readings["温度计2"]=27.65;
	readings["传感器1"]=100.7;
	std::cout<<"readings size = "<<readings.size()<<std::endl;
	std::cout<<"readings[] "<<readings["温度计1"]<<std::endl;
	std::cout<<"readings.at() "<<readings.at("温度计1")<<std::endl;
	readings.erase("温度计1");
	std::cout<<"readings size = "<<readings.size()<<std::endl;
	std::cout<<"<--task2-->\n";
	for (const auto& pairs:readings)
	{
		std::cout<<pairs.first<<"->"<<pairs.second<<std::endl;
	}
	std::cout<<"结构化绑定\n";
	for (const auto& [name,val]:readings)
	{
		std::cout<<name<<"->"<<val<<std::endl;
	}
	std::cout<<"结构化绑定cmake未报错，不用加set\n";
	std::cout<<"<--task3-->\n";
	std::map<std::string,double> m;
	m["A"]=1.0;
	std::cout<<"m first size = "<<m.size()<<std::endl;
	std::cout<<"m[none key] "<<m["不存在"]<<std::endl;
	std::cout<<"second size = "<<m.size()<<std::endl;
	//std::cout<<"m.at(none key) "<<m.at("不存在的传感器")<<std::endl;
	//std::cout<<"third size "<<m.size()<<std::endl;
	std::cout<<"<--task4-->\n";
	if (m.count("温度计1")>0)
	{
		std::cout<<m["温度计1"]<<std::endl;
	}
	else 
	{
		std::cout<<"none key\n";
	}
	auto it = m.find("温度计");
	if (it != m.end())
	{
		std::cout<<it->first<<"->"<<it->second<<std::endl;
	}
	else
	{
		std::cout<<"none key\n";
	}
	std::cout<<"使用count的时候只能知道这个key是否存在，具体的val是什么不知道，要想用的话需要写读取如m[];，但是find是能够通过first和second进行具体内容的输出的，避免二次查询以及特殊情况创建新key的问题\n";
	std::cout<<"<--task5-->\n";
	std::map<std::string,double> m5;
	m5["pencil"] = 2.5;
	m5["pen"] = 5;
	m5["ben"] = 3.5;
	m5["red pen"] = 7.5;
	m5["毛笔"] = 1.1;
	m5["钢笔"] = 50.0;
	m5["中性笔"] = 99.9;
	for (const auto& g :m5)
	{
		std::cout<<g.first<<"："<<g.second<<std::endl;
	}
	std::cout<<"观察到中文的key输出的时候是按照val的升序进行排序的\n";
	std::cout<<"<--task6-->\n";
	std::vector<std::shared_ptr<Sensor>> v6;
        auto t1 = std::make_shared<TemperatureSensor>("温度计1",33);
        auto t2 = std::make_shared<TemperatureSensor>("温度计2",27);
        auto t3 = std::make_shared<DistanceSensor>("传感器1",172);
        v6.push_back(t1);
        v6.push_back(t2);
        v6.push_back(t3);
        std::map<std::string, double> m6;
	vector_map(v6,m6);
	vector_map(v6,m6);
	std::cout<<"当key相同时，会覆盖掉之前的值，相当于Linux里的>\n";
	std::cout<<"Vector 是有序储存，当我们需要修改当中的某一个值的时候，需要确定它的下标是什么，才可以通过下标来进行具体的修改。但是 Map 可以直接通过 key 修改值，不需要寻找下标以及遍历。两个都用就是相当于各取所长去用他们擅长的地方\n";*/
	//D5
	std::cout<<"<--task1-->\n";
	auto f =[](int x){return x*2;};
	std::cout<<"f(5)= "<<f(5)<<std::endl;
	std::cout<<typeid(f).name();

	std::cout<<"\n创建立即调用："<<[](int x){return x*x;}(5)<<std::endl;

	auto g = [](){std::cout<<"无参数返回\n";};
	g();

	std::cout<<"<--task2-->\n";
	int x = 20;
	int y = 123;
	//auto f1 = [](){std::cout<<x<<std::endl;};      捕获失败
	auto by_val = [x](){std::cout<<"值捕获："<<x<<std::endl;};
	auto by_ref = [&x](){std::cout<<"引用捕获："<<x<<std::endl;};
	x = 999;
	std::cout<<"x更改为999后：\n"<<"值捕获我认为输出20不变，实际上：";
	by_val();
	std::cout<<" 引用捕获我认为改为999，实际上：";
	by_ref();
	auto q = [&x]() { x = 20; };
	std::cout<<x<<std::endl;
	auto h = [x]() mutable { x = 988; std::cout <<"mutable后"<< x; };
	std::cout <<"mutable后"<<x<<std::endl;
	std::cout<<"<--task3-->\n";
	auto l1 = [=](){std::cout<<x<<std::endl; std::cout<<y<<std::endl;};
	auto l2 = [&](){std::cout<<x<<std::endl; std::cout<<y<<std::endl;};
	l1();
	l2();
	std::cout<<"<--task4-->\n";
	auto l4  = [](double x,double y){return x+y;};
	std::function<double(double,double) > f4 = l4;
	std::cout<<"7+9="<<f4(7,9)<<std::endl;
	auto l5 = [](){std::cout<<"无参数返回\n";};
	std::function<void()> f5 = l5;
	f5();
	insert_f([](int n) { std::cout << "第 " << n << " 次\n"; });
	insert_f([](int n) { std::cout << n * 100 << "\n"; });
	std::cout<<"<--task5-->\n";
	TemperatureSensor t1("温度计",30);
	DistanceSensor d1("传感器",100);
	t1.set_callback([](double raw){std::cout<<"温度回调："<<raw<<" ℃ \n";});
	d1.set_callback([](int dis){if (dis>=100){std::cout<<"当前距离过大\n";}});
	t1.read();
	d1.read();
	std::cout<<"<--task6-->\n";
	std::function<void()> saved;
	{
		int local = 42;
		saved = [local](){std::cout<<"使用local值复制就没问题了"<<local<<std::endl;};
	}
	saved();
	std::cout<<"<--task6-->\n";
	void (*fp)() = []() { std::cout << "ok,使用[x]就是会报错\n1.一般的捕获 x 和引用捕获 x 相比，引用 x 是随着 x 的值是实际性变化的，无论是在 x 无论是在捕获之前修还是捕获之后修改，引用捕获的 x 都是按照最新的来的。但是直接捕获的 x 是按照捕获之前的最新的 x 进行捕获。\n2.按照之前的时间维度上的差别，就说明了如果想用值引用的 X，就是会实时更新的 X。但是有可能会被删除导致悬垂的问题。用直接捕获的 x 就是相对安全且想要不变的\n3.Lambda 和指针的主要区别就是内存布局不同实际中相当于能不能存储对象。并且由于这个原因，在进行捕获时会传入对象，超出指针可接受的范围，导致捕获的值没有地方放，所以不能转换为指针\n4.不需要在main外部进行书写后再在main中调用，方便快捷；写法相较于一个外部函数更简单，可供放数据的地方多，可以说明参数，类型等\n5.callback_放在基类当中，所有子类都需要，放在子类需要写第二遍。且针对修改只需要修改main中的回调与子类中read的计算，不影响。\n6.[]几乎不会悬垂，而[&]会随时更新"
"\n  ┌─────────────────────────────────────┬───────────────────────────────────┐"
"\n  │              捕获方式               │             会悬垂吗              │"
"\n  ├─────────────────────────────────────┼───────────────────────────────────┤"
"\n  │ []                                  │ 不可能(什么都没捕)                │"
"\n  ├─────────────────────────────────────┼───────────────────────────────────┤"
"\n  │ [x],x 是值类型(int / string / 对象) │ 不会(持有独立副本)                │"
"\n  ├─────────────────────────────────────┼───────────────────────────────────┤"
"\n  │ [&x]                                │ 会(引用依赖原变量存活)            │"
"\n  ├─────────────────────────────────────┼───────────────────────────────────┤"
"\n  │ [p],p 是指针                        │ 会(副本是地址,不是对象)           │"
"\n  ├─────────────────────────────────────┼───────────────────────────────────┤"
"\n  │ [this]                              │ 会(this 就是指针)                 │"
"\n  ├─────────────────────────────────────┼───────────────────────────────────┤"
"\n  │ [sp],sp 是 shared_ptr               │ 不会 ⭐(拷贝时计数 +1,对象被保活) │"
"\n  └─────────────────────────────────────┴───────────────────────────────────┘"; };
	fp();
	//void (*fp2)() = [x]() { std::cout << x; };


}
