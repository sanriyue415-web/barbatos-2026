cmake_minimum_required(VERSION 3.8)
project(barbatos_demo)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
find_package(rclcpp REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(rosidl_default_generators 	REQUIRED)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(publisher src/publisher_member_function.cpp)
ament_target_dependencies(publisher PUBLIC rclcpp)
target_link_libraries(publisher PUBLIC
	${PROJECT_NAME}__rosidl_typesupport_cpp)

add_executable(subscriber src/subscriber_member_function.cpp)
ament_target_dependencies(subscriber PUBLIC rclcpp)

add_executable(marker_publisher src/marker_publisher.cpp)
ament_target_dependencies(marker_publisher PUBLIC rclcpp visualization_msgs)
target_link_libraries(marker_publisher PUBLIC
${PROJECT_NAME}__rosidl_typesupport_cpp)
target_link_libraries(subscriber PUBLIC
${PROJECT_NAME}__rosidl_typesupport_cpp)


rosidl_generate_interfaces(${PROJECT_NAME}
	"msg/Temperature.msg"
)

install(TARGETS publisher subscriber marker_publisher DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
	DESTINATION share/${PROJECT_NAME}
)

ament_package()
