#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// Define the Book structure
struct Book {
    int id;
    string title;
    string author;
    bool isAvailable;
};

// Define the BookNode structure (for the linked list)
struct BookNode {
    Book book;            // Book structure
    BookNode* next;       // Pointer to the next node
};

// LibraryManagementSystem class
class LibraryManagementSystem {
private:
    BookNode* head;    // Head pointer to the first book in the linked list
    stack<Book> undoStack, redoStack;
    int bookIDCounter;

public:
    LibraryManagementSystem() : head(nullptr), bookIDCounter(1) {
        // Pre-populating the library with 10 books
        addPredefinedBooks();
    }

    // Add predefined books to the library
    void addPredefinedBooks() {
        addBookToList("To Kill a Mockingbird", "Harper Lee");
        addBookToList("1984", "George Orwell");
        addBookToList("The Catcher in the Rye", "J.D. Salinger");
        addBookToList("The Alchemist", "Paulo Coelho");
        addBookToList("Sapiens: A Brief History of Humankind", "Yuval Noah Harari");
        addBookToList("The Power of Habit", "Charles Duhigg");
        addBookToList("Atomic Habits", "James Clear");
        addBookToList("The Great Gatsby", "F. Scott Fitzgerald");
        addBookToList("Educated", "Tara Westover");
        addBookToList("The Art of War", "Sun Tzu");
    }

