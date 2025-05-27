//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//class Book {
//private:
//    string title;
//    string author;
//    string ISBN;
//    bool isAvailable;
//
//public:
//    Book(string t, string a, string isbn)
//        : title(t), author(a), ISBN(isbn), isAvailable(true) {
//    }
//
//    string getTitle() const { return title; }
//    string getAuthor() const { return author; }
//    string getISBN() const { return ISBN; }
//    bool getAvailability() const { return isAvailable; }
//    void setAvailability(bool avail) { isAvailable = avail; }
//};
//
//class Member {
//private:
//    string name;
//    string memberID;
//    vector<string> borrowedISBNs;
//
//public:
//    Member(string n, string id) : name(n), memberID(id) {}
//
//    string getName() const { return name; }
//    string getMemberID() const { return memberID; }
//    vector<string> getBorrowedISBNs() const { return borrowedISBNs; }
//
//    void borrowBook(const string& isbn) {
//        borrowedISBNs.push_back(isbn);
//    }
//
//    void returnBook(const string& isbn) {
//        auto it = find(borrowedISBNs.begin(), borrowedISBNs.end(), isbn);
//        if (it != borrowedISBNs.end()) {
//            borrowedISBNs.erase(it);
//        }
//    }
//
//    bool hasBorrowed(const string& isbn) const {
//        return find(borrowedISBNs.begin(), borrowedISBNs.end(), isbn) != borrowedISBNs.end();
//    }
//};
//
//class Library {
//private:
//    vector<Book> books;
//    vector<Member> members;
//
//public:
//    void addBook(const string& title, const string& author, const string& ISBN) {
//        auto it = find_if(books.begin(), books.end(), [&ISBN](const Book& b) {
//            return b.getISBN() == ISBN;
//            });
//        if (it != books.end()) {
//            cout << "Error: Book with ISBN " << ISBN << " already exists.\n";
//            return;
//        }
//        books.emplace_back(title, author, ISBN);
//        cout << "Book added successfully.\n";
//    }
//
//    void addMember(const string& name, const string& memberID) {
//        auto it = find_if(members.begin(), members.end(), [&memberID](const Member& m) {
//            return m.getMemberID() == memberID;
//            });
//        if (it != members.end()) {
//            cout << "Error: Member with ID " << memberID << " already exists.\n";
//            return;
//        }
//        members.emplace_back(name, memberID);
//        cout << "Member added successfully.\n";
//    }
//
//    void issueBook(const string& isbn, const string& memberID) {
//        auto bookIt = find_if(books.begin(), books.end(), [&isbn](const Book& b) {
//            return b.getISBN() == isbn && b.getAvailability();
//            });
//
//        if (bookIt == books.end()) {
//            cout << "Book not found or not available.\n";
//            return;
//        }
//
//        auto memberIt = find_if(members.begin(), members.end(), [&memberID](const Member& m) {
//            return m.getMemberID() == memberID;
//            });
//
//        if (memberIt == members.end()) {
//            cout << "Member not found.\n";
//            return;
//        }
//
//        bookIt->setAvailability(false);
//        memberIt->borrowBook(isbn);
//        cout << "Book '" << bookIt->getTitle() << "' issued to " << memberIt->getName() << ".\n";
//    }
//
//    void returnBook(const string& isbn, const string& memberID) {
//        auto bookIt = find_if(books.begin(), books.end(), [&isbn](const Book& b) {
//            return b.getISBN() == isbn && !b.getAvailability();
//            });
//
//        if (bookIt == books.end()) {
//            cout << "Book not found or already available.\n";
//            return;
//        }
//
//        auto memberIt = find_if(members.begin(), members.end(), [&memberID](const Member& m) {
//            return m.getMemberID() == memberID;
//            });
//
//        if (memberIt == members.end()) {
//            cout << "Member not found.\n";
//            return;
//        }
//
//        if (!memberIt->hasBorrowed(isbn)) {
//            cout << "Member did not borrow this book.\n";
//            return;
//        }
//
//        bookIt->setAvailability(true);
//        memberIt->returnBook(isbn);
//        cout << "Book '" << bookIt->getTitle() << "' returned by " << memberIt->getName() << ".\n";
//    }
//
//    void displayStatus() const {
//        cout << "\nLibrary Status:\n";
//        cout << "===============\n";
//
//        cout << "\nBooks (" << books.size() << "):\n";
//        for (const auto& book : books) {
//            cout << "- " << book.getTitle() << " by " << book.getAuthor()
//                << " (ISBN: " << book.getISBN() << ") "
//                << (book.getAvailability() ? "[Available]" : "[Borrowed]") << endl;
//        }
//
//        cout << "\nMembers (" << members.size() << "):\n";
//        for (const auto& member : members) {
//            cout << "- " << member.getName() << " (ID: " << member.getMemberID() << ")";
//            if (!member.getBorrowedISBNs().empty()) {
//                cout << "\n  Borrowed Books (" << member.getBorrowedISBNs().size() << "):";
//                for (const auto& isbn : member.getBorrowedISBNs()) {
//                    auto bookIt = find_if(books.begin(), books.end(), [&isbn](const Book& b) {
//                        return b.getISBN() == isbn;
//                        });
//                    if (bookIt != books.end()) {
//                        cout << "\n  * " << bookIt->getTitle() << " (ISBN: " << isbn << ")";
//                    }
//                }
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//};
//
//int main() {
//    Library library;
//    int choice;
//    string title, author, isbn, name, memberId;
//
//    do {
//        cout << "\nLibrary Management System\n";
//        cout << "1. Add Book\n";
//        cout << "2. Add Member\n";
//        cout << "3. Issue Book\n";
//        cout << "4. Return Book\n";
//        cout << "5. Display Status\n";
//        cout << "6. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//        cin.ignore();
//
//        switch (choice) {
//        case 1:
//            cout << "Enter book title: ";
//            getline(cin, title);
//            cout << "Enter author: ";
//            getline(cin, author);
//            cout << "Enter ISBN: ";
//            getline(cin, isbn);
//            library.addBook(title, author, isbn);
//            break;
//        case 2:
//            cout << "Enter member name: ";
//            getline(cin, name);
//            cout << "Enter member ID: ";
//            getline(cin, memberId);
//            library.addMember(name, memberId);
//            break;
//        case 3:
//            cout << "Enter ISBN of book to issue: ";
//            getline(cin, isbn);
//            cout << "Enter member ID: ";
//            getline(cin, memberId);
//            library.issueBook(isbn, memberId);
//            break;
//        case 4:
//            cout << "Enter ISBN of book to return: ";
//            getline(cin, isbn);
//            cout << "Enter member ID: ";
//            getline(cin, memberId);
//            library.returnBook(isbn, memberId);
//            break;
//        case 5:
//            library.displayStatus();
//            break;
//        case 6:
//            cout << "Exiting system...\n";
//            break;
//        default:
//            cout << "Invalid choice! Please try again.\n";
//        }
//    } while (choice != 6);
//
//    return 0;
//}