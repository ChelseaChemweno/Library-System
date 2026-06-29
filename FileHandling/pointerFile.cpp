
 #include <iostream>
 #include <fstream>
 #include <string>

 using namespace std;

 class Student {
    private :
    int id ;
    string name; 
    float marks ;

    public:
    Student() {
        id = 0;
        name = "";
        marks = 0;
    }
    void input (){
        cout << "Enter student ID:" <<endl;
        cin>> id;

        cout << "Enter student name: "<< endl;
        cin >> name;

        cout << "Enter student marks:"<<endl;
        cin >> marks;   
    }
    //Saving the records to a file 
    void saveToFile(){
        // ios::app this  will allow to write more contents to the file instead of overwrititng the whole file 
        ofstream file ("students.txt ", ios::app);
        file << id <<","<<name << ","<< marks << endl;
        file.close();
        cout<<"Record updated succesfully !"<<endl;
    }
      //Display the oject details
     void display(){
            cout <<"ID" <<id;
            cout <<"Student Name " <<name ;
            cout <<"Student Marks " <<marks;
        }

        // Deleting Everything from the file 
        void clearFile() {
            ofstream file("students.txt", ios::trunc);
            file.close();

            cout << "All records have been deleted.\n";
        }
 };
//  Displaying all the records in the file 
void displayStudents(){
ifstream file ("students.txt");
// So this is a variable that store each and every file it reads 
string line;

cout<< " \n These are the student records " << endl ; 
while (getline(file, line)){
cout <<line<<endl;

}
file.close();

}

int main(){
    int choice ; 
    Student s;
    
    do {
        cout<<"\n A student Database system:";
        cout<<"1.Add  Student :\n";
        cout<<"2. Display Student  \n";
        cout<<"3.Clear\n";
        cout <<"4.Exit\n";
        
        cin >> choice; 
        switch(choice){
            case 1:
            s.input();
            s.saveToFile();
            break;

            case 2:
            s.display();
            break;
            
            case 3:
            s.clearFile();

            case 4:
            cout << "Invalid Choice!";



        }
    } while (choice !=4);
    return 0;
    
}
// File handlinfg is a mechanisim in C++ TO handle files 
// fstream is used to include all file classes 
// ifstream to read from a file 
// ofstream to create /open and write a file 
// e.g ofstream myfile ("example.txt") OR 

