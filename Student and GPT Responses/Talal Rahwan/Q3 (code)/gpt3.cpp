#include <iostream>
#include <cstdlib>
#include <utility>
using namespace std;

pair<int, int> findMinMax(int* arr, int size) {
    pair<int, int> result = make_pair(arr[0], arr[0]);
    for (int i = 1; i < size; i++) {
        if (arr[i] < result.first) result.first = arr[i];
        if (arr[i] > result.second) result.second = arr[i];
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
    pair<int, int> result = findMinMax(arr, size);
    cout << "Minimum value: " << result.first << endl;
    cout << "Maximum value: " << result.second << endl;
    delete[] arr; //deallocating memory
    return 0;
}
