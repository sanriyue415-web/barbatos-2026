#ifndef Temperature_H
#define Temperature_H

#include "sensor.h"
class TemperatureSensor:public Sensor
{
public: 
	TemperatureSensor(std::string n,double base);
	double read() override;
	std::string name()const override;
	void get_baseValue()const ;
	void set_name(const std::string name);
private:
	std::string name_;
	double base_value_;
};




#endif
