/*
 * main.cpp

 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 */
#include <mainpp.h>
#include <ros.h>
#include <std_msgs/String.h>

#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose2D.h>
#include <geometry_msgs/TwistStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <string>

ros::NodeHandle nh;

geometry_msgs::Pose2D initial_pose;

std_msgs::String str_msg;
geometry_msgs::Twist pose;
ros::Publisher chatter("chatter", &str_msg);
ros::Publisher output("output", &pose);
char hello[] = "Hello world ROS!";

void initial_pose_cb(const geometry_msgs::Pose2D& msg){
	initial_pose = msg;
}

ros::Subscriber<geometry_msgs::Pose2D> initial_pose_sub("/initial_pos", &initial_pose_cb);


void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}


void setup(void)
{
  nh.initNode();
  nh.advertise(chatter);
  nh.advertise(output);
  nh.subscribe(initial_pose_sub);
}

uint32_t tickstart = 0;
void loop(int* val)
{
//  str_msg.data = hello;
//  chatter.publish(&str_msg);
//
//  nh.spinOnce();
//
//  HAL_Delay(5);

//	if (nh.connected()){
//		if(HAL_GetTick() - tickstart >= 10){ // ms, 66.67hz
//			str_msg.data = hello;
//			pose.linear.x = val;
//		    chatter.publish(&str_msg);
//		    output.publish(&pose);
//
//	        tickstart = HAL_GetTick();
//	    }
//
//	}
//	nh.spinOnce();

	if (nh.connected()){
//		str_msg.data = hello;
		pose.linear.x = *val;
//		chatter.publish(&str_msg);
		output.publish(&pose);
	}
	nh.spinOnce();


}
//void setup(void)
//{
//  nh.initNode();
//  nh.advertise(chatter);
//  nh.subscribe(initial_pose_sub);
//}
//
//uint32_t tickstart = 0;
//void loop(int val)
//{
////  str_msg.data = hello;
////  chatter.publish(&str_msg);
////
////  nh.spinOnce();
////
//  HAL_Delay(50);
//	if (nh.connected()){
////		if(HAL_GetTick() - tickstart >= 15){ // ms, 66.67hz
//            str_msg.data = hello;
//		    chatter.publish(&str_msg);
//	        tickstart = HAL_GetTick();
////	    }
//
//	}
//	nh.spinOnce();
//}
