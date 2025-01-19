#include "FitnessTracker.h"
#include <iostream>

using namespace std;

int main() {
    vector<string> records;
    int choice;

    displayHeader();

    do {
        displayMenu();
        cin >> choice;
        processUserRequest(choice, records);
        cout << endl;
    } while (choice != 6);

    return 0;
}
