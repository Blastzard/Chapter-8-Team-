#include <iostream>
using namespace std;
double grade_input()
{

	double grade;
	cout << "\nenter the grade of the student; ";
	cin >> grade;
	while (cin.fail())
	{
		cout << "\nenter a valid grade of the student; ";
		cin >> grade;
	}
	return grade;
}