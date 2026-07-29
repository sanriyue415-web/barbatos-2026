#include <iostream>
#include <string>
class Robot{
	private:
		std::string name_;
		int id_;
		int battery_;
	public:
		Robot(std::string n,int i, int b):name_(n),id_(i),battery_(b){}
		int get_battery(){
			return battery_;
		}
		int get_id(){
			return id_;
		}
		std::string get_name(){
			return name_;
		}
	~Robot(){
		std::cout<<name_<<" is shutting down \n";
	}
	void say_hello(){
		std::cout<<"Hello I am "<<name_<<" ID: "<<id_<<" battery: "<<battery_<<std::endl;
	}
};

int main(){
	std::cout<<"<----task1---->";
	int a = 9;
	int b = 97;
	std::cout<<"value a is "<<a<<" address is "<<&a<<std::endl;
	std::cout<<"vlaue b is "<<b<<" address b is "<<&b<<std::endl;
	int* p;
	p = &a;
	std::cout<<"value p = &a is "<<*p<<std::endl;
	*p = 999;
	std::cout<<"modify a is "<<a<<std::endl;
	p = &b;
	std::cout<<"value p = &b is "<<*p<<std::endl;
	std::cout<<"<----task2---->\n";
	int x = 10;
	int y = 20;
	int& ref = x;
	int* ptr = &x;
	std::cout<<"before x is "<<x<<std::endl;
	ref = y;
	ptr = &y;
	std::cout<<"after ref x is "<<x<<std::endl;
	std::cout<<"*ptr is "<<*ptr<<std::endl;
	std::cout<<"<----task3----> \n";
	Robot r1("Stackbot",1,100);
	r1.say_hello();
	Robot* r2= new Robot("Heapbot",2,80);
	r2->say_hello();
	delete r2;
	std::cout << "--- main ending ---" << std::endl;
	//classic fault1 Robot* q = new Robot("Danger",1,100);
	//delete q;
	//q->say_hello();
	
	//fault2 Robot* k = nullptr;
	//k->say_hello();
}
