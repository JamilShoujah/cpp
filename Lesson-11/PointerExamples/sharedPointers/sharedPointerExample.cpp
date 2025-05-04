#include <iostream>
#include <memory>  // For shared_ptr and make_shared

using namespace std;

// A simple class to represent a Book
class Book {
public:
    string title;
    int year;

    // Constructor
    explicit Book(string t, int y) : title(t), year(y) {
        cout << "Book '" << title << "' (" << year << ") constructed!" << endl;
    }

    // Destructor
    ~Book() {
        cout << "Book '" << title << "' (" << year << ") destroyed!" << endl;
    }

    // Member function to print book details
    void printDetails() const {
        cout << "Title: " << title << ", Year: " << year << endl;
    }
};

// A function that accepts shared_ptr by reference
void printBookDetails(shared_ptr<Book> bookPtr) {
    cout << "Inside printBookDetails() - ";
    bookPtr->printDetails();
    cout << "use_count inside printBookDetails: " << bookPtr.use_count() << endl;
}

// A function that modifies the Book object via shared_ptr
void modifyBook(shared_ptr<Book> bookPtr) {
    cout << "Inside modifyBook() - ";
    bookPtr->printDetails();

    // Modifying the book's title
    bookPtr->title = "Modified Book Title";
    cout << "Modified book: ";
    bookPtr->printDetails();
}

void shared_ptr_example() {
    // Step 1: Create a shared_ptr to manage a Book object
    shared_ptr<Book> book1 = make_shared<Book>("The Great Gatsby", 1925);
    cout << "After creating book1, use_count = " << book1.use_count() << endl;  // Expected: 1

    // Step 2: Copy the shared_ptr to another shared_ptr (shared ownership)
    shared_ptr<Book> book2 = book1;
    cout << "After copying to book2, use_count = " << book1.use_count() << endl;  // Expected: 2

    // Step 3: Copy the shared_ptr again to another pointer (third owner)
    shared_ptr<Book> book3 = book1;
    cout << "After copying to book3, use_count = " << book1.use_count() << endl;  // Expected: 3

    // Step 4: Pass the shared_ptr to a function (use_count increases temporarily)
    printBookDetails(book1);
    cout << "After printBookDetails(), use_count = " << book1.use_count() << endl;  // Expected: 3

    // Step 5: Pass shared_ptr to modifyBook function (use_count still 3)
    modifyBook(book1);
    cout << "After modifyBook(), use_count = " << book1.use_count() << endl;  // Expected: 3

    // Step 6: Reset book2 (one less owner)
    book2.reset();
    cout << "After resetting book2, use_count = " << book1.use_count() << endl;  // Expected: 2

    // Step 7: Reset book3 (one more owner removed)
    book3.reset();
    cout << "After resetting book3, use_count = " << book1.use_count() << endl;  // Expected: 1

    // Step 8: Reset book1 (last owner, memory should be released)
    book1.reset();
    cout << "After resetting book1, book1 is " << (book1 ? "not null" : "null") << endl;  // Expected: null
}

int main() {
    cout << "=== Shared Pointer Detailed Example ===" << endl;
    shared_ptr_example();
    return 0;
}

// OUTPUT:
// === Shared Pointer Detailed Example ===
// Book 'The Great Gatsby' (1925) constructed!
// After creating book1, use_count = 1
// After copying to book2, use_count = 2
// After copying to book3, use_count = 3
// Inside printBookDetails() - Title: The Great Gatsby, Year: 1925
// use_count inside printBookDetails: 4
// After printBookDetails(), use_count = 3
// Inside modifyBook() - Title: The Great Gatsby, Year: 1925
// Modified book: Title: Modified Book Title, Year: 1925
// After modifyBook(), use_count = 3
// After resetting book2, use_count = 2
// After resetting book3, use_count = 1
// After resetting book1, book1 is null
// Book 'The Great Gatsby' (1925) destroyed!
