#include "rclcpp/rclcpp.hpp"
#include "rclcpp/qos.hpp"
#include "barbatos_demo/msg/temperature.hpp"

using namespace std::chrono_literals;

class Publisher : public rclcpp::Node{
public:
	Publisher() : Node("barbatos_publisher"),count_(0){
		publisher_ =
this->create_publisher<barbatos_demo::msg::Temperature>("barbatos_topic",rclcpp::QoS(rclcpp::KeepLast(10)));
		timer_ = this->create_wall_timer(
				500ms,std::bind(&Publisher::timer_callback,this));
	}
private:
	void timer_callback()
	{
		auto message = barbatos_demo::msg::Temperature();	
		message.temperature = 25.0 + count_ * 0.5f;
		message.unit = "C";
		message.sensor_name = "barbatos_sensor_01";
		count_++;
		RCLCPP_INFO(this->get_logger(), "Publishing:'temp=%.2f unit=%s sensor=%s'", message.temperature,message.unit.c_str(),message.sensor_name.c_str());
		publisher_->publish(message);
	}
	
	rclcpp::Publisher<barbatos_demo::msg::Temperature>::SharedPtr publisher_;
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

