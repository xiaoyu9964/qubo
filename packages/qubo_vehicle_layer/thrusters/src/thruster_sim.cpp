#include "thruster_sim.h"

ThrusterSimNode::ThrusterSimNode(int argc, char **argv, int rate){
  ros::Rate  loop_rate(rate);
  subscriber = n.subscribe("/qubo/thrusters_input", 1000, &ThrusterSimNode::thrusterCallBack,this);
  publisher = n.advertise<std_msgs::Float64MultiArray>("/g500/thrusters_input", 1000);
  
};

ThrusterSimNode::~ThrusterSimNode(){};


void ThrusterSimNode::update(){
  ros::spinOnce(); //the only thing we care about is depth here which updated whenever we get a depth call back, on a real node we may need to do something else.
}

void ThrusterSimNode::publish(){ //We might be able to get rid of this and always just call publisher.publish 
  publisher.publish(msg);
}


void ThrusterSimNode::thrusterCallBack(const std_msgs::Float64MultiArray sim_msg)
{
  msg.data = sim_msg.data;
}
