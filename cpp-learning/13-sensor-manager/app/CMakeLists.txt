add_executable(app main.cpp)
add_executable(test_sensor test_sensor.cpp)
target_link_libraries(app PRIVATE sensors)
target_link_libraries(test_sensor PRIVATE sensors)
