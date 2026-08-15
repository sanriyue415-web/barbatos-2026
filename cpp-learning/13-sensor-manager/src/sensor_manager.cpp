#include "sensor_manager.h"
#include <iostream>
#include <string>

void SensorManager::add_sensor(const std::shared_ptr<Sensor>& ptr)
{
	vec.push_back(ptr);
}
std::map<std::string,double> SensorManager::read_all()
{
	m.clear();
	if(lamb)
	{
		for (auto& t:vec)
		{
			std::string name = t->name();
			double val = t->read();
			m[name]=val;
			lamb(name,val);
		}
	}
	return m;
}
void SensorManager::on_reading(std::function<void(std::string,double)> cb)
{
		lamb = std::move(cb);
}

