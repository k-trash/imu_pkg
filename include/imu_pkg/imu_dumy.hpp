#ifndef __IMU_DUMY_LIB__
#define __IMU_DUMY_LIB__

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/imu.hpp>

namespace ImuDumy{
	class ImuNode : public rclcpp::Node{
		public:
			explicit ImuNode(const rclcpp::NodeOptions& options);
			virtual ~ImuNode(void);
		private:
			rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_pub;
			rclcpp::TimerBase::SharedPtr timer;

			void timerCallback(void);
	};
}

#endif