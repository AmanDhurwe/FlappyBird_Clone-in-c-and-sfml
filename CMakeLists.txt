cmake_minimum_required(VERSION 3.10)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Include headers
include_directories(include)

# Add executable
add_executable(FlappyBird src/main.cpp src/Game.cpp src/Bird.cpp src/Pipe.cpp)

# Link SFML libraries
target_link_libraries(FlappyBird sfml-graphics sfml-window sfml-system)
