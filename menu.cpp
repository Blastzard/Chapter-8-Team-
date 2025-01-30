#include <iostream>
using namespace std;
int menu()
{
	int choice,go=1;
	while (go==1)
	{
		cout << "Student Grades Management System\n1. Input Grades\n2. View Grades\n3.Save Grades to File\n4. Load Grades from File\n5. Load Grades from File\n6. Search for a Student by Name\n7. Sort Data\n8. Exit\n>";
		cin >> choice;
		if (cin.fail())
		{
			cout << "Please enter an integer next time\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			go = 1;
		}
		else
		{
			go = 0;
			while (choice <= 0 || choice>8)
			{
				cout << "Please input a value that is between 1-8: ";
				cin >> choice;
				if (cin.fail())
				{
					cout << "Please enter an integer next time\n\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					go = 1;
				}
			}
		}
	}
	return choice;
}