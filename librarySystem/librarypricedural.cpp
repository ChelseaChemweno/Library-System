// PROCDUERAL OOP
#include <iostream>
#include <string>
using namespace std;

const int MAX = 20;
string BookTitle[MAX];
bool BookAvailable [MAX];
int BookCount = 0;

string MemberNames[MAX];
int MemberCount = 0;

void AddBook(const string& title ){
    if (BookCount >= MAX) { cout << "library is full.\n";return;}
    BookTitle[BookCount] = title ;
    BookAvailable[BookCount] = true;
    BookCount++ ;
    cout << "Book Added Succesfully" << "\n";
}

void BorrowBook(const string& title ,const string& member) {
    for (int i = 0; i < BookCount ; i++)
    if (BookTitle[i] == title && BookAvailable[i]) {
            BookAvailable[i] = false;
              cout << member << " borrowed \"" << title << "\"\n";
            return;
}
cout << "\"" << title << "\" not available.\n";
}

void returnBook(const string& title) {
    for (int i = 0; i < BookCount; i++) {
        if (BookTitle[i] == title && !BookAvailable[i]) {
            BookAvailable[i] = true;
            cout << "\"" << title << "\" returned.\n";
            return;
        }
    }
    cout << "Book not found or already available.\n";
}
void printAllBooks() {
    cout << "\n--- Library Catalogue ---\n";
    for (int i = 0; i < BookCount; i++) {
        cout << "  " << BookTitle[i]
             << (BookAvailable[i] ? " [available]" : " [borrowed]") << "\n";
    }
}
int main (){
    AddBook("Object Oriented ");
    AddBook("Programming");
    BorrowBook("Object Oriented", "James");
    returnBook("Object Oriented");
    printAllBooks();
}

//OOP 