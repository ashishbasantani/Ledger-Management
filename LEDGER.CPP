#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<process.h>
struct ledger
 {
  int vno;
  char date[11],vtype[8],cname[25];
  float damt,camt;
 }ld;
void login();
void menu();
void input();
void show();
void search();
void delet();
void backup();
void searchmenu();
void dsearch();
void cnamesearch();
void vtypesearch();
void vnosearch();
fstream fp;
void main()
 {
  clrscr();
  login();
  getch();
 }
void login()
 {
  clrscr();
  int i,y;
  char uname[15],pwd[15];
  a:
  clrscr();
  gotoxy(30,6);
  for(i=0;i<30;i++)
   {
    cout<<"-";
   }
  y=7;
  for(i=0;i<5;i++)
   {
    gotoxy(30,y);
    cout<<"#";
    y++;
   }
  gotoxy(30,y);
  for(i=0;i<30;i++)
   {
    cout<<"-";
   }
  y=7;
 for(i=0;i<5;i++)
  {
   gotoxy(59,y);
   cout<<"#";
   y++;
  }
 gotoxy(33,8);
 cout<<"User Name";
 gotoxy(33,10);
 cout<<"Password";
 gotoxy(43,8);
 gets(uname);
 gotoxy(43,10);
 gets(pwd);
 if(strcmp(uname,"ashish")==0)
  {
   if(strcmp(pwd,"8871308703")==0)
    {
     menu();
    }
   else
    {
     goto a;
    }
  }
 else
  {
   goto a;
  }
 }
void menu()
 {
  clrscr();
  int i;
  for(i=0; i<80; i++)
   {
    cout<<"-";
   }
  for(i=0;i<23;i++)
   {
    cout<<"#";
    cout<<endl;
   }
  int j=2;
  for(i=0;i<23;i++)
   {
    gotoxy(80,j++);
    cout<<"#";
   }
  int k=1;
  for(i=0;i<79;i++)
   {
    gotoxy(k++,j);
    cout<<"-";
   }
  gotoxy(25,4);
  cout<<"Ledger Maintenance System";
  gotoxy(43,5);
  cout<<"//By Ashish Basantani";
  //top horizontal
  gotoxy(30,8);
  for(i=0;i<34;i++)
   {
    cout<<"#";
   }
  //left vertical
  j=9;
  for(i=0;i<12;i++)
   {
    gotoxy(30,j++);
    cout<<"#";
   }
  //down horizontal
  gotoxy(30,j);
  for(i=0;i<34;i++)
   {
    cout<<"#";
   }
  //right vertical
  j=9;
  for(i=0;i<12;i++)
   {
    gotoxy(63,j++);
    cout<<"#";
   }
  gotoxy(43,7);
  cout<<"MENU";
  gotoxy(34,10);
  cout<<"1. Input Record";
  gotoxy(34,12);
  cout<<"2. Show Records";
  gotoxy(34,14);
  cout<<"3. Search & show the Records";
  gotoxy(34,16);
  cout<<"4. Delete Record";
  gotoxy(34,18);
  cout<<"5. Backup Data";
  gotoxy(34,20);
  cout<<"6. Exit";
  int choice;
  gotoxy(34,23);
  cout<<"Enter your choice : ";
  cin>>choice;
  if(choice==1)
   {
    input();
   }
  if(choice==2)
   {
    show();
   }
  if(choice==3)
   {
    search();
   }
  if(choice==4)
   {
    delet();
   }
  if(choice==5)
   {
    backup();
   }
  if(choice==6)
   {
    exit(0);
   }
  }
void input()
 {
  char ch='n';
  int i;
  fp.open("ledger.pnb",ios::app|ios::binary);
  do
   {
    clrscr();
    gotoxy(5,3);
    cout<<"Date of Transaction : ";
    gotoxy(5,5);
    cout<<"Customer name : ";
    gotoxy(5,7);
    cout<<"Type of transaction (Sales/Receipt) : ";
    gotoxy(5,9);
    cout<<"Voucher no. : ";
    gotoxy(5,11);
    cout<<"Transaction Amount : ";
   /* else
     {
      cout<<"Transaction type does'nt exist please write correct transaction type";
      input();
     }*/
    gotoxy(45,3);
    gets(ld.date);
    gotoxy(45,5);
    gets(ld.cname);
    for(i=0;i<strlen(ld.cname);i++)
     {
      ld.cname[i]=toupper(ld.cname[i]);
     }
    a:
    gotoxy(45,7);
    gets(ld.vtype);
    if((strcmp(ld.vtype,"sales")!=0)&&(strcmp(ld.vtype,"SALES")!=0)&&(strcmp(ld.vtype,"Sales")!=0)&&(strcmp(ld.vtype,"receipt")!=0)&&(strcmp(ld.vtype,"RECEIPT")!=0)&&(strcmp(ld.vtype,"Receipt")!=0))
     {
      goto a;
     }
    for(i=0;i<strlen(ld.vtype);i++)
    {
     ld.vtype[i]=toupper(ld.vtype[i]);
    }
    gotoxy(45,9);
    cin>>ld.vno;
    gotoxy(45,11);
    if((strcmp(ld.vtype,"sales")==0)||(strcmp(ld.vtype,"SALES")==0)||(strcmp(ld.vtype,"Sales")==0))
     {
      cin>>ld.damt;
      ld.camt=0;
     }
    else if((strcmp(ld.vtype,"receipt")==0)||(strcmp(ld.vtype,"RECEIPT")==0)||(strcmp(ld.vtype,"Receipt")==0))
     {
      cin>>ld.camt;
      ld.damt=0;
     }
    fp.write((char*)&ld,sizeof(ledger));
    cout<<"\nData written to file succesfully\nDo you want to enter more data(Y/N) ";
    cin>>ch;
   }while((ch=='Y')||(ch=='y'));
  if(ch=='n')
   {
    fp.close();
    menu();
   }
  fp.close();
 }
