#ifndef FITNESSTRACKER_H
#define FITNESSTRACKER_H

#include <exception>
#include <string>
#include <vector>
#include <map>

namespace FitnessCore {

    // Logic Functions
    void addRecordDirect(std::vector<std::string>& records, const std::string& activity);
    void deleteRecordByIndex(std::vector<std::string>& records, size_t index);
    
    // Original Console Functions
    void displayHeader();
    void displayMenu();
    void addRecord(std::vector<std::string>& records); 
    void generateWorkouts(int numWorkouts);
    void generateReports(const std::vector<std::string>& records);

    // ADD THIS LINE BELOW:
    void processUserRequest(int choice, std::vector<std::string>& records);
}

#endif