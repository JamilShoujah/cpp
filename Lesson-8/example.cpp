// Class Book with private attributes to demonstrate encapsulation

// Constructor to initialize attributes

// Getter/Setter functions

// A member function to display book info

// Simple object usage in main


#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;

public:
    // Constructor
    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    // Getters
    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getPages() {
        return pages;
    }

    // Setters
    void setTitle(string t) {
        title = t;
    }

    void setAuthor(string a) {
        author = a;
    }

    void setPages(int p) {
        pages = p;
    }

    // Display Book Info
    void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }

    ~Book(){
        cout<<"hello rama! you are amazing!" <<endl;
    }
};

// Usage example
int main() {
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 180);
    book1.displayInfo();

    cout << "\nUpdating book title...\n";
    book1.setTitle("The Greater Gatsby");
    cout << "Updated Title: " << book1.getTitle() << endl;

    cout<<"return point";
    return 0;
}
