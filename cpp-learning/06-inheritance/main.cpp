#include "temperature_sensor.h"
#include "distance_sensor.h"
#include <iostream>
void print_reading(Sensor* s)
{
	std::cout<<s->name()<<"-->"<<s->read()<<std::endl;
}
int main()
{
Sensor* s1 = new TemperatureSensor("温度计",20);
Sensor* s2 = new DistanceSensor("距离",100);
print_reading(s1);
print_reading(s2);
print_reading(s1);
print_reading(s2);
delete s1;
delete s2;
}
