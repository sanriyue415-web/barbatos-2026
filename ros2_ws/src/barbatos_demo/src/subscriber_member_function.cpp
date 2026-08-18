#include "rclcpp/rclcpp.hpp"
#include "barbatos_demo/msg/temperature.hpp"
#include "rclcpp/qos.hpp"
#include <thread>
using namespace std::chrono_literals;

class Subscriber : public rclcpp::Node
{
	public:
		Subscriber():Node("barbatos_subscriber")
	{
		subscription_=this->create_subscription<barbatos_demo::msg::Temperature>(
				"barbatos_topic",rclcpp::QoS(rclcpp::KeepLast(10)),std::bind(&Subscriber::topic_callback,this,std::placeholders::_1));
	}
	
	private:
		void topic_callback(const barbatos_demo::msg::Temperature & msg)const
		{
			RCLCPP_INFO(this->get_logger(),"I heard: temp=%.2f unit=%s sensor=%s",msg.temperature,msg.unit.c_str(),msg.sensor_name.c_str());
		}

		rclcpp::Subscription<barbatos_demo::msg::Temperature>::SharedPtr subscription_;
};

int main(int argc,char * argv[])
{
	rclcpp::init(argc,argv);
	rclcpp::spin(std::make_shared<Subscriber>());
	rclcpp::shutdown();
	return 0;
}
