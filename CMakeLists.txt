cmake_minimum_required(VERSION 3.10)
project(FitnessTracker_Suite)

set(CMAKE_CXX_STANDARD 17)

# --- Find Dependencies ---
# These are free and standard in MSYS2
find_package(OpenGL REQUIRED)
# We assume you've added imgui and glfw as submodules in 'external/'
add_subdirectory(external/glfw)

# --- Include Directories ---
include_directories(external/imgui external/imgui/backends external/glfw/include)

# --- Source Files ---
set(IMGUI_SRCS
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)

# --- Executables ---
# 1. The Modern UI Version
add_executable(FitnessUI ui/main_ui.cpp FitnessTracker.cpp ${IMGUI_SRCS})
target_link_libraries(FitnessUI glfw OpenGL::GL)

# 2. The Legacy Console Version
add_executable(FitnessConsole main.cpp FitnessTracker.cpp)