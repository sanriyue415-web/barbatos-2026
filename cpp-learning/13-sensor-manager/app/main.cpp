#include <memory>
#include "temperature_sensor.h"
#include "distance_sensor.h"
#include "sensor_manager.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
	SensorManager man;
	auto t1 = std::make_shared<TemperatureSensor>("温度计1",34);
	auto t2 = std::make_shared<TemperatureSensor>("温度计2",30);
	auto t3 = std::make_shared<DistanceSensor>("传感器1",100);
	man.add_sensor(t1);
	man.add_sensor(t2);
	man.add_sensor(t3);
	man.on_reading([](std::string n,double k){if (k>30){std::cout<<n<<"的温度过高\n";}else{std::cout<<n<<"的温度适中\n";}});
	man.read_all();
	auto map = man.read_all();
	for(const auto &x :map)
	{
		std::cout<<x.first<<"->"<<x.second<<std::endl;
	}


}
