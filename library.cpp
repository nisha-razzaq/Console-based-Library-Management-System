#include "library.h"
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
 void books::display() 
{
    cout << Book_ID << " | " << Title << " | " << Author << " | " << Category << " | " << A_status << endl;
}
void members::display()
    {
    cout << Member_ID << " | " << Name << " | " << Contact << " | " << BorrowCount << endl;
    }
    void saveToFile(books* library, int s) {
        ofstream text_file("books.txt");
        if(text_file.is_open()) {
            for(int i = 0; i < s; i++) {
                text_file << library[i].Book_ID << "," << library[i].Title << ","<<library[i].Author << "," << library[i].Category<< ","<<library[i].A_status <<","<< library[i].BorrowCount << "," << library[i].DaysIssued<< endl;
            }
            text_file.close();
        }
    }
void databasebooks()
{
    string titles[10]={"The Great Gatsby","1984","To kill a Mockingbird","Pride and Prejudice","The Catcher in the Rye","Moby-dick","The Hobbit","Brave New World","Crime and Punishment","The Odyssey"};
    string Authors[10]={"F.Scott Fitzgerald","George Orwell","Harper Lee","Jane Austen","J.D.Salinger","Herman Melville","J.R.R.Tolkien","Aldous Huxley","Fyodor Dostoevsky","Homer"};
    ofstream text_file("books.txt");
    if(text_file.is_open())
    {
        for(int i=0;i<10;i++)
        {
    
            text_file<< (i+1) <<","<< titles[i]<<","<< Authors[i]<<",General,Available,0,0"<<endl;
        }
        text_file.close();
        cout<<"Database created successfully !"<<endl;
    }
    else
    {
        cout<<"Could not create database file";
    }



}
void loader(books* library, int s)
{   ifstream text_file("books.txt");
    int i=0;
   string line;
   if(text_file.is_open())
   {
   while(getline(text_file,line) && i<s)
   { stringstream ss(line);
     string attribute;
    getline(ss,attribute,',');
    library[i].Book_ID= stoi(attribute);
    getline(ss, library[i].Title,',');
    getline(ss, library[i].Author,',');
    getline(ss, library[i].Category,',');
    getline(ss, library[i].A_status,',');
    getline(ss, attribute, ','); 
   library[i].BorrowCount = stoi(attribute);
   getline(ss, attribute);     
    library[i].DaysIssued = stoi(attribute);

     i++;
   }
   text_file.close();
   cout<<"Loading data in dynamic memory successful !"<<endl;

}
else
{
    cout<<"File couldn't open";
}}
void show(books*library,int s)
{ cout << "ID | Title | Author | Category | Status" << endl;
    for(int i=0;i<s;i++)
    {
        library[i].display();
    }

}
void searchbyID(books*library, int s , int target)
{
    int low=0;
    int high=s-1;
    bool find=false;
    while(low<=high)
    {
        int m=(low+high)/2;
        if(library[m].Book_ID==target)
       { cout<<"Book found"<<endl;
        library[m].display();
        find=true;
         break;}
       else if(library[m].Book_ID<target)
         low= m+1;
        else
        high= m-1;}
    if(!find)
    cout<<"Book not found"<<endl;

    
}
void searchByTitle(books* library, int s, string targetTitle) {
    bool found = false;
    for (int i = 0; i < s; i++) {
        if (library[i].Title == targetTitle) {
            library[i].display();
            found = true;
        }
    }
    if (!found) cout << "No book found with that title." << endl;
}

