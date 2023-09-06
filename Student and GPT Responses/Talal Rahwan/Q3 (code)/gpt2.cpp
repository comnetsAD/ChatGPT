#include <iostream>
#include <cstdlib> //for rand() function
using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax findMinMax(int* arr, int size) {
    MinMax result;
    result.min = arr[0];
    result.max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < result.min) result.min = arr[i];
        if (arr[i] > result.max) result.max = arr[i];
    }
    return result;
}

int main() {
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    int* arr = new int[size]; //dynamically allocating memory for the array
    srand(time(0)); //seed the rand() function with current time
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 101; //populating the array with random values between 0 and 100
    }
    MinMax result = findMinMax(arr, size);
    cout << "Minimum value: " << result.min << endl;
    cout << "Maximum value: " << result.max << endl;
    delete[] arr; //deallocating memory
    return 0;
}
