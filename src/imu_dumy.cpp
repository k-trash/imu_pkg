#include "imu_pkg/imu_dumy.hpp"

#include <chrono>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <sensor_msgs/msg/imu.hpp>

namespace ImuDumy{
	ImuNode::ImuNode(const rclcpp::NodeOptions& options) : rclcpp::Node("imu_dumy", options){
		using namespace std::chrono_literals;

		imu_pub = this->create_publisher<sensor_msgs::msg::Imu>("imu_dumy", 10);
		timer = this->create_wall_timer(10ms, std::bind(&ImuNode::timerCallback, this));
	}

	ImuNode::~ImuNode(void){
		;
	}

	void ImuNode::timerCallback(void){
		sensor_msgs::msg::Imu imu_data;
		imu_data.orientation.x = 0;
		imu_data.orientation.y = 0;
		imu_data.orientation.z = 0;
		imu_data.orientation.w = 1;

		imu_data.header.stamp = this->get_clock()->now();
		imu_data.header.frame_id = "imu_link";

		imu_data.angular_velocity.x = 0;
		imu_data.angular_velocity.y = 0;
		imu_data.angular_velocity.z = 0;

		imu_data.linear_acceleration.x = 0;
		imu_data.linear_acceleration.y = 0;
		imu_data.linear_acceleration.z = 9.8;

		imu_pub->publish(imu_data);
	}
}

RCLCPP_COMPONENTS_REGISTER_NODE(ImuDumy::ImuNode)