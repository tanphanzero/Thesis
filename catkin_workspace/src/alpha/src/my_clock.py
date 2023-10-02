#!/usr/bin/python3

import rospy
from rosgraph_msgs.msg import Clock
from std_msgs.msg import String

rospy.init_node('tmp')
pub = rospy.Publisher('clock', Clock, queue_size=None)
print("node initialized")

while not rospy.is_shutdown():
    t = rospy.Time.now()
    msg = Clock()
    msg.clock = t
#    print(t.to_sec())
    pub.publish(msg)