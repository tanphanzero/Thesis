#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from sensor_msgs.msg import Imu, MagneticField
from nav_msgs.msg import Odometry
q = [0, 0, 0, 0, 0, 0, 0]
p = [0, 0, 0, 0, 0, 0, 0]
r = [0, 0, 0, 0, 0, 0, 0]
a = [0, 0, 0, 0, 0, 0, 0]
b = [0, 0, 0, 0, 0, 0, 0]
cnt0 = 0
cnt1 = 0
cnt2 = 0
cnt3 = 0
cnt4 = 0
def euler_from_quaternion(x, y, z, w):
        """
        Convert a quaternion into euler angles (roll, pitch, yaw)
        roll is rotation around x in radians (counterclockwise)
        pitch is rotation around y in radians (counterclockwise)
        yaw is rotation around z in radians (counterclockwise)
        """
        t0 = +2.0 * (w * x + y * z)
        t1 = +1.0 - 2.0 * (x * x + y * y)
        roll_x = math.atan2(t0, t1)
     
        t2 = +2.0 * (w * y - z * x)
        t2 = +1.0 if t2 > +1.0 else t2
        t2 = -1.0 if t2 < -1.0 else t2
        pitch_y = math.asin(t2)
     
        t3 = +2.0 * (w * z + x * y)
        t4 = +1.0 - 2.0 * (y * y + z * z)
        yaw_z = math.atan2(t3, t4)
     
        return roll_x, pitch_y, yaw_z # in radians

def callback0(odom0_msg):
    global q, cnt0
    cnt0 +=  1
    if cnt0 == 15:
    	q[0] = odom0_msg.pose.pose.position.x
    	q[1] = odom0_msg.pose.pose.position.y
    	q[2] = odom0_msg.pose.pose.position.z
    	q[3] = odom0_msg.pose.pose.orientation.x
    	q[4] = odom0_msg.pose.pose.orientation.y
    	q[5] = odom0_msg.pose.pose.orientation.z
    	q[6] = odom0_msg.pose.pose.orientation.w
    	f = open("odom_filtered_local_data.csv", "a")
    	f.write("{}, {}, {}, {}, {}, {}, {}\n".format(q[0], q[1], q[2], q[3], q[4], q[5], q[6]))
    	f.close()
    	cnt0 = 0
    		
def callback1(odom1_msg):
    global p, cnt1
    cnt1 +=  1
    if cnt1 == 15:
    	p[0] = odom1_msg.pose.pose.position.x
    	p[1] = odom1_msg.pose.pose.position.y
    	p[2] = odom1_msg.pose.pose.position.z
    	p[3] = odom1_msg.pose.pose.orientation.x
    	p[4] = odom1_msg.pose.pose.orientation.y
    	p[5] = odom1_msg.pose.pose.orientation.z
    	p[6] = odom1_msg.pose.pose.orientation.w
    	g = open("odom_filtered_global_data.csv", "a")
    	g.write("{}, {}, {}, {}, {}, {}, {}\n".format(p[0], p[1], p[2], p[3], p[4], p[5], p[6]))
    	g.close()
    	cnt1 = 0
    	
def callback2(odom2_msg):
    global r, cnt2
    cnt2 +=  1
    if cnt2 == 15:
    	r[0] = odom2_msg.pose.pose.position.x
    	r[1] = odom2_msg.pose.pose.position.y
    	r[2] = odom2_msg.pose.pose.position.z
    	r[3] = odom2_msg.pose.pose.orientation.x
    	r[4] = odom2_msg.pose.pose.orientation.y
    	r[5] = odom2_msg.pose.pose.orientation.z
    	r[6] = odom2_msg.pose.pose.orientation.w
    	h = open("odom_data.csv", "a")
    	h.write("{}, {}, {}, {}, {}, {}, {}\n".format(r[0], r[1], r[2], r[3], r[4], r[5], r[6]))
    	h.close()
    	cnt2 = 0
    	
def callback3(odom3_msg):
    global a, cnt3
    cnt3 +=  1
    if cnt3 == 15:
    	a[0] = odom3_msg.pose.pose.position.x
    	a[1] = odom3_msg.pose.pose.position.y
    	a[2] = odom3_msg.pose.pose.position.z
    	a[3] = odom3_msg.pose.pose.orientation.x
    	a[4] = odom3_msg.pose.pose.orientation.y
    	a[5] = odom3_msg.pose.pose.orientation.z
    	a[6] = odom3_msg.pose.pose.orientation.w
    	i = open("gps_filterd_data.csv", "a")
    	i.write("{}, {}, {}, {}, {}, {}, {}\n".format(a[0], a[1], a[2], a[3], a[4], a[5], a[6]))
    	i.close()
    	cnt3 = 0	
    
def callback4(odom3_msg):
    global b, cnt4
    cnt4 +=  1
    if cnt4 == 15:
    	b[0] = odom3_msg.pose.pose.position.x
    	b[1] = odom3_msg.pose.pose.position.y
    	b[2] = odom3_msg.pose.pose.position.z
    	b[3] = odom3_msg.pose.pose.orientation.x
    	b[4] = odom3_msg.pose.pose.orientation.y
    	b[5] = odom3_msg.pose.pose.orientation.z
    	b[6] = odom3_msg.pose.pose.orientation.w
    	j = open("odometry_gps_data.csv", "a")
    	j.write("{}, {}, {}, {}, {}, {}, {}\n".format(b[0], b[1], b[2], b[3], b[4], b[5], b[6]))
    	j.close()
    	cnt4 = 0
    	
def listener():
    rospy.init_node('odom_data', anonymous=True)

    rospy.Subscriber("odometry/filtered/local", Odometry, callback0)

    rospy.Subscriber("odometry/filtered/global", Odometry, callback1)
    
    rospy.Subscriber("odom", Odometry, callback2)
    
    
    #rospy.Subscriber("gps/filtered", Odometry, callback3)
    
    rospy.Subscriber("odometry/gps", Odometry, callback4)
    rospy.spin()

if __name__ == '__main__':
    listener()
