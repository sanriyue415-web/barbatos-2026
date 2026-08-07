#ifndef Sensor_H
#define Sensor_H
#include <string>
#include <functional>
class Sensor
{
public:
	virtual double read() = 0;
	virtual std::string name ()const = 0;
	void set_callback(std::function<void(double)> call){callback_=std::move(call);}
	virtual ~Sensor() = default;
protected:
	std::function<void(double)> callback_;
};

#endif
