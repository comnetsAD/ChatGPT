#include <iostream>
using namespace std;

int main() {
    double assignments, lab, midterm, final;
    double totalScore;
    string grades[] = {"F", "D", "C", "B", "A"};
    int percentageThresholds[] = {60, 70, 80, 90};

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

    string grade = "F";
    for (int i = 0; i < 4; i++) {
        if (percentage >= percentageThresholds[i]) {
            grade = grades[i];
            break;
        }
    }

    cout << "Total Score: " << totalScore << endl;
    cout << "Grade: " << grade << endl;

    return 0;
}
