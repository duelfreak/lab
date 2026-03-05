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
	const int MAX_STUDENTS = 20;

	cout << "How many sudents?: ";
	rosterSize = getUserNum();

	// recur input for name and score == inputted roster size number

	name = studentName();
	ofstream outFile("grades.txt", ios::app);
	time_t now = time(0);
	char dt[26];  // required buffer size
	ctime_s(dt, sizeof(dt), &now);
	outFile << name << " logged in at " << dt;
	outFile.close();

	cout << "Student's grade: ";
	score = getUserNum();

	return 0;
}

int getUserNum() {
	int input = -1;

	do
	{
		cin >> input; // Trying to use the Auto-Cast, so getLine wont work


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
	cin.ignore(); // Because of "cin >> input" adding a trailing newline, you need to add the ignore

	cout << "Student's Name: " << endl;
	getline(cin, name);

	cout << name;

	return name;
}

double classAverage(int rosterSize, int total)
{
	double average;
	average = total / rosterSize;
	return average;
}
