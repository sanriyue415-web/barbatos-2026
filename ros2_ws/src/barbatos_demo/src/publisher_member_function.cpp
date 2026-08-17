#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class Publisher : public rclcpp::Node{
public:
	Publisher() : Node("barbatos_publisher"),count_(0){
		publisher_ =
this->create_publisher<std_msgs::msg::String>("barbatos_topic",10);
		timer_ = this->create_wall_timer(
				2000ms,std::bind(&Publisher::timer_callback,this));
	}
private:
	void timer_callback()
	{
		auto message = std_msgs::msg::String();	
		message.data =std::string("temperature:") + std::to_string(25.0 + count_ * 0.5);
		RCLCPP_INFO(this->get_logger(), "Publishing:'%s'", message.data.c_str());
		count_++;
		publisher_->publish(message);
	}
	
	rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
	rclcpp::TimerBase::SharedPtr timer_;
	size_t count_;
};

int main(int argc,char * argv[])
{
	rclcpp::init(argc,argv);
	rclcpp::spin(std::make_shared<Publisher>());
	rclcpp::shutdown();
	return 0;
}

