#ifndef Sensor_H
#define Sensor_H
#include <string>
class Sensor
{
public:
	virtual double read() = 0;
	virtual std::string name ()const = 0;
	virtual ~Sensor() = default;
};

#endif
