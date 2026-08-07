#include "distance_sensor.h"
#include <cstdlib>
#include <iostream>
DistanceSensor::DistanceSensor(std::string n,double d):name_(n),distance_(d){}
DistanceSensor::~DistanceSensor()
{
	std::cout<<name_ <<" is shutting down \n";
}
double DistanceSensor::read()
{
	double noise = ((rand()% 11) - 5);
	if (callback_)
	{
		callback_(distance_ + noise);
	}
	return distance_ + noise;
}
std::string DistanceSensor::name()const
{
	return name_;
}
void DistanceSensor::set_name(const std::string name)
{
	name_ = name;
}
