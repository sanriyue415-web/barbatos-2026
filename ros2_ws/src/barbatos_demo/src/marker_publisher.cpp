#include "rclcpp/rclcpp.hpp"
#include "barbatos_demo/msg/temperature.hpp"
#include "visualization_msgs/msg/marker.hpp"

using namespace std::chrono_literals;

class TempMaker :public rclcpp::Node
{
public:
	TempMaker():Node("barbatos_marker")
	{
		marker_pub_ = this->create_publisher<visualization_msgs::msg::Marker>("barbatos_visual",10);
		subscription_= this->create_subscription<barbatos_demo::msg::Temperature>("/barbatos_topic",10,
				std::bind(&TempMaker::topic_callback,this,std::placeholders::_1));
	}
private:
	rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr marker_pub_;
	rclcpp::Subscription<barbatos_demo::msg::Temperature>::SharedPtr subscription_;
	void topic_callback(const barbatos_demo::msg::Temperature & msg)const
	{
		auto marker = visualization_msgs::msg::Marker();
		marker.header.frame_id = "world";
		marker.header.stamp = this->now();
		marker.ns = "barbatos_temperature";
		marker.type = visualization_msgs::msg::Marker::SPHERE;
		marker.action = visualization_msgs::msg::Marker::ADD;
		marker.pose.position.x = 0.0;
		marker.pose.position.y = 0.0;
		marker.pose.position.z = 1.0; //球在z=1的高度

		marker.pose.orientation.x = 0.0;
		marker.pose.orientation.y = 0.0;
		marker.pose.orientation.z = 0.0;
		marker.pose.orientation.w = 1.0;//单元四位数 = 没旋转
		float t_norm = (msg.temperature - 25.0)/(50.0 - 25.0);
		marker.scale.x=0.3 +t_norm*0.7;
		marker.scale.y=0.3 + t_norm*0.7;
		marker.scale.z=0.3 + t_norm*0.7;

		marker.color.r = t_norm;
		marker.color.g = 0.0;
		marker.color.b = 1.0 - t_norm;
		marker.color.a = 1.0;

		marker_pub_->publish(marker);
	}
};
int main(int argc,char * argv[])
{
	rclcpp::init(argc,argv);
	rclcpp::spin(std::make_shared<TempMaker>());
	rclcpp::shutdown();
	return 0;
}



