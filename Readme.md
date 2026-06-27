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

## ⚙️ Compilation & Execution
Ensure you have a C++ compiler installed (e.g., MinGW, GCC).  
Place all source files (`main.cpp`, `library.cpp`, `library.h`) and data files (`books.txt`, `members.txt`) in the same directory.  

```bash
g++ main.cpp library.cpp -o library_system
.\library_system (For Windows)
./library_system (For Linux/macOS)
```
