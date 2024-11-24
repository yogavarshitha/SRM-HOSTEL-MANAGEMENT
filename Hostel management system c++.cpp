#include<iostream>
#include<conio.h>
#include<process.h>
#include<fstream>
#include<stdio.h>
#include <string.h>

using namespace std;

class hostel
{
    int room_no;
    char name[30];
    char address[50];
    char phone[10];
public:
    int main_menu();
    int add();
    int display();
    int rooms();
    int edit();
    int check(int);
    int modify(int);
    int delete_rec(int);
};
int hostel::main_menu()
{
    int choice=0;
    while(choice!=5)
    {
        cout<<"\n\t\t\t\t*************";
        cout<<"\n\t\t\t\t* MAIN MENU *";
        cout<<"\n\t\t\t\t*************";
        cout<<"\n\n\n\t\t\t1.Allot A Room";
        cout<<"\n\t\t\t2.student record";
        cout<<"\n\t\t\t3.Rooms Allotted";
        cout<<"\n\t\t\t4.Edit record";
        cout<<"\n\t\t\t5.Exit";
        cout<<"\n\n\t\t\tEnter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            display();
            system("pause");
            break;
        case 3:
            rooms();
            break;
        case 4:
            edit();
            break;
        case 5:
            break;
        default:
        {
            cout<<"\n\n\t\t\tWrong choice!!!";
            cout<<"\n\t\t\tPress any key to continue!!";
            return 0;
//system("pause");
        }
        }
    }
    return(0);
}
int hostel::add()
{
    int r,flag;
    ofstream fout("record.dat",ios::binary|ios::app);
    cout<<"\n Enter Customer Detalis";
    cout<<"\n **********************";
    cout<<"\n\n Room no: ";
    cin>>r;
    flag=check(r);
    if(flag)
        cout<<"\n Sorry..!!!Room is already booked";
    else
    {
        room_no=r;
        cout<<"\n Name:\t ";
        cin>>name;
        cout<<"\n Address:\t ";
        cin>>address;
        cout<<"\n Phone No:\t ";
        cin>>phone;
        cout<<endl;
        fout.write((char*)this,sizeof(*this));
        cout<<"\n Room is booked!!!";
    }
    cout<<"\n Press any key to continue!!";
    system("pause");
    fout.close();
    return 0;
}
int hostel::display()
{
    ifstream fin("record.dat",ios::binary|ios::in);
    int r;
    cout<<"\n Enter room no: ";
    cin>>r;
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(*this));
        if(room_no == r)
        {
            cout<<"\n Customer Details";
            cout<<"\n ****************";
            cout<<"\n\n Room no: "<<room_no;
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Phone no: "<<phone;
        }
        else
        {
            cout<<"\n Sorry Room no. not found or vacant!!";
            cout<<"\n\n";

        }
        fin.close();
        break;
    }
    return 0;

}
int hostel::rooms()
{
    ifstream fin("record.dat",ios::in|ios::binary);
    cout<<"\n\t\t\tList Of Rooms Allotted";
    cout<<"\n\t\t\t*********************";
    cout<<"\n\n Room No.\tName\t\tAddress\t\tPhone No.\n";
    while(fin.read((char*)this,sizeof(*this)))
    {
        cout<<"\n\n "<<room_no<<"\t\t"<<name;
        cout<<"\t\t"<<address<<"\t\t"<<phone;
    }
    cout<<"\n\n\n\t\t\tPress any key to continue!!";

    fin.close();
    return 0;
}
int hostel::edit()
{
    int choice,r;
    rooms();
    cout<<"\n EDIT MENU";
    cout<<"\n *********";
    cout<<"\n\n 1.Modify Customer record";
    cout<<"\n 2.Delete Customer record";
    cout<<"\n Enter your choice: ";
    cin>>choice;
    cout<<"\n Enter room no: ";
    cin>>r;
    switch(choice)
    {
    case 1:
        modify(r);
        break;
    case 2:
        delete_rec(r);
        break;
    default:
        cout<<"\n Wrong Choice!!";
    }
    cout<<"\n Press any key to continue!!!";
    return 0;
// system("pause");
}
int hostel::check(int r)
{
    int flag=0;
    ifstream fin("record.dat",ios::in|ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(*this));
        if(room_no==r)
        {
            flag=1;
            break;
        }
    }
    fin.close();
    return(flag);
}

int hostel::modify(int r)
{
    long pos, flag;
    fstream file("record.dat",ios::in|ios::out|ios::binary);
    flag=0;
    while(!file.eof())
    {
        pos=file.tellg();
        file.read((char*)this,sizeof(*this));
        if(room_no==r)
        {
            cout<<"\n Enter New Details";
            cout<<"\n *****************";
            cout<<"\n Name: ";
            cin>>name;
            cout<<" Address: ";
            cin>>address;
            cout<<" Phone no: ";
            cin>>phone;
            file.seekg(pos);
            file.write((char*)this,sizeof(*this));
            cout<<"\n record is modified!!";
            flag=1;
            break;
        }
    }
}

int hostel::delete_rec(int r)
{
    int flag=0;
    char ch;
    ifstream fin("record.dat",ios::in|ios::binary);
    ofstream fout("temp.dat",ios::out|ios::binary);
    while(!fin.eof())
    {
        fin.read((char*)this,sizeof(*this));
        if(room_no==r)
        {
            cout<<"\n Name: "<<name;
            cout<<"\n Address: "<<address;
            cout<<"\n Pone No: "<<phone;
            cout<<"\n\n Do you want to delete this record(y/n): ";
            cin>>ch;
            if(ch=='n')
                fout.write((char*)this,sizeof(*this));
            flag=1;
        }
        else
            fout.write((char*)this,sizeof(*this));
    }
    fin.close();
    fout.close();
    if(flag==0)
        cout<<"\n Sorry room no. not found or vacant!!";
    else
    {
        remove("record.dat");
        rename("temp.dat","record.dat");
    }
    return 0;
}

int pass(void)
{
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "user";
    char pass[10] = "pass";
    do
    {
        system("cls");

        cout<<"\n  **************************  LOGIN FORM  **************************  ";
        cout<<" \n                       ENTER USERNAME:-";
        cin>>uname;
        cout<<" \n                       ENTER PASSWORD:-";
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                printf("*");
            i++;
        }
        pword[i] = '\0';
        // char code=pword;
        i = 0;
        // scanf("%s",&pword);
        if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0)
        {
            printf("  \n\n\n\t\t       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
            system("PAUSE");
            break;
        }
        else
        {
            printf("\n\t\t        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
            system("PAUSE");
            a++;

            getch();
        }
    }
    while (a <= 2);
    if (a > 2)
    {
        printf("\nSorry you have entered the wrong username and password for four times!!!");

        getch();
    }
    system("cls");
}

int main()
{
    hostel h;
    pass();

    cout<<"\n\t\t\t*****************************";
    cout<<"\n\t\t\t* HOSTEL MANAGEMENT PROJECT *";
    cout<<"\n\t\t\t*****************************";
    cout<<"\n\n\n\n\n\t\t\t";
    system("pause");
    h.main_menu();
    system("pause");
    return 0;
}
