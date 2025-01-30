#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
void grade_output(vector<string>& students, vector<vector<double>>& grades, int, int);
double grade_input();
void analzye(vector<string>& students, vector<vector<double>>& grades, int, int);
int menu();
void sort(vector<string>& students, vector<vector<double>>& grades, int, int);
void student(vector<string>& students, vector<vector<double>>& grades, int, int);
int main()
{
	int input = 1;
	int studentnumber = 0, gradenumber = 0;
	vector<vector<double>> grades;
	vector<string> students;
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
				input = 0;
			}
			grades.resize(studentnumber, vector<double>(gradenumber));
			students.resize(studentnumber);
			for (int row = 0; row < studentnumber; row++)
			{
				string student;
				cout << "What is the students name: ";
				getline(cin, student);
				student[row];
				for (int col = 0; col < gradenumber; col++)
				{
					int grade = grade_input();
					grades[row][col] = grade;
				}
			}
		}
		else if (choice == 2)
		{
			if (input == 1)
			{
				cout << "Please input grades first\n\n";
			}
			else
			{
				grade_output(students, grades, studentnumber, gradenumber);
			}
		}
		else if (choice == 3)
		{
			if (!(input == 1))
			{
				ofstream outfile;
				outfile.open("grades.txt");
				outfile << studentnumber << "\n";
				outfile << gradenumber << "\n";
				for (int row = 0; row < studentnumber; row++)
				{
					for (int col = 0; col < gradenumber; col++)
					{
						outfile << grades[row][col] << "\n";
					}
				}
				for (int row = 0; row < studentnumber; row++)
				{
					outfile << students[row] << "\n";
				}
				outfile.close();
				cout << "Grades Successfully Added to storage";
			}
			else
			{
				cout << "You have no students entered. \n\n";
			}
		}
		else if (choice == 4)
		{
			ifstream infile;
			infile.open("grades.txt");
			if (!infile)
			{
				cout << "No File Found\n\n";
			}
			else
			{
				infile >> studentnumber;
				infile >> gradenumber;
				for (int row = 0; row < studentnumber; row++)
				{
					for (int col = 0; col < gradenumber; col++)
					{
						infile >> grades[row][col];
					}
				}
				cout << "Grades Successfully Found";
			}
		}
		else if (choice == 5)
		{
			analzye(students, grades, studentnumber, gradenumber);
		}
		else if (choice == 6)
		{
			student(students, grades, studentnumber, gradenumber);
		}
		else if (choice == 7)
		{
			sort(students, grades, studentnumber, gradenumber);
		}
		else if (choice == 8)
		{
			cout << "Thank You for using";
		}
		choice = menu();
	}
}