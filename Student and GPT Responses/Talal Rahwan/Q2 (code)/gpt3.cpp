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

    grade = (percentage >= 90) ? "A" : (percentage >= 80) ? "B" : (percentage >= 70) ? "C" : (percentage >= 60) ? "D" : "F";
    cout << "Total Score: " << totalScore << endl;
    cout << "Grade: " << grade << endl;
    return 0;
}
