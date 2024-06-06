#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

// Book Class
class Book {
public:
    int id;
    std::string title;
    std::string author;
    std::string genre;
    bool isBorrowed;

    Book(int id, const std::string& title, const std::string& author, const std::string& genre)
        : id(id), title(title), author(author), genre(genre), isBorrowed(false) {}
};

// User Class
class User {
public:
    int userId;
    std::string userName;
    std::vector<int> borrowedBooks;

    User(int userId, const std::string& userName)
        : userId(userId), userName(userName) {}

    void borrowBook(int bookId) {
        borrowedBooks.push_back(bookId);
    }

    void returnBook(int bookId) {
        borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookId), borrowedBooks.end());
    }
};

// Library Class
class Library {
private:
    std::vector<Book> books;
    std::vector<User> users;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(int bookId) {
        books.erase(std::remove_if(books.begin(), books.end(), [bookId](const Book& b) { return b.id == bookId; }), books.end());
    }

    void addUser(const User& user) {
        users.push_back(user);
    }

    void removeUser(int userId) {
        users.erase(std::remove_if(users.begin(), users.end(), [userId](const User& u) { return u.userId == userId; }), users.end());
    }

    Book* searchBookByTitle(const std::string& title) {
        for (auto& book : books) {
            if (book.title == title) return &book;
        }
        return nullptr;
    }

    Book* searchBookByAuthor(const std::string& author) {
        for (auto& book : books) {
            if (book.author == author) return &book;
        }
        return nullptr;
    }

    Book* searchBookById(int id) {
        for (auto& book : books) {
            if (book.id == id) return &book;
        }
        return nullptr;
    }

    User* findUserById(int userId) {
        for (auto& user : users) {
            if (user.userId == userId) return &user;
        }
        return nullptr;
    }

    bool borrowBook(int userId, int bookId) {
        User* user = findUserById(userId);
        Book* book = searchBookById(bookId);
        if (user && book && !book->isBorrowed) {
            book->isBorrowed = true;
            user->borrowBook(bookId);
            return true;
        }
        return false;
    }

    bool returnBook(int userId, int bookId) {
        User* user = findUserById(userId);
        Book* book = searchBookById(bookId);
        if (user && book && book->isBorrowed) {
            book->isBorrowed = false;
            user->returnBook(bookId);
            return true;
        }
        return false;
    }

    void listBooks() {
        std::cout << "Available books:\n";
        for (const auto& book : books) {
            std::cout << book.id << ": " << book.title << " by " << book.author << " [" << (book.isBorrowed ? "Borrowed" : "Available") << "]\n";
        }
    }
};

// Function to run the library management system
void runLibrarySystem() {
    Library lib;

    // Add books
    lib.addBook(Book(1, "Doll's House", "Author1", "Genre1"));
    lib.addBook(Book(2, "The River and the Source", "Author2", "Genre2"));
    lib.addBook(Book(3, "Goon", "Author3", "Genre3"));
    lib.addBook(Book(4, "Beast", "Author4", "Genre4"));
    lib.addBook(Book(5, "Monster", "Author5", "Genre5"));
    lib.addBook(Book(6, "Apocalypse", "Author6", "Genre6"));
    lib.addBook(Book(7, "The Vine", "Author7", "Genre7"));
    lib.addBook(Book(8, "The Walking Dead", "Author8", "Genre8"));
    lib.addBook(Book(9, "Atlanta", "Author9", "Genre9"));
    lib.addBook(Book(10, "George", "Author10", "Genre10"));

    // Add users
    lib.addUser(User(1, "Alice"));
    lib.addUser(User(2, "Bob"));

    int choice, userId, bookId;
    std::string bookTitle;

    while (true) {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. List all books\n";
        std::cout << "2. Borrow a book\n";
        std::cout << "3. Return a book\n";
        std::cout << "4. Search for a book by title\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                lib.listBooks();
                break;
            case 2:
                std::cout << "Enter user ID: ";
                std::cin >> userId;
                std::cout << "Enter book ID to borrow: ";
                std::cin >> bookId;
                if (lib.borrowBook(userId, bookId)) {
                    std::cout << "Book borrowed successfully!\n";
                } else {
                    std::cout << "Book borrowing failed. It might be already borrowed or invalid IDs.\n";
                }
                break;
            case 3:
                std::cout << "Enter user ID: ";
                std::cin >> userId;
                std::cout << "Enter book ID to return: ";
                std::cin >> bookId;
                if (lib.returnBook(userId, bookId)) {
                    std::cout << "Book returned successfully!\n";
                } else {
                    std::cout << "Book return failed. It might not be borrowed or invalid IDs.\n";
                }
                break;
            case 4:
                std::cout << "Enter book title: ";
                std::cin.ignore();
                std::getline(std::cin, bookTitle);
                {
                    Book* book = lib.searchBookByTitle(bookTitle);
                    if (book) {
                        std::cout << "Book found: " << book->title << " by " << book->author << "\n";
                    } else {
                        std::cout << "Book not found.\n";
                    }
                }
                break;
            case 5:
                std::cout << "Exiting...\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    runLibrarySystem();
    return 0;
}

