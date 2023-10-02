#!/usr/bin/python3

import rospy
from math import pi
from std_msgs.msg import String
from geometry_msgs.msg import Twist

class ForwardBack():
    def __init__(self):
        rospy.init_node("forward_back",anonymous=True)
        self.pub = rospy.Publisher('cmd_vel',Twist,queue_size=10)
        rate = 50
        r = rospy.Rate(rate)

        linear_velocity = 0.2
        goal_distance =2
        linear_time_duration = goal_distance/linear_velocity

        angular_velocity = pi/20
        goal_angle = pi/2
        angular_time_duration = goal_angle/angular_velocity

        move_cmd = Twist()
        for j in range(2):
            for t in range(2):
                ticks = int(rate * linear_time_duration)
                move_cmd.linear.x = linear_velocity
                move_cmd.angular.z = 0

                for t in range(ticks):
                    self.pub.publish(move_cmd)
                    r.sleep()

                move_cmd = Twist()
                self.pub.publish(move_cmd)
                rospy.sleep(1)

                ticks = int(rate * angular_time_duration)
                move_cmd.linear.x = 0
                move_cmd.angular.z = angular_velocity

                for t in range(ticks):
                    self.pub.publish(move_cmd)
                    r.sleep()

                move_cmd = Twist()
                self.pub.publish(move_cmd)
                rospy.sleep(1)


if __name__ == '__main__':
    try:
        ForwardBack()
    except rospy.ROSInterruptException:
        pass