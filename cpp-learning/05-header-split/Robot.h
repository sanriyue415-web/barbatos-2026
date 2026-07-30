#ifndef ROBOT_H
#define ROBOT_H

#include <string>

class Robot{
	private:
		std::string name_;
		int id_;
		int battery_;
	public:
		Robot(std::string n,int i,int b);
		std::string get_name()const;
		int get_id()const;
		int get_battery()const;
		void set_battery(int b);
		void charge_battery(int amount);
		void say_hello()const;
		void get_status()const;
};
				



#endif
