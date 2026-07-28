#include <iostream>
#include <string>
class Robot
{
	public:
		Robot(std::string n,int i, int b):name_(n),id_(i),battery_(b){}
		std::string get_name()const{
			return name_;
		}
		int get_id()const{
			return id_;
		}
		int get_battery()const{
			return battery_;
		}
		void set_battery(int b){
			if (b >=0 && b <=100)
				battery_ = b;
			else if (b>100)
				battery_ = 100;
			else 
				battery_ = 0;
		}
		void charge(int amount){
			set_battery(battery_ + amount);
		}
		void say_hello()const{
			std::cout<<"Hello I am "<<name_<<" ID: "<<id_<<std::endl;
		}
		void my_status()const{
			std::cout<<name_<<" battery is "<<battery_<<"% \n";
		}
	private:
		std::string name_;
		int id_;
		int battery_;
};
void drain_by_value(Robot r){
	r.set_battery(0);
	std::cout<<"[inside drain_by_value] r battery = "
		 <<r.get_battery()<<std::endl;
}
void drain_by_reference(Robot& r){
        r.set_battery(0);
        std::cout<<"[inside drain_by_reference] r battery = "<<r.get_battery()<<std::endl;
}
void print_robot(const Robot& r){
	std::cout<<"[print] "<<r.get_name()<<"\n battery "<<r.get_battery()<<"%"<<std::endl;
}
int main(){
	std::cout<<"<----值传递测试----> \n";
	Robot a("A",1,100);
	std::cout<<"bafore: a battery is "<<a.get_battery()<<std::endl;
	drain_by_value(a);
	std::cout<<"after: a battery is "<<a.get_battery()<<std::endl;


        std::cout<<"<----值引用测试----> \n";
        Robot b("B",2,100);
        std::cout<<"bafore: b battery is "<<b.get_battery()<<std::endl;
        drain_by_reference(b);
        std::cout<<"after: b battery is "<<b.get_battery()<<std::endl;

	std::cout<<"<----const---->"<<std::endl;
	Robot c("C",3,77);
	print_robot(c);

	Robot barbatos("Barbatos", 1, 50);
	barbatos.set_battery(-30);
	std::cout << barbatos.get_battery() << std::endl;
	barbatos.charge(60);
	barbatos.charge(80);
	std::cout << barbatos.get_battery() << std::endl;
	//barbatos.battery_ = -999;
}
