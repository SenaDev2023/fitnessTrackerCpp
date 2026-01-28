#ifndef FITNESSTRACKER_H
#define FITNESSTRACKER_H

#include <exception>
#include <string>
#include <vector>
#include <map>

// 1. Industry Tip: Avoid 'using namespace std' in headers to prevent 100 years of naming conflicts.
// Use explicit std:: instead.

namespace FitnessCore {

    // Logic Functions (Pure data, no cin/cout)
    void addRecordDirect(std::vector<std::string>& records, const std::string& activity);
    void deleteRecordByIndex(std::vector<std::string>& records, size_t index);
    
    // Original Console Functions (Keep for backward compatibility)
    void displayHeader();
    void displayMenu();
    void addRecord(std::vector<std::string>& records); 
    void generateWorkouts(int numWorkouts);
    void generateReports(const std::vector<std::string>& records);
}

#endif