using namespace std;
int main()
{
    double temp;
    cout << "Enter Temperature in Celsius: ";
    //while the user's input into temp is invalid (any value not accepted by double)
    while (!(cin >> temp))
    {
        cin.clear();
        //discard everything saved in the input stream
        cin.ignore();
        cout << "Enter Temperature in Celsius: ";
    }
    //change the inputted temperature directly into fahrenheit
    temp = temp * (9.0/5.0) + 32;
    cout << "Temperature in Fahrenheit is: " << temp <<endl;
}
