#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3, Vector3Stamped
#geometry_msgs/Vector3Stamped
q = 0
cnt = 0
q1 = 0
def callback(imu_msg):
    global q, cnt, q1
    cnt +=  1
    if cnt == 10:
    	q = imu_msg.vector.z
    	q1 = q * 180 / 3.141592654
    	f = open("imu_yaw.csv", "a")
    	f.write("{}\n".format(q1))
    	f.close()
    	cnt = 0
    
def listener():
    rospy.init_node('imu_data_visualize', anonymous=True)
    rospy.Subscriber("imu/rpy/filtered", Vector3Stamped, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()
