#include <iostream>

#include <fstream>
#include <string>
//#include <chrono>
#include <stdio.h>
using namespace std;
class Borrow
 {
    public :
    string location;
    string req_date;
    string Item_type;
    int id;



 };


class physicalitem
{
 public:
 string name;
 int count;
 physicalitem()
 {
  count =0;
 }
 
};
class book:public physicalitem
{
public:
int  bookid;
string Isbn;
string author;
book()
{
  bookid=0;
}

} ;
class magzzine:public physicalitem
{
   public:
   string rank;
   
} ;


class jounral
{
   public:
   string name;
} ;
 
 
 
 
 book B[100];
    magzzine M[100];
 jounral j[100];
 Borrow bb[100];





class Library
{
    
    public:
void x()
  { ifstream obj("fileforbooks.csv");


  if(!obj.is_open())
  {
    cout << "ERROR: File Open" << '\n';
  }
   string c;
  int i=0;
getline(obj, c, '\n');
 
 


  while(!obj.eof())
  {

    getline(obj,c,',');
    B[i].bookid = atoi(c.c_str());

    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');

    getline(obj,c,',');
    B[i].count = atoi(c.c_str());

     getline(obj,c,',');
    B[i].Isbn = c;

    getline(obj,c,',');

    getline(obj,c,',');
    B[i].author = c;

    getline(obj,c,',');
    getline(obj,c,',');

    getline(obj,c,',');
    B[i].name = c;


    
    

    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,',');
    getline(obj,c,'\n');

  //  cout<<i<<"--->";
 //   cout << "count: "<< B[i].count<< '\n';
 //    cout << "Isbn: "<< B[i].Isbn<< '\n';
 //   cout << "name"  << B[i].name<<"\n";
   

    i++;

  }
  obj.close();}

void mag()
{
    ifstream obj("fileformagazines.csv");


  if(!obj.is_open())
  {
    cout << "ERROR: File Open" << '\n';
  }

  
  string c;
  int i=0;


  getline(obj, c, '\n');


  while(!obj.eof())
  {

   
    
    getline(obj,c,',');
    M[i].name = c;


    getline(obj,c,',');
    M[i].rank = c;

    getline(obj,c,',');
     getline(obj,c,',');
      getline(obj,c,',');
       getline(obj,c,',');
        getline(obj,c,',');
       getline(obj,c,',');
        getline(obj,c,',');
         getline(obj,c,'\n');  
   

    //cout<<i<<"--->";
    //cout << "publication:" << M[i].name << '\n';
    //cout << "rank:" << M[i].rank<< '\n';
   

    i++;

  }
  obj.close();
}
void jon();
void purchase_book(string isbn,string author,int copies);


};


void Library :: jon()
{
     ifstream obj("journals.csv");


  if(!obj.is_open())
  {
    cout << "ERROR: File Open" << '\n';
  }

  
  string c;
  int i=0;


  while(!obj.eof())
  {

     getline(obj,c,',');
    j[i].name=c;
    getline(obj,c,'\n');

    //cout<<i<<"--->";
    //cout << "name: "<< j[i].name<< '\n';
   
   

    i++;

  }
  obj.close();
  

}
void Library:: purchase_book(string isbn,string author,int copies)
  {   for(int i=0;i<200;i++)
       {if(B[i].Isbn==isbn&& B[i].author==author)
        {  cout<<"this is already in library \n";
          B[i].count+=copies;
        }

       }    
          
            cout<<"book succsefully purchased\n";
          
       

  }



int borrowed_book[100];
int s=0;
string  borrowed_mag_jou[100];
int s_b=0;

string User_id[100];
int s_u=0;


string time_book[100];
string time_mag[100];
string time_jour[100];

int item=0;

class User
{
    private:
    string name;
    string user_id;
    string type;
    string phoneno;

    public:

    void registration()
    {  
        cout<<"Enter the name ";
        cin>>name;
        cout<<"Enter user id ";
        cin>>user_id;
        cout<<"Enter phone number";
        cin>>phoneno;
        cout<<"Enter type";
        cin>> type;
        int f=1;
       for(int i=0;i<s_u;i++)
       {if(User_id[i]!=user_id) 
       { f=0;
        break;}}

       if(f==1)
       {
        s_u++;
        User_id[s_u]=user_id;
        cout<<"user registered";
       }
       else
       {
        cout<<"user already registered";
       }
    }

    void display_detail()
    {
        cout<<"user register sucssefully";
        cout<<name;
        cout<<user_id;
    }
    void book_borrow(int  book_id)
    { int f=1;
       for(int i=0;i<s;i++)
       {if(borrowed_book[i]!=book_id) 
       { f=0;
        break;}}

       if(f==1)
       {
        s++;
        borrowed_book[s]=book_id;
        cout<<"book issued";
       }
       else
       {
        cout<<"book already issued";
       }
    }

    void mag_borrow(string  name)
    { int f=1;
       for(int i=0;i<s_b;i++)
       {if(borrowed_mag_jou[i]!=name) 
       { f=0;
        break;}}

       if(f==1)
       {
        s_b++;
        borrowed_mag_jou[s_b]=name;
        cout<<"Item issued";
       }
       else
       {
        cout<<"Item already issued";
       }
    }

    

       void book_location(int id,string author,string isbn)
       {
        int i,c=0;
             for( i=0;i<100;i++)
             {
               if(B[i].bookid==id && B[i].author==author && B[i].Isbn==isbn)
               {
                c = i;
                break;
               }
             } 
             
                cout<<"location of Book :--"<<"\n"<<"SHELF no-1  "<<"row :"<<c+1;
                auto now = chrono::system_clock::now();
                auto nowTimeT = chrono::system_clock::to_time_t(now);
                   time_book[c]= ctime(&nowTimeT);
                   cout<<"Time: "<<time_book[c];
               
               
       }

