//#include <iostream>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>  // Added this include for the remove function
//#include <string>     // Added this include for the string type
//using namespace std;
//
//// Book Class
//class Book {
//public:
//    string title, author;
//    int id;
//    bool isAvailable;
//
//    Book(int bookId, string bookTitle, string bookAuthor)
//        : id(bookId), title(bookTitle), author(bookAuthor), isAvailable(true) {
//    }
//};
//
//// Member Class
//class Member {
//public:
//    string name;
//    int memberId;
//    vector<int> borrowedBooks;
//
//    Member(int id, string memberName) : memberId(id), name(memberName) {}
//};
//
//// Library Class
//class Library {
//private:
//    vector<Book> books;
//    unordered_map<int, Member> members;
//    unordered_map<int, int> issuedBooks; // Maps book ID to member ID
//
//public:
//    void addBook(string title, string author) {
//        int bookId = books.size() + 1;
//        books.push_back(Book(bookId, title, author));
//        cout << "Book added successfully: " << title << endl;
//    }
//
//    void addMember(string name) {
//        int memberId = members.size() + 1;
//        members[memberId] = Member(memberId, name);
//        cout << "Member added: " << name << endl;
//    }
//
//    void issueBook(int bookId, int memberId) {
//        if (bookId > books.size() || bookId <= 0 || !books[bookId - 1].isAvailable) {
//            cout << "Book unavailable or invalid ID." << endl;
//            return;
//        }
//        if (members.find(memberId) == members.end()) {
//            cout << "Invalid member ID." << endl;
//            return;
//        }
//
//        books[bookId - 1].isAvailable = false;
//        members[memberId].borrowedBooks.push_back(bookId);
//        issuedBooks[bookId] = memberId;
//        cout << "Book issued to " << members[memberId].name << endl;
//    }
//
//    void returnBook(int bookId) {
//        if (issuedBooks.find(bookId) == issuedBooks.end()) {
//            cout << "Book not issued or invalid ID." << endl;
//            return;
//        }
//
//        books[bookId - 1].isAvailable = true;
//        int memberId = issuedBooks[bookId];
//        issuedBooks.erase(bookId);
//
//        auto& borrowed = members[memberId].borrowedBooks;
//        borrowed.erase(remove(borrowed.begin(), borrowed.end(), bookId), borrowed.end());
//        cout << "Book returned successfully." << endl;
//    }
//
//    void viewStatus() {
//        cout << "\nLibrary Status:\nBooks Available:\n";
//        for (const auto& book : books) {
//            cout << "ID: " << book.id << ", Title: " << book.title
//                << ", Author: " << book.author << ", Available: "
//                << (book.isAvailable ? "Yes" : "No") << endl;
//        }
//
//        cout << "\nMembers:\n";
//        for (const auto& member : members) {
//            cout << "ID: " << member.first << ", Name: " << member.second.name
//                << ", Borrowed Books: " << member.second.borrowedBooks.size() << endl;
//        }
//    }
//};
//
//// Main function to test the system
//int main() {
//    Library library;
//
//    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
//    library.addBook("1984", "George Orwell");
//    library.addBook("To Kill a Mockingbird", "Harper Lee");
//
//    library.addMember("Alice");
//    library.addMember("Bob");
//
//    library.issueBook(1, 1);
//    library.issueBook(2, 2);
//    library.viewStatus();
//
//    library.returnBook(1);
//    library.viewStatus();
//
//    return 0;
//}