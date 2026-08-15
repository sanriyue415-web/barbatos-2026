#ifndef Distance_H
#define Distance_H

#include "sensor.h"

class DistanceSensor:public Sensor
{
public:
	DistanceSensor(std::string n,double d);
	double read() override;
	std::string name()const  override;
	void set_name(const std::string name);
	~DistanceSensor();
private:
	std::string name_;
	double distance_;

};

#endif
