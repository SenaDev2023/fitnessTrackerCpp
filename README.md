# 🛡️ Fitness Tracker C++ Suite

A modular, long-lived fitness tracking system built in C++ with a clean separation between core logic and presentation. The project supports both a high-speed terminal workflow and a modern graphical dashboard without duplicating business logic.

---

## Project Architecture

- **FitnessCore**  
  Decoupled C++ domain logic contained in its own namespace to avoid symbol collisions and enable reuse across interfaces.

- **FitnessUI**  
  Graphical interface built with **Dear ImGui**, **GLFW**, and **OpenGL** for immediate feedback and low-latency interaction.

- **FitnessConsole**  
  Lightweight CLI interface optimized for fast data entry and scripting.

- **Build System**  
  Cross-platform **CMake** configuration designed for portability and long-term maintenance.

---

## Technology Stack

- **Language:** C++17  
- **GUI:** [Dear ImGui](https://github.com/ocornut/imgui) (immediate-mode GUI)  
- **Windowing:** GLFW  
- **Build Tool:** CMake 3.10+  
- **Compiler:** GCC 15.2.0 (MSYS2 / UCRT64)

---

## Directory Structure

