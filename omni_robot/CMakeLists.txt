cmake_minimum_required(VERSION 2.8.3)
project(slave_robot)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs sensor_msgs genmsg pcl_conversions pcl_ros)

## Declare ROS messages and services
add_message_files(
	FILES
	keyframeMsg.msg 
	keyframeGraphMsg.msg)

## Generate added messages and services
generate_messages(DEPENDENCIES std_msgs)

## Declare a catkin package
catkin_package()

SET (INCLUDE_DIRS "../eigen3.1/")

set(CMAKE_MODULE_PATH /home/turtlebot-3/catkin_ws/src/omni_robot)
#set(CMAKE_MODULE_PATH /home/daniel/ROS_HKUST_project/slave_robot2_catkin_ws/src/slave_robot)
find_package( Eigen3 REQUIRED )
INCLUDE_DIRECTORIES( ${EIGEN3_INCLUDE_DIR} )
SET( Sophus_INCLUDE_DIR ${Sophus_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR} )

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

##add_executable(talker src/talker.cpp)
##target_link_libraries(talker ${catkin_LIBRARIES})
##add_dependencies(talker beginner_tutorials_generate_messages_cpp)

##add_executable(listener src/listener.cpp)
##target_link_libraries(listener ${catkin_LIBRARIES})
##add_dependencies(listener beginner_tutorials_generate_messages_cpp)

##add_executable(pose src/pose.cpp)
##target_link_libraries(pose ${catkin_LIBRARIES})
##add_dependencies(pose beginner_tutorials_generate_messages_cpp)

add_executable(slave_robot src/pc_fetcher.cpp src/pc_filter.cpp src/slave_robot.cpp)
target_link_libraries(slave_robot ${catkin_LIBRARIES})
add_dependencies(slave_robot slave_robot_generate_messages_cpp)



# add_dependencies(talker beginner_tutorials_generate_messages_cpp)
# %EndTag(FULLTEXT)%
