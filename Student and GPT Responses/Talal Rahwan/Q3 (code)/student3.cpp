#include<iostream>
#include<cstdlib>
#include <time.h>
using namespace std;
void findMinMax(int[],int, int&, int&);	//function declaration
int main(void)
{
	srand(time(NULL));
	//Declare variables
	int min, max, arraySize;

	//Prompt user for the array size
	cout << "Enter the size of the array: ";
	while (!(cin >> arraySize) || arraySize <= 0)
	{
		cin.clear();
		cin.ignore();
		cout << "Incorrect input. Enter the size of the array as a positive integer: ";
	}
	//Create dynamic array
	int *array = new int[arraySize];
	//Populate the array with random values
	for (int counter = 0; counter < arraySize; counter++)
		array[counter]= rand() % 101;
	//Call function findMinMax()
	findMinMax(array, arraySize, min, max);
	//Print the values of array followed by min and max values
	for (int counter = 0; counter < arraySize; counter++)
		cout<<"array["<<counter<<"] = "<<array[counter]<<endl;
	cout<< "min: "<<min<<endl;
	cout<< "max : "<<max<<endl;
	//Do Necessary cleanup, e.g. delete dynamically allocated memory.
	delete[] array;

	return EXIT_SUCCESS;
}

//Function Definition
void findMinMax(int array[], int arraySize, int& min, int& max)
{
	//define function body.
	min = array[0];
	max = array[0];
	for (int j = 0; j < arraySize; j++)
	{
		if (array[j] > max)
			max = array[j];
		if (array[j] < min)
			min = array[j];
	}
}
