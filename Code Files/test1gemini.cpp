//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <limits> // Required for numeric_limits
//
//// --- Book Class ---
//class Book {
//private:
//    int bookId;
//    std::string title;
//    std::string author;
//    std::string publisher;
//    std::string isbn;
//    bool isAvailable;
//    static int nextBookId;
//
//public:
//    Book(std::string title, std::string author, std::string publisher, std::string isbn)
//        : title(title), author(author), publisher(publisher), isbn(isbn), isAvailable(true) {
//        this->bookId = ++nextBookId;
//    }
//
//    int getBookId() const { return bookId; }
//    std::string getTitle() const { return title; }
//    std::string getAuthor() const { return author; }
//    std::string getPublisher() const { return publisher; }
//    std::string getIsbn() const { return isbn; }
//    bool getIsAvailable() const { return isAvailable; }
//
//    void borrowBook() {
//        if (isAvailable) {
//            isAvailable = false;
//        }
//        else {
//            std::cout << "Book is already borrowed." << std::endl;
//        }
//    }
//
//    void returnBook() {
//        if (!isAvailable) {
//            isAvailable = true;
//        }
//        else {
//            std::cout << "Book is already available." << std::endl;
//        }
//    }
//
//    void display() const {
//        std::cout << "  ID: " << bookId << std::endl;
//        std::cout << "  Title: " << title << std::endl;
//        std::cout << "  Author: " << author << std::endl;
//        std::cout << "  Publisher: " << publisher << std::endl;
//        std::cout << "  ISBN: " << isbn << std::endl;
//        std::cout << "  Availability: " << (isAvailable ? "Available" : "Borrowed") << std::endl;
//    }
//};
//
//int Book::nextBookId = 0;
//
//// --- Member Class ---
//class Member {
//private:
//    int memberId;
//    std::string name;
//    std::string address;
//    std::string phone;
//    std::vector<int> borrowedBooks; // Stores book IDs
//    static int nextMemberId;
//
//public:
//    Member(std::string name, std::string address, std::string phone)
//        : name(name), address(address), phone(phone) {
//        this->memberId = ++nextMemberId;
//    }
//
//    int getMemberId() const { return memberId; }
//    std::string getName() const { return name; }
//    std::string getAddress() const { return address; }
//    std::string getPhone() const { return phone; }
//    const std::vector<int>& getBorrowedBooks() const { return borrowedBooks; }
//
//    void borrowBook(int bookId) {
//        borrowedBooks.push_back(bookId);
//    }
//
//    void returnBook(int bookId) {
//        for (size_t i = 0; i < borrowedBooks.size(); ++i) {
//            if (borrowedBooks[i] == bookId) {
//                borrowedBooks.erase(borrowedBooks.begin() + i);
//                return;
//            }
//        }
//        std::cout << "Error: Member did not borrow this book." << std::endl;
//    }
//
//    void display() const {
//        std::cout << "  ID: " << memberId << std::endl;
//        std::cout << "  Name: " << name << std::endl;
//        std::cout << "  Address: " << address << std::endl;
//        std::cout << "  Phone: " << phone << std::endl;
//        std::cout << "  Borrowed Books: ";
//        if (borrowedBooks.empty()) {
//            std::cout << "None";
//        }
//        else {
//            for (int id : borrowedBooks) {
//                std::cout << id << " ";
//            }
//        }
//        std::cout << std::endl;
//    }
//};
//
//int Member::nextMemberId = 0;
//
//// --- Library Class ---
//class Library {
//private:
//    std::map<int, Book> books;
//    std::map<int, Member> members;
//    std::vector<std::string> allBookTitles; // Stores all book names ever added
//
//public:
//    void addBook(const std::string& title, const std::string& author, const std::string& publisher, const std::string& isbn) {
//        Book newBook(title, author, publisher, isbn);
//        books.insert({ newBook.getBookId(), newBook });
//        allBookTitles.push_back(title); // Store the title
//        std::cout << "Book '" << title << "' (ID: " << newBook.getBookId() << ") added successfully." << std::endl;
//    }
//
//    void addMember(const std::string& name, const std::string& address, const std::string& phone) {
//        Member newMember(name, address, phone);
//        members.insert({ newMember.getMemberId(), newMember });
//        std::cout << "Member '" << name << "' (ID: " << newMember.getMemberId() << ") added successfully." << std::endl;
//    }
//
//    void issueBook(int bookId, int memberId) {
//        auto bookIt = books.find(bookId);
//        auto memberIt = members.find(memberId);
//
//        if (bookIt == books.end()) {
//            std::cout << "Error: Book with ID " << bookId << " not found." << std::endl;
//            return;
//        }
//        if (memberIt == members.end()) {
//            std::cout << "Error: Member with ID " << memberId << " not found." << std{ ::cout << "Error: Book with ID " << bookId << " is already borrowed." << std::endl;
//            return;
//            }
//
//                // Update book availability in the map
//            bookIt->second.borrowBook();
//            // Update member's borrowed books
//            memberIt->second.borrowBook(bookId);
//
//            std::cout << "Book '" << bookIt->second.getTitle() << "' issued to member '" << memberIt->second.getName() << "' successfully." << std::endl;
//        }
//
//        void returnBook(int bookId, int memberId) {
//            auto bookIt = books.find(bookId);
//            auto memberIt = members.find(memberId);
//
//            if (bookIt == books.end()) {
//                std::cout << "Error: Book with ID " << bookId << " not found." << std::endl;
//                return;
//            }
//            if (memberIt == members.end()) {
//                std::cout << "Error: Member with ID " << memberId << " not found." << std::endl;
//                return;
//            }
//
//            if (bookIt->second.getIsAvailable()) {
//                std::cout << "Error: Book with ID " << bookId << " is already available." << std::endl;
//                return;
//            }
//
//            // Update book availability
//            bookIt->second.returnBook();
//            // Update member's borrowed books
//            memberIt->second.returnBook(bookId);
//
//            std::cout << "Book '" << bookIt->second.getTitle() << "' returned by member '" << memberIt->second.getName() << "' successfully." << std::endl;
//        }
//
//        void viewAllBooks() const {
//            if (books.empty()) {
//                std::cout << "No books in the library." << std::endl;
//                return;
//            }
//            std::cout << "\n--- All Books in Library ---" << std::endl;
//            for (const auto& pair : books) {
//                pair.second.display();
//                std::cout << "--------------------------" << std::endl;
//            }
//        }
//
//        void viewAllMembers() const {
//            if (members.empty()) {
//                std::cout << "No members registered." << std::endl;
//                return;
//            }
//            std::cout << "\n--- All Members ---" << std::endl;
//            for (const auto& pair : members) {
//                pair.second.display();
//                std::cout << "--------------------------" << std::endl;
//            }
//        }
//
//        void viewSystemStatus() const {
//            int availableBooks = 0;
//            int borrowedBooks = 0;
//            for (const auto& pair : books) {
//                if (pair.second.getIsAvailable()) {
//                    availableBooks++;
//                }
//                else {
//                    borrowedBooks++;
//                }
//            }
//            std::cout << "\n--- Library System Status ---" << std::endl;
//            std::cout << "Total Books: " << books.size() << std::endl;
//            std::cout << "Available Books: " << availableBooks << std::endl;
//            std::cout << "Borrowed Books: " << borrowedBooks << std::endl;
//            std::cout << "Total Members: " << members.size() << std::endl;
//            std::cout << "-----------------------------" << std::endl;
//        }
//
//        void viewAllBookTitles() const {
//            if (allBookTitles.empty()) {
//                std::cout << "No book titles recorded yet." << std::endl;
//                return;
//            }
//            std::cout << "\n--- All Recorded Book Titles ---" << std::endl;
//            for (const std::string& title : allBookTitles) {
//                std::cout << "- " << title << std::endl;
//            }
//            std::cout << "--------------------------------" << std::endl;
//        }
//    };
//
//    // --- Main Function (User Interface) ---
//    void displayMenu() {
//        std::cout << "\n--- Library Management System ---" << std::endl;
//        std::cout << "1. Add New Book" << std::endl;
//        std::cout << "2. Add New Member" << std::endl;
//        std::cout << "3. Issue Book" << std::endl;
//        std::cout << "4. Return Book" << std::endl;
//        std::cout << "5. View All Books" << std::endl;
//        std::cout << "6. View All Members" << std::endl;
//        std::cout << "7. View System Status" << std::endl;
//        std::cout << "8. View All Book Titles (including deleted/unavailable)" << std::endl;
//        std::cout << "9. Exit" << std::endl;
//        std::cout << "Enter your choice: ";
//    }
//
//    int main() {
//        Library library;
//        int choice;
//
//        do {
//            displayMenu();
//            std::cin >> choice;
//
//            // Clear the input buffer
//            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//
//            switch (choice) {
//            case 1: {
//                std::string title, author, publisher, isbn;
//                std::cout << "Enter Book Title: ";
//                std::getline(std::cin, title);
//                std::cout << "Enter Author: ";
//                std::getline(std::cin, author);
//                std::cout << "Enter Publisher: ";
//                std::getline(std::cin, publisher);
//                std::cout << "Enter ISBN: ";
//                std::getline(std::cin, isbn);
//                library.addBook(title, author, publisher, isbn);
//                break;
//            }
//            case 2: {
//                std::string name, address, phone;
//                std::cout << "Enter Member Name: ";
//                std::getline(std::cin, name);
//                std::cout << "Enter Address: ";
//                std::getline(std::cin, address);
//                std::cout << "Enter Phone: ";
//                std::getline(std::cin, phone);
//                library.addMember(name, address, phone);
//                break;
//            }
//            case 3: {
//                int bookId, memberId;
//                std::cout << "Enter Book ID to issue: ";
//                std::cin >> bookId;
//                std::cout << "Enter Member ID: ";
//                std::cin >> memberId;
//                library.issueBook(bookId, memberId);
//                break;
//            }
//            case 4: {
//                int bookId, memberId;
//                std::cout << "Enter Book ID to return: ";
//                std::cin >> bookId;
//                std::cout << "Enter Member ID: ";
//                std::cin >> memberId;
//                library.returnBook(bookId, memberId);
//                break;
//            }
//            case 5: {
//                library.viewAllBooks();
//                break;
//            }
//            case 6: {
//                library.viewAllMembers();
//                break;
//            }
//            case 7: {
//                library.viewSystemStatus();
//                break;
//            }
//            case 8: {
//                library.viewAllBookTitles();
//                break;
//            }
//            case 9: {
//                std::cout << "Exiting Library Management System. Goodbye!" << std::endl;
//                break;
//            }
//            default: {
//                std::cout << "Invalid choice. Please try again." << std::endl;
//                break;
//            }
//            }
//        } while (choice != 9);
//
//        return 0;
//    }