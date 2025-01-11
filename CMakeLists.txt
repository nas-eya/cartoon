cmake_minimum_required(VERSION 3.10)
project(CartoonVideoGenerator)

set(CMAKE_CXX_STANDARD 11)

# Set OpenCV_DIR to the path where OpenCVConfig.cmake is located
set(OpenCV_DIR /workspaces/cartoon/opencv/build)  # Update this path

find_package(OpenCV REQUIRED)
find_package(FFmpeg REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS} ${FFmpeg_INCLUDE_DIRS})

add_executable(CartoonVideoGenerator core/main.cpp)
target_link_libraries(CartoonVideoGenerator ${OpenCV_LIBS} ${FFmpeg_LIBRARIES})

add_executable(main_test core/main_test.cpp)
target_link_libraries(main_test gtest_main ${OpenCV_LIBS} ${FFmpeg_LIBRARIES})

add_executable(scene_manager_test core/modules/scene_renderer/scene_manager_test.cpp)
target_link_libraries(scene_manager_test gtest_main ${OpenCV_LIBS} ${FFmpeg_LIBRARIES})

include(GoogleTest)
gtest_discover_tests(main_test)
gtest_discover_tests(scene_manager_test)