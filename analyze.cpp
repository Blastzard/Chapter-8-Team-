#include <iostream>
#include <vector>
using namespace std;
void analyze(vector<string>students, vector<vector<double>> grades, int studentnumber, int gradenumber)
{
    cout << "Student Name\tAverage Grade" << endl;

    double highest_avg = -1;  
    double lowest_avg = 101;  
    string highest_student, lowest_student; 
    vector<double> averages(studentnumber, 0); 

    for (int i = 0; i < studentnumber; i++) {
        double sum = 0;  

        for (int j = 0; j < gradenumber; j++) {
            sum += grades[i][j];
        }

        averages[i] = sum / gradenumber;

        cout << students[i] << "\t\t" << averages[i] << endl;

        if (averages[i] > highest_avg) {
            highest_avg = averages[i];
            highest_student = students[i];  
        }

        if (averages[i] < lowest_avg) {
            lowest_avg = averages[i];
            lowest_student = students[i]; 
        }
    }

    cout << "\nHighest Average: " << highest_student << " with average " << highest_avg << endl;
    cout << "Lowest Average: " << lowest_student << " with average " << lowest_avg << endl;
}






