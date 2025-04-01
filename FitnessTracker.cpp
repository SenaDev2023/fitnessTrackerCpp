#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Function to display the ASCII header
void displayHeader() {
    cout << R"(
     _________
    / ======= \
   / __________\
  | ___________ |
  | | -       | |
  | |         | |
  | |_________| |________________________
  \=____________/   chris sena     
  / """"""""""" \                       /
 / ::::::::::::: \                  =D-'
(_________________)
    )" << endl;
    cout << "Welcome to the Fitness Tracker!" << endl;
    cout << "Track your activities and achieve your goals!" << endl;
    cout << "----------------------------------------------" << endl;
}

// Function to display the menu
void displayMenu() {
    cout << "Fitness Tracker Menu:" << endl;
    cout << "1.\tAdd new record." << endl;
    cout << "2.\tDelete record." << endl;
    cout << "3.\tView records." << endl;
    cout << "4.\tSearch record." << endl;
    cout << "5.\tGenerate Workouts." << endl;
    cout << "6.\tView Reports." << endl;
    cout << "7.\tQuit." << endl;
    cout << "Enter your choice: ";
}

// Function to load a record from user input
string loadRecord() {
    string record;
    cout << "Enter the fitness activity (e.g., 'Ran 5km', '30 mins Yoga'): ";
    cin.ignore(); // Clear the input buffer
    getline(cin, record);
    return record;
}

// Function to add a record
void addRecord(vector<string>& records) {
    string record = loadRecord();
    records.push_back(record);
    cout << "Record added successfully!" << endl;
}

// Function to delete a record
void deleteRecord(vector<string>& records) {
    if (records.empty()) {
        cout << "No records to delete!" << endl;
        return;
    }
    cout << "Enter the record number to delete (1 to " << records.size() << "): ";
    int index;
    cin >> index;
    if (index < 1 || index > records.size()) {
        cout << "Invalid record number!" << endl;
    } else {
        records.erase(records.begin() + index - 1);
        cout << "Record deleted successfully!" << endl;
    }
}

// Function to view all records
void viewRecords(const vector<string>& records) {
    if (records.empty()) {
        cout << "No records to display!" << endl;
    } else {
        cout << "Fitness Records:" << endl;
        for (size_t i = 0; i < records.size(); ++i) {
            cout << i + 1 << ". " << records[i] << endl;
        }
    }
}

// Function to search for a record
void searchRecord(const vector<string>& records) {
    if (records.empty()) {
        cout << "No records to search!" << endl;
        return;
    }
    cout << "Enter a keyword to search for: ";
    string keyword;
    cin.ignore(); // Clear the input buffer
    getline(cin, keyword);
    bool found = false;
    for (size_t i = 0; i < records.size(); ++i) {
        if (records[i].find(keyword) != string::npos) {
            cout << "Found: " << records[i] << " (Record #" << i + 1 << ")" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No records found with the keyword '" << keyword << "'." << endl;
    }
}

// Function to generate workouts
void generateWorkouts(int numWorkouts) {
    map<string, vector<string>> exerciseCategories = {
        {"Strength", {"press-ups", "pull-ups", "deadlifts", "squats", "KB swings", "box jumps", "med ball", "DB press", "DB flys", "upright rows", "tricep extensions"}},
        {"Agility", {"jump rope", "ninja hops", "sprints", "high knees", "bear crawl", "side hops", "double skip", "scissor kick", "shadow box"}},
        {"Flexibility", {"track stretch", "hip flexor stretch", "shoulder stretch", "quad stretch", "neck rotations", "foam rolling", "butt kicks"}},
        {"Cardio", {"running", "biking", "swimming", "hiking", "row machine", "jumping jacks"}},
        {"Core", {"crunches", "plank", "mountain climbers", "leg raises", "Russian twists", "V sit-ups"}}
    };

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < numWorkouts; ++i) {
        cout << "Workout " << i + 1 << ":" << endl;
        for (const auto& category : exerciseCategories) {
            const vector<string>& exercises = category.second;
            string randomExercise = exercises[rand() % exercises.size()];
            cout << category.first << ": " << randomExercise << endl;
        }
        cout << endl;
    }
}

// Function to generate reports
void generateReports(const vector<string>& records) {
    cout << "\nFitness Reports:" << endl;
    cout << "Total records: " << records.size() << endl;
    map<string, int> activityCount;
    for (const string& record : records) {
        activityCount[record]++;
    }
    string mostCommon;
    int maxCount = 0;
    for (const auto& pair : activityCount) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostCommon = pair.first;
        }
    }
    if (!records.empty()) {
        cout << "Most common activity: " << mostCommon << " (" << maxCount << " times)" << endl;
    }
}

// Function to process the user's menu choice
void processUserRequest(int choice, vector<string>& records) {
    switch (choice) {
        case 1:
            addRecord(records);
            break;
        case 2:
            deleteRecord(records);
            break;
        case 3:
            viewRecords(records);
            break;
        case 4:
            searchRecord(records);
            break;
        case 5:
            int numWorkouts;
            cout << "Enter the number of workouts to generate: ";
            cin >> numWorkouts;
            if (numWorkouts > 0) {
                generateWorkouts(numWorkouts);
            } else {
                cout << "Please enter a valid number greater than 0." << endl;
            }
            break;
        case 6:
            generateReports(records);
            break;
        case 7:
            cout << "Exiting the Fitness Tracker. Stay healthy!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select a number between 1 and 7." << endl;
    }
}
