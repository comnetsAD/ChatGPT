#include <iostream>
using namespace std;
int main()
{
	double assign = -1, lab = -1, midterm = -1, final = -1, total;
	char grade;

	cout << "Enter the score of assignments (out of 20): ";
	//while the user input is unacceptable
	while (!(cin >> assign) || assign < 0 || assign > 20)
	{
        cin.clear();
        //discard everything saved in the input stream
        cin.ignore();
		cout << "Enter the score of assignments (out of 20): ";
	}
	cout << "Enter the score of lab (out of 10): ";
	//while the user input is unacceptable
	while (!(cin >> lab) || lab < 0 || lab > 10)
	{
        cin.clear();
        //discard everything saved in the input stream
        cin.ignore();
		cout << "Enter the score of lab (out of 10): ";
	}
	cout << "Enter the score of midterm exam (out of 30): ";
	//while the user input is unacceptable
	while (!(cin >> midterm) || midterm < 0 || midterm > 30)
	{
        cin.clear();
        //discard everything saved in the input stream
        cin.ignore();
		cout << "Enter the score of midterm exam (out of 30): ";
	}
	cout << "Enter the score of final exam (out of 40): ";
	//while the user input is unacceptable
	while (!(cin >> final) || final < 0 || final > 40)
	{
        cin.clear();
        //discard everything saved in the input stream
        cin.ignore();
		cout << "Enter the score of final exam (out of 40): ";
	}
	//the total is the sum of all of the correctly inputted values
	total = final + midterm + lab + assign;
	cout << "Total score = " << total << endl;

	if (total >= 90)
		grade = 'A';
	else if (total >= 80)
		grade = 'B';
	else if (total >= 70)
		grade = 'C';
	else if (total >= 60)
		grade = 'D';
	else
		grade = 'F';

	cout << "Grade = " << grade << endl;
}
