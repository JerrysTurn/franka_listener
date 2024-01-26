#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <std_msgs/String.h>

void stateCallback(const sensor_msgs::JointState& joint_state){
    ROS_INFO("Running");
    for(size_t i = 0; i < joint_state.name.size(); i++){
        if(joint_state.name.empty()==true){
            ROS_INFO("Joint not detected");
        } else {
            ROS_INFO("Joint name info: [%s]", joint_state.name[i].c_str());
        }

        if(joint_state.position.empty()==true){
            ROS_INFO("position value not found");
        } else {
            ROS_INFO("Joint position info: [%f]", joint_state.position[i]);
        }

        if(joint_state.velocity.empty()==true){
            ROS_INFO("velocity value not found");
        } else {
            ROS_INFO("Joint velocity info: [%f]", joint_state.velocity[i]);
        }
    }
}

int main(int argc, char **argv){
    ros::init(argc, argv, "state_listener");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/joint_states", 1000, stateCallback);

    ros::spinOnce();
    return 0;
}
