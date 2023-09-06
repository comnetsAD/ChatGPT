#include<iostream>
#include<cstdlib>

using namespace std;

int main()
// Assignment Grade
{
    int assignment;
	cout<<"Enter the grade of assignments out of 20:";
	cin>>assignment;

// Check if user input is Invalid
    while (cin.fail() || assignment>20 || assignment<0) {
    	cin.clear();
        cin.ignore();
		cout<<"Invalid input."<<endl;
		cout<<"Enter again:";
		cin>>assignment;
	}

// Lab grade
	int lab;
	cout<<"Enter the grade of labs out of 10:";
	cin>>lab;

//check if user input is invalid
	while (cin.fail() || lab>10 || lab<0) {
		cin.clear();
        cin.ignore();
		cout<<"Invalid input."<<endl;
		cout<<"Enter again:";
		cin>>lab;
	}

// Midterm Grade
	int midterm;
	cout<<"Enter grade of midterm out of 30:";
	cin>>midterm;

// Check if user input is invalid
	while (cin.fail() || midterm>30 || midterm<0) {
		cin.clear();
        cin.ignore();
		cout<<"Invalid input."<<endl;
		cout<<"Enter again:";
		cin>>midterm;
	}

// Final Grade
	int final;
	cout<<"Enter grade of final exam out of 40:";
	cin>>final;

// Check if user input is invalid
	while (cin.fail() || final>40 || final<0) {
		cout<<"Invalid input."<<endl;
		cout<<"Enter again:";
		cin>>final;
	}

// Calculate Total Grade
int total=assignment+lab+midterm+final;
cout<<"The total grade is:"<<total<<endl;

if(total>=90) {
    cout<<"letter grade = A"<<endl;
}
else if(80<=total) {
    cout<<"letter grade = B"<<endl;
}
else if(70<=total) {
    cout<<"letter grade = C"<<endl;
}
else if(60<=total) {
    cout<<"letter grade = D"<<endl;
}
else {
    cout<<"letter grade = F"<<endl;
}
    return 0;
}
