//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <iomanip>
//
//class Book {
//private:
//    int id;
//    std::string title;
//    std::string author;
//    bool isAvailable;
//    int issuedToMemberId;
//
//public:
//    Book(int bookId, const std::string& bookTitle, const std::string& bookAuthor)
//        : id(bookId), title(bookTitle), author(bookAuthor), isAvailable(true), issuedToMemberId(-1) {
//    }
//
//    // Getters
//    int getId() const { return id; }
//    std::string getTitle() const { return title; }
//    std::string getAuthor() const { return author; }
//    bool getAvailability() const { return isAvailable; }
//    int getIssuedToMemberId() const { return issuedToMemberId; }
//
//    // Issue book to member
//    void issueBook(int memberId) {
//        isAvailable = false;
//        issuedToMemberId = memberId;
//    }
//
//    // Return book
//    void returnBook() {
//        isAvailable = true;
//        issuedToMemberId = -1;
//    }
//
//    // Display book info
//    void displayBook() const {
//        std::cout << std::setw(5) << id << " | "
//            << std::setw(25) << title << " | "
//            << std::setw(20) << author << " | "
//            << std::setw(12) << (isAvailable ? "Available" : "Issued") << " | ";
//        if (!isAvailable) {
//            std::cout << std::setw(10) << issuedToMemberId;
//        }
//        else {
//            std::cout << std::setw(10) << "N/A";
//        }
//        std::cout << std::endl;
//    }
//};
//
//class Member {
//private:
//    int id;
//    std::string name;
//    std::string email;
//    std::vector<int> issuedBooks;
//
//public:
//    Member(int memberId, const std::string& memberName, const std::string& memberEmail)
//        : id(memberId), name(memberName), email(memberEmail) {
//    }
//
//    // Getters
//    int getId() const { return id; }
//    std::string getName() const { return name; }
//    std::string getEmail() const { return email; }
//    const std::vector<int>& getIssuedBooks() const { return issuedBooks; }
//
//    // Issue book to member
//    void issueBook(int bookId) {
//        issuedBooks.push_back(bookId);
//    }
//
//    // Return book from member
//    void returnBook(int bookId) {
//        auto it = std::find(issuedBooks.begin(), issuedBooks.end(), bookId);
//        if (it != issuedBooks.end()) {
//            issuedBooks.erase(it);
//        }
//    }
//
//    // Check if member has a specific book
//    bool hasBook(int bookId) const {
//        return std::find(issuedBooks.begin(), issuedBooks.end(), bookId) != issuedBooks.end();
//    }
//
//    // Display member info
//    void displayMember() const {
//        std::cout << std::setw(5) << id << " | "
//            << std::setw(20) << name << " | "
//            << std::setw(25) << email << " | "
//            << std::setw(12) << issuedBooks.size() << std::endl;
//    }
//};
//
//class Library {
//private:
//    std::vector<Book> books;
//    std::vector<Member> members;
//    std::vector<std::string> allBookTitles; // Stores all book names ever added
//    int nextBookId;
//    int nextMemberId;
//
//public:
//    Library() : nextBookId(1), nextMemberId(1) {}
//
//    // Add a new book
//    void addBook(const std::string& title, const std::string& author) {
//        books.emplace_back(nextBookId++, title, author);
//        allBookTitles.push_back(title);
//        std::cout << "Book '" << title << "' by " << author << " added successfully!\n";
//    }
//
//    // Add a new member
//    void addMember(const std::string& name, const std::string& email) {
//        members.emplace_back(nextMemberId++, name, email);
//        std::cout << "Member '" << name << "' added successfully!\n";
//    }
//
//    // Issue book to member
//    void issueBook(int bookId, int memberId) {
//        auto bookIt = std::find_if(books.begin(), books.end(),
//            [bookId](const Book& book) { return book.getId() == bookId; });
//
//        auto memberIt = std::find_if(members.begin(), members.end(),
//            [memberId](const Member& member) { return member.getId() == memberId; });
//
//        if (bookIt == books.end()) {
//            std::cout << "Error: Book with ID " << bookId << " not found!\n";
//            return;
//        }
//
//        if (memberIt == members.end()) {
//            std::cout << "Error: Member with ID " << memberId << " not found!\n";
//            return;
//        }
//
//        if (!bookIt->getAvailability()) {
//            std::cout << "Error: Book '" << bookIt->getTitle() << "' is already issued!\n";
//            return;
//        }
//
//        bookIt->issueBook(memberId);
//        memberIt->issueBook(bookId);
//        std::cout << "Book '" << bookIt->getTitle() << "' issued to " << memberIt->getName() << " successfully!\n";
//    }
//
//    // Return book
//    void returnBook(int bookId, int memberId) {
//        auto bookIt = std::find_if(books.begin(), books.end(),
//            [bookId](const Book& book) { return book.getId() == bookId; });
//
//        auto memberIt = std::find_if(members.begin(), members.end(),
//            [memberId](const Member& member) { return member.getId() == memberId; });
//
//        if (bookIt == books.end()) {
//            std::cout << "Error: Book with ID " << bookId << " not found!\n";
//            return;
//        }
//
//        if (memberIt == members.end()) {
//            std::cout << "Error: Member with ID " << memberId << " not found!\n";
//            return;
//        }
//
//        if (bookIt->getAvailability()) {
//            std::cout << "Error: Book '" << bookIt->getTitle() << "' is not currently issued!\n";
//            return;
//        }
//
//        if (bookIt->getIssuedToMemberId() != memberId) {
//            std::cout << "Error: Book '" << bookIt->getTitle() << "' is not issued to this member!\n";
//            return;
//        }
//
//        bookIt->returnBook();
//        memberIt->returnBook(bookId);
//        std::cout << "Book '" << bookIt->getTitle() << "' returned by " << memberIt->getName() << " successfully!\n";
//    }
//
//    // Display all books
//    void displayAllBooks() const {
//        if (books.empty()) {
//            std::cout << "No books in the library!\n";
//            return;
//        }
//
//        std::cout << "\n==================== ALL BOOKS ====================\n";
//        std::cout << std::setw(5) << "ID" << " | "
//            << std::setw(25) << "Title" << " | "
//            << std::setw(20) << "Author" << " | "
//            << std::setw(12) << "Status" << " | "
//            << std::setw(10) << "Member ID" << std::endl;
//        std::cout << std::string(75, '-') << std::endl;
//
//        for (const auto& book : books) {
//            book.displayBook();
//        }
//        std::cout << std::string(75, '=') << std::endl;
//    }
//
//    // Display available books
//    void displayAvailableBooks() const {
//        std::vector<Book> availableBooks;
//        for (const auto& book : books) {
//            if (book.getAvailability()) {
//                availableBooks.push_back(book);
//            }
//        }
//
//        if (availableBooks.empty()) {
//            std::cout << "No books are currently available!\n";
//            return;
//        }
//
//        std::cout << "\n================= AVAILABLE BOOKS =================\n";
//        std::cout << std::setw(5) << "ID" << " | "
//            << std::setw(25) << "Title" << " | "
//            << std::setw(20) << "Author" << std::endl;
//        std::cout << std::string(55, '-') << std::endl;
//
//        for (const auto& book : availableBooks) {
//            std::cout << std::setw(5) << book.getId() << " | "
//                << std::setw(25) << book.getTitle() << " | "
//                << std::setw(20) << book.getAuthor() << std::endl;
//        }
//        std::cout << std::string(55, '=') << std::endl;
//    }
//
//    // Display all members
//    void displayAllMembers() const {
//        if (members.empty()) {
//            std::cout << "No members registered!\n";
//            return;
//        }
//
//        std::cout << "\n=================== ALL MEMBERS ===================\n";
//        std::cout << std::setw(5) << "ID" << " | "
//            << std::setw(20) << "Name" << " | "
//            << std::setw(25) << "Email" << " | "
//            << std::setw(12) << "Books Issued" << std::endl;
//        std::cout << std::string(65, '-') << std::endl;
//
//        for (const auto& member : members) {
//            member.displayMember();
//        }
//        std::cout << std::string(65, '=') << std::endl;
//    }
//
//    // Display all book titles ever added
//    void displayAllBookTitles() const {
//        if (allBookTitles.empty()) {
//            std::cout << "No books have been added to the library yet!\n";
//            return;
//        }
//
//        std::cout << "\n============== ALL BOOK TITLES EVER ADDED ==============\n";
//        for (size_t i = 0; i < allBookTitles.size(); ++i) {
//            std::cout << (i + 1) << ". " << allBookTitles[i] << std::endl;
//        }
//        std::cout << std::string(55, '=') << std::endl;
//    }
//
//    // Search book by title
//    void searchBookByTitle(const std::string& title) const {
//        std::vector<Book> foundBooks;
//        for (const auto& book : books) {
//            if (book.getTitle().find(title) != std::string::npos) {
//                foundBooks.push_back(book);
//            }
//        }
//
//        if (foundBooks.empty()) {
//            std::cout << "No books found with title containing '" << title << "'!\n";
//            return;
//        }
//
//        std::cout << "\n================ SEARCH RESULTS ================\n";
//        std::cout << std::setw(5) << "ID" << " | "
//            << std::setw(25) << "Title" << " | "
//            << std::setw(20) << "Author" << " | "
//            << std::setw(12) << "Status" << std::endl;
//        std::cout << std::string(65, '-') << std::endl;
//
//        for (const auto& book : foundBooks) {
//            std::cout << std::setw(5) << book.getId() << " | "
//                << std::setw(25) << book.getTitle() << " | "
//                << std::setw(20) << book.getAuthor() << " | "
//                << std::setw(12) << (book.getAvailability() ? "Available" : "Issued") << std::endl;
//        }
//        std::cout << std::string(65, '=') << std::endl;
//    }
//
//    // Display system status
//    void displaySystemStatus() const {
//        int totalBooks = books.size();
//        int availableBooks = 0;
//        int issuedBooks = 0;
//
//        for (const auto& book : books) {
//            if (book.getAvailability()) {
//                availableBooks++;
//            }
//            else {
//                issuedBooks++;
//            }
//        }
//
//        std::cout << "\n================= SYSTEM STATUS =================\n";
//        std::cout << "Total Books in Library: " << totalBooks << std::endl;
//        std::cout << "Available Books: " << availableBooks << std::endl;
//        std::cout << "Issued Books: " << issuedBooks << std::endl;
//        std::cout << "Total Members: " << members.size() << std::endl;
//        std::cout << "Total Book Titles Ever Added: " << allBookTitles.size() << std::endl;
//        std::cout << std::string(50, '=') << std::endl;
//    }
//};
//
//// Function to display menu
//void displayMenu() {
//    std::cout << "\n================== LIBRARY MANAGEMENT SYSTEM ==================\n";
//    std::cout << "1. Add Book\n";
//    std::cout << "2. Add Member\n";
//    std::cout << "3. Issue Book\n";
//    std::cout << "4. Return Book\n";
//    std::cout << "5. Display All Books\n";
//    std::cout << "6. Display Available Books\n";
//    std::cout << "7. Display All Members\n";
//    std::cout << "8. Search Book by Title\n";
//    std::cout << "9. Display All Book Titles Ever Added\n";
//    std::cout << "10. Display System Status\n";
//    std::cout << "11. Exit\n";
//    std::cout << "================================================================\n";
//    std::cout << "Enter your choice: ";
//}
//
//int main() {
//    Library library;
//    int choice;
//
//    // Add some sample data
//    library.addBook("The Great Gatsby", "F. Scott Fitzgerald");
//    library.addBook("To Kill a Mockingbird", "Harper Lee");
//    library.addBook("1984", "George Orwell");
//    library.addMember("John Doe", "john.doe@email.com");
//    library.addMember("Jane Smith", "jane.smith@email.com");
//
//    std::cout << "Welcome to the Library Management System!\n";
//    std::cout << "Sample books and members have been added.\n";
//
//    while (true) {
//        displayMenu();
//        std::cin >> choice;
//
//        switch (choice) {
//        case 1: {
//            std::string title, author;
//            std::cout << "Enter book title: ";
//            std::cin.ignore();
//            std::getline(std::cin, title);
//            std::cout << "Enter author name: ";
//            std::getline(std::cin, author);
//            library.addBook(title, author);
//            break;
//        }
//        case 2: {
//            std::string name, email;
//            std::cout << "Enter member name: ";
//            std::cin.ignore();
//            std::getline(std::cin, name);
//            std::cout << "Enter member email: ";
//            std::getline(std::cin, email);
//            library.addMember(name, email);
//            break;
//        }
//        case 3: {
//            int bookId, memberId;
//            std::cout << "Enter book ID to issue: ";
//            std::cin >> bookId;
//            std::cout << "Enter member ID: ";
//            std::cin >> memberId;
//            library.issueBook(bookId, memberId);
//            break;
//        }
//        case 4: {
//            int bookId, memberId;
//            std::cout << "Enter book ID to return: ";
//            std::cin >> bookId;
//            std::cout << "Enter member ID: ";
//            std::cin >> memberId;
//            library.returnBook(bookId, memberId);
//            break;
//        }
//        case 5:
//            library.displayAllBooks();
//            break;
//        case 6:
//            library.displayAvailableBooks();
//            break;
//        case 7:
//            library.displayAllMembers();
//            break;
//        case 8: {
//            std::string title;
//            std::cout << "Enter title to search: ";
//            std::cin.ignore();
//            std::getline(std::cin, title);
//            library.searchBookByTitle(title);
//            break;
//        }
//        case 9:
//            library.displayAllBookTitles();
//            break;
//        case 10:
//            library.displaySystemStatus();
//            break;
//        case 11:
//            std::cout << "Thank you for using the Library Management System!\n";
//            return 0;
//        default:
//            std::cout << "Invalid choice! Please try again.\n";
//        }
//    }
//
//    return 0;
//}