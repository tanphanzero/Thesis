#!/usr/bin/python3

import rospy
import math
import tf

from geometry_msgs.msg import Point, Pose, Quaternion, Twist, Vector3
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu, NavSatFix

x = 0.0
y = 0.0
th = 0.0

vx = 0
vy = 0
vth = 0


def callback(cmd_vel):
    global x, y, th, vx, vy, vth
    vx = cmd_vel.linear.x
    vth = cmd_vel.angular.z


def main():
    rospy.init_node('Serial_Bridge')
    
    imu_data = Imu()
    imu_pub = rospy.Publisher('imu/data', Imu, queue_size=10)

    odom = Odometry()
    odom_pub = rospy.Publisher('odom', Odometry, queue_size=10)

    fix = NavSatFix()
    fix_pub = rospy.Publisher('gps/fix', NavSatFix, queue_size=10)

    rospy.Subscriber('cmd_vel', Twist, callback)

    tf_broadcaster = tf.TransformBroadcaster()

    rate = rospy.Rate(50) # 50hz

    last_time = rospy.Time.now()

    while not rospy.is_shutdown():
        global x, y, th, vx, vy, vth

        current_time = rospy.Time.now()

        dt = (current_time - last_time).to_sec()
        delta_x = (vx * math.cos(th) - vy * math.sin(th)) * dt
        delta_y = (vx * math.sin(th) + vy * math.cos(th)) * dt
        delta_th = vth * dt

        x += delta_x
        y += delta_y
        th += delta_th

        odom_quat = tf.transformations.quaternion_from_euler(0, 0, th)

        # tf_broadcaster.sendTransform((x, y, 0.), odom_quat, current_time, "base_link", "odom")
        
        odom.header.stamp = current_time
        odom.header.frame_id = 'odom'

        odom.pose.pose = Pose(Point(x, y, 0.), Quaternion(*odom_quat))
        odom.child_frame_id = 'base_link'
        odom.twist.twist = Twist(Vector3(vx, vy, 0), Vector3(0, 0, vth))
        
        imu_data.orientation = Quaternion(*odom_quat)

        fix.header.stamp = current_time
        fix.header.frame_id = 'map'
        fix.latitude = 10.77203
        fix.longitude = 106.65778
        fix.altitude = 0

        odom_pub.publish(odom)
        imu_pub.publish(imu_data)
        fix_pub.publish(fix)
        last_time = current_time
        rate.sleep()


if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass
