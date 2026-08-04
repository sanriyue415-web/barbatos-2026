#include <memory>
#include "temperature_sensor.h"
#include "distance_sensor.h"
#include <iostream>
#include <vector>
#include <string>
void print_reading(Sensor* t)
{
	std::cout<<"I am "<<t->name()<<" ----->val: "<<t->read()<<std::endl;
}
int main()
{
	std::cout<<"<--task1-->\n";
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


	


}
