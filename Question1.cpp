

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <stdio.h>
using namespace std;


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
    


};