using namespace std;

int main()
{
    float ass, lab, mid, fin, total = 0;
    string grade;

    cout << "Hi!" << endl;
    cout << "Please enter the score of assignments(out of 20): " << endl;
    cin >> ass;
    if (ass > 20 || ass < 0) {
        cout << "Invalid score, please run again...";
        return -1;
    }
    //if statement does input validation
    cout << "Please enter the score of lab(out of 10): " << endl;
    cin >> lab;
    if (lab > 10 || lab < 0) {
        cout << "Invalid score, please run again...";
        return -2;
    }
    //if statement does input validation
    cout << "Please enter the score of midterm exam(out of 30): " << endl;
    cin >> mid;
    if (mid > 30 || mid < 0) {
        cout << "Invalid score, please run again...";
        return -3;
    }
    //if statement does input validation
    cout << "Please enter the score of final exam(out of 40: " << endl;
    cin >> fin;
    if (fin > 40 || fin < 0) {
        cout << "Invalid score, please run again...";
        return -4;
    }
    //if statement does input validation

    total = ass + lab + mid + fin;//formula for total
    cout << "Total score = " << total << endl;

    if (total >= 90) {
        grade = "A";
    }
    else if (total >= 80) {
        grade = "B";
    }
    else if (total >= 70) {
        grade = "C";
    }
    else if (total >= 60) {
        grade = "D";
    } else {
        grade = "F";
    }
    //if else statements to calculate grade
    cout << "Grade = " << grade;

    return 0;
}
