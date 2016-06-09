/*
Program name    : Restaurant Billing System
Version         : 1.0 (2013-2014)
Last Updated on : 30 November 2013
Filename        : comp_43.h
Developers      : Tarasha Khurana
School Name     : DELHI PUBLIC SCHOOL, R.K.Puram, New Delhi
*/

const char VL=179,HL=196,TL=218,TR=191,BL=192,BR=217;
const char DVL=186,DHL=205,DTL=201,DTR=187,DBL=200,DBR=188;

class Member
{
  int Id;
  char Name[20];
  char Phone_No[15];

 public:

  void Input()
  {
   cout<<"\nName: ";
   gets(Name);
   cout<<"Membership ID: ";
   cin>>Id;
   cout<<"Phone Number: ";
   cin>>Phone_No;
  }

  void Display()
  {
   cout<<endl<<setw(25)<<Name<<setw(15)<<Id<<setw(20)<<Phone_No<<endl;
  }

  int Return_Id()
  {
   return Id;
  }
};

class Food_Item
{
  char Menu_Type;
  int Item_Code;
  char Item_Name[20];
  float Item_Price;
  float Calories;

 public:

  void Input()
  {
   cout<<"\nItem code: ";
   cin>>Item_Code;
   cout<<"Item name: ";
   gets(Item_Name);
   cout<<"Item Price: Rs. ";
   cin>>Item_Price;
   cout<<"Calories: ";
   cin>>Calories;
   cout<<"Menu type (B-Breakfast/L-Lunch/D-Dinner): ";
   cin>>Menu_Type;
  }

  void Display()
  {
   cout<<setw(15)<<Item_Code<<setw(25)<<Item_Name<<setw(15)<<Item_Price<<setw(15)<<Calories<<endl<<endl;
  }

  float Return_Price()
  {
   return Item_Price;
  }

  int Return_Code()
  {
   return Item_Code;
  }

  char* Return_Name()
  {
   return Item_Name;
  }

  char Return_Type()
  {
   return Menu_Type;
  }
};

class Order_Item
{
 int Qty;
 int Item_Code;

 public:

  void Input()
  {
   cout<<"\nItem code: ";
   cin>>Item_Code;
   cout<<"Quantity: ";
   cin>>Qty;
  }

  int Return_Qty()
  {
   return Qty;
  }

  int Return_Item_Code()
  {
   return Item_Code;
  }

};

void Color(int TC,int BC)//For Changing Text Color and Text Background
{
	textcolor(TC);
	textbackground(BC);
}

void ShowXY(int X,int Y,char CH)//Displays a character at X,Y position
{
	gotoxy(X,Y);
	cprintf("%c",CH);  //cout<<CH;
}

void ShowXY(int X,int Y,char CH[])//Displays a string at X,Y position
{
	gotoxy(X,Y);
	cprintf("%s",CH);  //cout<<CH;
}

void Vline(int X,int Y,int L)//To vertical line by joining vert. characters
{
	for (int i=Y;i<=Y+L;i++)
		ShowXY(X,i,VL);
}
void Hline(int X,int Y,int L)//To horizontal line by joining hor.characters
{
	for (int i=X;i<=X+L;i++)
		ShowXY(i,Y,HL);
}
void Recta(int C1,int R1,int C2,int R2)
{
	ShowXY(C1,R1,TL);             //
	ShowXY(C1,R2,BL);             //Placing corner characters
	ShowXY(C2,R1,TR);             //
	ShowXY(C2,R2,BR);             //
	Vline(C1,R1+1,R2-R1-2);       //
	Vline(C2,R1+1,R2-R1-2);       //Joining Corners by Vertical lines
	Hline(C1+1,R1,C2-C1-2);       //
	Hline(C1+1,R2,C2-C1-2);       //Joining Corners by Horizontal lines
}
void DVline(int X,int Y,int L)
{
	for (int i=Y;i<=Y+L;i++)
		ShowXY(X,i,DVL);
}
void DHline(int X,int Y,int L)
{
	for (int i=X;i<=X+L;i++)
		ShowXY(i,Y,DHL);
}
void DRecta(int C1,int R1,int C2,int R2)
{
	ShowXY(C1,R1,DTL);
	ShowXY(C1,R2,DBL);
	ShowXY(C2,R1,DTR);
	ShowXY(C2,R2,DBR);
	DVline(C1,R1+1,R2-R1-2);
	DVline(C2,R1+1,R2-R1-2);
	DHline(C1+1,R1,C2-C1-2);
	DHline(C1+1,R2,C2-C1-2);
}

				 //X,Y are coordinates for displaying menu
				 //Mnu all choices which required to be displayed as Menu Choices
				 //Noc no. of choices
int Vmenu(int X,int Y,char Mnu[][20],int Noc)
{
	Color(RED,WHITE);
	Recta(X,Y,X+strlen(Mnu[0])+1,Y+Noc+1);
	for (int i=0;i<Noc;i++)
		ShowXY(X+1,Y+i+1,Mnu[i]);

	int Sel=0,Exit=0;//Sel - Current Selected Option
									 //Exit- Control Variable for loop
	do
	{
		int Tsel=Sel;    //To store the current selection in Tsel
		Color(WHITE,RED);
		ShowXY(X+1,Y+Sel+1,Mnu[Sel]);
		Color(RED,WHITE);
		char Cho=getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch(Cho)
		{
		 case 71:Sel=0;break;
		 case 79:Sel=Noc-1;break;
		 case 72:if (Sel==0)
				 Sel=Noc-1;
			 else
				 Sel--;
			 break;
		 case 80:if (Sel==Noc-1)
				 Sel=0;
			 else
				 Sel++;
			 break;
		 case 13:Exit=1; //Enter Key
			 break;
		 case 27:Sel=-1; //Escape
			 Exit=1;
			 break;
		}
		ShowXY(X+1,Y+Tsel+1,Mnu[Tsel]);
	}
	while (!Exit);
	return Sel;
}

int Hmenu(int X,int Y,char Mnu[][20],int Noc)
{
	Color(RED,WHITE);
	for (int i=0;i<Noc;i++)
		ShowXY(X+13*i+1,Y,Mnu[i]);
	int Sel=0,Exit=0;
	do
	{
		int Tsel=Sel;    //To store the current selection in Tsel
		Color(WHITE,RED);
		ShowXY(X+13*Sel+1,Y,Mnu[Sel]);
		Color(RED,WHITE);
		char Cho=getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch(Cho)
		{
		 case 71:Sel=0;break;
		 case 79:Sel=Noc-1;break;
		 case 75:if (Sel==0)
				 Sel=Noc-1;
			 else
				 Sel--;
			 break;
		 case 77:if (Sel==Noc-1)
				 Sel=0;
			 else
				 Sel++;
			 break;
		 case 13:Exit=1;
			 break;
		 case 27:Sel=-1;
			 Exit=1;
			 break;
		}
		ShowXY(X+13*Tsel+1,Y,Mnu[Tsel]);
	}
	while (!Exit);
	return Sel;
}

void ClearArea(int C1,int R1,int C2,int R2)
{
	window(C1,R1,C2,R2);
	clrscr();
	window(1,1,80,25);
}


void About_Us();
void Food_Menu();
void Membership();
void Menu_Update();
void Add_Item();
void Delete_Item();
void Add_Member();
void Delete_Member();
void List_Members();
void Lunch();
void Place_Order();
void Billing();
int Is_Member(int);
void Breakfast();
void Dinner();