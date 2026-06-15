#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    vector<string> names;
    vector<int> marks;
    vector<char> grades;

    int n;

    cout << "How many students? ";
    cin >> n;

    for (int i = 0; i < n; i++) {

        string name;
        int mark;
        char grade;

        cout << "\nEnter your name: ";
        cin >> name;

        cout << "Enter your marks: ";
        cin >> mark;

        if (mark >= 80)
            grade = 'A';
        else if (mark >= 70)
            grade = 'B';
        else if (mark >= 60)
            grade = 'C';
        else if (mark >= 50)
            grade = 'D';
        else if (mark >= 40)
            grade = 'E';
        else
            grade = 'F';

        names.push_back(name);
        marks.push_back(mark);
        grades.push_back(grade);
    }

    cout << "\nSTUDENT RESULTS\n";

    for (int i = 0; i < names.size(); i++) {
        cout << names[i]
             << "\t" << marks[i]
             << "\t" << grades[i]
             << endl;
    }

    return 0;
}