       void magazine_location(string name,string rank)
       { int c=0;
             for(int i=0;i<81;i++)
             {
               if(M[i].name==name && M[i].rank==rank )
               { 
                 c=i;
                 break;
               }
             } 
              cout<<"location of Magazine :--"<<"\n"<<"SHELF no- 2  "<<"row :"<<c+1;
               auto now = chrono::system_clock::now();
                auto nowTimeT = chrono::system_clock::to_time_t(now);
                   time_mag[c]= ctime(&nowTimeT);
                   cout<<"Time: "<<time_mag[c]; 
       }

       void journals_location(string name)
       {
        int c;
             for(int i=0;i<99;i++)
             {
               if(j[i].name==name)
               {
               c=i;
               break;
               }
             } 
             cout<<"location of Journals :--"<<"\n"<<"SHELF no- 3  "<<"row :"<<c+1;
             auto now = chrono::system_clock::now();
                auto nowTimeT = chrono::system_clock::to_time_t(now);
                   time_jour[c]= ctime(&nowTimeT);
                   cout<<"Time: "<<time_jour[c];  
       }



       void borrow_on_loan()
       {   

              
              

              
                cout<<"enter from which library you want borrow\n";
                cin>>bb[item].location;
                cout<<"enter from request date\n";
                cin>>bb[item].req_date;
                cout<<"enter which item you borrow \n";
                cin>>bb[item].Item_type;
                cout<<"Enter Item id";
                cin>>bb[item].id;

                cout<<"successfully borrowed ";
             
             item++;

       }
    
     void location_borrowed(int id)
     {
          for(int i=0;i<100;i++)
          {
           if( bb[i].id==id)
           {
               cout<<"library from this book borrowed \n"<<bb[i].location;
           }
          }

          cout<<" no location  ";
     }

};




int main()
{

    string name_of_book,auth_name, name, ele, ebook, auth, author, isbn, rank;
    int copies,id;
    Library l;
  
    User u;
    l.x();
   l.mag();
    l.jon();
    while(1)
 {char ch;
   cout<<"1.Enter as librarian\n";
    cout<<"2.Enter as Member\n";
    cout<<"3.Borrow book on loan from other library \n";
    cout<<"4.see library of borrowed  book\n";
    cout<<"5.exit\n";
    cout<<"Enter you choice:";
    cin>>ch;
    switch(ch)
    {
        case '1':

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       
        cout<<"Name of the book want to purschase \n";
        getline(cin,name_of_book);
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"enter author name\n";
       getline(cin, author);
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       cout<<"enter Isbn number\n";
       getline(cin,isbn);
       cout<<"enter number of copies\n";
       cin>>copies;
       l.purchase_book(isbn,author,copies);
       break;
        case '2':
        
        int i;
        cout<<"1. New registration"<<"\n";
        cout<<"2. Borrow Item"<<"\n";
        cout<<"3. see location"<<"\n";
        cout<<"enter your choise"<<"\n";
         cin>> i;
        switch(i)
        {
            case 1:
            u.registration();
            break;
            case 2:
            int e;
        cout<<"enter what do you want borrow"<<"\n";
        cout<<"1- book"<<"\n";
        cout<<"2- magazine"<<"\n";
        cout<<"3- journal"<<"\n";
        cout<<"4- electronic item"<<"\n";
        cout<<"5- ebook"<<"\n";
        cin>>e;
        switch (e)
        {
        case 1:
        int book_id;
        cout<<"enter book id";
        cin>>book_id;
          u.book_borrow(book_id);
            break;
        case 2:
        //string name;
        cout<<"enter magazine";
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
           getline(cin,name);
          u.mag_borrow(name);
            break; 
         case 3:
         //string name;
         
        cout<<"enter journal";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       getline(cin,name);
          u.mag_borrow(name);
            break;        
         case 4:
         //string ele;
        
         cout<<"enter electronic  item name"<<"\n";
          cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin,ele);
         cout<<"Issued sucssefully"<<"\n";
            break; 

          case 5:
         //string ebook,auth;
         
         cout<<"enter ebook  name and author"<<"\n";
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         getline(cin,ele);
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         getline(cin,auth);
         cout<<"Issued sucssefully"<<"\n";
            break;  
        default:
            break;
        }
        break;
        case 3:
        
          int p;
        cout<<"enter what do you want see location"<<"\n";
        cout<<"1- book"<<"\n";
        cout<<"2- magazine"<<"\n";
        cout<<"3- journal"<<"\n";
       
        cin>>p;
        switch (p)
        {
        case 1:
        int book_id;
        //string author;
        //string isbn;
    cout<<"enter book details(book_id,author,isbn)";
        cin>>book_id;
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       getline(cin,author);
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin,isbn);
          u.book_location(book_id,author,isbn);
            break;
        case 2:
        //string name,rank;
        
        cout<<"enter magazine name and rank";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin,name);
       cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin,rank);
        u.magazine_location(name, rank);
            break; 

         case 3:
         //string name;
        
        cout<<"enter journal";
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        getline(cin,name);
          u.journals_location(name);
            break;        
          
        default:
            break;
        }

        }
           break;

      case '3':
      u.borrow_on_loan();
      break;

      case '4':
      cout<<"Enter book id";
      cin>>id;
      u.location_borrowed(id);
      break;

        case '5':
        exit(0);



    }}

    return 0;
}
 

 


 
