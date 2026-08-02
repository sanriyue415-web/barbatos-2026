#include <memory>
#include "temperature_sensor.h"
#include "distance_sensor.h"
#include <iostream>
void print_reading(Sensor* s)
{
	std::cout<<s->name()<<"-->"<<s->read()<<std::endl;
}
void test_scope()
{
	auto s = std::make_unique<TemperatureSensor>("作用域测试 ",20);
	std::cout<<"函数即将结束\n";
}
int main()
{
	std::unique_ptr<Sensor> s1 = std::make_unique<TemperatureSensor>("温度计 ",20);
	std::unique_ptr<Sensor> a = std::make_unique<TemperatureSensor>("A ", 20);
	std::unique_ptr<Sensor> c = std::move(a);
	c->read();
	auto s2 = std::make_unique<DistanceSensor>("距离 ",100);
	print_reading(s1.get());
	print_reading(s2.get());
	print_reading(s1.get());
	print_reading(s2.get());
	test_scope();
	std::cout<<"回到main\n";
}
