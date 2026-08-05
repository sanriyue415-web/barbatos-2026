#include <memory>
#include "temperature_sensor.h"
#include "distance_sensor.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
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
	std::cout<<"main结束\n";*/
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
	std::cout<<"Vector 是有序储存，当我们需要修改当中的某一个值的时候，需要确定它的下标是什么，才可以通过下标来进行具体的修改。但是 Map 可以直接通过 key 修改值，不需要寻找下标以及遍历。两个都用就是相当于各取所长去用他们擅长的地方\n";
}
