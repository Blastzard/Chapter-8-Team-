#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for sort and binary_search
#include <iomanip>   // for setprecision
using namespace std;

// Function to calculate average
double calculate_average(const vector<double>& grades) {
    double sum = 0;
    for (double grade : grades) {
        sum += grade;
    }
    return sum / grades.size();
}

void student(vector<vector<double>> grades, vector<string> students) {
    // Sort students alphabetically to enable binary search
    sort(students.begin(), students.end());

    // Input student name to search
    string search_name;
    cout << "Enter the name of the student to search for: ";
    cin.ignore();
    getline(cin, search_name);

    // Binary search for the student
    auto it = lower_bound(students.begin(), students.end(), search_name);
    if (it != students.end() && *it == search_name) {
        // Student found
        int index = distance(students.begin(), it); // Get the index of the student
        cout << "Student found: " << students[index] << endl;

        // Display the student's grades
        cout << "Grades: ";
        for (double grade : grades[index]) {
            cout << grade << " ";
        }
        cout << endl;

        // Calculate and display the student's average
        double average = calculate_average(grades[index]);
        cout << "Average grade: " << setprecision(2) << fixed << average << endl;
    }
    else {
        cout << "Student not found." << endl;
    }
}