    // Helper function to add a book to the list
    void addBookToList(string title, string author) {
        Book newBook;
        newBook.id = bookIDCounter++;
        newBook.title = title;
        newBook.author = author;
        newBook.isAvailable = true;

        BookNode* newNode = new BookNode{newBook, nullptr};

        // If the list is empty, set the new node as the head
        if (!head) {
            head = newNode;
        } else {
            // Traverse to the last node and add the new node
            BookNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Add a new book
    void addBook() {
        Book newBook;
        newBook.id = bookIDCounter++;
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, newBook.title);
        cout << "Enter Author: ";
        getline(cin, newBook.author);
        newBook.isAvailable = true;

        BookNode* newNode = new BookNode{newBook, nullptr};

        // If the list is empty, set the new node as the head
        if (!head) {
            head = newNode;
        } else {
            // Traverse to the last node and add the new node
            BookNode* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        undoStack.push(newBook);
        cout << "Book added successfully with ID: " << newBook.id << "\n";
    }

    // Undo the last operation (add book)
    void undo() {
        if (!undoStack.empty()) {
            Book lastBook = undoStack.top();
            undoStack.pop();
            redoStack.push(lastBook);

            // Remove the last book from the list
            if (head && head->book.id == lastBook.id) {
                BookNode* temp = head;
                head = head->next;
                delete temp;
            } else {
                BookNode* temp = head;
                while (temp && temp->next && temp->next->book.id != lastBook.id) {
                    temp = temp->next;
                }
                if (temp && temp->next) {
                    BookNode* toDelete = temp->next;
                    temp->next = temp->next->next;
                    delete toDelete;
                }
            }
            cout << "Last action undone.\n";
        } else {
            cout << "Nothing to undo.\n";
        }
    }

    // Redo the last undone operation
    void redo() {
        if (!redoStack.empty()) {
            Book lastRedo = redoStack.top();
            redoStack.pop();
            addBookToList(lastRedo.title, lastRedo.author);
            undoStack.push(lastRedo);
            cout << "Redo successful.\n";
        } else {
            cout << "Nothing to redo.\n";
        }
    }

    // Update book details
    void updateBook() {
        int id;
        cout << "Enter Book ID to update: ";
        cin >> id;
        cin.ignore();

        BookNode* temp = head;
        while (temp) {
            if (temp->book.id == id) {
                cout << "Enter new title: ";
                getline(cin, temp->book.title);
                cout << "Enter new author: ";
                getline(cin, temp->book.author);
                cout << "Book updated successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Book ID not found.\n";
    }

    // Count the number of books
    void countBooks() {
        int count = 0;
        BookNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        cout << "Total number of books: " << count << "\n";
    }

    // Show all books
    void showAllBooks() {
        if (!head) {
            cout << "No books available.\n";
            return;
        }
        cout << "\n==== Book List ====\n";
        BookNode* temp = head;
        while (temp) {
            cout << "ID: " << temp->book.id << ", Title: " << temp->book.title
                 << ", Author: " << temp->book.author
                 << ", Available: " << (temp->book.isAvailable ? "Yes" : "No") << "\n";
            temp = temp->next;
        }
    }

    // Show available books
    void showAvailableBooks() {
        bool found = false;
        cout << "\n==== Available Books ====\n";
        BookNode* temp = head;
        while (temp) {
            if (temp->book.isAvailable) {
                cout << "ID: " << temp->book.id << ", Title: " << temp->book.title
                     << ", Author: " << temp->book.author << "\n";
                found = true;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No available books at the moment.\n";
        }
    }

    // Borrow a book
    void borrowBook(int bookID) {
        BookNode* temp = head;
        while (temp) {
            if (temp->book.id == bookID) {
                if (temp->book.isAvailable) {
                    temp->book.isAvailable = false;
                    undoStack.push(temp->book);  // Push the borrowed book to undo stack
                    cout << "You have successfully borrowed: " << temp->book.title << "\n";
                    return;
                } else {
                    cout << "This book is currently unavailable.\n";
                    return;
                }
            }
            temp = temp->next;
        }
        cout << "Book ID not found.\n";
    }

    // Return a borrowed book
    void returnBook(int bookID) {
        BookNode* temp = head;
        while (temp) {
            if (temp->book.id == bookID) {
                if (!temp->book.isAvailable) {
                    temp->book.isAvailable = true;
                    undoStack.push(temp->book);  // Push the returned book to undo stack
                    cout << "You have successfully returned: " << temp->book.title << "\n";
                    return;
                } else {
                    cout << "This book was not borrowed.\n";
                    return;
                }
            }
            temp = temp->next;
        }
        cout << "Book ID not found.\n";
    }

    // Delete a book
    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;

        if (!head) {
            cout << "No books available.\n";
            return;
        }

        // Special case: if the book to be deleted is the head
        if (head->book.id == id) {
            BookNode* temp = head;
            head = head->next;
            delete temp;
            cout << "Book deleted successfully.\n";
            return;
        }

        // Traverse the list to find the book to delete
        BookNode* temp = head;
        while (temp->next && temp->next->book.id != id) {
            temp = temp->next;
        }

        if (temp->next) {
            BookNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            cout << "Book deleted successfully.\n";
        } else {
            cout << "Book ID not found.\n";
        }
    }

    // Destructor to delete all nodes and free memory
    ~LibraryManagementSystem() {
        while (head) {
            BookNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
	system("color 30");
    LibraryManagementSystem library;
    int roleChoice;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~WELCOMEEEE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TO~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\n================================~~~~~~~~~~~~~LIBRARY MANAGEMENT SYSTEM~~~~~~~~~~~====================================" << endl;

    // Role selection
    cout << "Select Role:\n1. Admin\n2. Librarian\n3. Member\nChoice: ";
    cin >> roleChoice;

    int choice;
    while (true) {
        // Admin menu options
        if (roleChoice == 1) {
             cout << "\n================================================Admin Menu============================================================\n";
            cout << "1. Add Book\n";
            cout << "2. Update Book\n";
            cout << "3. Delete Book\n";
            cout << "4. Show All Books\n";
            cout << "5. Show Available Books\n";
            cout << "6. Count Books\n";
            cout << "7. Undo\n";
            cout << "8. Redo\n";
            cout << "9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    library.addBook();
                    break;
                case 2:
                    library.updateBook();
                    break;
                case 3:
                    library.deleteBook();
                    break;
                case 4:
                    library.showAllBooks();
                    break;
                case 5:
                    library.showAvailableBooks();
                    break;
                case 6:
                    library.countBooks();
                    break;
                case 7:
                    library.undo();
                    break;
                case 8:
                    library.redo();
                    break;
                case 9:
                    cout << "Exiting the system.\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }

        // Librarian menu options
        else if (roleChoice == 2) {
             cout << "\n===============================================Librarian Menu=======================================================\n";
            cout << "1. Show All Books\n";
            cout << "2. Show Available Books\n";
            cout << "3. Borrow Book\n";
            cout << "4. Return Book\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    library.showAllBooks();
                    break;
                case 2:
                    library.showAvailableBooks();
                    break;
                case 3: {
                    int bookID;
                    cout << "Enter Book ID to borrow: ";
                    cin >> bookID;
                    library.borrowBook(bookID);
                    break;
                }
                case 4: {
                    int bookID;
                    cout << "Enter Book ID to return: ";
                    cin >> bookID;
                    library.returnBook(bookID);
                    break;
                }
                case 5:
                    cout << "Exiting the system.\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }

        // Member menu options
        else if (roleChoice == 3) {
              cout << "\n===========================================Member Menu==============================================================\n";
            cout << "1. Show All Books\n";
            cout << "2. Show Available Books\n";
            cout << "3. Borrow Book\n";
            cout << "4. Return Book\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    library.showAllBooks();
                    break;
                case 2:
                    library.showAvailableBooks();
                    break;
                case 3: {
                    int bookID;
                    cout << "Enter Book ID to borrow: ";
                    cin >> bookID;
                    library.borrowBook(bookID);
                    break;
                }
                case 4: {
                    int bookID;
                    cout << "Enter Book ID to return: ";
                    cin >> bookID;
                    library.returnBook(bookID);
                    break;
                }
                case 5:
                    cout << "Exiting the system.\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
        else {
            cout << "Invalid role. Exiting.\n";
            return 0;
        }
    }

    return 0;
}