void searchByAuthor(books* library, int s, string targetAuthor) {
    bool found = false;
    for (int i = 0; i < s; i++) {
        if (library[i].Author == targetAuthor) {
            library[i].display();
            found = true;
        }
    }
    if (!found) cout << "No books found by that author." << endl;
}
 void addbook(books*&library,int& s)
 {
    books* temp= new books[s+1];
    for(int i=0;i<s;i++)
    {
        temp[i]=library[i];
    }

    cout << "Enter Book ID: ";
    cin >> temp[s].Book_ID;
    cin.ignore(); 
    cout << "Enter Title: ";
     getline(cin, temp[s].Title);
    cout << "Enter Author: ";
     getline(cin, temp[s].Author);
     cout << "Enter Category: ";
     getline(cin, temp[s].Category);
     cout << "Enter Availability status: ";
     getline(cin, temp[s].A_status);
    delete[] library;
    library= temp;
    s++;
    saveToFile(library,s);
 }
 void deletebook(books*&library, int& s,int target)
 {
    if(s<=0)
    return;
 int count=0;
   books* temp= new books[s-1];
   bool find=false;
   for(int i=0;i<s;i++)
   { if(library[i].Book_ID==target)
    {
    find=true;
   }
   else
   {temp[count]=library[i];
    count++;}

}
if(find)
{
    delete[] library;
    library= temp;
    s--;
    saveToFile(library,s);
    cout << "Book deleted successfully." << endl;
    } 
else
{
    cout<<"Book ID not found";
    delete[] temp;
}
 }
 void updateBook(books* library, int s, int targetID) {
    for (int i = 0; i < s; i++) {
        if (library[i].Book_ID == targetID) {
    cout << "Updating Book ID " << targetID << endl;
    cout << "Enter New Title: ";
   getline(cin, library[i].Title);
    cout << "Enter New Author: ";
       getline(cin, library[i].Author);
      cout<<"Enter category: ";
    getline(cin,library[i].Category); 
     saveToFile(library, s);
           return;
        }
    }
    cout << "Book not found." << endl;
}
void saveMembersToFile(members* memberList, int s) {
    ofstream file("members.txt");
    if(file.is_open()) {
    for(int i = 0; i < s; i++) {
file << memberList[i].Member_ID << "," << memberList[i].Name << "," << memberList[i].Contact << "," << memberList[i].BorrowCount <<","<<memberList[i].TotalFine << endl;
        }
        file.close();
    }
}

void databaseMembers() {
    string IDs[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
    string names[10] = {"Ahmed Khan", "Fatima Ali", "Bilal Ahmed", "Ayesha Noor", "Usman Tariq", "Zara Malik", "Hamza Saleem", "Hina Khalid", "Saad Irfan", "Mariam Javed"};
    string phones[10] = {"0300-1111111", "0321-2222222", "0333-3333333", "0345-4444444", "0301-5555555", "0312-6666666", "0322-7777777", "0300-8888888", "0341-9999999", "0331-0000000"};
    string status[10] = {"0", "0", "0", "0", "0", "0", "0", "0", "0", "0"};

    ofstream file("members.txt");
    if (file.is_open()) {
        for (int i = 0; i < 10; i++) {
            file << IDs[i] << "," << names[i] << "," << phones[i] << "," << status[i] << endl;
        }
        file.close();
        cout << "Member database created successfully!" << endl;
    } else {
        cout << "Could not create member database file" << endl;
    }
}

void loadMembers(members* memberList, int s) {
    ifstream file("members.txt");
    int i = 0;
    string line;
    if(file.is_open()) {
        while(getline(file, line) && i < s) 
{
    stringstream ss(line);
    string attribute;
 getline(ss, attribute, ',');
memberList[i].Member_ID = stoi(attribute);
 getline(ss, memberList[i].Name, ',');
getline(ss, memberList[i].Contact, ',');
 getline(ss, attribute);
memberList[i].BorrowCount = stoi(attribute);
getline(ss, attribute, ','); 
memberList[i].TotalFine = stof(attribute);
         i++;
        }
file.close();
        cout << "Loading member data successful!" << endl;
    } 
else 
{
        cout << "File couldn't open";
    }
}

void showMembers(members* memberList, int s) {
    cout << "ID | Name | Contact | Borrow Count | Total Fine" << endl;
    for(int i = 0; i < s; i++) {
        cout << memberList[i].Member_ID << " | " << memberList[i].Name << " | " 
             << memberList[i].Contact << " | " << memberList[i].BorrowCount 
             << " | " << memberList[i].TotalFine << " PKR" << endl;
    }
}

void addMember(members*& memberList, int& s) {
    members* temp = new members[s + 1];
    for(int i = 0; i < s; i++) {
        temp[i] = memberList[i];
    }
    cout << "Enter Member ID: ";
    cin >> temp[s].Member_ID;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, temp[s].Name);
    cout << "Enter Contact: ";
    getline(cin, temp[s].Contact);
    temp[s].BorrowCount = 0;
    delete[] memberList;
    memberList = temp;
    s++;
    saveMembersToFile(memberList, s);
}

