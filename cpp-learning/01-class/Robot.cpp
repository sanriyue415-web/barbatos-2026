#include <string>
#include <iostream>
class Robot
{
    public:
	std::string name = "watch";
	int id = 12123;
	int battery = 32;
    void say_hello()
	{
	    std::cout<<"Hi, I am "<<name<<", ID "<<id<<std::endl;
	}
    void report_battery()
	{
	    std::cout<<name<<" battery: "<<battery<<"% \n";
	}

};

int main()
{
    Robot barbatos;
    Robot Otto;
    barbatos.say_hello();
    barbatos.report_battery();
    Otto.say_hello();
    Otto.report_battery();
    return 0;
}
