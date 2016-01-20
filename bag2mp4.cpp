#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <rosbag/bag.h>
#include "std_msgs/UInt8MultiArray.h"
#include <rosbag/view.h>
#include <boost/foreach.hpp>
#define foreach BOOST_FOREACH

using namespace cv;

bool bag2mp4(std::string bagfile,std::string topic,std::string output){
  rosbag::Bag bag;
  bag.open(bagfile,rosbag::bagmode::Read);
  std::vector<std::string> topics;
  topics.push_back(topic);
  rosbag::View view(bag,rosbag::TopicQuery(topics));
  std::cout << topic;
  foreach(rosbag::MessageInstance const m,view){
    std_msgs::UInt8MultiArray::ConstPtr ui8 = m.instantiate<std_msgs::UInt8MultiArray>();
    if(ui8 != NULL){
      std::cout << ui8->data[0] << std::endl;
    }
    else{
      std::cout << m.getDataType();
    }
  }
}
int main(int argc, char **argv){
  if(argc < 4){
    printf("Usage: bag2mp4 filename.bag topicname output.mp4\n");
    return 0;
  }
  bag2mp4(argv[1],argv[2],argv[3]);
  return 0;
}
