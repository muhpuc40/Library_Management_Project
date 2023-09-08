#include <iostream>
#include <string>

using namespace std;

// Define the structure for a book
struct Book {
    string title;
    string author;
    string isbn;
    string publisher;
    int total_copies;
    int available_copies;
    Book* next;
};

// Function to add a new book to the linked list
void addBook(Book*& head) {
    Book* new_book = new Book;
    cout << "Enter the book information:\n";
    cout << "Title: ";
    getline(cin, new_book->title);
    cout << "Author: ";
    getline(cin, new_book->author);
    cout << "ISBN: ";
    getline(cin, new_book->isbn);
    cout << "Publisher: ";
    getline(cin, new_book->publisher);
    cout << "Total copies: ";
    cin >> new_book->total_copies;
    new_book->available_copies = new_book->total_copies;
    new_book->next = nullptr;

    // If the list is empty, set the new book as the head
    if (head == nullptr) {
        head = new_book;
        cout << "Book added successfully!\n";
        return;
    }

    // Otherwise, add the new book to the end of the list
    Book* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = new_book;
    cout << "Book added successfully!\n";
}

// Function to search for a book by title
void searchBook(Book* head) {
    string title;
    cout << "Enter the title of the book you are looking for: ";
    getline(cin, title);

    // Traverse the list to find the book with the given title
    Book* current = head;
    while (current != nullptr) {
        if (current->title == title) {
            cout << "Title: " << current->title << endl;
            cout << "Author: " << current->author << endl;
            cout << "ISBN: " << current->isbn << endl;
            cout << "Publisher: " << current->publisher << endl;
            cout << "Total copies: " << current->total_copies << endl;
            cout << "Available copies: " << current->available_copies << endl;
            return;
        }
        current = current->next;
    }

    cout << "Book not found in the library.\n";
}

int main() {
    Book* head = nullptr;
    int choice;

    while (true) {
        cout << "\n-- Library Management System --\n";
        cout << "1. Add a new book\n";
        cout << "2. Search for a book\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addBook(head);
                break;
            case 2:
                searchBook(head);
                break;
            case 3:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

