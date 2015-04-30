#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
// PCL specific includes
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/random_sample.h>

class pc_filter{
    public:
	pc_filter();
	~pc_filter();	
	void pcCallback(const sensor_msgs::PointCloud2ConstPtr & cloud2);
	
    private:
	
	ros::NodeHandle _slaveRobot;
	ros::Subscriber _pcSub;
	ros::Publisher _pcPub;
};

