cmake_minimum_required(VERSION 3.0.2)
project(beginner_tutorials)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  sensor_msgs
  message_filters
  message_generation
  cv_bridge
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
  add_message_files(
    FILES
    Custom.msg
#   Message1.msg
#   Message2.msg
  )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages aundefined reference to `message_filters::Connection::Connection(boost::function<void ()> const&)'dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

  generate_messages(
    DEPENDENCIES
    std_msgs
    sensor_msgs
  )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
  catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES beginner_tutorials
    CATKIN_DEPENDS roscpp rospy std_msgs message_runtime
#  DEPENDS system_lib
  )

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/beginner_tutorials.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# add_executable(${PROJECT_NAME}_node src/beginner_tutorials_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# catkin_install_python(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_beginner_tutorials.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker0 src/talker0.cpp)
target_link_libraries(talker0 ${catkin_LIBRARIES})
add_dependencies(talker0 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker1 src/talker1.cpp)
target_link_libraries(talker1 ${catkin_LIBRARIES})
add_dependencies(talker1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker2 src/talker2.cpp)
target_link_libraries(talker2 ${catkin_LIBRARIES})
add_dependencies(talker2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker3 src/talker3.cpp)
target_link_libraries(talker3 ${catkin_LIBRARIES})
add_dependencies(talker3 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker4 src/talker4.cpp)
target_link_libraries(talker4 ${catkin_LIBRARIES})
add_dependencies(talker4 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker5 src/talker5.cpp)
target_link_libraries(talker5 ${catkin_LIBRARIES})
add_dependencies(talker5 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker6 src/talker6.cpp)
target_link_libraries(talker6 ${catkin_LIBRARIES})
add_dependencies(talker6 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker7 src/talker7.cpp)
target_link_libraries(talker7 ${catkin_LIBRARIES})
add_dependencies(talker7 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#add_executable(listener_2_2 src/listener_2_2.cpp)
#target_link_libraries(listener_2_2 ${catkin_LIBRARIES})
#add_dependencies(listener_2_2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


#image listener
add_executable(image_send src/image_send.cpp)
target_link_libraries(image_send ${catkin_LIBRARIES})
add_dependencies(image_send ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_recv src/image_recv.cpp)
target_link_libraries(image_recv ${catkin_LIBRARIES})
add_dependencies(image_recv ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_recv_2 src/image_recv_2.cpp)
target_link_libraries(image_recv_2 ${catkin_LIBRARIES})
add_dependencies(image_recv_2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_recv_4 src/image_recv_4.cpp)
target_link_libraries(image_recv_4 ${catkin_LIBRARIES})
add_dependencies(image_recv_4 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_recv_8 src/image_recv_8.cpp)
target_link_libraries(image_recv_8 ${catkin_LIBRARIES})
add_dependencies(image_recv_8 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


#add_executable(image_recv2 src/image_recv2.cpp)
#target_link_libraries(image_recv2 ${catkin_LIBRARIES})
#add_dependencies(image_recv2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#add_executable(image_recv4 src/image_recv4.cpp)
#target_link_libraries(image_recv4 ${catkin_LIBRARIES})
#add_dependencies(image_recv4 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#add_executable(image_recv8 src/image_recv8.cpp)
#target_link_libraries(image_recv8 ${catkin_LIBRARIES})
#add_dependencies(image_recv8 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


#simple listener
add_executable(listener_2_2 src/listener_2_2.cpp)
target_link_libraries(listener_2_2 ${catkin_LIBRARIES})
add_dependencies(listener_2_2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(listener_4_2 src/listener_4_2.cpp)
target_link_libraries(listener_4_2 ${catkin_LIBRARIES})
add_dependencies(listener_4_2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(listener_8_2 src/listener_8_2.cpp)
target_link_libraries(listener_8_2 ${catkin_LIBRARIES})
add_dependencies(listener_8_2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

#simple talker
add_executable(talker_timestamp src/talker_timestamp.cpp)
target_link_libraries(talker_timestamp ${catkin_LIBRARIES})
add_dependencies(talker_timestamp ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp0 src/talker_timestamp0.cpp)
target_link_libraries(talker_timestamp0 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp0 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp1 src/talker_timestamp1.cpp)
target_link_libraries(talker_timestamp1 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp2 src/talker_timestamp2.cpp)
target_link_libraries(talker_timestamp2 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp3 src/talker_timestamp3.cpp)
target_link_libraries(talker_timestamp3 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp3 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp4 src/talker_timestamp4.cpp)
target_link_libraries(talker_timestamp4 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp4 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp5 src/talker_timestamp5.cpp)
target_link_libraries(talker_timestamp5 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp5 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp6 src/talker_timestamp6.cpp)
target_link_libraries(talker_timestamp6 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp6 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp7 src/talker_timestamp7.cpp)
target_link_libraries(talker_timestamp7 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp7 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp8 src/talker_timestamp8.cpp)
target_link_libraries(talker_timestamp8 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp8 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp9 src/talker_timestamp9.cpp)
target_link_libraries(talker_timestamp9 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp9 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp10 src/talker_timestamp10.cpp)
target_link_libraries(talker_timestamp10 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp10 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp11 src/talker_timestamp11.cpp)
target_link_libraries(talker_timestamp11 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp11 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp12 src/talker_timestamp12.cpp)
target_link_libraries(talker_timestamp12 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp12 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp13 src/talker_timestamp13.cpp)
target_link_libraries(talker_timestamp13 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp13 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(talker_timestamp14 src/talker_timestamp14.cpp)
target_link_libraries(talker_timestamp14 ${catkin_LIBRARIES})
add_dependencies(talker_timestamp14 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})


#image talker
add_executable(image_send0 src/image_send0.cpp)
target_link_libraries(image_send0 ${catkin_LIBRARIES})
add_dependencies(image_send0 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send1 src/image_send1.cpp)
target_link_libraries(image_send1 ${catkin_LIBRARIES})
add_dependencies(image_send1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send2 src/image_send2.cpp)
target_link_libraries(image_send2 ${catkin_LIBRARIES})
add_dependencies(image_send2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send3 src/image_send3.cpp)
target_link_libraries(image_send3 ${catkin_LIBRARIES})
add_dependencies(image_send3 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send4 src/image_send4.cpp)
target_link_libraries(image_send4 ${catkin_LIBRARIES})
add_dependencies(image_send4 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send5 src/image_send5.cpp)
target_link_libraries(image_send5 ${catkin_LIBRARIES})
add_dependencies(image_send5 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send6 src/image_send6.cpp)
target_link_libraries(image_send6 ${catkin_LIBRARIES})
add_dependencies(image_send6 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send7 src/image_send7.cpp)
target_link_libraries(image_send7 ${catkin_LIBRARIES})
add_dependencies(image_send7 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send8 src/image_send8.cpp)
target_link_libraries(image_send8 ${catkin_LIBRARIES})
add_dependencies(image_send8 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send9 src/image_send9.cpp)
target_link_libraries(image_send9 ${catkin_LIBRARIES})
add_dependencies(image_send9 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send10 src/image_send10.cpp)
target_link_libraries(image_send10 ${catkin_LIBRARIES})
add_dependencies(image_send10 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send11 src/image_send11.cpp)
target_link_libraries(image_send11 ${catkin_LIBRARIES})
add_dependencies(image_send11 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send12 src/image_send12.cpp)
target_link_libraries(image_send12 ${catkin_LIBRARIES})
add_dependencies(image_send12 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send13 src/image_send13.cpp)
target_link_libraries(image_send13 ${catkin_LIBRARIES})
add_dependencies(image_send13 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

add_executable(image_send14 src/image_send14.cpp)
target_link_libraries(image_send14 ${catkin_LIBRARIES})
add_dependencies(image_send14 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

