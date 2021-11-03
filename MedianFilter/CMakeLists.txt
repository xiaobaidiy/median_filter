add_library(MedianFilter median_filter.cpp)

# INTERFACE, anybody link to this library will include CURRENT_SOURCE_DIR
# so main CMakeLists no need to include this DIR
target_include_directories(MedianFilter
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )