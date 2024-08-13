#include "imu_pkg/imu_norm.hpp"

#include <rclcpp/rclcpp.hpp>

int main(int argc, char *argv[]){
	rclcpp::init(argc, argv);

	rclcpp::executors::MultiThreadedExecutor exec;
	const auto publisher = std::make_shared<ImuPkg::ImuNorm>(rclcpp::NodeOptions());

	exec.add_node(publisher);

	exec.spin();

	rclcpp::shutdown();

	return 0;
}