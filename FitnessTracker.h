#ifndef FITNESSTRACKER_H
#define FITNESSTRACKER_H

#include <string>
#include <vector>
#include <map>

using namespace std;

// Function declarations
void displayHeader();
void displayMenu();
string loadRecord();
void addRecord(vector<string>& records);
void deleteRecord(vector<string>& records);
void viewRecords(const vector<string>& records);
void searchRecord(const vector<string>& records);
void generateWorkouts(int numWorkouts);
void processUserRequest(int choice, vector<string>& records);
<<<<<<< HEAD
void generateReports (const vector<string>& records);
=======
>>>>>>> c5bc106cf0d196e08eeeda460bc56473f3dc538d

#endif // FITNESSTRACKER_H
