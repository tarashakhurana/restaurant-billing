/*
Program name    : Restaurant Billing System
Version         : 1.0 (2013-2014)
Last Updated on : 30 November 2013
Filename        : comp_43.cpp
Developers      : Tarasha Khurana
School Name     : DELHI PUBLIC SCHOOL, R.K.Puram, New Delhi
*/

#include <fstream.h>
#include <conio.h>
#include <string.h>
#include <iomanip.h>
#include <stdio.h>

#include "comp_43.h"

void main()
{
	char MainMenu[][20] = {	" ABOUT US    ",
				" FOOD MENU   ",
				" BILLING     ",
				" MEMBERSHIP  ",
				" MENU UPDATE ",
				" EXIT        "
				};

	int Ch;
	do
	{
		Color(RED,WHITE);
		clrscr();

		Ch = Hmenu(1,1,MainMenu,6);

		switch(Ch)
		{
			case 0:About_Us(); break;
			case 1:Food_Menu(); break;
			case 2:{
				Billing();
				fstream Fil;
				Fil.open("ORDER.DAT", ios::binary| ios::out);
				Fil.close();
				break;
			       }
			case 3:Membership(); break;
			case 4:Menu_Update();
		}
	} while(Ch!=5);
}

void About_Us()
{
 gotoxy(1,10);
 cout<<"--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--";
 gotoxy(20,12);
 cout<<"!!!       A.B.C. RESTAURANT       !!!"<<endl<<endl;
 cout<<"--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--.--"<<endl<<endl;
 cout<<" We are a vegetarian restaurant with a wide variety of food items."<<endl<<endl;
 cout<<" We value our customers the most and have a special 20% discount for"<<endl;
 cout<<" the registered members."<<endl<<endl;
 cout<<" You can order online here."<<endl<<endl;
 cout<<" We list calories against food items for our health conscious customers."<<endl<<endl;
 cout<<" We take suggestions for updating our offerings also!"<<endl<<endl<<endl;
 cout<<" Our Address: Sector-12, R. K. Puram, Delhi - 110022"<<endl<<endl;
 cout<<" Contact mobile: 8527215555"<<endl<<endl;
 cout<<" Contact email: abc@yahoo.com"<<endl;
 gotoxy(30,49);
 cout<<" Project developed by : Tarasha Khurana, XII - H"<<endl;
 getch();
}

void Membership()
{
 char SMenu[][20] = {	"ADD MEMBER    " ,
			"DELETE MEMBER " ,
			"LIST MEMBERS  "
					};
	int Ch;
	Ch = Vmenu(41,3,SMenu,3);
	switch(Ch)
	{
		case 0:	Add_Member(); break;
		case 1:	Delete_Member(); break;
		case 2: List_Members();
	}
}

void Add_Member()
{
 fstream Fil; Member M;
 Fil.open("MEMBERS.DAT", ios::binary|ios::out|ios::app);
 char Choice;
 gotoxy(1,10);
 cout<<"Please enter the following details "<<endl<<endl;
 do
 {
  M.Input();
  Fil.write((char*)&M, sizeof(M));
  cout<<"More(Y/N)?";
  cin>>Choice;
 }
 while (Choice=='Y');
 Fil.close();
}

void Delete_Member()
{
 fstream Fil1, Fil2;
 Member M;
 int Id;
 Fil1.open("MEMBERS.DAT",ios::binary|ios::in);
 Fil2.open("TEMP.DAT",ios::binary|ios::out);
 gotoxy(1,10);
 cout<<"Enter member ID to be deleted: ";
 cin>>Id;
 int Del = 0;
 while (Fil1.read((char*)&M, sizeof(M)))
 {
  if (M.Return_Id()!=Id)
	Fil2.write((char*)&M, sizeof(M));
  else
	Del++;
 }
 if (!Del)
	{
	 cout<<"Record match not found."<<endl;
	 getch();
	}
 Fil1.close();
 Fil2.close();
 Fil1.open("TEMP.DAT",ios::binary|ios::in);
 Fil2.open("MEMBERS.DAT",ios::binary|ios::out);
 while (Fil1.read((char*)&M, sizeof(M)))
 {
  Fil2.write((char*)&M, sizeof(M));
 }
 Fil1.close();
 Fil2.close();
}