void viewBorrowingHistory(members* memberList, int s) {
    int targetID;
    cout << "Enter Member ID to view history: ";
    cin >> targetID;

    bool found = false;
    for (int i = 0; i < s; i++) {
        if (memberList[i].Member_ID == targetID) {
            cout << "\n--- Borrowing History for " << memberList[i].Name << " ---" << endl;
            cout << "Member ID    : " << memberList[i].Member_ID << endl;
            cout << "Total Borrows: " << memberList[i].BorrowCount << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Member ID not found." << endl;
    }
}
void issueBook(books* library, int bCount, members* memberList, int mCount) {
    int bID, mID;
    cout << "Enter Book ID to issue: "; cin >> bID;
    cout << "Enter Member ID: "; cin >> mID;

    int bIndex = -1, mIndex = -1;
    for(int i=0;i<bCount;i++)
     if(library[i].Book_ID==bID)
      bIndex =i;
    for(int i=0;i<mCount;i++)
     if(memberList[i].Member_ID ==mID) 
     mIndex=i;

    if(bIndex != -1 && mIndex != -1 && library[bIndex].A_status == "Available") {
 library[bIndex].A_status ="Issued";
        memberList[mIndex].BorrowCount++;
        saveToFile(library,bCount);
        saveMembersToFile(memberList,mCount);
        cout << "Book issued successfully!" << endl;
    }
    else
     {
        cout << "Transaction failed! Check ID or Availability." << endl;
    }
}
void returnBook(books* library, int bCount, members* memberList, int mCount)
 {
    int bID, mID, daysKept;
    cout << "Enter Book ID to return: "; 
    cin >> bID;
    cout << "Enter Member ID: "; 
    cin >> mID;
    cout << "Enter number of days the book was kept: "; 
    cin >> daysKept;
  int bIndex = -1, mIndex = -1;
    for (int i = 0; i < bCount; i++)
     {
        if (library[i].Book_ID == bID)
         {
            bIndex = i;
            break;
        }
    }
for (int i = 0; i < mCount; i++)
 {
        if (memberList[i].Member_ID == mID)
         {
            mIndex = i;
            break;
        }
    }
    if (bIndex != -1 && mIndex != -1 && library[bIndex].A_status == "Issued")
     {
        library[bIndex].A_status = "Available";

        // Fine calculation if late
        if (daysKept > 14) {
            float fine = (daysKept - 14) * 20.0; 
            memberList[mIndex].TotalFine += fine;
            cout << "Book returned late! Fine of " << fine << " PKR added to your account." << endl;
        }

        if (memberList[mIndex].BorrowCount > 0) {
            memberList[mIndex].BorrowCount--;
        }

        saveToFile(library, bCount);
        saveMembersToFile(memberList, mCount);
        cout << "Book returned successfully!" << endl;
    } else {
        cout << "Return failed! Check Book ID, Member ID, or Status." << endl;
    }
}

void reportIssuedBooks(books* library, int s) {
    cout << "\n--- Currently Issued Books ---\n";
    for (int i = 0; i < s; i++) {
        if (library[i].A_status == "Issued") {
            library[i].display();
        }
    }
}

void reportMostBorrowed(books* library, int s) {
    int maxIndex = 0;
    for (int i = 1; i < s; i++) {
        if (library[i].BorrowCount > library[maxIndex].BorrowCount) {
            maxIndex = i;
        }
    }
    cout << "\n--- Most Borrowed Book ---\n";
    library[maxIndex].display();
}
void reportOverdue(books* library, int s) {
    cout << "\n--- Overdue Books (> 14 days) ---\n";
    for (int i = 0; i < s; i++) {
        if (library[i].A_status == "Issued" && library[i].DaysIssued > 14) {
            library[i].display();
        }
    }
}
bool performLogin(members* memberList, int s, bool &isAdmin) {
    string user, pass;
    cout << "\n--- Welcome to Our Library System ---" << endl;
    cout << "Enter Username (or Member ID): "; 
    cin >> user;
    cout << "Enter Password: ";
     cin >> pass;
    if (user == "admin" && pass == "admin123") {
        cout << "Login Successful! Welcome Admin." << endl;
        isAdmin= true;
        return true;
    }
    for(int i = 0; i < s; i++) {
        if (to_string(memberList[i].Member_ID) == user) {
            cout << "Login Successful! Welcome " << memberList[i].Name << "." << endl;
            return true;
        }
    }
    cout << "Invalid Credentials. Try again." << endl;
    isAdmin=false;
    return false;
}
void exportIssuedToCSV(books* library, int bCount) {
    ofstream file("IssuedBooksReport.csv");
    file << "Book ID,Title,Author,Status\n"; 
    for(int i = 0; i < bCount; i++) {
        if(library[i].A_status == "Issued") {
            // Yahan Book_ID use karein
            file << library[i].Book_ID << "," << library[i].Title << "," 
                 << library[i].Author << "," << library[i].A_status << "\n";
        }
    }
    file.close();
    cout << "Report exported to IssuedBooksReport.csv successfully!" << endl;
}