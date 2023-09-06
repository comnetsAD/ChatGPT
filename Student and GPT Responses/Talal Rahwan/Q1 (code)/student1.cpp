#include <iostream>
using namespace std;
int main()
{
    float temp = 0;
    float tempf = 0;
    cout << "Hi! Please enter temperature in Celsius: " ;
    cin >> temp;
    tempf = (temp * 1.8) + 32;
    cout << "The temperature in Fahrenheit is: " << tempf << endl;
    return 0;
}

