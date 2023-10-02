#!/usr/bin/python3

import rospy
from rosgraph_msgs.msg import Clock

if __name__ == '__main__':
    rospy.init_node('clock')
    pub = rospy.Publisher('/clock', Clock, queue_size=10)
    rate = rospy.Rate(10) # 10Hz
    while not rospy.is_shutdown():
        current_time = rospy.get_rostime()
        clock_msg = Clock()
        clock_msg.clock = current_time
        pub.publish(clock_msg)
        rate.sleep()