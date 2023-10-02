#!/usr/bin/python3

import rospy
from geometry_msgs.msg import PoseWithCovarianceStamped

def set_pose():
    # Initialize ROS node
    rospy.init_node('set_pose_publisher', anonymous=True)

    # Create publisher to publish the set_pose topic
    pub = rospy.Publisher('/set_pose', PoseWithCovarianceStamped, queue_size=10)

    # Create a message to publish
    msg = PoseWithCovarianceStamped()
    msg.header.frame_id = "map"
    msg.pose.pose.position.x = 0.0
    msg.pose.pose.position.y = 0.0
    msg.pose.pose.position.z = 0.0
    msg.pose.pose.orientation.x = 0.0
    msg.pose.pose.orientation.y = 0.0
    msg.pose.pose.orientation.z = 0.0
    msg.pose.pose.orientation.w = 1.0
    # Publish the message
    rate = rospy.Rate(10) # 10hz
    while not rospy.is_shutdown():
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        set_pose()
    except rospy.ROSInterruptException:
        pass