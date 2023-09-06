#include <iostream>
using namespace std;

int main() {
    double assignments, lab, midterm, final;
    double totalScore;
    string grade;

    cout << "Enter marks scored in assignments (out of 20): ";
    cin >> assignments;
    cout << "Enter marks scored in lab (out of 10): ";
    cin >> lab;
    cout << "Enter marks scored in midterm exam (out of 30): ";
    cin >> midterm;
    cout << "Enter marks scored in final exam (out of 40): ";
    cin >> final;

    totalScore = assignments + lab + midterm + final;
    double percentage = (totalScore / 100) * 100;

    if (percentage >= 90) {
        grade = "A";
    } else if (percentage >= 80) {
        grade = "B";
    } else if (percentage >= 70) {
        grade = "C";
    } else if (percentage >= 60) {
        grade = "D";
    } else {
        grade = "F";
    }

    cout << "Total Score: " << totalScore << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}
