#include <iostream>
#include "Robot.h"

Robot::Robot(std::string n,int i,int b):name_(n),id_(i),battery_(b){}
std::string Robot::get_name()const{
	return name_;
}
int Robot::get_id()const{
	return id_;
}
int Robot::get_battery()const{
	return battery_;
}
void Robot::set_battery(int b){
	if (b >= 100)
		battery_ = 100;
	else if (b <= 0)
		battery_ = 0;
	else 
		battery_ = b;
}
void Robot::charge_battery(int amount){
	Robot::set_battery(battery_ + amount);
}
void Robot::say_hello()const{
	std::cout<<"Hello I am "<<name_<<" ID: "<<id_<<std::endl;
}
void Robot::get_status()const{
	std::cout<<name_<<" battery is "<<battery_<<"% \n";
}
