
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Book
{
public:
   char title[100];
   char author[50];
   int isbn;
   bool available=0; //1 is yes 0 if no
   bool availability(bool available)
   {
      if(available)
      {cout <<"Book is available"<<endl;
      return true;
       }
       return false;

   }
};
class Library
{ public: 
    Book books[20];
    User users[20];
};


class User
{
public:
   int user_id;
   char username[20];
   int books_issued[10];
   
};

int main()
{
   int operation;
   std::cout<< "this is operation menu, enter -1 to exit"<<std::endl;
   while(1){
   std::cout<<"Enter 1 for entering book details"<<std::endl;
   std::cout<<"Enter 2 for updating user details"<<std::endl;
   std::cout<<"Enter 3 for updating library  details"<<std::endl;
   std::cin >> operation;
    std::cout << std::endl;
   if(operation == -1)
   {
      break;
   }
   switch(operation)
   {
      case 1:
         

   }


   }
   return 0;
}