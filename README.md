# Library Management Application

The Library Management Application is a console-based program written in C++. It serves as a tool for managing library operations, including user registration, item search, item borrowing, and tracking issued items. This application is designed to work with books, journals, and publications and allows users to interact with the library system efficiently.

## Features

- *User Registration:* Users can register as either faculty members or students. The system generates a unique user ID for each registered user.

- *Search Item:* Users can search for items (books, journals, and publications) by providing a keyword. The system displays a list of matching items.

- *Request Item:* Users can request to borrow an available item by providing the book ID and user ID. The system checks the availability of the item and records the issue details, including due dates.

- *Display Issued Items:* Users can view a list of all issued items, including their issue dates, return dates, and user information.

- *Display All Users:* Users can view a list of all registered users, including their user IDs, usernames, and user types.

- *Data Loading:* The application reads data from CSV files for books, publications ranks, and journals during initialization. This data is used for searching and issuing items.

## Data Files

- `books.csv`: Contains data for books, including details like book ID, title, author, ISBN, and more.

- `publications_rank.csv`: Contains data for publication ranks, including details like publication name, rank, total paid, and more.

- `journals.csv`: Contains data for journals, specifically IEEE Latin America Transactions

## Usage

Run the program and choose whether to enter as a Librarian or Member. As a Librarian: You can add new books to the library's collection by specifying the book's details. As a Member: Register with your user details.

Borrow items by selecting the item type (e.g., book, magazine, journal) and providing the required information.

Query the location of library items.

Borrow items on loan by specifying the library branch and requested date.

See the location of items on loan.

Exit the program.


# Contributors: 
Ranu Goyal
