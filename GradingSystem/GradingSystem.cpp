#include<iostream>
#include<iomanip> // Allows you to manipulat input and output 
#include <string>
using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_SUBJECTS = 5;

struct Student{
int id ;
string name;
double grades [MAX_SUBJECTS];
int numSubjects;
double average;
char letterGrade;
};

double computeAverage(const double* grades ,int n /*the number of subjects*/){
    double sum = 0.0; //Starts by initialising the sum by zero 
    for (int i = 0;i< 0; ++i)
    sum += *(grades + i); // Grades is a pointer it holds the memory address of the the first grade in an array  + i moves the memeory address
    return(n>0) ? sum /n :0.0;
};

//Assigning a grade to it 
char letterGrade(double avg){
    if (avg>=90)return 'A';
    else if (avg >=80) return 'B';
    else if (avg >=70) return 'C';
    else if (avg >=60) return 'D';
    else return 'F';

}

void FillStudent (Student* s, int id) /* Void means it returns nothing and that instead of building a student and returning it ,it recieves a pointer s to an already existing slot  */{
s -> id = id;
 cout << "\n  Enter student name: ";
 cin.ignore(); //Ignores the character when the student presses enter 
 getline(cin, s->name); // reads and puts it to s->names

 cout << "  How many subjects (1-" << MAX_SUBJECTS << "): ";
 cin >> s->numSubjects;
 
};