void show()
 {
  clrscr();
  int i;
  fp.open("ledger.pnb",ios::in|ios::binary);
  cout<<"Date\t     Customer Name\tvoucher type   voucher no.\tDr.\tCr.\n";
  for(i=0;i<80;i++)
   cout<<"_";
  cout<<endl;
  while(fp.read((char*)&ld,sizeof(ledger)))
   {
    cout<<ld.date<<"  "<<ld.cname<<"\t   "<<ld.vtype<<"\t   "<<ld.vno<<"\t       "<<ld.damt<<"\t  "<<ld.camt<<"\n";
    for(i=0;i<80;i++)
     cout<<"_";
    cout<<endl;
   }
  cout<<"Press any key to return to main menu";
  getch();
  fp.close();
  menu();
 }
void search()
 {
  clrscr();
  searchmenu();
 }
void delet()
 {
  clrscr();
  fstream fp1;
  int dvno,found=0,nor=0;
  char ch='n';
  do
   {
    clrscr();
    found=0;
    nor=0;
    fp.open("ledger.pnb",ios::in|ios::binary);
    while(fp.read((char*)&ld,sizeof(ledger)))
     {
      nor++;
     }
    fp.close();
    a:
    fp.open("ledger.pnb",ios::in|ios::binary);
    fp1.open("temp.pnb",ios::out|ios::binary);
    if(nor>0)
     {
      cout<<"Enter the Voucher No. to be deleted";
      cin>>dvno;
      while(fp.read((char*)&ld,sizeof(ledger)))
       {
	if(ld.vno==dvno)
	 {
	  found=1;
	 }
       }
      if(found==0)
       {
	cout<<"Record not found please try again\n";
	fp.close();
	goto a;
       }
      else if(found==1)
       {
	fp.close();
	fp.open("ledger.pnb",ios::in|ios::binary);
	while(fp.read((char*)&ld,sizeof(ledger)))
	 {
	  if(ld.vno!=dvno)
	   {
	    fp1.write((char*)&ld,sizeof(ledger));
	   }
	 }
	cout<<"Record deleted succesfully";
	fp.close();
	fp1.close();
	remove("ledger.pnb");
	rename("temp.pnb","ledger.pnb");
	cout<<"\nDo you want to delete nore record(Y/N) ";
	cin>>ch;
       }
     }
    if(nor==0)
     {
      cout<<"There is no record which can be deleted\n";
      cout<<"Press any key to return to main menu";
      getch();
      fp.close();
      menu();
     }
   }while((ch=='y') || (ch=='Y'));
  if(ch=='n')
   {
    fp.close();
    menu();
   }
 }
void backup()
 {
  clrscr();
  char bpath[30];
  int i;
  fstream fp1;
  fp.open("ledger.pnb",ios::in|ios::binary);
  cout<<"Enter the path & file name for your Backup File(for ex. d:\\backup)";
  gets(bpath);
  i=strlen(bpath);
  bpath[i]='.';
  bpath[i+1]='p';
  bpath[i+2]='n';
  bpath[i+3]='b';
  bpath[i+4]='\0';
  fp1.open(bpath,ios::out|ios::binary);
  while(fp.read((char*)&ld,sizeof(ledger)))
   {
    fp1.write((char*)&ld,sizeof(ledger));
   }
  cout<<"\n\nBack File created succesfully";
  cout<<"\nPress any key to return to Main Menu";
  getch();
  fp.close();
  fp1.close();
  menu();
 }
void searchmenu()
 {
  clrscr();
  int choice;
  gotoxy(40,5);
  cout<<"SEARCH MENU";
  gotoxy(34,8);
  cout<<"1. Search using Date";
  gotoxy(34,10);
  cout<<"2. Search using Customer Name";
  gotoxy(34,12);
  cout<<"3. Search using Voucher Type";
  gotoxy(34,14);
  cout<<"4. Search using Voucher No.";
  gotoxy(34,16);
  cout<<"5. Return to Main Menu";
  cin>>choice;
  if(choice==1)
   {
    dsearch();
   }
  if(choice==2)
   {
    cnamesearch();
   }
  if(choice==3)
   {
    vtypesearch();
   }
  if(choice==4)
   {
    vnosearch();
   }
  if(choice==5)
   {
    menu();
   }
 }
