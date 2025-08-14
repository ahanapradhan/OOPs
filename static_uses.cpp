#include <iostream>
#include <string>
using namespace std;

// ------------------------------
// 1. Static global variable (file scope only)
// ------------------------------
static int totalSightings = 0; // Visible only in this file

// ------------------------------
// 2. Static global function (file scope only)
// ------------------------------
static void logSighting(const string& animal) {
    cout << "[LOG] " << animal << " sighted!" << endl;
}

// ------------------------------
// 3. Class with static data member and static function
// ------------------------------
class Tracker {
    string trackerName;

public:
    static int totalTrackers; // shared across all Tracker objects

    Tracker(const string& name) {
        this->trackerName = name;
        totalTrackers++;
    }

    void recordSighting(const string& animal) {
        totalSightings++;
        logSighting(animal);
        cout << trackerName << " recorded: " << animal << endl;
    }

    static void reportTotals() {
        cout << "\n=== Report ===\n";
        cout << "Total trackers: " << totalTrackers << endl;
        cout << "Total sightings: " << totalSightings << endl;
    }
};

// Definition of static member
int Tracker::totalTrackers = 0;

// ------------------------------
// 4. Static local variable in a function
// ------------------------------
void visitStation() {
    static int stationVisits = 0; // retains value between calls
    stationVisits++;
    cout << "Station visited " << stationVisits << " times today.\n";
}


// ------------------------------
// 6. Static variable inside a function
// ------------------------------
int animalIDGenerator() {
    static int id = 1000; // keeps incrementing across calls
    return ++id;
};

// ------------------------------
int main() {
    Tracker t1("Alice");
    Tracker t2("Bob");

    visitStation();
    visitStation();

    t1.recordSighting("Tiger #" + to_string(animalIDGenerator()));
    t1.recordSighting("Elephant #" + to_string(animalIDGenerator()));
    t2.recordSighting("Peacock #" + to_string(animalIDGenerator()));

    Tracker::reportTotals();
}
