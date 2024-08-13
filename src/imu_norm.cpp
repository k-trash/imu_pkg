#include "imu_pkg/imu_norm.hpp"

#include <chrono>

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <sensor_msgs/msg/imu.hpp>

namespace ImuPkg{
	ImuNorm::ImuNorm(const rclcpp::NodeOptions& options) : rclcpp::Node("imu_norm", options){
		using namespace std::chrono_literals;

		imu_pub = this->create_publisher<sensor_msgs::msg::Imu>("/sensing/imu/imu_norm", 10);
		imu_sub = this->create_subscription<sensor_msgs::msg::Imu>("/sensing/imu/livox/imu", 10, std::bind(&ImuNorm::imuCallback, this, std::placeholders::_1));
	}

	ImuNorm::~ImuNorm(void){
		;
	}

	void ImuNorm::imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg_){
		sensor_msgs::msg::Imu imu_data;
		//double acc_norm;

		imu_data.orientation = msg_->orientation;

		imu_data.header = msg_->header;
		imu_data.angular_velocity = msg_->angular_velocity;

		//acc_norm = std::sqrt(msg_.linear_acceleration.x*msg_.linear_acceleration.x+msg_.linear_acceleration.y*msg_.linear_acceleration.y+msg_.linear_acceleration.z*msg_.linear_acceleration.z);

		imu_data.linear_acceleration.x = 9.8 * msg_->linear_acceleration.x - 0.220;
		imu_data.linear_acceleration.y = 9.8 * msg_->linear_acceleration.y + 0.120;
		imu_data.linear_acceleration.z = 9.8 * msg_->linear_acceleration.z + 0.035;

		imu_pub->publish(imu_data);
	}
}

RCLCPP_COMPONENTS_REGISTER_NODE(ImuPkg::ImuNorm)
