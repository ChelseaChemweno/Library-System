//OOP libraby system 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Book {
private:
    string title;
    string author;
    bool   available;

    public:
    Book(const string& t, const string& a)
        : title(t), author(a), available(true) {}
        bool borrow() {
        if (!available) return false;
            available = false;
            return true;
         }
          void returnBook(){available = true; }
          // ✓ Add this to Book class
            void printStatus() const {
            cout << "  \"" << title << "\" by " << author
             << (available ? " [available]" : " [borrowed]") << "\n";
}

        string getTitle()  const { return title;  }
        string getAuthor() const { return author; }
         bool   isAvailable() const { return available; }

    
};

class Member {
    private:
    string        name;
    vector<string> borrowedTitles;
    public:
    explicit Member(const string& n) : name(n) {}

    void recordBorrow(const string& title) { borrowedTitles.push_back(title); }

    void recordReturn(const string& title) {
        auto it = find(borrowedTitles.begin(), borrowedTitles.end(), title);
        if (it != borrowedTitles.end()) borrowedTitles.erase(it);
}
  string getName() const { return name; }

    void printBorrowed() const {
        cout << name << " holds: ";
        if (borrowedTitles.empty()) { cout << "(none)\n"; return; }
        for (const auto& t : borrowedTitles) cout << "\"" << t << "\" ";
        cout << "\n";
}
};

class Library {
    private:
    vector<Book>   books;
    vector<Member> members;

    Book*   findBook(const string& title) {
        for (auto& b : books)
            if (b.getTitle() == title) return &b;
        return nullptr;
    }
    Member* findMember(const string& name) {
        for (auto& m : members)
            if (m.getName() == name) return &m;
        return nullptr;
    }
    public:
    void addBook(const string& title, const string& author) {
        books.emplace_back(title, author);
        cout << "Added: \"" << title << "\"\n";
    }

    void registerMember(const string& name) {
        members.emplace_back(name);
        cout << "Registered member: " << name << "\n";
    }
    void borrowBook(const string& title, const string& memberName) {
        Book*   book   = findBook(title);
        Member* member = findMember(memberName);

        if (!book)   { cout << "Book not found.\n";   return; }
        if (!member) { cout << "Member not found.\n"; return; }  

        if (book->borrow()) {
            member->recordBorrow(title);
            cout << memberName << " borrowed \"" << title << "\"\n";
        } else {
            cout << "\"" << title << "\" is not available.\n";
        }
        
    }
    
        void returnBook(const string& title, const string& memberName) {
        Book*   book   = findBook(title);
        Member* member = findMember(memberName);
        if (!book || !member) { cout << "Invalid book or member.\n"; return; }
        book->returnBook();
        member->recordReturn(title);
        cout << memberName << " returned \"" << title << "\"\n";
}
    void printAllBooks() const {
        cout << "\n--- Library Catalogue ---\n";
        for (const auto& b : books) b.printStatus();
    }
    void printMemberStatus(const string& name) {
        Member* m = findMember(name);
        if (m) m->printBorrowed();
        else cout << "Member not found.\n";
    }
};

int main(){
    Library lib;

    lib.addBook("Clean Code", "Robert Martin");
    lib.addBook("The Pragmatic Programmer", "Hunt & Thomas");
    lib.addBook("Design Patterns", "Gang of Four");

    lib.registerMember("Alice");
    lib.registerMember("Bob");

    lib.borrowBook("Clean Code", "Alice");
    lib.borrowBook("Design Patterns", "Bob");
    lib.borrowBook("Clean Code", "Bob");     // should fail — already borrowed

    lib.printAllBooks();
    lib.printMemberStatus("Alice");
    lib.printMemberStatus("Bob");

    lib.returnBook("Clean Code", "Alice");
    lib.printAllBooks();
}