void List_Members()
{
 ShowXY(33,10, "MEMBERS");
 fstream Fil; Member M;
 Fil.open("MEMBERS.DAT",ios::binary|ios::in);
 cout<<endl<<endl<<endl<<endl<<setw(25)<<"Name"<<setw(15)<<"Member Id"<<setw(20)<<"Phone no"<<endl<<endl;
 while (Fil.read((char*)&M, sizeof(M)))
	 M.Display();
 Fil.close();
 getch();
}

void Menu_Update()
{
 char SMenu[][20] = {	"ADD ITEM    " ,
			"DELETE ITEM " ,
					};
	int Ch;
	Ch = Vmenu(54,3,SMenu,2);
	switch(Ch)
	{
		case 0:	Add_Item(); break;
		case 1:	Delete_Item();
	}
}

void Add_Item()
{
 fstream Fil; Food_Item I;
 Fil.open("FOODMENU.DAT", ios::binary|ios::out|ios::app);
 char Choice;
 gotoxy(1,10);
 cout<<"Please enter the following details "<<endl<<endl;
 do
 {
  I.Input();
  Fil.write((char*)&I, sizeof(I));
  cout<<"More(Y/N)?";
  cin>>Choice;
 }
 while (Choice=='Y');
 Fil.close();
}

void Delete_Item()
{
 fstream Fil1, Fil2;
 Food_Item I;
 int Id;
 Fil1.open("FOODMENU.DAT",ios::binary|ios::in);
 Fil2.open("TEMP.DAT",ios::binary|ios::out);
 gotoxy(1,10);
 cout<<"Enter Item code to be deleted: ";
 cin>>Id;
 int Del = 0;
 while (Fil1.read((char*)&I, sizeof(I)))
 {
  if (I.Return_Code()!=Id)
	Fil2.write((char*)&I, sizeof(I));
  else
	Del++;
 }
 if (!Del)
	cout<<"Record match not found."<<endl;
 Fil1.close();
 Fil2.close();
 Fil1.open("TEMP.DAT",ios::binary|ios::in);
 Fil2.open("FOODMENU.DAT",ios::binary|ios::out);
 while (Fil1.read((char*)&I, sizeof(I)))
 {
  Fil2.write((char*)&I, sizeof(I));
 }
 Fil1.close();
 Fil2.close();
}

void Food_Menu()
{
	char SMenu[][20] = {	"BREAKFAST " ,
				"LUNCH     " ,
				"DINNER    " ,
						};
	int Ch;
	Ch = Vmenu(15,3,SMenu,3);
	switch(Ch)
	{
		case 0:	Breakfast(); break;
		case 1:	Lunch(); break;
		case 2: Dinner();
	}
}

void Place_Order()
{
 fstream Fil;
 Order_Item I;
 Fil.open("ORDER.DAT", ios::binary|ios::out|ios::app);
 char Choice;
 cout<<endl<<endl<<"Place the order now(Y/N)? "<<endl;
 cin>>Choice;
 if (Choice=='Y')
	{
	 cout<<endl<<"Enter the item codes for the food items and their quantity you want to order."<<endl<<endl;
	 char Choice_;
	 do
	 {
	  I.Input();
	  Fil.write((char*)&I, sizeof(I));
	  cout<<endl<<"More (Y/N)? ";
	  cin>>Choice_;
	 }
	 while (Choice_=='Y');
	 cout<<endl<<endl<<"Thank you for ordering. Enjoy the food!"<<endl;
	 Fil.close();
	 getch();
	}
 else if (Choice=='N')
	cout<<"";
 else
	cout<<"You made a wrong choice."<<endl;
}

