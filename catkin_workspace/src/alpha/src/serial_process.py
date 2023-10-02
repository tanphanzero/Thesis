#!/usr/bin/python3

import rospy
import math
import tf
from math import sin,cos,pi,sqrt
from std_msgs.msg import Float64
from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3, Vector3Stamped
from nav_msgs.msg import Odometry
from std_msgs.msg import Float32
from sensor_msgs.msg import Imu, NavSatFix

x = 0.0
y = 0.0
th = 0.0
s=0.0
vx = 0.0
vy = 0.0
vth = 0.0


def vel_callback(vel_pub):
    global x, y, th, vx, vy, vth
    vx = vel_pub.linear.x*1.8
    vy = vel_pub.linear.y*1.8
    vth = vel_pub.angular.z
# def theta_callback(theta):
#     global x, y, th, vx, vy, vth

#     th = theta.vector.z


def main():
    rospy.init_node('Serial_Process')

    odom = Odometry()
    odom_pub = rospy.Publisher('odom', Odometry, queue_size=10)
    distance = rospy.Publisher("distance",Float64,queue_size=50)
    rospy.Subscriber('vel_pub', Twist, vel_callback)
    #rospy.Subscriber('/imu/rpy/filtered', Vector3Stamped, theta_callback)

    #fix = NavSatFix()
    #fix_pub = rospy.Publisher('gps/fix', NavSatFix, queue_size=10)

    # tf_broadcaster = tf.TransformBroadcaster()

    rate = rospy.Rate(200) # 50hz

    last_time = rospy.Time.now()
    
    while not rospy.is_shutdown():
        global x, y, th, vx, vy, vth,s

        current_time = rospy.Time.now()

        dt = (current_time - last_time).to_sec()
        delta_x = (vx * math.cos(th) - vy * math.sin(th)) * dt
        delta_y = (vx * math.sin(th) + vy * math.cos(th)) * dt
        delta_th = vth * dt

        x += delta_x
        y += delta_y
        th += delta_th
        s += sqrt(delta_x**2 + delta_y**2)
        odom_quat = tf.transformations.quaternion_from_euler(0, 0, th)

        odom.header.stamp = current_time
        odom.header.frame_id = 'odom'

        odom.pose.pose = Pose(Point(x, y, 0.), Quaternion(*odom_quat))
        odom.child_frame_id = 'base_link'
        odom.twist.twist = Twist(Vector3(vx, vy, 0), Vector3(0, 0, vth))

        #fix.header.stamp = current_time
        #fix.header.frame_id = 'map'
        #fix.latitude = 10.77203
        #fix.longitude = 106.65778
        #fix.altitude = 0

        #fix_pub.publish(fix)


        odom_pub.publish(odom)
        distance.publish(s)
        last_time = current_time
        rate.sleep()


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
