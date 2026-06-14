#include <iostream>
#include <string>
using namespace std;

int main() {
    int numStudents;
    cout << "How many students? ";
    cin >> numStudents;

    double total = 0;
    for (int i = 0; i < numStudents; i++) {
        string name;
        int grade;
        cout << "Student  name: ";
        cin >> name;

        cout << "Grade (0-100): ";
        cin >> grade;

        total += grade;
        cout << "--- Results ---" << endl;
        
        cout << name << ":  (" << /* letter grade */ ")" << endl;
    }

    cout << "Class average: " << (total / numStudents) << endl;
    return 0;
}