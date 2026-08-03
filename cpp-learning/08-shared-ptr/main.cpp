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
	std::cout<<"D3\n";
	std::shared_ptr<Sensor> d = std::make_shared<TemperatureSensor>("温度计2",33);
        std::cout<<"外层共享指针个数："<<d.use_count()<<std::endl;
        {
                std::shared_ptr<Sensor> f = d;
                std::cout<<"内层生效时个数："<<d.use_count()<<std::endl;
                std::cout<<"新指针的地址："<<f.get()<<std::endl;
        }
        std::cout<<"回到外层的个数："<<d.use_count()<<std::endl;
	std::shared_ptr<Sensor> h;
	std::cout<<"创建空指针h\n";
	std::cout<<h.use_count()<<std::endl;
	{
		auto p1 = std::make_shared<TemperatureSensor>("温度计3",33);
		h = p1;
		std::cout << p1.use_count() << std::endl;
	}
	std::cout<<h.use_count()<<std::endl;
	print_reading(h.get());
	std::cout << sizeof(Sensor*) << std::endl;
	std::cout << sizeof(std::unique_ptr<Sensor>) << std::endl;
	std::cout << sizeof(std::shared_ptr<Sensor>) << std::endl;
}
