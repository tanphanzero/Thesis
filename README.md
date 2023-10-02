# Thesis
My Graduate Thesis in The University

* file robot -----> used to read encoder and control motor by MRAC controller on STM32F407
* file raspberry -----> This file is saved on raspberry pi to use to connect IMU devices (file catkin_ws/src/ros-driver_mpu9250), microcontroller STM32F407 (file catkin_ws/src/rosserial_stm32, catkin_ws/src/rosserial_python) and GNSS - RTK (file catkin_test/src/nmea_reading)
* file catkin_workspace -----> includes alpha files (used to simulate robot), navigation and my_robot (used to navigate robot), robot_localization (used to perform robot positioning), rviz_satelitte-master (used to locate robot on google map based on GNSS - RTK)
* DATN_2023.pdf is my THESIS
---------------------------------------------------------
## THESIS DESCRIPTION
- **Topic content**: Design of a self-propelled robot with the following features: localization, self-finding in outdoor environments on a fixed map (navigation), following people ( human following), identifying and counting the number of tomatoes at different levels of ripeness (tomatoes tracking), building software to help monitor and control robots and store data.
- **Model**

![266850627-8d74ffba-9b43-497a-a413-67e0cb48d76e](https://github.com/tanphanzero/Thesis/assets/85573204/7131e5fc-df70-4545-b6b4-78f20d1abc1d)

- **Block diagram of topic overview**

![270311343-578ecfb0-dbe6-47a6-87c2-9aa38ebc679c](https://github.com/tanphanzero/Thesis/assets/85573204/77daeb21-1b49-4e03-b79f-35ac04f9aac8)

![266849945-4b34ae20-9e2c-41a1-834b-58b9706973ff](https://github.com/tanphanzero/Thesis/assets/85573204/9aaa96ec-0fc1-4ad7-9674-3a228fd899bf)


---------------------------------------------------------
## WORK AND ROLE IN THESIS
* Assemble, connect hardware and write programs to transmit and receive data using communication interface (UART, I2C) between devices including Motor, STM32F407 microcontroller, Raspberry Pi embedded computer and IMU sensors (I2C ), GNSS - RTK (USART), Encoder.
* Design an adaptive controller (MRAC) for the motor.
* Use Kalman Extended filter to Fusion data from sensors (IMU, Encoder, GPS)
* Control the robot in manual mode and determine the robot's location (Localization) for indoor and outdoor environments.
* Design and simulation on RVIZ.
----------------------------------------------------------
## VIDEO DEMO
* IMU demo: https://github.com/tanphanzero/Thesis_reup/assets/85573204/3e9c99cc-c18e-44a3-9f45-4e74e866f638
* Encoder and Motor demo: https://github.com/tanphanzero/Thesis_reup/assets/85573204/425ab5c3-544b-4a5d-a0d6-b1cc1229596d
* video demo localization (Fusion data of Encoder, IMU and GNSS-RTK) -----> https://youtu.be/M6Fwr30Cngc
* video demo navigation (Me ft. Other member) ------> https://youtu.be/9cIWs4yet14
