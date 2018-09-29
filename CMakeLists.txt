cmake_minimum_required(VERSION 2.8.3)
project(rostopic_sample)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  std_msgs
  roscpp
)

add_message_files(FILES MsgSample.msg)
generate_messages(DEPENDENCIES std_msgs)

catkin_package(
  LIBRARIES rostopic_sample
  CATKIN_DEPENDS std_msgs roscpp
)

include_directories(${catkin_INCLUDE_DIRS})

add_executable(
  topic_publisher src/topic_publisher.cpp
)
add_dependencies(
  topic_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(
  topic_publisher ${catkin_LIBRARIES}
)

add_executable(
  topic_subscriber1 src/topic_subscriber1.cpp
)
add_dependencies(
  topic_subscriber1 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(
  topic_subscriber1 ${catkin_LIBRARIES}
)

add_executable(
  topic_subscriber2 src/topic_subscriber2.cpp
)
add_dependencies(
  topic_subscriber2 ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}
)
target_link_libraries(
  topic_subscriber2 ${catkin_LIBRARIES}
)
