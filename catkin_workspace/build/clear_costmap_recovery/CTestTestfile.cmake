# CMake generated Testfile for 
# Source directory: /home/tranhieu/catkin_workspace/src/navigation/clear_costmap_recovery
# Build directory: /home/tranhieu/catkin_workspace/build/clear_costmap_recovery
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_clear_costmap_recovery_rostest_test_clear_tests.launch "/home/tranhieu/catkin_workspace/build/clear_costmap_recovery/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/tranhieu/catkin_workspace/build/clear_costmap_recovery/test_results/clear_costmap_recovery/rostest-test_clear_tests.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/tranhieu/catkin_workspace/src/navigation/clear_costmap_recovery --package=clear_costmap_recovery --results-filename test_clear_tests.xml --results-base-dir \"/home/tranhieu/catkin_workspace/build/clear_costmap_recovery/test_results\" /home/tranhieu/catkin_workspace/src/navigation/clear_costmap_recovery/test/clear_tests.launch ")
set_tests_properties(_ctest_clear_costmap_recovery_rostest_test_clear_tests.launch PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;80;add_rostest;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;100;_add_rostest_google_test;/home/tranhieu/catkin_workspace/src/navigation/clear_costmap_recovery/CMakeLists.txt;48;add_rostest_gtest;/home/tranhieu/catkin_workspace/src/navigation/clear_costmap_recovery/CMakeLists.txt;0;")
subdirs("gtest")
