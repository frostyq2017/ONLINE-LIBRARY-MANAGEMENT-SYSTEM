# ONLINE-LIBRARY-MANAGEMENT-SYSTEM
Documentation for the library management system, explaining how it works:

# Library Management System in C++

## Overview

This library management system is implemented in C++ and includes essential classes for managing books, users, and library operations. It provides functionalities such as adding and removing books, searching for books by various criteria, managing user accounts, and handling book borrowing and returning.

## Class Definitions

### Book Class
The `Book` class represents a book in the library.

#### Attributes
- `int id`: Unique identifier for the book.
- `std::string title`: Title of the book.
- `std::string author`: Author of the book.
- `std::string genre`: Genre of the book.
- `bool isBorrowed`: Flag indicating whether the book is currently borrowed.

#### Constructor
```cpp
Book(int id, const std::string& title, const std::string& author, const std::string& genre)
```
Initializes a new `Book` object with the given `id`, `title`, `author`, and `genre`. The `isBorrowed` flag is initialized to `false`.

### User Class
The `User` class represents a user in the library.

#### Attributes
- `int userId`: Unique identifier for the user.
- `std::string userName`: Name of the user.
- `std::vector<int> borrowedBooks`: List of book IDs borrowed by the user.

#### Constructor
```cpp
User(int userId, const std::string& userName)
```
Initializes a new `User` object with the given `userId` and `userName`.

#### Methods
- `void borrowBook(int bookId)`: Adds the `bookId` to the user's list of borrowed books.
- `void returnBook(int bookId)`: Removes the `bookId` from the user's list of borrowed books.

### Library Class
The `Library` class manages the collection of books and users, and handles borrowing and returning of books.

#### Attributes
- `std::vector<Book> books`: List of books in the library.
- `std::vector<User> users`: List of users in the library.

#### Methods

##### Book Management
- `void addBook(const Book& book)`: Adds a new book to the library.
- `void removeBook(int bookId)`: Removes a book with the given `bookId` from the library.

##### User Management
- `void addUser(const User& user)`: Adds a new user to the library.
- `void removeUser(int userId)`: Removes a user with the given `userId` from the library.

##### Book Searching
- `Book* searchBookByTitle(const std::string& title)`: Searches for a book by its title. Returns a pointer to the book if found, or `nullptr` if not found.
- `Book* searchBookByAuthor(const std::string& author)`: Searches for a book by its author. Returns a pointer to the book if found, or `nullptr` if not found.
- `Book* searchBookById(int id)`: Searches for a book by its ID. Returns a pointer to the book if found, or `nullptr` if not found.

##### User Searching
- `User* findUserById(int userId)`: Searches for a user by their ID. Returns a pointer to the user if found, or `nullptr` if not found.

##### Borrowing and Returning Books
- `bool borrowBook(int userId, int bookId)`: Allows a user to borrow a book if it is not already borrowed. Returns `true` if successful, `false` otherwise.
- `bool returnBook(int userId, int bookId)`: Allows a user to return a borrowed book. Returns `true` if successful, `false` otherwise.

## Test Cases

The `runTests` function contains a suite of test cases to validate the functionality of the library management system.

### Test Cases
- Adding books and users to the library.
- Searching for books by title and author.
- Borrowing and returning books.
- Ensuring that books cannot be borrowed if they are already borrowed.

### Running Tests
The `main` function runs the `runTests` function and prints a message indicating whether all tests passed.

### Code
```cpp
void runTests() {
    Library lib;

### Conclusion

This library management system provides a basic framework for managing books and users, and includes functionalities for adding, removing, borrowing, and returning books. The included test cases ensure that the system works as expected. To extend this system, additional features such as user authentication, detailed book information, and advanced search criteria can be implemented.
