#include "Robot.h"
#include <iostream>
int main(){
	Robot barbatos("barbatos",12123,97);
	Robot otto("otto",32321,0);
	barbatos.say_hello();
	barbatos.get_status();
	std::cout<<"set battery 64% \n";
	barbatos.set_battery(64);
	barbatos.get_status();
	std::cout<<"charge 30% for barbatos \n";
	barbatos.charge_battery(30);
	barbatos.get_status();
	otto.get_status();
}
