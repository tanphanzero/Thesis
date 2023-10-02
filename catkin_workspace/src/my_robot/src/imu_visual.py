#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Imu, MagneticField

q = [0, 0, 0, 0, 0, 0]

def callback(imu_msg):
    global q
    q[0] = imu_msg.angular_velocity.x
    q[1] = imu_msg.angular_velocity.y
    q[2] = imu_msg.angular_velocity.z
    q[3] = imu_msg.linear_acceleration.x
    q[4] = imu_msg.linear_acceleration.y
    q[5] = imu_msg.linear_acceleration.z
    f = open("imu_data.txt", "a")
    f.write("{}, {}, {}, {}, {}, {}\n".format(q[0], q[1], q[2], q[3], q[4], q[5]))
    f.close()
    
    
def listener():
    rospy.init_node('imu_data_visualize', anonymous=True)

    rospy.Subscriber("imu/data_orig", Imu, callback)

    rospy.spin()

if __name__ == '__main__':
    listener()
