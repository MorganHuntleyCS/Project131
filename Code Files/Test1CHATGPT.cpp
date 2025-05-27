#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Book structure
struct Book {
    int id;
    string title;
    bool available;

    Book(int bookId, string bookTitle)
        : id(bookId), title(bookTitle), available(true) {}
};

// Member structure
struct Member {
    int id;
    string name;
    vector<int> borrowedBooks;

    Member() : id(0), name("") {}
    Member(int memberId, string memberName)
        : id(memberId), name(memberName) {}
};

class LibrarySystem {
private:
    vector<Book> books;
    unordered_map<int, Member> members;
    int bookCounter = 1;
    int memberCounter = 1;

    Book* findBookById(int bookId) {
        for (auto& book : books) {
            if (book.id == bookId) return &book;
        }
        return nullptr;
    }

public:
    void addBook(const string& title) {
        books.emplace_back(bookCounter++, title);
        cout << "Book added successfully.\n";
    }

    void registerMember(const string& name) {
        members[memberCounter] = Member(memberCounter, name);
        cout << "Member registered with ID: " << memberCounter++ << endl;
    }

    void issueBook(int memberId, int bookId) {
        auto memberIt = members.find(memberId);
        if (memberIt == members.end()) {
            cout << "Member not found.\n";
            return;
        }

        Book* book = findBookById(bookId);
        if (!book) {
            cout << "Book not found.\n";
            return;
        }

        if (!book->available) {
            cout << "Book is currently issued to someone else.\n";
            return;
        }

        book->available = false;
        memberIt->second.borrowedBooks.push_back(bookId);
        cout << "Book issued to " << memberIt->second.name << ".\n";
    }

    void returnBook(int memberId, int bookId) {
        auto memberIt = members.find(memberId);
        if (memberIt == members.end()) {
            cout << "Member not found.\n";
            return;
        }

        Book* book = findBookById(bookId);
        if (!book) {
            cout << "Book not found.\n";
            return;
        }

        auto& borrowed = memberIt->second.borrowedBooks;
        auto it = find(borrowed.begin(), borrowed.end(), bookId);
        if (it != borrowed.end()) {
            borrowed.erase(it);
            book->available = true;
            cout << "Book returned successfully.\n";
        }
        else {
            cout << "This book was not issued to the member.\n";
        }
    }

    void viewStatus() {
        cout << "\n=== Library Books ===\n";
        for (const auto& book : books) {
            cout << "ID: " << book.id << ", Title: " << book.title
                << ", Status: " << (book.available ? "Available" : "Issued") << endl;
        }

        cout << "\n=== Members and Borrowed Books ===\n";
        for (const auto& pair : members) {
            const Member& member = pair.second;
            cout << "ID: " << member.id << ", Name: " << member.name << ", Books: ";
            if (member.borrowedBooks.empty()) {
                cout << "None";
            }
            else {
                for (int bookId : member.borrowedBooks) {
                    cout << bookId << " ";
                }
            }
            cout << endl;
        }
    }
};

void showMenu() {
    cout << "\n--- Library Menu ---\n";
    cout << "1. Add Book\n";
    cout << "2. Register Member\n";
    cout << "3. Issue Book\n";
    cout << "4. Return Book\n";
    cout << "5. View Status\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    LibrarySystem lib;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            string title;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            lib.addBook(title);
        }
        else if (choice == 2) {
            string name;
            cout << "Enter member name: ";
            cin.ignore();
            getline(cin, name);
            lib.registerMember(name);
        }
        else if (choice == 3) {
            int memberId, bookId;
            cout << "Enter member ID: ";
            cin >> memberId;
            cout << "Enter book ID: ";
            cin >> bookId;
            lib.issueBook(memberId, bookId);
        }
        else if (choice == 4) {
            int memberId, bookId;
            cout << "Enter member ID: ";
            cin >> memberId;
            cout << "Enter book ID: ";
            cin >> bookId;
            lib.returnBook(memberId, bookId);
        }
        else if (choice == 5) {
            lib.viewStatus();
        }
        else if (choice == 6) {
            break;
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
