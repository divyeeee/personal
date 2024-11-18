#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    // Part 1: Create a set and an unordered set, and insert values
    set<int> orderedSet = {1, 2, 4, 3, 6, 2};  // Duplicate 2 will be ignored
    unordered_set<int> unorderedSet = {1, 2, 4, 3, 6, 2};  // Duplicate 2 will be ignored

    // Iterating through the ordered set
    cout << "Ordered Set contents: ";
    for (const int& val : orderedSet) {
        cout << val << " ";
    }
    cout << endl;

    // Iterating through the unordered set
    cout << "Unordered Set contents: ";
    for (const int& val : unorderedSet) {
        cout << val << " ";
    }
    cout << endl;

    // Part 2: Create an unordered map "record" to store student names and their roll numbers
    unordered_map<string, int> record;

    // Insert records of 3 students
    record["A"] = 101;
    record["B"] = 102;
    record["C"] = 103;

    // Search for the roll number of one student
    string studentName = "C";
    if (record.find(studentName) != record.end()) {
        cout << "Roll number of " << studentName << ": " << record[studentName] << endl;
    } else {
        cout << studentName << " not found in the records." << endl;
    }

    return 0;
}
