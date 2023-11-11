#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

class Book
{
public:
   char title[100];
   char author[50];
   int isbn;
   bool available;

   void displayBookDetails()
   {
      cout << "Title: " << title << endl;
      cout << "Author: " << author << endl;
      cout << "ISBN: " << isbn << endl;
      cout << "Availability for issuing: " << (available ? "Available" : "Not Available") << endl;
      return;
   }
};

class User
{
public:
   int user_id;
   char name[20];
   int books_issued[10];
   int count;
   int temp, i;
   User() : count(0) {}

   void issueBook(int isbn)
   {
      books_issued[count] = isbn;
      cout << "Book issued successfully" << endl;
      count++;
   }
   void returnBook(int isbn)
   {
      int foundIndex = -1;

      // Find the index of the book to return
      for (int i = 0; i < count; ++i)
      {
         if (books_issued[i] == isbn)
         {
            foundIndex = i;
            break;
         }
      }

      // If the book was found
      if (foundIndex != -1)
      {
         cout << "Book returned successfully" << endl;

         // Shift the elements to remove the returned book
         for (int i = foundIndex; i < count - 1; ++i)
         {
            books_issued[i] = books_issued[i + 1];
         }

         // Decrement the count
         count--;
      }
      else
      {
         cout << "You did not issue this book!" << endl;
      }
   }

   void displayUserDetails()
   {
      cout << "User ID: " << user_id << endl;
      cout << "Username: " << name << endl;
      cout << "Books Issued: " << count << endl;
   }
};
class Librarian
{
public:
   char lname[20];
   char lpassword[20];
};
class Library
{
public:
   vector<Book> books;
   vector<User> users;
   vector<Librarian> librarians;
};

int main()
{
   char name[20], password[20];
   Library lib1;
   Librarian l1;
   Book book1 = {"The Great Gatsby", "F. Scott Fitzgerald", 123456, true};
   Book book2 = {"To Kill a Mockingbird", "Harper Lee", 789012, true};

   // Push the books into the library
   lib1.books.push_back(book1);
   lib1.books.push_back(book2);

   User u1;
   strcpy(u1.name, "Hitesh");
   u1.user_id = 1234;
   lib1.users.push_back(u1);

   strcpy(l1.lname, "Ramesh");
   strcpy(l1.lpassword, "12345");
   lib1.librarians.push_back(l1);
   int operation, isbn, id, i;

   while (1)
   {
      cout << "This is the operation menu, enter -1 to exit" << endl;
      cout << "Enter 1 for entering new book details" << endl;
      cout << "Enter 2 for entering new user details" << endl;
      cout << "Enter 3 for issuing book" << endl;
      cout << "Enter 4 for checking book details" << endl;
      cout << "Enter 5 for checking user details" << endl;
      cout << "Enter 6 for returning book"<<endl;
      cin >> operation;

      if (operation == -1)
      {
         cout << "Exiting" << endl;
         break;
      }

      switch (operation)
      {
      case 1:
      {
         Book newBook;
         cout << "Enter book title: ";
         cin.ignore();
         cin.getline(newBook.title, sizeof(newBook.title));

         cout << "Enter author: ";
         cin.getline(newBook.author, sizeof(newBook.author));

         cout << "Enter ISBN: ";
         cin >> newBook.isbn;
         newBook.available = true;
         lib1.books.push_back(newBook);
         cout << "Book added successfully!" << endl;
         break;
      }
      case 2:
      {
         User newuser;

         cout << "Enter user name: ";
         cin.ignore();
         cin.getline(newuser.name, sizeof(newuser.name));
         cout << "Enter userid: ";
         cin >> newuser.user_id;
         lib1.users.push_back(newuser);
         break;
      }
      case 3:
      {
         cout << "Enter the Userid for the user who wants a book: ";
         cin >> id;

         for (size_t i = 0; i < lib1.users.size(); ++i)
         {
            if (lib1.users[i].user_id == id)
            {
               cout << "Enter the ISBN for the book to be issued: ";
               cin >> isbn;

               for (size_t j = 0; j < lib1.books.size(); ++j)
               {
                  if (lib1.books[j].isbn == isbn)
                  {
                     if (lib1.books[j].available)
                     {
                        lib1.users[i].issueBook(isbn);
                        lib1.books[j].available = false;
                     }
                     else
                     {
                        cout << "Book is not available for issuing." << endl;
                     }
                     // Exit the inner loop after finding the book
                     break;
                  }
               }
               // Exit the outer loop after issuing the book
               break;
            }
         }
         break;
      }

      case 4:
      {
         cout << "Enter ISBN of book whose details you want: " << endl;
         cin >> isbn;

         for (size_t j = 0; j < lib1.books.size(); ++j)
         {
            if (lib1.books[j].isbn == isbn)
            {
               lib1.books[j].displayBookDetails();
            }
         }
         break;
      }
      case 5:
      {
         // Code to check user details
         // can check only if the request is made from a librarian
         char name[20];
         char password[20];

         cout << "Enter username: " << endl;
         cin >> name;
         cout << "Enter password" << endl;
         cin >> password;

         bool validLibrarian = false;

         for (const auto &librarian : lib1.librarians)
         {
            if (strcmp(librarian.lname, name) == 0 && strcmp(librarian.lpassword, password) == 0)
            {
               validLibrarian = true;
               cout << "Entry given" << endl;
               cout << "Enter user id whose details you want: " << endl;
               cin >> id;

               for (size_t i = 0; i < lib1.users.size(); ++i)
               {
                  if (lib1.users[i].user_id == id)
                  {
                     lib1.users[i].displayUserDetails();
                  }
               }

               break;
            }
         }

         if (!validLibrarian)
         {
            cout << "Invalid username or password for librarian." << endl;
         }

         break;
      }
      case 6:
         cout <<"Enter id of the user who wants to return book" <<endl;
         cin >>id;
         for (size_t i = 0; i < lib1.users.size(); ++i)
               {
                  if (lib1.users[i].user_id == id)
                  {
                     cout << "Enter ISBN of book you want to return"<<endl;
                     cin >>isbn;
                     lib1.users[i].returnBook(isbn);
                  }
               }
         break;

      default:
         cout << "Invalid option, please try again." << endl;
         break;
      }

      
   }
   return 0;
}
