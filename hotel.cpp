 //C++ PROGRAM ON HOTEL MANAGEMENT                                

 //CODING BY SHASHANK S CLASS 12TH A

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
//#include<conio.h>
using namespace std;
COORD coord = {0, 0};
class hotel
{
	int room_no;
	char name[30];
	char address[50];
	char phone[10];

	public:
	void main_menu();		//to dispay the main menu
	void add();			//to book a room
	void display(); 		//to display the customer record
	void rooms();			//to display alloted rooms
	void edit();			//to edit the customer record
	int check(int);			//to check room status
	void modify(int);		//to modify the record
	void delete_rec(int);		//to delete the record
};
void gotoxy (int x, int y)	
{
    coord.X = x;
    coord.Y = y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void welcome_dance()	
{
	system("color FC");
	int j,i,x,y;
	for(i=0;i<27;i++)
	{
		gotoxy(i,13);
		cout<<" ";
		cout<<"CONTINENTAL HOTEL";
		Sleep(40);
	}
	for(j=67;j>44;j--)
	{
		gotoxy(j,13);
		cout<<" WELCOME YOU";cout<<"            ";
		Sleep(40);
	}
	gotoxy(27,13);cout<<"CONTINENTAL HOTEL";
	gotoxy(45,13);cout<<" WELCOMES YOU";
	for(int j=78;j>=0;j--)
	{
		gotoxy(j,20);cout<<"#";
		gotoxy(j,4);cout<<"V";
		Sleep(30);
	}
	gotoxy(56,23);cout<<"SHASHANK S    4SF15IS069";
	gotoxy(56,24);cout<<"PRANIL        4SF15IS055";
	Sleep(2000);
}

void hotel::main_menu()
{
	int choice;
	while(choice!=5)
	{
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\t\t\t\t* MAIN MENU *";
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\n\n\t\t\t1.Book A Room";
		cout<<"\n\t\t\t2.Customer Record";
		cout<<"\n\t\t\t3.Rooms Allotted";
		cout<<"\n\t\t\t4.Edit Record";
		cout<<"\n\t\t\t5.Exit";
		cout<<"\n\n\t\t\tEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:	add();
				break;
			case 2: display();
				break;
			case 3: rooms();
				break;
			case 4:	edit();
				break;
			case 5: break;
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.....!!!";
					cout<<"\n\t\t\tPress enter to continue....!!";
					getchar();
				}
		}
		system("cls");
	}
}

void hotel::add()
{
	
	int r,flag;
	ofstream fout("Record.dat",ios::app);

	cout<<"\n Enter Customer Detalis";
	cout<<"\n ----------------------";
	cout<<"\n\n Room no: ";
	cin>>r;
	flag=check(r);

	if(flag)
		cout<<"\n Sorry..!!!Room is already booked";

	else
	{
		room_no=r;
		cout<<" Name: ";
		gets(name);
		cout<<" Address: ";
		gets(address);
		cout<<" Phone No: ";
		gets(phone);
		fout.write((char*)this,sizeof(hotel));
		cout<<"\n Room is booked...!!!";
	}

	cout<<"\n Press S key to continue.....!!";
	getchar();
	fout.close();
}

void hotel::display()
{
	
	ifstream fin("Record.dat",ios::in);
	int r,flag;
	cout<<"\n Enter room no: ";
	cin>>r;

	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			//clrscr();
			cout<<"\n Cusromer Details";
			cout<<"\n ----------------";
			cout<<"\n\n Room no: "<<room_no;
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Phone no: "<<phone;
			flag=1;
			break;
		}
	}

	if(flag==1)
	{
	
		cout<<"\n Sorry Room no. not found or vacant....!!";
		
	
}
     	

	//<<"\n\n Press S key to continue....!!";
	
	fin.close();
	system("pause");

}


void hotel::rooms()
{

	ifstream fin("Record.dat",ios::in);
	cout<<"\n\t\t\t    List Of Rooms Allotted";
	cout<<"\n\t\t\t    ----------------------";
	cout<<"\n\n Room No.\tName\t\tAddress\t\t\t\tPhone No.\n";

	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		cout<<"\n\n "<<room_no<<"\t\t"<<name;
		cout<<"\t\t"<<address<<"\t\t"<<phone;
	}
	cout<<"\n\n\t";
	system("pause");
	fin.close();
	system("cls");
}

void hotel::edit()
{
	
	int choice,r;

	cout<<"\n EDIT MENU";
	cout<<"\n ---------";
	cout<<"\n\n 1.Modify Customer Record";
	cout<<"\n 2.Delete Customer Record";

	cout<<"\n Enter your choice: ";
	cin>>choice;
	//clrscr();
	cout<<"\n Enter room no: " ;
	cin>>r;

	switch(choice)
	{
		case 1:	modify(r);
			break;
		case 2:	delete_rec(r);
			break;
		default: cout<<"\n Wrong Choice.....!!";
	}
	cout<<"\n Press S key to continue....!!!";
	getchar();
}


int hotel::check(int r)
{
	int flag=0;
	ifstream fin("Record.dat",ios::in);
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			flag=1;
			break;
		}
	}

	fin.close();
	return(flag);
}


void hotel::modify(int r)
{
	long pos,flag=0;
	fstream file("Record.dat",ios::in|ios::out|ios::binary);
	while(!file.eof())
	{
		pos=file.tellg();
		file.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			cout<<"\n Enter New Details";
			cout<<"\n -----------------";
			cout<<"\n Name: ";
			gets(name);
			cout<<" Address: ";
			gets(address);
			cout<<" Phone no: ";
			gets(phone);

			file.seekg(pos);
			file.write((char*)this,sizeof(hotel));
			cout<<"\n Record is modified....!!";
			flag=1;
			break;
		   }
	}

	if(flag==0)
		cout<<"\n Sorry Room no. not found or vacant...!!";
	file.close();
}

void hotel::delete_rec(int r)
{
	int flag=0;
	char ch;
	ifstream fin("Record.dat",ios::in);
	ofstream fout("temp.dat",ios::out);
	while(!fin.eof())
	{
		fin.read((char*)this,sizeof(hotel));
		if(room_no==r)
		{
			cout<<"\n Name: "<<name;
			cout<<"\n Address: "<<address;
			cout<<"\n Pone No: "<<phone;
			cout<<"\n\n Do you want to delete this record(y/n): ";
			cin>>ch;

			if(ch=='n')
				fout.write((char*)this,sizeof(hotel));
			flag=1;
		}
		else
			fout.write((char*)this,sizeof(hotel));
	}

	fin.close();
	fout.close();
	if(flag==0)
		cout<<"\n Sorry room no. not found or vacant...!!";
	else
	{
		remove("Record.dat");
		rename("temp.dat","Record.dat");
	}
}


int main()
{
	hotel h;
    welcome_dance();
    system("cls");

	// clrscr();
	
	cout<<"\n\t\t\t***************************************************";
	cout<<"\n\t\t\t*             HOTEL MANAGEMENT PROJECT ";
	cout<<"\n\t\t\t***************************************************";


	cout<<"\n\n\n\n\tMade By:";

	cout<<"\n\t\tshashank\n\n\t\tPranil\n\n";


       cout<<"\t\t\t\t\t";
	
	
	system("pause");
	system("cls");
	h.main_menu();
	
	return 0;
}

