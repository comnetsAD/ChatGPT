#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int temp;
	cout<<"Enter temperature in celsius:";
	cin>>temp;
	while (cin.fail() || temp<0){
		cin.clear();
		cin.ignore();
		cout<<"Please enter a valid input:";
		cin>>temp;
	}
	int F=temp*9.0/5+32;
	cout<<"The temperature in fahrenheit is: "<<F<<endl;

	return 0;
}
