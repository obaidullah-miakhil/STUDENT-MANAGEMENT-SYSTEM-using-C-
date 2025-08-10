#include <iostream>
#include<fstream>//used to open a file for modification
using namespace std;
struct scholar //structure used to make a block of variables
{
 char name[80];
 string id;
 int roll;
 float pro,ap,english,ict,sum,average;//ap stands for applied physics
};//all the prototypes of functions being used in program
void intro();//introduction function
void main_menu();//funtion to display main menu of project
void accept_data();//funtion used to enter student data
void view_Specific(int);//funtion being used to display record of just one student
void view_all();//function used to display all the student's records
void result(int);//function being used to display a student's record
void delete_record(int);//function being used to delete student record
void modify(int);// for modification ofstudent record
int main()
{
 char option;
 intro();//intro function of program
 do{
    cout<<endl<<endl;
    cout<<"\t====================STUDENT MANEGEMENT SYSTEM====================\n";
    cout<<endl;
    cout<<"\t\t\t\tOption 1: MAIN MENU\n\n"; //if chosen main menu function will initiate 
    cout<<"\t\t\t\tOption 2: EXIT\n\n";
    cout<<"CHOOSE AN OPTION :"; //used to prompt the user to choose an option
    cin>>option;
    switch(option)
   {
    case '1':
        {
         main_menu();
         break;
        }
   case '2': //case 2 is implemented if the user wants to exit the program
       {          
	    cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE"<<endl;
        cout<<endl<<endl;
        cout<<"\t   GROUP MEMBERS(DEVELOPERS)";
        cout << "\n\n";
        cout << "\t   NAME                               ID                 PHONE NUMBER     \n\n";
        cout << "\t   1. Obaidullah                  B21F0801CS052          +93782030870     \n\n";
        cout << "\t   2. Zakirullah                  B21F0803CS053          +93795454825     \n\n";
        cout << "\t   3. Rohail                      B21F0085CS004          +923375105999    \n\n";
        cout << "\t   4. Ahmed Saleem                 B21F0418CS033          +922318360836    \n\n";
        cout << "\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t   SUBMITED TO:   Sir. Osama & dr.waheed\n";
        cout<<"\t\t\t\t\t\t\t\t\t   SUBMITED DATE: 1/2/2022 \n\n"; //diplaying info of group members and instructors      
       }
   }
    }
	while(option!='2'); //loop will run till the user does not enter 2
    return 0;
}
void accept_data( )
{
    scholar sch;
    ofstream outfile; //ofstream used for implimentation of outputting file
    outfile.open("Report.txt",ios::app|ios::binary);
    if(outfile.fail())//if file does not exist the following will happen
    {
        cout<<"This file can not be opened...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<endl<<endl;
    cout<<"\t\t\t\t=======CREATE A REPORT CARD========\n\n";
    cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(sch.name,80);
    cout<<"ENTER YOUR ID NUMBER :";
    cin>>sch.id;
   cout<<"ENTER YOUR ROLL NUMBER :";
    cin>>sch.roll;
    cout<<"ENTER YOUR PROGRAMMING MARK :";
    cin>>sch.pro;
    cout<<"ENTER YOUR APPLIED PHYSICS MARK :";
    cin>>sch.ap;
    cout<<"ENTER YOUR ENGLISH & COMMUNICATION SKILL MARK :";
    cin>>sch.english;
    cout<<"ENTER YOUR ICT MARK :";
    cin>>sch.ict;
    sch.sum=sch.pro+sch.ap+sch.english+sch.ict;//sum of marks in all the subjects
    sch.average=(sch.sum/4);//finding average marks accross all subjects
    outfile.write(reinterpret_cast<char *> (&sch), sizeof(scholar));//used to change one pointer data type to another
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE HAS BEEN SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
}
void intro()
{
 cout<<"\t\t\t\t============================================="<<endl;
 cout<<"\t\t\t\tTHIS IS STUDENT REPORT CARD MANEGEMENT SYSTEM"<<endl;
 cout<<"\t\t\t\t============================================="<<endl;
 cout<<"press any key to continue...";
 cin.ignore();
}
void main_menu()//main menu function body
{
 char op;// op stands for options
 cout<<endl<<endl;
 cout<<"\t\t\t\t=================MAIN MENU================\n\n"<<endl;
 cout<<"\t\t\t\tOption 1: CREATE STUDENT REPORT CARD\n\n."<<endl;
 cout<<"\t\t\t\tOption 2: VIEW ALL STUDENT REPORT CARDS.\n\n"<<endl;
 cout<<"\t\t\t\tOption 3: VIEW A SINGLE STUDENT'S REPORT CARD.\n\n"<<endl;
 cout<<"\t\t\t\tOption 4: MODIFY A REPORT CARD.\n\n"<<endl;
 cout<<"\t\t\t\tOption 5: RESULT.\n\n"<<endl;
 cout<<"\t\t\t\tOption 6: DELETE RECORD.\n\n"<<endl;
 cout<<"\t\t\t\tANY OTHER KEY FOR EXIT MENU.\n\n"<<endl;
 cout<<"\t\t\t\t=============================="<<endl;
 cout<<"\t\t\t\tENTER YOUR CHOICE HERE <1-6>:";
 cin>>op;
 cout<<endl;
 switch(op)
        {
         case '1':
             {
              accept_data(); ///it will accepty data and will save  in specific file
              break;
             }
         case '2':
             {
              view_all();//will go to the function and will show all the saved data
              break;
             }
         case '3':
             {
              int num;
              cout<<"ENTER YOUR ROLL NUMBER :";
              cin>>num;
              view_Specific(num);//viewing student data for specific student by roll num
              break;
             }
         case '4':
             {
              int num;
              cout<<"ENTER YOUR ROLL NUMBER :";
              cin>>num;
              modify(num);//for modifying record of student
              break;
             }
         case '5':
             {
              int num;
              cout<<"ENTER YOUR ROLL NUMBER :";
              cin>>num;
              cout<<endl;
              result(num);//will run the result funtion showing data of a specific student
              break;
             }
         case '6':
             {
              int num;
              cout<<"ENTER YOUR ROLL NUMBER :";
              cin>>num;
              cout<<endl;
              delete_record(num);//funtion to delete record of a student
              break;
             }
        }
}
void view_all()//displaying all the data that is saved in the file 
{
 scholar sch;
 ifstream infile;
 bool check=false;//bool variable used to ckeck status of record
 infile.open("Report.txt",ios::app|ios::binary);
 if(infile.fail())
   {
    cout<<"The file could'nt open.....press enter key...";
    cin.ignore();
    cin.get();
   }
 cout<<"\n\n";
 cout<<"\t\t\t\tLIST OF ALL REPORT CARDS"<<endl;
 cout<<"=================================================================================="<<endl;
 while(infile.read(reinterpret_cast<char*>(&sch),sizeof(scholar)))//using re-interpret cast function for converting pointer to another data type
    {
     cout<<"\t\t\t\tSTUDENT NAME :"<<sch.name<<endl<<endl;
     cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<sch.roll<<endl<<endl;
     cout<<"\t\t\t\tPROGRAMMING MARKS :"<<sch.pro<<endl<<endl;
     cout<<"\t\t\t\tAPPLIED PHYSICS MARKS :"<<sch.ap<<endl<<endl;
     cout<<"\t\t\t\tENGLISH & COMMUNICATION SKILL MARKS :"<<sch.english<<endl<<endl;
     cout<<"\t\t\t\tICT MARKS :"<<sch.ict<<endl<<endl;
     cout<<"\t\t\t\tSUM :"<<sch.sum<<endl<<endl;
     cout<<"\t\t\t\tAVERAGE :"<<sch.average<<endl<<endl;
     cout<<"=================================================================================="<<endl;
     check=true;
    }
 infile.close();
 if(check==false)//if no record is found
    {
	 cout<<"\t\t\t\tNO RECORD FOUND..."<<endl<<endl;
    }
 cout<<"press any key to continue....";
 cin.ignore();
 cin.get();
  main_menu();
}
void view_Specific(int num)
{//viewing record of a specific record
 scholar sch;
 ifstream infile;
 infile.open("Report.txt",ios::app|ios::binary);//app stands or append, used so that the data which is already in file isn't overwritten.
 if(infile.fail())
   {
    cout<<"THE FILE COULD NOT BE OPENED...";
    cin.ignore();
    cin.get();
   }
 bool equality=false;
 cout<<"\t\t\t\t==========VIEW A STUDENT'S REPORT==========\n\n";
 while(infile.read(reinterpret_cast<char*>(&sch),sizeof(scholar)))//re-interpret cast is used to change datatype of one pointer variable to another pointer datatype 
     {
      if(sch.roll==num)
        {
         cout<<"\t\t\t\tSTUDENT NAME :"<<sch.name<<endl;
         cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<sch.roll<<endl;
         cout<<"\t\t\t\tPROGRAMMING MARK :"<<sch.pro<<endl;
         cout<<"\t\t\t\tAPPLIED PHYSICS MARKS :"<<sch.ap<<endl<<endl;
         cout<<"\t\t\t\tENGLISH & COMMUNICATION SKILL MARKS :"<<sch.english<<endl<<endl;
         cout<<"\t\t\t\tICT MARKS :"<<sch.ict<<endl<<endl;
         cout<<"\t\t\t\tSUM :"<<sch.sum<<endl;
         cout<<"\t\t\t\tAVERAGE :"<<sch.average<<endl;
         cout<<"\t\t\t\t================================================"<<endl;
         equality=true;
        }
     }
 infile.close();
 if(equality==false)//to check if a record is present or not
   {
	cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
   }
 cout<<endl;
 cout<<"press any key to continue...";
 cin.ignore();
 cin.get();
  main_menu();//to go back to the main menu in case of no record found
}
void result(int num)//result funtion to just display result of a single student
{
 scholar sch;
 ifstream infile;
 infile.open("Report.txt",ios::app|ios::binary);
 if(infile.fail())
   {
    cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
    cin.ignore();
    cin.get();
   }
 bool eq=false;
 cout<<"\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
 while(infile.read(reinterpret_cast<char*>(&sch),sizeof(scholar)))//used to change one pointer datatype to another data type
     {
      if(sch.roll==num)
        {
         cout<<"\t\t\t\tSTUDENT NAME :"<<sch.name<<endl<<endl;
         cout<<"\t\t\t\tPROGRAMMING MARK :"<<sch.pro<<endl<<endl;
         cout<<"\t\t\t\tAPPLIED PHYSICS MARKS :"<<sch.ap<<endl<<endl;
         cout<<"\t\t\t\tENGLISH & COMMUNICATION SKILL MARKS :"<<sch.english<<endl<<endl;
         cout<<"\t\t\t\tICT MARKS :"<<sch.ict<<endl<<endl;
         cout<<"\t\t\t\tSUM :"<<sch.sum<<endl<<endl;
         cout<<"\t\t\t\tAVERAGE :"<<sch.average<<endl<<endl;
         cout<<"\t\t\t\t=================================================="<<endl;
         eq=true;
        }
     }
 infile.close();//to close the infile
 if(eq==false)//in case record not found
   {
	cout<<"\t\t\t\tRECORD NOT FOUND..."<<endl;
   }
 cout<<endl;
 cout<<"press any key to continue...";
 cin.ignore();
 cin.get();
main_menu();// go back to main menu
}
void modify(int num)
{//modify function
 scholar sch;
 fstream infile;
 infile.open("Report.txt",ios::binary|ios::in|ios::out);
 if(infile.fail())//if file does not exist display appropriate message
   {
    cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
    cin.ignore();
    cin.get();
   }
 bool checker=false;
 cout<<"\t\t\t\t==========MODIFY A REPORT CARD==========\n\n";
 while(!infile.eof() && checker==false)//.eof stands for end of file
     {
      infile.read(reinterpret_cast<char*>(&sch),sizeof(scholar));
      {
         if(sch.roll==num)
          {
           cout<<"\t\t\t\tSTUDENT NAME :"<<sch.name<<endl<<endl;
           cout<<"\t\t\t\tSTUDENT ROLL NUMBER :"<<sch.roll<<endl<<endl;
           cout<<"\t\t\t\tPROGRAMMING MARK :"<<sch.pro<<endl<<endl;
           cout<<"\t\t\t\tAPPLIED PHYSICS MARKS :"<<sch.ap<<endl<<endl;
           cout<<"\t\t\t\tENGLISH & COMMUNICATION SKILL MARKS :"<<sch.english<<endl<<endl;
           cout<<"\t\t\t\tICT MARKS :"<<sch.ict<<endl<<endl;
           cout<<"============================================="<<endl;
           cout<<"\t\tENTER THE NEW INFORMATION"<<endl;
           cout<<"============================================="<<endl;
           cout<<"ENTER YOUR FULL NAME :";
           cin.ignore();
           cin.getline(sch.name,80);
           cout<<"ENTER YOUR ROLL NUMBER :";
           cin>>sch.roll;
           cout<<"ENTER YOUR ID NUMBER :";
           cin>>sch.id;
           cout<<"ENTER YOUR PROGRAMMING MARK :";
           cin>>sch.pro;
           cout<<"ENTER YOUR APPLIED PHYSICS MARK :";
           cin>>sch.ap;
           cout<<"ENTER YOUR ENGLISH & COMMUNICATION SKILL MARK :";
           cin>>sch.english;
           cout<<"ENTER YOUR ICT MARK :";
           cin>>sch.ict;
           sch.sum=sch.pro+sch.ap+sch.english+sch.ict;// summing all the marks of a single student
           sch.average=(sch.sum/4);//used to find the avg of a student's marks
           int pos=(-1)*static_cast<int>(sizeof(scholar));//static typecasting used 
           infile.seekp(pos,ios::cur);//used to change the position of pointer to another location
           infile.write(reinterpret_cast<char *> (&sch), sizeof(scholar));
           cout<<endl;
           cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY updated"<<endl;
           checker=true;
          }
      }
     }
  infile.close();
  if(checker==false)//bool check to see if record is present or not
    {
     cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
    }
 cout<<endl;
 cout<<"press any key to continue...";
 cin.ignore();
 cin.get();
main_menu();
}
void delete_record(int num)
{//funtion used to delete any record stored at run time
 scholar sch;
 ifstream infile;
 infile.open("Report.txt",ios::binary);
 if(!infile)
   {
    cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
    cin.ignore();
    cin.get();
   }
 ofstream outfile;
 outfile.open("Record2.txt",ios::binary);
 infile.seekg(0,ios::beg);// used to start pointer position from the beginning of the file
 cout<<"\t\t\t\t===========DELETE A REPORT CARD==========\n\n";
 while(infile.read(reinterpret_cast<char*>(&sch),sizeof(scholar)))// re-interpret cast used to change data type of one pointer to another pointer
     {
      if(sch.roll!=num)//if conditional statement
        {
         outfile.write(reinterpret_cast<char*>(&sch),sizeof(scholar));
        }
     }
 infile.close();
 outfile.close();
 remove("Report.txt");//to remove the record
 rename("Record2.txt","Report.txt");
 cout<<endl;
 cout<<"\t\t\t\tRECORD SUCCESSFULLY DELETED"<<endl;
 cout<<"press any key to continue...";
 cin.ignore();
 cin.get();
 main_menu();//used to display main menu again
}
