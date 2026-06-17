#include<iostream>
#include "library.h"

int main()
{
    int t_books = 10;
    int t_members = 10;
    books* library = new books[t_books];
    databasebooks(); //making the database of books
    loader(library, t_books);
    members* memberList = new members[t_members];
    databaseMembers(); //making database of members
    loadMembers(memberList, t_members);
    bool isLoggedIn = false;
    bool isAdmin = false;
    while (!isLoggedIn) 
    {
        isLoggedIn = performLogin(memberList, t_members,isAdmin);
    }
   cout << "\nPress Enter to continue to the Menu...";
   cin.ignore(); 
   cin.get();
   
   int choice, target;
   bool run = true;
   while (run)
  {
    system("cls");
    cout << "\n--- Library Management System ---\n";
    cout << "1. Book Management\n2. Member Management\n3. Borrow-Return\n4. Reporting System\n5. Exit\nChoice: ";
    
    if (!(cin >> choice))
    {
        cout << "Invalid input. Please enter a number.\n";
        cin.clear(); 
        cin.ignore(1000, '\n');
        continue;
    }

    if (choice == 5)
    {
        run = false; 
        cout << "Exiting system. Goodbye!" << endl;
    }
   else
    {     switch (choice)
          {
            case 1:
            {
                bool back=false;
                int bChoice;
                cout << "\n--- Book Management ---\n";
                cout << "1. Show All\n2. Add (Admin Only)\n3. Delete (Admin Only)\n4. Edit (Admin Only)\n5. Search\n6. Back\nChoice: ";
                cin >> bChoice;

                if (bChoice == 1)
               {
                     show(library, t_books);
               } 
                else if (bChoice == 5)
               {
                     cout << "Search by:\n1. ID\n2. Title\n3. Author\nChoice: ";
                     int sChoice;
                     cin >> sChoice;
                     cin.ignore();
                     if (sChoice == 1)
                    {
                       int id; 
                       cout << "Enter ID: ";
                       cin >> id;
                       searchbyID(library, t_books, id);
                    }
                    else if (sChoice == 2)
                    {
                        string t;
                        cout << "Enter Title: ";
                        getline(cin, t);
                        searchByTitle(library, t_books, t);
                    }
                    else if (sChoice == 3)
                    {
                        string a; 
                        cout << "Enter Author: "; 
                        getline(cin, a);
                        searchByAuthor(library, t_books, a);
                    }
    } 
    else if (bChoice == 2 || bChoice == 3 || bChoice == 4) 
    {
                    if (isAdmin) 
                    {
                        if (bChoice == 2) 
                        addbook(library, t_books);
                        else if (bChoice == 3) 
                        {
                          int target;
                          cout << "Enter ID: "; 
                          cin >> target;
                          deletebook(library, t_books, target);
                        }
                        else if (bChoice == 4)
                        {
                           int target; 
                           cout << "Enter ID: "; 
                           cin >> target;
                           updateBook(library, t_books, target);
                        }
                        } 
                        
                        else
                         {
                           cout << "Access Denied: Only Admin can perform this action!" << endl;
                         }
    } 
  
    cout << "\nPress Enter to continue to the Menu...";
    cin.ignore(1000, '\n');
    cin.get();
    break;
   }
            case 2:
            { 
  
               cout << "\n--- Members Menu ---\n";
               cout << "1. Show All\n2. Add (Admin Only)\n3. History\n4. View Fines\n5. Back\nChoice: ";
               int mChoice; 
               cin >> mChoice;

               if (mChoice == 1)
               showMembers(memberList, t_members);
               else if (mChoice == 2) 
               {
                 if (isAdmin) 
                { 
                addMember(memberList, t_members);
                }
                else 
                {
                cout << "Access Denied: Only Admin can add new members!" << endl;
                }
        }
    else if (mChoice == 3)
     viewBorrowingHistory(memberList, t_members);
    else if (mChoice == 4) 
    {
       int id; 
       cout << "Enter Member ID to check fine: "; 
    if (!(cin >> id))
    {
        cout << "Invalid Input!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    } 
    else
    {
        bool found = false;
        for (int i = 0; i < t_members; i++) 
        {
            if (memberList[i].Member_ID == id)
            {
                cout << "\n--- Fine Status ---" << endl;
                cout << "Member Name: " << memberList[i].Name << endl;
                cout << "Total Fine: " << memberList[i].TotalFine << " PKR" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Member ID not found." << endl;
        }
    
}
    }
    cout << "\nPress Enter to continue to the Menu...";
    cin.ignore(1000, '\n'); 
    cin.get();
   
    break;
}
                
            case 3: 
             {
              cout << "\n--- Borrow-Return System ---\n";
              cout << "1. Issue\n2. Return\n3. Back\nChoice: ";
              int trChoice;
              cin >> trChoice;
            if (trChoice == 1) 
             issueBook(library, t_books, memberList, t_members);
            else if (trChoice == 2) 
             returnBook(library, t_books, memberList, t_members);
             cout << "\nPress Enter to continue to the Menu...";
             cin.ignore(1000, '\n');
             cin.get();
   
                    break;}
                
            case 4:
            {
             cout << "\n--- Reporting System ---\n";
             cout << "1. Issued Books\n2. Most Borrowed\n3. Overdue\n4. Export Issued to CSV\n5. Back\nChoice: ";
             int rChoice; 
             cin >> rChoice;
        
             if (rChoice == 1)
              reportIssuedBooks(library, t_books);
            else if (rChoice == 2)
             reportMostBorrowed(library, t_books);
            else if (rChoice == 3) 
            reportOverdue(library, t_books);
            else if (rChoice == 4) 
            {
             exportIssuedToCSV(library, t_books);
            }
            cout << "\nPress Enter to continue to the Menu...";
            cin.ignore(1000, '\n'); 
            cin.get();
   
    break;
}
 default:
                    cout << "Invalid option!\n";
            }
        }
    }

    delete[] memberList;
    delete[] library;
    return 0;
}