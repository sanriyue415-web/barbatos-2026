#include "temperature_sensor.h"
#include <iostream>

int main()
{
	TemperatureSensor tem("温度计",33);
	std::cout<<tem.name()<<"->"<<tem.read()<<std::endl;
}
