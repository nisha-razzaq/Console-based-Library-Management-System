# 📚 Library Management System (CLI + File Handling)


---

## ℹ️ About
A console‑based Library Management System developed in **C++** using **object‑oriented programming principles**.  
It ensures accurate and persistent handling of library operations with features for book management, member tracking, borrowing/return, and reporting.

---

## ✨ Features
- 📖 **Book Management**: Add, update, delete, and search books  
- 👥 **Member Management**: Register members and track borrowing history  
- 🔄 **Borrow & Return System**: Automated issue/return with availability updates  
- 📊 **Reporting**: Generate reports on most borrowed books, issued books, and overdue tracking  
- 🔐 **Access Control**:  
  - **Admin Login** → Username: `admin`, Password: `admin123`  
  - **Member Login** → Username: Member ID, Password: any numeric sequence  
- 💰 **Fine System**: Late returns incur fines  
- 📑 **CSV Export**: Reports can be exported for record keeping  

---

## 🛠️ Process
1. **Planning & Design** → Define requirements and structure classes for books, members, and transactions  
2. **Implementation** → Develop core logic in `library.cpp` and supporting headers in `library.h`  
3. **Integration** → Connect modules with `main.cpp` to handle user interaction and program flow  
4. **File Handling** → Store and update records in `books.txt` and `members.txt` for persistence  
5. **Testing & Review** → Verify login, borrowing/return, and reporting features for accuracy  

---
---

## 📘 What I Learned
- Strengthened understanding of **object‑oriented programming** in C++  
- Applied **file handling** for persistent storage of books and members  
- Designed a **modular structure** with header and implementation files  
- Practiced building a **login system** with admin/member roles  
- Implemented **error handling** to manage invalid inputs and file access issues  
- Improved confidence in handling **real‑world scenarios** like fines and overdue tracking  
- Learned how **OOP design choices** (inheritance, encapsulation, polymorphism) impact maintainability  

---

## 🔧 How It Can Be Improved
- Refactor the **OOP structure**:  
  - Create separate classes for `Book`, `Member`, and `Transaction`  
  - Use **inheritance** (e.g., `User` → `Admin` and `Member`)  
  - Apply **encapsulation** with private data members and getters/setters  
  - Introduce **polymorphism** for flexible reporting and login handling  
- Add a **graphical user interface (GUI)** for better usability  
- Implement a **database backend** (e.g., MySQL/SQLite) instead of text files  
- Enhance **security** with encrypted passwords and role‑based access  
- Make the system **scalable** with optimized search algorithms for large datasets  
- Add **analytics dashboards** for visual reporting of library usage trends  
- Introduce **unit testing** for more robust and maintainable performance  

---



## ⚙️ Compilation & Execution
Ensure you have a C++ compiler installed (e.g., MinGW, GCC).  
Place all source files (`main.cpp`, `library.cpp`, `library.h`) and data files (`books.txt`, `members.txt`) in the same directory.  

```bash
g++ main.cpp library.cpp -o library_system
.\library_system (For Windows)
./library_system (For Linux/macOS)
```
