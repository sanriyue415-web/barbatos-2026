#include "temperature_sensor.h"
#include <cstdlib>
#include <iostream>

TemperatureSensor::TemperatureSensor(std::string n,double base):name_(n),base_value_(base){}
double TemperatureSensor::read()
{
	double noise = ((double)rand() / RAND_MAX - 0.5) ;
	return base_value_ + noise;
}
std::string TemperatureSensor::name()const
{
	return name_;
}
void TemperatureSensor::set_name(const std::string name)
{
	name_ = name;
}
void TemperatureSensor::get_baseValue()const
{
	std::cout<<"当前温度为："<<base_value_<<std::endl;
}
