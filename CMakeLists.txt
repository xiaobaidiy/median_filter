cmake_minimum_required(VERSION 3.10)

# set the project name
project(test_mf VERSION 1.0)

option(PRINT_VERSION "Print Version" ON)

# add MedianFilter library
add_subdirectory(MedianFilter)
list(APPEND EXTRA_LIBS MedianFilter)
# list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MedianFilter")

# add the executable
add_executable(test_mf main.cpp)

# link libraries
target_link_libraries(test_mf PUBLIC ${EXTRA_LIBS})

# generate a Config.h file from Config.h.in
configure_file(Config.h.in Config.h)

# Config.h will be generated in PROJECT_BINARY_DIR, so including it
# include MedianFilter header files
target_include_directories(test_mf PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           # "${EXTRA_INCLUDES}"
                           )

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

