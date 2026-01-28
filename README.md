\# 🛡️ Fitness Tracker C++ Suite 



A robust, modular fitness tracking application designed for longevity and portability. This project features a dual-interface system, allowing for both high-speed terminal interaction and a modern graphical dashboard.



\## 🚀 Project Architecture

\- \*\*FitnessCore\*\*: A decoupled C++ logic engine contained within a unique namespace to prevent naming conflicts.

\- \*\*FitnessUI\*\*: A modern graphical interface powered by \*\*Dear ImGui\*\*, \*\*GLFW\*\*, and \*\*OpenGL\*\*.

\- \*\*FitnessConsole\*\*: A classic, lightweight CLI version for rapid data entry.

\- \*\*Build System\*\*: Cross-platform \*\*CMake\*\* configuration for future-proof compilation.



\## 🛠️ Tech Stack

\- \*\*Language\*\*: C++17

\- \*\*GUI\*\*: \[Dear ImGui](https://github.com/ocornut/imgui) (Immediate Mode GUI)

\- \*\*Windowing\*\*: GLFW

\- \*\*Build Tool\*\*: CMake 3.10+

\- \*\*Compiler\*\*: GCC 15.2.0 (MSYS2/UCRT64)



\## 📁 Directory Structure

\* `ui/`: Source code for the graphical user interface.

\* `external/`: External libraries (ImGui, GLFW) managed via Git Submodules.

\* `FitnessTracker.h/cpp`: The core "engine" shared by all interfaces.

\* `main.cpp`: Entry point for the console application.

\* `CMakeLists.txt`: Global build instructions.



\## 🔨 How to Build

1\. \*\*Initialize Submodules\*\*:

&nbsp;  ```cmd

&nbsp;  git submodule update --init --recursive

