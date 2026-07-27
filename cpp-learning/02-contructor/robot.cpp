#include <iostream>
#include <string>
class Robot
{
	public:
		std::string name;
		int id;
		int battery;
		Robot(std::string n,int i,int b):name(n),id(i),battery(b){}
	~Robot(){
		std::cout<<name<<" is shutting down..."<<std::endl;
	}
	void say_hello()
		{
			std::cout<<"Hello i am "<<name<<" ID:"<<id<<std::endl;
		}
	void my_status()
		{
			std::cout<<"Battery:"<<battery<<"%\n";
		}
};
int main()
{
	Robot barbatos("barbatos",12123,1);
	Robot otto("otto",32321,97);
	barbatos.say_hello();
	barbatos.my_status();
	otto.say_hello();
	otto.my_status();
	return 0;
}
