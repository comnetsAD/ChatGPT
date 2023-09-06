#include <iostream>
#include <cstdlib>  //for rand() function
using namespace std;

void findMinMax(int* arr, int size, int &min, int &max) {
    min = arr[0];  //initialize min and max
    max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
}

int main() {
    int size, min, max;
    cout << "Enter size of the array: ";
    cin >> size;
    int* arr = new int[size]; //dynamically allocating memory for the array
    srand(time(0)); //seed the rand() function with current time
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101; //populating the array with random values between 0 and 100
    }
    findMinMax(arr, size, min, max);
    cout << "Minimum value: " << min << endl;
    cout << "Maximum value: " << max << endl;
    delete[] arr; //deallocating memory
    return 0;
}
