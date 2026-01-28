cmake_minimum_required(VERSION 3.10)
project(FitnessTrackerUI)

# Use C++17 for long-term stability
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include your core logic
add_library(FitnessCore FitnessTracker.cpp)

