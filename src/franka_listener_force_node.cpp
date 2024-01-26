#include <ros/ros.h>
#include <geometry_msgs/WrenchStamped.h>
#include <std_msgs/String.h>

void forceStateCallback(const geometry_msgs::WrenchStamped& force_state){
    ROS_INFO("Running");
    ROS_INFO("WRENCH FORCE: x : %f, y : %f, z : %f", force_state.wrench.force.x, force_state.wrench.force.y, force_state.wrench.force.z);
    ROS_INFO("WRENCH TORQUE: x : %f, y : %f, z : %f", force_state.wrench.torque.x, force_state.wrench.torque.y, force_state.wrench.torque.z);
}
int main(int argc, char** argv){

    ros::init(argc, argv, "state_listener");
    ros::NodeHandle nh;

    ros::Subscriber sub1 = nh.subscribe("/franka_state_controller/F_ext", 1000, forceStateCallback);
    ros::spinOnce();

    return 0;
    //ros::Subscriber sub2 = nh.subscribe("")
}
