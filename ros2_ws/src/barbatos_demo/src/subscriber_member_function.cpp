#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Subscriber : public rclcpp::Node
{
	public:
		Subscriber():Node("barbatos_subscriber")
	{
		subscription_=this->create_subscription<std_msgs::msg::String>(
				"barbatos_topic",10,
				std::bind(&Subscriber::topic_callback,this,std::placeholders::_1));
	}
	
	private:
		void topic_callback(const std_msgs::msg::String & msg)const
		{
			std::this_thread::sleep_for(std::chrono::seconds(5));
			RCLCPP_INFO(this->get_logger(),"I heard: '%s'",msg.data.c_str());
		}

		rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc,char * argv[])
{
	rclcpp::init(argc,argv);
	rclcpp::spin(std::make_shared<Subscriber>());
	rclcpp::shutdown();
	return 0;
}
