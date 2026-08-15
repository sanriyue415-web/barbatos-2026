#include "sensor.h"
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <memory>

class SensorManager
{
	public:
		void add_sensor(const std::shared_ptr<Sensor>& ptr);
		std::map<std::string,double> read_all();
		void on_reading(std::function<void (std::string, double)> cb);


	private:
		std::vector<std::shared_ptr<Sensor>> vec;
		std::function<void(std::string,double)> lamb;
		std::map<std::string,double> m;
		int c;
};
