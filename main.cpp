#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void grade_output();
double grade_input();
void analzye();
int menu();
void sort();
void student();
int main()
{
	int choice = menu();
	while (!(choice == 8))
	{
		if (choice == 1)
		{
			int studentnumber, gradenumber, go = 1;
			while (go == 1)
			{
				cout << "How Many Students do you want to add: ";
				cin >> studentnumber;
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
					while (studentnumber <= 0 || studentnumber > 8)
					{
						cout << "Please input a number more than 0: ";
						cin >> studentnumber;
						if (cin.fail())
						{
							cout << "Please enter an integer next time\n\n";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							go = 1;
						}
					}
					cout << "How Many Grades are going to be added: ";
					cin >> gradenumber;
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
						while (gradenumber < 1)
						{
							cout << "Please input a number more than 0: ";
							cin >> studentnumber;
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
			}
			vector<vector<double>> grades(studentnumber, vector<double>(gradenumber));
			vector<string>students;
			for (int row = 0; row < studentnumber; ++row)
			{
				string student;
				cout << "What is the students name: ";
				getline(cin,student);
				student[row]
				for (int col = 0; col < gradenumber; ++col)
				{
					int grade = grade_input();
					grades[row][col]=grade;
				}
			}
		}
		choice = menu();
	}


}