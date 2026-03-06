#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

int getUserNum();
string studentName();
double classAverage(int roster, int score);



int main() {
	int rosterSize;
	int score;
	string name;
	int total = 0;
	const int MAX_STUDENTS = 20;

	cout << "How many sudents?: ";
	rosterSize = getUserNum();

	if (rosterSize > 20) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input. Try again.\n";
		rosterSize;
	}
	for (int i = 0; i <= rosterSize; i++);
// recur input for name and score == inputted roster size number

	name = studentName();

		cout << "Student's grade: ";
		score = getUserNum();

		

		ofstream outFile("grades.txt", ios::app);
		time_t now = time(0);
		char dt[26];  // required buffer size
		ctime_s(dt, sizeof(dt), &now);

		outFile << name << " logged in at " << dt;
		outFile << score << "submitted at " << dt;
		outFile.close();
		score += total;
		
		
	cout << "Student Grades Report"<<endl;
	cout << "---------------------"<<endl;

	
	classAverage(rosterSize, total);
	cout << name << ":       " << score;
	return 0;
}

int getUserNum() {
	int input = -1;

	do
	{
		cin >> input;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Try again.\n";
			input = -1;
		}

	} while (input < 0);

	return input;
}

string studentName() {
	string name;
	cin.ignore();

	cout << "Student's Name: " ;
	getline(cin, name);
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Invalid input. Try again.\n";
		getline(cin, name);
		cin.ignore();
	}

	return name;
}

double classAverage(int rosterSize, int total)
{
	double  average;
	static_cast<double>(average) = total / rosterSize;
		cout << "Class Average: " << average << endl;

	return average;
}
