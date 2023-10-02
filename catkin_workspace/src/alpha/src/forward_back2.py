#!/usr/bin/python3

import rospy
from math import pi
from std_msgs.msg import String
from geometry_msgs.msg import Twist

class ForwardBack():
    def __init__(self):
        rospy.init_node("forward_back",anonymous=True)
        self.pub = rospy.Publisher('cmd_vel',Twist,queue_size=10)
        rate = 100
        r = rospy.Rate(rate)



        move_cmd = Twist()
        for j in range(1):
            for t in range(1):
                linear_velocity = 0.1
                goal_distance = 1
                linear_time_duration = goal_distance/linear_velocity
                ticks = int(rate * linear_time_duration)
                move_cmd.linear.x = linear_velocity
                move_cmd.angular.z = 0

                for t in range(ticks):
                    self.pub.publish(move_cmd)
                    r.sleep()

                move_cmd = Twist()
                self.pub.publish(move_cmd)
                rospy.sleep(1)

                linear_velocity = 0.1
                goal_distance = 1
                linear_time_duration = goal_distance/linear_velocity
                ticks = int(rate * linear_time_duration)
                move_cmd.linear.x = -0.1
                move_cmd.angular.z = 0

                for t in range(ticks):
                    self.pub.publish(move_cmd)
                    r.sleep()

                move_cmd = Twist()
                self.pub.publish(move_cmd)
                rospy.sleep(1)
####-----------------------------------------------------------------------------

                linear_velocity = 0.15
                goal_distance = 1.5
                linear_time_duration = goal_distance/linear_velocity
                ticks = int(rate * linear_time_duration)
                move_cmd.linear.x = linear_velocity
                move_cmd.angular.z = 0

                for t in range(ticks):
                    self.pub.publish(move_cmd)
                    r.sleep()

                move_cmd = Twist()
                self.pub.publish(move_cmd)
                rospy.sleep(1)

                linear_velocity = 0.15
                goal_distance = 1.5
                linear_time_duration = goal_distance/linear_velocity
                ticks = int(rate * linear_time_duration)
                move_cmd.linear.x = -0.15
                move_cmd.angular.z = 0

                for t in range(ticks):
                    self.pub.publish(move_cmd)
                    r.sleep()

                move_cmd = Twist()
                self.pub.publish(move_cmd)
                rospy.sleep(1)
####-----------------------------------------------

                linear_velocity = 0.2
                goal_distance = 2
                linear_time_duration = goal_distance/linear_velocity
                ticks = int(rate * linear_time_duration)
                move_cmd.linear.x = linear_velocity
                move_cmd.angular.z = 0

                for t in range(ticks):
                    self.pub.publish(move_cmd)
                    r.sleep()

                move_cmd = Twist()
                self.pub.publish(move_cmd)
                rospy.sleep(1)

                linear_velocity = 0.2
                goal_distance = 2
                linear_time_duration = goal_distance/linear_velocity
                ticks = int(rate * linear_time_duration)
                move_cmd.linear.x = -0.2
                move_cmd.angular.z = 0

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