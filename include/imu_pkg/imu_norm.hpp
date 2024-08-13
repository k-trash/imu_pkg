#ifndef __IMU_NORM_LIB__
#define __IMU_NORM_LIB__

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>

namespace ImuPkg{
	class ImuNorm : public rclcpp::Node{
		public:
			explicit ImuNorm(const rclcpp::NodeOptions& options);
			virtual ~ImuNorm(void);
		private:
			rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub;
			rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub;

			void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg_);
	};
}

#endif