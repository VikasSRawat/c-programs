/*Learn how to output to the output screen such that the starting colomns match of 2 rows
ex: Vikas Rawat     20011943       69
    God             98560302       1
*/
//WE CAN CALCULATE AND DISPLAY THE RETURN DATE ANOTHER FUNCTION WHEN ASKED
#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
using namespace std;
int getid(int );
void add_book();
void Modify_book();
void delete_book();
void view_all_book_details();
void view_book_details();
void add_student();
void modify_student();
void delete_student();
void view_student();
void view_all();
void issue();
void return_book();
string getbook(int );
class date{
    public:
    int dd;
    int mm;
    int yy;
    void correct()
    {
        if(dd>30)
        {
            dd-=30;
            mm++;
        }
        if(mm>12)
        {
            mm-=12;
            yy++;
        }
    }
    date()
    {
        dd=0;
        mm=0;
        yy=0;
    }
    void set_date()
    {
        cout<<"Enter the date of issue in the format dd mm yyyy : ";
        cin>>dd>>mm>>yy;
    }
    void show_date()
    {
        cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
    }
};
class book_data{
    public:
    char title[40];
    char author[40];
    char publisher[40];
    int books_acc_no;//can know which student has issued which book through books_acc_no(Books Accession number)
    int quant;
    int present_in_lib;//if less than quant then one of this book has been issued
    void input_data_book()
    {
        cout<<"Enter the title of the book : ";
        cin>>title;
        cout<<"Enter the authour's name : ";
        cin>>author;
        cout<<"Enter the publisher's name : ";
        cin>>publisher;
        cout<<"Enter the book accession number : ";
        cin>>books_acc_no;
        cout<<"Enter the quantity of the books you will be adding to the library : ";
        cin>>quant;
        present_in_lib=quant;
    }
    void display()
    {
        cout<<"Title : "<<title<<endl;
        cout<<"Author's name : "<<author<<endl;
        cout<<"Publisher : "<<publisher<<endl;
        //cout<<"Books Accession number : "<<books_acc_no<<endl;
        cout<<"Accession Number : "<<books_acc_no<<endl;
        cout<<"Max amount of books present in library : "<<quant<<endl;
        cout<<"The amount of books currently present inside the library : "<<present_in_lib<<endl;
    }
};
class student_data{
    public:
        int student_id;//University
        char fname[40];
        char lname[40];
        //char address[40];
        char course[40];
        char branch[40];
        //int books_issued;
        void books_issued_details();
        int arr_acc[5]={-1};//we can store the accession numbers of the books issued by the person in this array
        student_data(){
            for(int i=0;i<5;i++)
                arr_acc[i]=-1;
        }
        //A person can take a maximum of 5 books at a time
        //if the 1st block contains -1 then that means this person has issuesd no books at all
        //if all the 5 blocks arr non negative numbers than the person cannot issue anymore books
        date arr_issue[5];//similarly in sync with acc_arr we can see which the issue date of the book
        date arr_return[5];
        void input_data(){
            cout<<"Enter the Student ID : ";
            cin>>student_id;
            cout<<"Enter the name of the Student : ";
            cin>>fname>>lname;
            cout<<"Enter the branch of the student : ";
            cin>>branch;
            cout<<"Enter the course of the student : ";
            cin>>course;
        }
        void display()
        {
            cout<<"Student Id : "<<student_id<<endl;
            cout<<"First Name : "<<fname<<endl;
            cout<<"Last Name : "<<lname<<endl;
            cout<<"Branch : "<<branch<<endl;
            cout<<"course : "<<course<<endl;
        }
};
class menu{
    public:
        void main_menu();
        void student_menu();
        void Book_menu();
};
int main()
{
    //main_menu();
    menu obj;
    obj.main_menu();
    return 0;
}
void menu::main_menu()
{
    while(1)
    {
        system("cls");
        cout<<"*****************************Main Menu*****************************"<<endl<<endl;
        cout<<"\t1. Student Menu\n\t2. Book Menu\n\t3. Issue Book\n\t4. Return Book\n\t5. Exit"<<endl;//In issue book we reduce the quantity of the book and edit the details of a book issue section in a student to 1
        int ch;
        scanf("%d",&ch);
        //system("pause");    
        switch (ch)
        {
        case 1: student_menu();
            break;
        case 2: Book_menu();
            break;
        case 3: issue();
            break;
        case 4: return_book();
            break;
        default:
            cout<<"Exiting the Main Menu\nThank you!!!!!"<<endl;
            exit(1);    
        }
    }
}
void menu :: student_menu()
{
    while(1)
    {
        system("cls");
        cout<<"*****************************Student Menu*****************************"<<endl<<endl;
        cout<<"\t1. Add new student\n\t2. Modify student details\n\t3. Delete student details\n\t4. View Student details\n\t5. View all Student details \n\t6. Go Back to Main Menu"<<endl;
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: add_student();
                system("pause");
                break;
            case 2: modify_student();
                system("pause");
                break;
            case 3: delete_student();
                system("pause");
                break;
            case 4: view_student();
                system("pause");
                break;
            case 5: view_all();
                system("pause");
                break;
            default:
                main_menu();
        }
    }
}
void menu :: Book_menu()
{
    while(1)
    {
        system("cls");
        cout<<"*****************************Book Menu*****************************"<<endl<<endl;
        cout<<"\t1. Add new Book\n\t2. Modify book details\n\t3. Delete book details\n\t4. View book details\n\t5. View all books \n\t6. Go Back to Main Menu"<<endl;
        int ch;
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: add_book();
            system("pause");
            break;
        case 2: Modify_book();
            system("pause");
            break;
        case 3: delete_book();
            system("pause");
            break;
        case 4: view_book_details();
            system("pause");
            break;
        case 5: view_all_book_details();
            system("pause");
            break;
        default:
            main_menu();
        }
    }
}
int getid(int i)
{
    ifstream fhandle;
    fhandle.open("student.txt");
    student_data obj;
    while(fhandle>>obj.student_id>>obj.fname>>obj.lname>>obj.branch>>obj.course>>obj.arr_acc[0]>>obj.arr_acc[1]>>obj.arr_acc[2]>>obj.arr_acc[3]>>obj.arr_acc[4])
    {
        if(i==obj.student_id)
            return 1;
    }
    fhandle.close();
    return 0;
}
void add_student()
{
    student_data obj;
    obj.input_data();
    ofstream fhandle;
    fhandle.open("student.txt",ios::app);
    //Making a function if the student id you want to add already exists then return to the main menu directly wihtout adding anymore data
    //as student id is unique only one can exist
    if(getid(obj.student_id))
    {
        cout<<"Student ID already exists \nPlease choose another option"<<endl;
        return ;
    }
    fhandle<<obj.student_id<<" "<<obj.fname<<" "<<obj.lname<<" "<<obj.branch<<" "<<obj.course<<" "<<obj.arr_acc[0]<<" "<<obj.arr_acc[1]<<" "<<obj.arr_acc[2]<<" "<<obj.arr_acc[3]<<" "<<obj.arr_acc[4]<<" "<</*obj.arr_issue[0]<<" "<<obj.arr_issue[1]<<" "<<obj.arr_issue[2]<<" "<<obj.arr_issue[3]<<" "<<obj.arr_issue[4]<<" "<<obj.arr_return[0]<<" "<<obj.arr_return[1]<<" "<<obj.arr_return[2]<<" "<<obj.arr_return[3]<<" "<<obj.arr_return[4]<<*/endl;
    fhandle.close();
}
void modify_student()
{//creates a new file and copies the old file contents to the new file with the updated student information and deletes the old file
//then renames the new file name with the old file name
    int i,f=1;//i is for student id you want  to modify and f is for seeing if that student id exists or not
    cout<<"Enter the student ID of whose you want to modify : ";
    cin>>i;
    ifstream fhandle;
    ofstream nhandle;
    fhandle.open("student.txt");
    nhandle.open("new.txt");
    student_data obj;
    while(fhandle>>obj.student_id>>obj.fname>>obj.lname>>obj.branch>>obj.course>>obj.arr_acc[0]>>obj.arr_acc[1]>>obj.arr_acc[2]>>obj.arr_acc[3]>>obj.arr_acc[4])//This will prevent the last element from being printed twice
    {
        if(obj.student_id==i)
        {
            f=0;
            obj.display();
            cout<<endl;
            cout<<"1 for the first name\n2. for the branch\n3. for course\n4. for not modifying anything\nEnter : ";
            int ch;
            cin>>ch;
            switch(ch)
            {
                case 1: cout<<"Enter the new name : ";
                    cin>>obj.fname>>obj.lname;
                    break;
                case 2: cout<<"Enter the new branch : ";
                    cin>>obj.branch;
                    break;
                case 3: cout<<"Enter the new course : ";
                    cin>>obj.course;
                    break;
            }
            cout<<"Data modified successfully\n";
        }
        nhandle<<obj.student_id<<" "<<obj.fname<<" "<<obj.lname<<" "<<obj.branch<<" "<<obj.course<<" "<<obj.arr_acc[0]<<" "<<obj.arr_acc[1]<<" "<<obj.arr_acc[2]<<" "<<obj.arr_acc[3]<<" "<<obj.arr_acc[4]<<" "<</*obj.arr_issue[0]<<" "<<obj.arr_issue[1]<<" "<<obj.arr_issue[2]<<" "<<obj.arr_issue[3]<<" "<<obj.arr_issue[4]<<" "<<obj.arr_return[0]<<" "<<obj.arr_return[1]<<" "<<obj.arr_return[2]<<" "<<obj.arr_return[3]<<" "<<obj.arr_return[4]<<*/endl;
        //we are inputing all the data with the modified data into a new txt file
    }
    nhandle.close();
    fhandle.close();
    remove("student.txt");//we delete the old student.txt file
    rename("new.txt","student.txt");//renaming the new file as student.txt
    if(f)
        cout<<"Invalid Student ID\n\n";
}
void delete_student()
{//almost the same as modify but instead of editing that particluar student data and copying it to the new file
//instead when encountering the student id in the loop then it skips that particular input
    int i,f=1;//i is for student id you want  to modify and f is for seeing if that student id exists or not
    cout<<"Enter the student ID of whose you want to modify : ";
    cin>>i;
    ifstream fhandle;
    ofstream nhandle;
    fhandle.open("student.txt");
    nhandle.open("new.txt");
    student_data obj;
    while(fhandle>>obj.student_id>>obj.fname>>obj.lname>>obj.branch>>obj.course>>obj.arr_acc[0]>>obj.arr_acc[1]>>obj.arr_acc[2]>>obj.arr_acc[3]>>obj.arr_acc[4])//This will prevent the last element from being printed twice
    {
        if(obj.student_id==i)
        {
            f=0;
            obj.display();
            cout<<"Data deleted successfully\n";
            continue;
        }
        nhandle<<obj.student_id<<" "<<obj.fname<<" "<<obj.lname<<" "<<obj.branch<<" "<<obj.course<<" "<<obj.arr_acc[0]<<" "<<obj.arr_acc[1]<<" "<<obj.arr_acc[2]<<" "<<obj.arr_acc[3]<<" "<<obj.arr_acc[4]<<" "<</*obj.arr_issue[0]<<" "<<obj.arr_issue[1]<<" "<<obj.arr_issue[2]<<" "<<obj.arr_issue[3]<<" "<<obj.arr_issue[4]<<" "<<obj.arr_return[0]<<" "<<obj.arr_return[1]<<" "<<obj.arr_return[2]<<" "<<obj.arr_return[3]<<" "<<obj.arr_return[4]<<*/endl;
    }
    nhandle.close();
    fhandle.close();
    remove("student.txt");//we delete the old student.txt file
    rename("new.txt","student.txt");//renaming the new file as student.txt
    if(f)
        cout<<"Invalid Student ID\n\n";
}
void view_student()
{
    int i,f=1;//i is for student id you want  to modify and f is for seeing if that student id exists or not
    cout<<"Enter the student ID of the student that you want to view : ";
    cin>>i;
    ifstream fhandle;
    fhandle.open("student.txt");
    student_data obj;
    ifstream bhandle;
    bhandle.open("Books.txt");
    book_data obj1;
    while(fhandle>>obj.student_id>>obj.fname>>obj.lname>>obj.branch>>obj.course>>obj.arr_acc[0]>>obj.arr_acc[1]>>obj.arr_acc[2]>>obj.arr_acc[3]>>obj.arr_acc[4])//This will prevent the last element from being printed twice
    {
        if(obj.student_id==i)
        {
            f=0;
            cout<<"The details of student id are %d \n"<<i<<endl;
            obj.display();
            if(obj.arr_acc[0]==-1)
                cout<<"Student has not issued anybook"<<endl;
            else
            {
                cout<<"Books issued"<<endl;
                while(bhandle>>obj1.title>>obj1.author>>obj1.publisher>>obj1.books_acc_no>>obj1.quant>>obj1.present_in_lib)
                    for(int i=0;i<5;i++)
                        if(obj.arr_acc[i]==obj1.books_acc_no)
                            cout<<obj1.title<<endl;
            }
        }
    }
    fhandle.close();
    if(f)
        cout<<"Invalid Student ID\n\n";
    bhandle.close();
}
void view_all()
{
    ifstream fhandle;
    fhandle.open("student.txt");
    student_data obj;
    int c=0;
    while(fhandle>>obj.student_id>>obj.fname>>obj.lname>>obj.branch>>obj.course>>obj.arr_acc[0]>>obj.arr_acc[1]>>obj.arr_acc[2]>>obj.arr_acc[3]>>obj.arr_acc[4])//This will prevent the last element from being printed twice
    {
            //cout<<"The details of the student id %d \n",i<<endl;
            c++;
            obj.display();
            cout<<endl;
    }
    fhandle.close();
    if(!c)
        cout<<"There are no students information present in the database currently"<<endl;
}
void add_book()
{
    book_data obj;
    obj.input_data_book();
    ofstream fhandle;
    fhandle.open("Books.txt",ios::app);
    fhandle<<obj.title<<" "<<obj.author<<" "<<obj.publisher<<" "<<obj.books_acc_no<<" "<<obj.quant<<" "<<obj.present_in_lib<<endl;
    fhandle.close();
}
void Modify_book()
{
    book_data obj;
    int acc_num;
    cout<<"Enter the accession number of the book of which you want to edit : ";
    cin>>acc_num;
    ifstream fhandle;
    ofstream nhandle;
    fhandle.open("Books.txt");
    nhandle.open("new.txt");
    int c=1;
    while(fhandle>>obj.title>>obj.author>>obj.publisher>>obj.books_acc_no>>obj.quant>>obj.present_in_lib)
    {
        if(obj.books_acc_no==acc_num)
        {
            obj.display();
            c=0;
            int ch;
            cout<<"1. for modifying title of the book \n2. for modifying the author's name\n3. for modifying the publisher's name\n4. for Max amount of this particular book in the library \n";
            cout<<"Enter : ";
            cin>>ch;
            switch (ch)
            {
            case 1: cout<<"Enter the new title of the book : ";
                cin>>obj.title;
                break;
            case 2: cout<<"Enter the new author's name : ";
                cin>>obj.author;
                break;
            case 3: cout<<"Enter the new publisher's name : ";
                cin>>obj.publisher;
                break;
            case 4: cout<<"Enter the new max amount of this book : ";
                cin>>obj.quant;
                break;
            case 5: cout<<"Enter the new amount of the books currently present in the book : ";
                cin>>obj.present_in_lib;
                break;
            //default:
                //break;
            }
            cout<<"Data modified successfully\n";
        }
        nhandle<<obj.title<<" "<<obj.author<<" "<<obj.publisher<<" "<<obj.books_acc_no<<" "<<obj.quant<<" "<<obj.present_in_lib<<endl;
    }
    if(c)
        cout<<"Invalid Student Id"<<endl;
    nhandle.close();
    fhandle.close();
    remove("Books.txt");
    rename("new.txt","Books.txt");
}
void view_all_book_details()
{
    ifstream fhandle;
    fhandle.open("Books.txt");
    book_data obj;
    int c=0;
    while(fhandle>>obj.title>>obj.author>>obj.publisher>>obj.books_acc_no>>obj.quant>>obj.present_in_lib)
    {
        obj.display();
        c++;
        cout<<endl;
    }
    cout<<endl;
    if(c==0)
        cout<<"There are currently no books present in the library "<<endl;
    fhandle.close();
}
void delete_book()
{
    int i,c=1;
    cout<<"Enter the book accession number of which you want to delete : ";
    cin>>i;
    ofstream nhandle;
    ifstream fhandle;
    nhandle.open("new.txt");
    fhandle.open("Books.txt");
    book_data obj;
    while(fhandle>>obj.title>>obj.author>>obj.publisher>>obj.books_acc_no>>obj.quant>>obj.present_in_lib)
    {
        if(i==obj.books_acc_no)
        {
            c=0;
            obj.display();
            cout<<"\nData deleted successfully "<<endl;
            continue;
        }
        nhandle<<obj.title<<" "<<obj.author<<" "<<obj.publisher<<" "<<obj.books_acc_no<<" "<<obj.quant<<" "<<obj.present_in_lib<<endl;
    }
    if(c)
        cout<<"There is no book with that accession number present in the library\n";
    nhandle.close();
    fhandle.close();
    remove("Books.txt");
    rename("new.txt","Books.txt");
}
void view_book_details()
{
    int i,c=1;
    cout<<"Enter the accession number of the book details you want to display : ";
    cin>>i;
    ifstream fhandle;
    fhandle.open("Books.txt");
    book_data obj;
    while(fhandle>>obj.title>>obj.author>>obj.publisher>>obj.books_acc_no>>obj.quant>>obj.present_in_lib)
    {
        if(i==obj.books_acc_no)
        {
            cout<<"The details of the books is : \n";
            obj.display();
            c=0;
        }
    }
    if(c)
        cout<<"Invalid accession number"<<endl;
    fhandle.close();
}
void issue()
{//decrements the present in library by 1 and updates the accession array by the books accession number
    int stdid;
    cout<<"Enter the student id : ";
    cin>>stdid;
    student_data obj;
    ifstream stdfhandle;
    ifstream bookfhandle;
    ofstream newstd;
    ofstream newbook;
    newbook.open("Newbook.txt");
    newstd.open("Newstudent.txt");
    stdfhandle.open("student.txt");
    bookfhandle.open("Books.txt");
    while(stdfhandle>>obj.student_id>>obj.fname>>obj.lname>>obj.branch>>obj.course>>obj.arr_acc[0]>>obj.arr_acc[1]>>obj.arr_acc[2]>>obj.arr_acc[3]>>obj.arr_acc[4])//This will prevent the last element from being printed twice
    {
        if(obj.student_id==stdid)
        {
            if(obj.arr_acc[4]!=-1)
            {
                cout<<"Cannot issue anymore books \nPlease return the books that you have issued before"<<endl;
                break;
            }
            int acc_num;
            cout<<"Enter the accession number of the book you want to issue : ";
            cin>>acc_num;
            book_data obj1;
            while(bookfhandle>>obj1.title>>obj1.author>>obj1.publisher>>obj1.books_acc_no>>obj1.quant>>obj1.present_in_lib)
            {
                if(obj1.present_in_lib==0)
                    cout<<"Currently the book which you are asking for is not there \nPlease try and issue that book later\nMeanwhile you can issue any other book"<<endl;
                if(acc_num==obj1.books_acc_no&&obj1.present_in_lib>0)
                {
                    int i=0;
                    while(obj.arr_acc[i]!=-1)
                        i++;
                    obj.arr_acc[i]=acc_num;
                    obj1.present_in_lib=obj1.present_in_lib-1;

                }
                newbook<<obj1.title<<" "<<obj1.author<<" "<<obj1.publisher<<" "<<obj1.books_acc_no<<" "<<obj1.quant<<" "<<obj1.present_in_lib<<endl;
            }
        }
        newstd<<obj.student_id<<" "<<obj.fname<<" "<<obj.lname<<" "<<obj.branch<<" "<<obj.course<<" "<<obj.arr_acc[0]<<" "<<obj.arr_acc[1]<<" "<<obj.arr_acc[2]<<" "<<obj.arr_acc[3]<<" "<<obj.arr_acc[4]<<" "<</*obj.arr_issue[0]<<" "<<obj.arr_issue[1]<<" "<<obj.arr_issue[2]<<" "<<obj.arr_issue[3]<<" "<<obj.arr_issue[4]<<" "<<obj.arr_return[0]<<" "<<obj.arr_return[1]<<" "<<obj.arr_return[2]<<" "<<obj.arr_return[3]<<" "<<obj.arr_return[4]<<*/endl;
    }
    newstd.close();
    newbook.close();
    stdfhandle.close();
    bookfhandle.close();
    remove("student.txt");
    rename("Newstudent.txt","student.txt");
    remove("Books.txt");
    rename("Newbook.txt","Books.txt");
}
string getbook(int n=0)//returns the book name of that accession number
{
    ifstream fhandle;
    fhandle.open("Books.txt");
    book_data obj;
    while(fhandle>>obj.title>>obj.author>>obj.publisher>>obj.books_acc_no>>obj.quant>>obj.present_in_lib)
    {
        if(obj.books_acc_no==n)
            return obj.title;
    }
    fhandle.close();
    return "error";
}
void return_book()
{//It increments the present in library by 1 and updates that particular student's array accession number to -1 of that book
    int id;
    cout<<"Please Enter the student ID : ";
    cin>>id;
    ifstream stdfhandle,bookfhandle;
    ofstream newstd,newbook;
    if(getid(id)==0)
        cout<<"Please Enter the correct student ID"<<endl;
    else
    {
        stdfhandle.open("student.txt");
        newstd.open("newstd.txt");
        student_data obj;
        while(stdfhandle>>obj.student_id>>obj.fname>>obj.lname>>obj.branch>>obj.course>>obj.arr_acc[0]>>obj.arr_acc[1]>>obj.arr_acc[2]>>obj.arr_acc[3]>>obj.arr_acc[4])//This will prevent the last element from being printed twice
        {
            if(obj.student_id==id&&obj.arr_acc[0]>-1)
            {
                cout<<"You have issued the following books "<<endl;
                for(int i=0;i<5;i++)
                    if(obj.arr_acc[i]>-1)
                        cout<<getbook(obj.arr_acc[i])<<" "<<obj.arr_acc[i]<<endl;
                cout<<"Please Enter the accession number of that particular book : ";
                int acc_num;
                cin>>acc_num;
                for(int i=0;i<5;i++)
                {
                    if(obj.arr_acc[i]==acc_num)
                    {
                        for(int j=i;j<5;j++)
                            obj.arr_acc[j]=obj.arr_acc[j+1];
                        obj.arr_acc[4]=-1;
                    }
                }
                        //obj.arr_acc[i]=-1;//reseting that book issued accession number section to -1 in the students data
                bookfhandle.open("Books.txt");
                newbook.open("newbook.txt");
                book_data obj1;
//                int f=1;
                while(bookfhandle>>obj1.title>>obj1.author>>obj1.publisher>>obj1.books_acc_no>>obj1.quant>>obj1.present_in_lib)
                {
                    if(acc_num==obj1.books_acc_no)
                    {
                        obj1.present_in_lib++;
                        //f=0;
                    }
                    newbook<<obj1.title<<" "<<obj1.author<<" "<<obj1.publisher<<" "<<obj1.books_acc_no<<" "<<obj1.quant<<" "<<obj1.present_in_lib<<endl;
                }
            }
            newstd<<obj.student_id<<" "<<obj.fname<<" "<<obj.lname<<" "<<obj.branch<<" "<<obj.course<<" "<<obj.arr_acc[0]<<" "<<obj.arr_acc[1]<<" "<<obj.arr_acc[2]<<" "<<obj.arr_acc[3]<<" "<<obj.arr_acc[4]<<" "<</*obj.arr_issue[0]<<" "<<obj.arr_issue[1]<<" "<<obj.arr_issue[2]<<" "<<obj.arr_issue[3]<<" "<<obj.arr_issue[4]<<" "<<obj.arr_return[0]<<" "<<obj.arr_return[1]<<" "<<obj.arr_return[2]<<" "<<obj.arr_return[3]<<" "<<obj.arr_return[4]<<*/endl;
        }
    }
    stdfhandle.close();
    bookfhandle.close();
    newstd.close();
    newbook.close();
    remove("student.txt");
    rename("newstd.txt","student.txt");
    remove("Books.txt");
    rename("newbook.txt","Books.txt");
}