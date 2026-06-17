### **Project Title**: Library Management System

### (CLI + File Handling)

Internship Task ID: CPP-INT-1



### 

#### Description:

This project is a console-based Library Management System designed to handle library operations with accuracy and persistence. It features an object-oriented design that manages:

Book Management: Adding, updating, deleting, and searching for books.

Member Management: Adding members and tracking their borrowing history.

Borrow \& Return System: Automated issue/return processes with availability status updates.

Reporting: Generating reports for most borrowed books, currently issued books, and overdue tracking.

Additional Features: Admin/member login, a fine system for late returns, and CSV report exports.

Access Control:

Admin Access: The administrator can add, view, and delete books. Use the following credentials:
Username: admin
Password: admin123

Member Access: Other members can log in using their unique ID as their username. For the current version, the password can be any sequence of numeric numbers



##### 

##### Instructions to Run the Project:



Ensure you have a C++ compiler installed (e.g., MinGW, GCC).

Place all source files (main.cpp, library.cpp, library.h) and data files (books.txt, members.txt) in the same directory.

Open your terminal or command prompt in that directory.

Compile the source code using the following command:
g++ main.cpp library.cpp -o library_system
Run the executable:
On Windows: .\library_system.exe

On Linux/macOS: ./library_system

