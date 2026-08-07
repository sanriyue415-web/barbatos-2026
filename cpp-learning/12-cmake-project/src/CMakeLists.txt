add_library(sensors distance_sensor.cpp temperature_sensor.cpp )
target_include_directories(sensors PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
