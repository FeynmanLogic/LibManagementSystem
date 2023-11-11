#include <iostream>
#include <cstring> // Instead of <string.h>
using namespace std;

class Book {
public:
   char title[100];
   char author[50];
   int isbn;
   bool available = false; // 1 is yes, 0 if no
   bool availability() {
      if (available) {
         cout << "Book is available" << endl;
         return true;
      }
      return false;
   }
};

class User {
public:
   int user_id;
   char username[20];
   int books_issued[10];
};

class Library {
public:
   Book books[1000];
   User users[20];
};

int main() {
   Library lib1;
   int operation;


   while (1) {
      cout << "this is the operation menu, enter -1 to exit" << endl;
      cout << "Enter 1 for entering book details" << endl;
      cout << "Enter 2 for updating user details" << endl;
      cout << "Enter 3 for updating library details" << endl;
      cin >> operation;

      if (operation == -1) {
         cout << "exiting" << endl;
         break;
      }

      switch (operation) {
         case 1:
            cout << "Enter book id" << endl;
            cin >> lib1.books[0].isbn;

            cout << "Enter book title" << endl;
            cin.ignore(); // Ignore the newline character left in the buffer
            cin.getline(lib1.books[0].title, sizeof(lib1.books[0].title));

            cout << "Book title just entered is: " << endl;
            cout << lib1.books[0].title << endl;
            break;
      }
   }

   return 0;
}
