#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void findMinMax(int array[], int arraySize, int& min, int& max);	//function declaration

int main(void)
{
	//Declare variables
	int min= 0;
	int max =0;
	int arraySize = 0;

	//Prompt user for the array size
	cout << "Enter size of the array:";
	cin >> arraySize;

	//Create dynamic array
	int* array = new int[arraySize];

    // Use current time as seed for random generator
    srand(time(0));

	//Populate the array with random values using for loop
    for (int i=0; i <arraySize; i++) {
        array[i]=rand() % 100;

    }
	//Call function finMinMax()
	findMinMax(array, arraySize, min, max);
	//Print the values of array followed by min and max values
    for (int i=0; i <arraySize; i++) {
        cout << array[i] << endl;

    }
    cout << "Min: " << min <<endl;
    cout << "Max: " << max << endl;
    delete [] array;
	//Do Necessary cleanup, e.g. delete dynamically allocated memory.
	return EXIT_SUCCESS;
}

//Function Definition
void findMinMax(int array[], int arraySize, int& min, int& max)
{
	/*here we're using for loops to find the min and max values. we basically assign the first element as the
	min and max in the start and then compare all the values one by one to the min and max. if any value
	is less than the min, it gets reassigned to the min. similarly, if any value is greater than the max, it
	gets assigned to the max.
	*/

	min=array[0];
    for (int i=0; i <arraySize; i++) {

        if (array[i] < min) {
            min = array[i];
        }
    }
    max = array[0];
    for (int i=0; i <arraySize; i++) {

        if (array[i] > max) {
            max = array[i];
        }
    }
}
