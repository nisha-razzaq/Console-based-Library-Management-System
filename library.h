#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class members {
public:
    int Member_ID;
    string Name;
    string Contact;
    int BorrowCount;  
    float TotalFine;
    members() : TotalFine(0.0) {}
    
    void display();
};

class books {
public:
    int Book_ID;
    string Title;
    string Author;
    string Category;
    string A_status;
    int BorrowCount; 
    int DaysIssued;
    void display();
};

void databasebooks();
void saveToFile(books* library, int s);
void loader(books* library, int s);
void show(books* library, int s);
void addbook(books*& library, int& s);
void deletebook(books*& library, int& s, int target);
void searchbyID(books* library, int s, int target);
void searchByTitle(books* library, int s, string targetTitle);
void searchByAuthor(books* library, int s, string targetAuthor);
void reportIssuedBooks(books* library, int s);
void reportMostBorrowed(books* library, int s);
void reportOverdue(books* library, int s);
void issueBook(books* library, int bCount, members* memberList, int mCount);
void returnBook(books* library, int bCount, members* memberList, int mCount);
void databaseMembers();
void saveMembersToFile(members* memberList, int s);
void loadMembers(members* memberList, int s);
void showMembers(members* memberList, int s);
void addMember(members*& memberList, int& s);
void viewBorrowingHistory(members* memberList, int s);
bool performLogin(members* memberList, int s, bool &isAdmin);
void exportIssuedToCSV(books* library, int bCount);
void updateBook(books* lib, int t_books, int target);

#endif