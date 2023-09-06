#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
using namespace std;

void findMinMax(int array[],int arraySize, int& min , int& max);        //function declaration

int main(void)
{
        //Declare variables
        int arraySize, min, max;
        //Prompt user for the array size
        cout<<"Please enter a size for the array: ";
        cin>>arraySize;
        //Create dynamic array ( creating pointer)
        int *array = new int[arraySize];
        //Populate the array with random values
        srand(time(NULL));
        for (int j=0; j<=arraySize; j++)
        {

                array[j]= rand()%101;
                cout<<"array ["<<j<<"]"<<"= "<<array[j]<<endl;

        }
//Call function finMinMax()
         findMinMax(array,arraySize,min,max);
        delete [] array;

return 0;
}

//Function Definition / determining max and min
void findMinMax(int array[], int arraySize, int& min, int& max)
{
        min=array[0];
        max=array[0];

        for (int j=0; j<arraySize; j++) // starting from the first element in the list to the last
        {
                if(array[j]<min) //  array[i] the number in the list
                        min=array[j];

                if(array[j]>max)
                        max=array[j];
        }
        cout<<"Minimum = "<<min<<endl;
        cout<<"Maximum = "<<max<<endl;
}
