#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    int pages;

public:

    Book(string t, int p) {
        /*do initialization of the class attributes*/
        cout << "Book created: " << title << "\n";
    }

    ~Book() {
        cout << "Book destroyed: " << title << "\n";
    }

    void show() {
        // display title and pages using cout
    }

    void addPagesFrom(Book* other) {
        // add pages of the other book to this book. When book list is displayed again, this book page numbers should be more
    }

    string getTitle() {
        // return title of the book
    }
};

// make an array of size 10 of 10 books.
// declare and initialize a variable bookCount as 0.


void createBook() {
    string title;
    int pages;

    /**
     * Write an if-block which checks if bookCount is more than 10, it prints that book store is full, and then exits the program.
     */

    cout << "Enter title: ";
    cin >> title;
    cout << "Enter pages: ";
    cin >> pages;

    /*create a new (use kew keyword) book object using title and pages as parameters to the constructor
     * add it in the global book array
     * then increase bookCount by 1.
     */
}

Book* findBookByTitle(string title) {
    for (int i = 0; i < bookCount; i++) {
        /*return the book from the global book array which matches the title*/
    }
    return NULL;
}

void showAllBooks() {
    cout << "\n===== BOOK LIST =====\n";
    for (int i = 0; i < bookCount; i++) {
        books[i]->show();
    }
    cout << "=====================\n";
}

void addBooks() {
    string t1, t2;

    cout << "Enter first book title: ";
    cin >> t1;
    cout << "Enter second book title: ";
    cin >> t2;

    Book* b1 = /*get book which has title t1, use findBookByTitle function*/
    Book* b2 = /*get book which has title t2, use findBookByTitle function*/

    if (b1 == NULL || b2 == NULL) {
        cout << "Book not found!\n";
        return;
    }

    /*call addPages method for b1 to add pages of b2 to it*/
    cout << t1 << " has more pages now\n";
}

void deleteAllBooks() {
    // delete all elements of the global book array
    // make bookCount variable as 0
}


int printMenu() {
    int choice;
    cout << "\n1. Create Book\n";
    cout << "2. Show All Books\n";
    cout << "3. Merge 2nd book to the 1st\n";
    cout << "4. Delete All Books\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    return choice;
}

int main() {
    int choice;

    while (true) {
        choice = printMenu();

        if (choice == 1) createBook();
        else if (choice == 2) showAllBooks();
        else if (choice == 3) addBooks();
        else if (choice == 4) deleteAllBooks();
        else if (choice == 5) {
            deleteAllBooks();
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
