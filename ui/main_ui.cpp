#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "../FitnessTracker.h" // Link to your existing logic
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

int main() {
    // 1. Setup GLFW (Window Management)
    if (!glfwInit()) return 1;
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Sena Fitness Recon v1.0", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // 2. Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    // 3. Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Our State (Your existing data structures)
    std::vector<std::string> records;
    char activityInput[128] = "";

    // 4. Main Loop
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // --- UI WINDOW START ---
        ImGui::Begin("Fitness Tracker Dashboard");

        ImGui::Text("Welcome, Chris Sena. Track your 100-year progress.");
        ImGui::Separator();

        // Input Section
        ImGui::InputText("Activity Details", activityInput, IM_ARRAYSIZE(activityInput));
        if (ImGui::Button("Add Record")) {
            if (strlen(activityInput) > 0) {
                records.push_back(std::string(activityInput));
                activityInput[0] = '\0'; // Clear input
            }
        }

        ImGui::SameLine();
        if (ImGui::Button("Generate Random Workout")) {
            // This calls your existing logic from FitnessTracker.cpp!
            generateWorkouts(1); 
        }

        // Display Records
        ImGui::Spacing();
        if (ImGui::CollapsingHeader("Your Fitness History", ImGuiTreeNodeFlags_DefaultOpen)) {
            for (size_t i = 0; i < records.size(); ++i) {
                ImGui::BulletText("%s", records[i].c_str());
            }
        }

        if (ImGui::Button("Exit Application")) glfwSetWindowShouldClose(window, true);

        ImGui::End();
        // --- UI WINDOW END ---

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}