void dsearch()
 {
  clrscr();
  int found=0,i;
  char sdate[12];
  fp.open("ledger.pnb",ios::in|ios::binary);
  cout<<"Enter the Date to be searched";
  gets(sdate);
  cout<<"Date\t     Customer Name\tvoucher type   voucher no.\tDr.\tCr.\n";
  for(i=0;i<80;i++)
   cout<<"_";
  cout<<endl;
  while(fp.read((char*)&ld,sizeof(ledger)))
   {
    if(strcmp(ld.date,sdate)==0)
     {
      cout<<ld.date<<"  "<<ld.cname<<"\t   "<<ld.vtype<<"\t   "<<ld.vno<<"\t       "<<ld.damt<<"\t  "<<ld.camt<<"\n";
      for(i=0;i<80;i++)
       cout<<"_";
      cout<<endl;
      found=1;
     }
   }
   if(found==0)
    {
     cout<<"Data does'nt exist please check entered date and try again";
     getch();
     fp.close();
     searchmenu();
    }
   cout<<"Press any key to return to search menu";
   getch();
   fp.close();
   searchmenu();
 }
void cnamesearch()
 {
  clrscr();
  int found=0,i;
  char cname[25];
  fp.open("ledger.pnb",ios::in|ios::binary);
  cout<<"Enter the Customer Name to be searched";
  gets(cname);
  for(i=0;i<strlen(cname);i++)
   {
    cname[i]=toupper(cname[i]);
   }
  cout<<"Date\t     Customer Name\tvoucher type   voucher no.\tDr.\tCr.\n";
  for(i=0;i<80;i++)
   cout<<"_";
  cout<<endl;
  while(fp.read((char*)&ld,sizeof(ledger)))
   {
    if(strcmp(ld.cname,cname)==0)
     {
      cout<<ld.date<<"  "<<ld.cname<<"\t   "<<ld.vtype<<"\t   "<<ld.vno<<"\t       "<<ld.damt<<"\t  "<<ld.camt<<"\n";
      for(i=0;i<80;i++)
       cout<<"_";
      cout<<endl;
      found=1;
     }
   }
   if(found==0)
    {
     cout<<"Data does'nt exist please check entered date and try again";
     getch();
     fp.close();
     searchmenu();
    }
   cout<<"Press any key to return to search menu";
   getch();
   fp.close();
   searchmenu();
 }
void vtypesearch()
 {
  clrscr();
  int found=0,i;
  char vtype[10];
  fp.open("ledger.pnb",ios::in|ios::binary);
  cout<<"Enter the Customer Name to be searched";
  gets(vtype);
  for(i=0;i<strlen(vtype);i++)
   {
    vtype[i]=toupper(vtype[i]);
   }
  cout<<"Date\t     Customer Name\tvoucher type   voucher no.\tDr.\tCr.\n";
  for(i=0;i<80;i++)
   cout<<"_";
  cout<<endl;
  while(fp.read((char*)&ld,sizeof(ledger)))
   {
    if(strcmp(ld.vtype,vtype)==0)
     {
      cout<<ld.date<<"  "<<ld.cname<<"\t   "<<ld.vtype<<"\t   "<<ld.vno<<"\t       "<<ld.damt<<"\t  "<<ld.camt<<"\n";
      for(i=0;i<80;i++)
       cout<<"_";
      cout<<endl;
      found=1;
     }
   }
   if(found==0)
    {
     cout<<"Data does'nt exist please check entered date and try again";
     getch();
     fp.close();
     searchmenu();
    }
   cout<<"Press any key to return to search menu";
   getch();
   fp.close();
   searchmenu();
 }
void vnosearch()
 {
  clrscr();
  int svno,found=0,i;
  fp.open("ledger.pnb",ios::in|ios::binary);
  cout<<"Enter the Voucher No. to be searched";
  cin>>svno;
  cout<<"Date\t     Customer Name\tvoucher type   voucher no.\tDr.\tCr.\n";
  for(i=0;i<80;i++)
   cout<<"_";
  cout<<endl;
  while(fp.read((char*)&ld,sizeof(ledger)))
   {
    if(ld.vno==svno)
     {
      cout<<ld.date<<"  "<<ld.cname<<"\t   "<<ld.vtype<<"\t   "<<ld.vno<<"\t       "<<ld.damt<<"\t  "<<ld.camt<<"\n";
      for(i=0;i<80;i++)
       cout<<"_";
      cout<<endl;
      found=1;
     }
   }
   if(found==0)
    {
     cout<<"Data does'nt exist please check vno. and try again";
     getch();
     fp.close();
     searchmenu();
    }
   cout<<"Press any key to return to search menu";
   getch();
   fp.close();
   searchmenu();
  }