void Billing()
{
 int printed = 0;
 float Price = 0, TPrice = 0, VATamount= 0, STamount = 0 ;
 char Choice;
 int No;
 fstream Fil1, Fil2;
 Food_Item I;
 Order_Item O;
 Fil2.open("ORDER.DAT",ios::binary|ios::in);
 while (Fil2.read((char*)&O, sizeof(O)))
 {
  Fil1.open("FOODMENU.DAT", ios::binary|ios::in);
  while (Fil1.read((char*)&I, sizeof(I)))
  {
   if (I.Return_Code() == O.Return_Item_Code())
	{
	 if (printed == 0)
	 {
	  gotoxy(1,6);
	  cout<<setw(30)<<"Item Name"<<setw(13)<<"Quantity"<<setw(10)<<"Price"<<endl<<endl<<endl;
	  printed = 1;
	 }
	 Price = I.Return_Price() * O.Return_Qty();
	 cout<<setw(30)<<I.Return_Name()<<setw(13)<<O.Return_Qty()<<setw(10)<<Price<<endl<<endl;
	 TPrice += Price;
	}
  }
  Fil1.close();
 }
 Fil2.close();
 if (printed)
 {
  cout<<endl<<setw(37)<<"Total Price: "<<TPrice<<endl<<endl;
  cout<<"Member(Y/N) ? ";
  cin>>Choice;
  if (Choice == 'Y')
	{
	 cout<<endl<<"Enter the membership number: ";
	 cin>>No;
	 if (Is_Member(No))
		{
		 TPrice -= 0.2 * TPrice; // Discount for members
		 cout<<endl<<endl<<setw(37)<<"Amount after Discount (20%): "<<TPrice<<endl;
		}
	 else
		cout<<endl<<"This is not a valid member ID."<<endl<<endl;
	}
 VATamount = 0.1 * TPrice; // VAT
 cout<<setw(37)<<"VAT (10%): "<<VATamount<<endl;
 STamount =  0.05 * TPrice; //Service Tax
 cout<<setw(37)<<"Service Tax (5%): "<<STamount<<endl;
 TPrice += VATamount; // VAT
 TPrice += STamount; //Service Tax
 cout<<setw(37)<<"Bill Amount: "<<TPrice<<endl;
 }
 else
  cout<<endl<<endl<<"Please order first."<<endl;
 getch();
}

int Is_Member(int a)
{
 fstream Fil; Member M;
 Fil.open("MEMBERS.DAT", ios::binary|ios::in);
 while (Fil.read((char*)&M, sizeof(M)))
 {
  if (M.Return_Id()==a)
	return 1;
 }
 Fil.close();
 return 0;
}

void Breakfast()
{
 ShowXY(33,10, "BREAKFAST MENU");
 cout<<endl<<endl<<endl<<setw(15)<<"Item Code"<<setw(25)<<"Item Name"<<setw(15)<<"Item Price"<<setw(15)<<"Calories"<<endl<<endl<<endl;
 fstream Fil; Food_Item I;
 Fil.open("FOODMENU.DAT",ios::binary|ios::in);
 while (Fil.read((char*)&I, sizeof(I)))
	if (I.Return_Type()=='B')
		I.Display();
 getch();
 Place_Order();
 Fil.close();
}

void Lunch()
{
 ShowXY(33,10, "LUNCH MENU");
 cout<<endl<<endl<<endl<<setw(15)<<"Item Code"<<setw(25)<<"Item Name"<<setw(15)<<"Price"<<setw(15)<<"Calories"<<endl<<endl<<endl;
 fstream Fil; Food_Item I;
 Fil.open("FOODMENU.DAT",ios::binary|ios::in);
 while (Fil.read((char*)&I, sizeof(I)))
	if (I.Return_Type()=='L')
		I.Display();
 getch();
 Place_Order();
 Fil.close();
}

void Dinner()
{
 ShowXY(33,10, "DINNER MENU");
 cout<<endl<<endl<<endl<<setw(15)<<"Item Code"<<setw(25)<<"Item Name"<<setw(15)<<"Price"<<setw(15)<<"Calories"<<endl<<endl<<endl;
 fstream Fil; Food_Item I;
 Fil.open("FOODMENU.DAT",ios::binary|ios::in);
 while (Fil.read((char*)&I, sizeof(I)))
	if (I.Return_Type()=='D')
		I.Display();
 getch();
 Place_Order();
 Fil.close();
}
