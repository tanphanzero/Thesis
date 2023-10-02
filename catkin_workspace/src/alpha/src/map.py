#!/usr/bin/python3

import rospy
from nav_msgs.msg import OccupancyGrid

def main():
    rospy.init_node('map_publisher')

    # Load map from file
    filename = "/home/tanphan/catkin_stm32_ws/src/alpha/map/map.pgm"
    with open(filename, "r", encoding="utf8", errors='ignore') as file:
        pgm_header = file.readline()
        values = file.readline()
        print(values)
        width, height = [int(i) for i in values.split()]
        map_data = []
        for line in file:
            map_data.extend([int(i) for i in line.split()])
        print(map_data)

    # Create OccupancyGrid message
    map_msg = OccupancyGrid()
    map_msg.header.stamp = rospy.Time.now()
    map_msg.header.frame_id = "map"
    map_msg.info.resolution = 0.05 # meters/pixel
    map_msg.info.width = width
    map_msg.info.height = height
    map_msg.info.origin.position.x = -width * 0.5 * map_msg.info.resolution
    map_msg.info.origin.position.y = -height * 0.5 * map_msg.info.resolution
    map_msg.info.origin.position.z = 0
    map_msg.info.origin.orientation.x = 0
    map_msg.info.origin.orientation.y = 0
    map_msg.info.origin.orientation.z = 0
    map_msg.info.origin.orientation.w = 1
    map_msg.data = map_data

    # Publish map
    pub = rospy.Publisher('/map', OccupancyGrid, queue_size=10)
    rate = rospy.Rate(10) # 10Hz
    while not rospy.is_shutdown():
        map_msg.header.stamp = rospy.Time.now()
        pub.publish(map_msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        main()
    except rospy.ROSInterruptException:
        pass