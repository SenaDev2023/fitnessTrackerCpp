#include <iostream>  // Fixes the 'cin' error
#include <vector>
#include <string>
#include "FitnessTracker.h"

int main() {
    std::vector<std::string> records;
    int choice = 0;

    FitnessCore::displayHeader();

    while (choice != 7) {
        FitnessCore::displayMenu();
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        
        FitnessCore::processUserRequest(choice, records);
    }

    return 0;
}