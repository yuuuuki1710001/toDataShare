/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// %Tag(FULLTEXT)%
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/connection.h>
#include <beginner_tutorials/Custom.h>
#include <time.h>
#include <string>

using namespace message_filters;

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
// %Tag(CALLBACK)%
void chatterCallback(const beginner_tutorials::Custom::ConstPtr& msg1, const beginner_tutorials::Custom::ConstPtr& msg2, const beginner_tutorials::Custom::ConstPtr& msg3, const beginner_tutorials::Custom::ConstPtr& msg4, const beginner_tutorials::Custom::ConstPtr& msg5, const beginner_tutorials::Custom::ConstPtr& msg6, const beginner_tutorials::Custom::ConstPtr& msg7, const beginner_tutorials::Custom::ConstPtr& msg8, const beginner_tutorials::Custom::ConstPtr& msg9, const beginner_tutorials::Custom::ConstPtr& msg10, const beginner_tutorials::Custom::ConstPtr& msg11, const beginner_tutorials::Custom::ConstPtr& msg12, const beginner_tutorials::Custom::ConstPtr& msg13, const beginner_tutorials::Custom::ConstPtr& msg14, const beginner_tutorials::Custom::ConstPtr& msg15, const beginner_tutorials::Custom::ConstPtr& msg16)
{
  ROS_INFO("I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], I heard: [%s], now: [%u.%09u]", msg1->string.c_str(), msg2->string.c_str(), msg3->string.c_str(), msg4->string.c_str(), msg5->string.c_str(), msg6->string.c_str(), msg7->string.c_str(), msg8->string.c_str(),, msg1->string.c_str(), msg->string.c_str(), msg11->string.c_str(), msg12->string.c_str(), msg13->string.c_str(), msg14->string.c_str(), msg15->string.c_str(), msg16->string.c_str(), ros::WallTime::now().sec, ros::WallTime::now().nsec);
}
// %EndTag(CALLBACK)%

int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line. For programmatic
   * remappings you can use a different version of init() which takes remappings
   * directly, but for most command-line programs, passing argc and argv is the easiest
   * way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "listener");

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle nh;

  message_filters::Subscriber<beginner_tutorials::Custom> sub1(nh, "chatter", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub2(nh, "chatter_0", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub3(nh, "chatter_1", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub4(nh, "chatter_2", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub5(nh, "chatter_3", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub6(nh, "chatter_4", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub7(nh, "chatter_5", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub8(nh, "chatter_6", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub9(nh, "chatter_7", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub10(nh, "chatter_8", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub11(nh, "chatter_9", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub12(nh, "chatter_10", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub13(nh, "chatter_11", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub14(nh, "chatter_12", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub15(nh, "chatter_13", 1);
  message_filters::Subscriber<beginner_tutorials::Custom> sub16(nh, "chatter_14", 1);

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
   * object go out of scope, this callback will automatically be unsubscribed from
   * this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to throw
   * away the oldest ones.
   */
// %Tag(SUBSCRIBER)%
//  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
// %EndTag(SUBSCRIBER)%

  typedef sync_policies::ApproximateTime<beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom, beginner_tutorials::Custom> MySyncPolicy;
  Synchronizer<MySyncPolicy> sync(MySyncPolicy(10), sub1, sub2, sub3, sub4, sub5, sub6, sub7, sub8, sub9, sub10, sub11, sub12, sub13, sub14, sub15, sub16);
  sync.registerCallback(&chatterCallback);
  //sync.registerCallback(boost::bind(&chatterCallback, _1, _2));

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
// %Tag(SPIN)%
  ros::spin();
// %EndTag(SPIN)%

  return 0;
}
// %EndTag(FULLTEXT)%
