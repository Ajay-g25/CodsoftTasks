#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Book structure
struct Book {
    string title;
    string author;
    string ISBN;
    bool isAvailable;
};

// Borrower structure
struct Borrower {
    string name;
    string borrowedBookISBN;
    int borrowDate;
};

// Library class
class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;

public:
    // Add a book to the library
    void addBook(string title, string author, string ISBN) {
        Book newBook{title, author, ISBN, true};
        books.push_back(newBook);
    }

    // Search for a book by title, author, or ISBN
    void searchBook(string query) {
        for (const auto& book : books) {
            if (book.title.find(query) != string::npos || book.author.find(query) != string::npos || book.ISBN.find(query) != string::npos) {
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "ISBN: " << book.ISBN << endl;
                cout << "Availability: " << (book.isAvailable ? "Available" : "Not Available") << endl;
                cout << endl;
            }
        }
    }

    // Check out a book to a borrower
    void checkoutBook(string ISBN, string borrowerName) {
        for (auto& book : books) {
            if (book.ISBN == ISBN && book.isAvailable) {
                book.isAvailable = false;
                Borrower newBorrower{borrowerName, ISBN, 0}; // Assuming today's date is 0
                borrowers.push_back(newBorrower);
                cout << "Book checked out successfully." << endl;
                return;
            }
        }
        cout << "Book not found or not available." << endl;
    }

    // Return a book
    void returnBook(string ISBN) {
        for (auto& book : books) {
            if (book.ISBN == ISBN && !book.isAvailable) {
                book.isAvailable = true;
                auto it = find_if(borrowers.begin(), borrowers.end(), [&](Borrower& borrower) { return borrower.borrowedBookISBN == ISBN; });
                if (it != borrowers.end()) {
                    borrowers.erase(it);
                    cout << "Book returned successfully." << endl;
                    return;
                }
            }
        }
        cout << "Book not found or already available." << endl;
    }

    // Calculate fine for overdue books
    void calculateFine() {
        int today = 10; // Assuming today's date is 10
        for (const auto& borrower : borrowers) {
            int overdueDays = today - borrower.borrowDate;
            if (overdueDays > 7) {
                cout << "Borrower: " << borrower.name << endl;
                cout << "Book ISBN: " << borrower.borrowedBookISBN << endl;
                cout << "Overdue days: " << overdueDays << endl;
                cout << "Fine: " << overdueDays * 0.5 << endl;
                cout << endl;
            }
        }
    }
};

int main() {
    Library library;

    // Add some sample books to the library
    library.addBook("Book1", "Author1", "ISBN1");
    library.addBook("Book2", "Author2", "ISBN2");
    library.addBook("Book3", "Author3", "ISBN3");

    while (true) {
        cout << "Library Management System" << endl;
        cout << "------------------------" << endl;
        cout << "1. Search for a book" << endl;
        cout << "2. Check out a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Calculate fine for overdue books" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer

        switch (choice) {
            case 1: {
                cout << "Enter search query (title, author, or ISBN): ";
                string query;
                getline(cin, query);
                library.searchBook(query);
                break;
            }
            case 2: {
                cout << "Enter ISBN of the book to check out: ";
                string ISBN;
                getline(cin, ISBN);
                cout << "Enter borrower's name: ";
                string borrowerName;
                getline(cin, borrowerName);
                library.checkoutBook(ISBN, borrowerName);
                break;
            }
            case 3: {
                cout << "Enter ISBN of the book to return: ";
                string ISBN;
                getline(cin, ISBN);
                library.returnBook(ISBN);
                break;
            }
            case 4: {
                library.calculateFine();
                break;
            }
            case 5: {
                cout << "Exiting..." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }

        cout << endl;
    }

    return 0;
}
