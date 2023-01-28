#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<bios.h>
#include<dos.h>
#define U 18432
#define B 12386
#define D 20480
#define R 19712
#define L 19200
#define E 7181
#define ESC 283
int something=0;
int save();
int month(int,int,int);
void credit();
void frontpage();
void mainmenu();
void about();
void membersubmenu();
void issuesubmenu();
void issueissue();
void reportsubmenu();
void booksubmenu();
void showissue();
void notreturned();
void searchmemid();
void searchmemname();
void searchphone();
void searchbookid();
void searchbookname();
void searchauthor();
void searchpublisher();
void bkidcheck(char[]);
void memidcheck(char[]);
void bookdikha();
void memberdikha();
void border();
void border1();
void notfound();
void inserti();
void insertp();
void insertm();
void insertb();
void report1();
void report2();
void report3();
void main()
	{
	frontpage();
	}
class book
	{
	char author[10];
	char pub[10];
	int edition;
	float price;
	char bkid[5];
	char bkname[20];
	int bal;
	int stock;
	public :
	void inbk();
	void outbk(int a)
		{
		textcolor(7);
		gotoxy(3,6+a); cout<<bkid;
		gotoxy(11,6+a);cout<<bkname;
		gotoxy(22,6+a);cout<<author;
		gotoxy(33,6+a);cout<<pub;
		gotoxy(46,6+a);cout<<stock;
		gotoxy(53,6+a);cout<<edition;
		gotoxy(63,6+a);cout<<price;
		gotoxy(71,6+a);cout<<bal;
		}
	int getbal()
		{return(bal+1-1);}
	int getstock()
		{return(stock);}
	void changebal(int a)
		{bal=bal+a;}
	void changestock(int a)
		{stock=stock+a;}
	char* getbkid()
		{return bkid;}
	char* getbkname()
		{return bkname;}
	char* getauthor()
		{return author;}
	char* getpub()
		{return pub;}
	};
void book::inbk()
	{
	int r=7;border();
	textcolor(6);
	gotoxy(19,r);cprintf("Enter Data");r+=2;
	textcolor(7);
	gotoxy(19,r);cprintf("Enter Book ID :");gets(bkid);r++;
	bkidcheck(bkid);
	gotoxy(19,r);cprintf("Enter Book Name :");gets(bkname);r++;
	gotoxy(19,r);cprintf("Enter Author :");gets(author);r++;
	gotoxy(19,r);cprintf("Enter Publisher :");gets(pub);r++;
	gotoxy(19,r);cprintf("Enter Stock :");cin>>stock;r++;
	gotoxy(19,r);cprintf("Enter Edition :");cin>>edition;r++;
	gotoxy(19,r);cprintf("Enter Price :");cin>>price;r++;
	bal=stock;
	}
void bkidcheck(char bookid[5])
	{
	fstream i;book c;int flag=1;
	i.open("BOOK.DAT",ios::in|ios::binary);
	while(i.read((char *)&c,sizeof(c)))
		{
		if(strcmpi(c.getbkid(),bookid)==0)
			{
			flag=0;
			break;
			}
		}
	i.close();
	if(flag==0)
			{
			textcolor(4);
			gotoxy(19,11);cprintf("BookID already in use");
			gotoxy(43,20);cprintf("Press Escape to go back");
			gotoxy(43,21);cprintf("Or any other key to Re-Insert");

			int p=bioskey(0);
			if(p==ESC)
				mainmenu();
			else
				insertb();
			}
	else
		return;
	}
class members
	{
	char memid[5];
	char mname[20];
	char add[40];
	char phn[12];
	public :
	void inmem()
		{
		clrscr();border();
		int r=7;textcolor(6);
		gotoxy(19,r);cprintf("Enter Data :");r+=2;
		textcolor(7);
		gotoxy(19,r);cprintf("Enter Member ID : ");gets(memid);r++;r=r+1-1;
		memidcheck(memid);
		gotoxy(19,r);cprintf("Enter Member Name : ");gets(mname);r++;
		gotoxy(19,r);cprintf("Enter Member Address: ");gets(add);r++;
		gotoxy(19,r);cprintf("Enter Member Phone No. : ");cin>>phn;r++;
		}
	void outmem(int a)
		{
		textcolor(7);
		gotoxy(3,6+a); cout<<memid;
		gotoxy(13,6+a);cout<<mname;
		gotoxy(30,6+a);cout<<add;
		gotoxy(60,6+a);cout<<phn;
		}
	char* getmemid()
		{return memid;}
	char* getmname()
		{return mname;}
	char* getphn()
		{return phn;}
	};
void memidcheck(char memberid[5])
	{
	ifstream i;members c;int flag=1;
	i.open("MEMBERS.DAT",ios::in|ios::binary);
	while(i.read((char *)&c,sizeof(c)))
		{
		if(strcmpi(c.getmemid(),memberid)==0)
			{
			flag=0;
			break;
			}
		}
	i.close();
	if(flag==0)
			{
			textcolor(4);
			gotoxy(19,11);cprintf("MemberID already in use");
			gotoxy(43,20);cprintf("Press Escape to go back");
			gotoxy(43,21);cprintf("Or any other key to Re-Insert");

			int p=bioskey(0);
			if(p==ESC)
				mainmenu();
			else
				insertm();
			}
	else
		return;
	}

struct dop
	{int dd,mm,yy;};
class purchase
	{
	int qty;
	float price;
	char vendor[10],idbook[5],namebook[25];
	dop d;
	public:
	void inpur();
	void outpur(int a)
		{
		textcolor(7);
		gotoxy(3,5+a);cout<<idbook;
		gotoxy(13,5+a);cout<<namebook;
		gotoxy(28,5+a);cout<<qty;
		gotoxy(40,5+a);cout<<price;
		gotoxy(50,5+a);cout<<vendor;
		gotoxy(60,5+a);cout<<d.dd<<"/"<<d.mm<<"/"<<d.yy;
		}
	dop getdop()
		{return d;}
	};
void purchase::inpur()
		{
		border();
		int r=7;
		textcolor(6);
		gotoxy(19,r);cprintf("Enter Data ");r+=2;
		textcolor(7);
		gotoxy(19,r);cprintf("Enter BookID :");gets(idbook);r++;
		fstream file;book b;int use=0,c=0;
		file.open("BOOK.DAT",ios::in|ios::binary|ios::out);
		while(!file.eof())
			{
			use=file.tellg();
			file.read((char *)&b,sizeof(b));
				if(strcmpi(b.getbkid(),idbook)==0)
					{
					gotoxy(19,r);
					cprintf("Enter Bookname :");
					cout<<b.getbkname();
					strcpy(namebook,b.getbkname());
					r++;c++;break;
					}
			}
			if(c==0)
				{
				gotoxy(19,r);
				textcolor(4);cprintf("Invalid Book ID");
				gotoxy(43,20);textcolor(4);
				cprintf("Press Escape to go back");
				gotoxy(43,21);
				cprintf("Or any other key to Re-Insert");
				int p=bioskey(0);
				if(p==ESC)
					mainmenu();
				else
					insertp();
				}
		while(1)
			{
			textcolor(7);
			gotoxy(19,r);cprintf("Enter Quantity :");cin>>qty;
			if(qty<=0)
				{
				gotoxy(19,r+1);textcolor(4);
				cprintf("Quantity cannot be = 0 or negative");
				getch();
				gotoxy(19,r+1);cprintf("                                  ");
				gotoxy(19,r);cprintf("                     ");
				}
			else
				{
				r++;
				break;
				}
			}
		while(1)
			{
			gotoxy(19,r);textcolor(7);
			cprintf("Enter Price :");cin>>price;
			if(price<0)
				{
				gotoxy(19,r+1);textcolor(4);
				cprintf("Price cannot be negative");
				getch();
				gotoxy(19,r+1);cprintf("                           ");
				gotoxy(19,r);cprintf("                     ");
				}
			else
				{
				r++;
				break;
				}
			}
		gotoxy(19,r);cprintf("Enter Vendor :");gets(vendor);r++;
		while(1)
			{
			int flag=0;
			textcolor(7);
			gotoxy(19,r);cprintf("Enter Date of Purchase (dd/m(m)/yyyy) : ");
			gotoxy(59,r);cin>>d.dd;gotoxy(61,r);cout<<"/";
			gotoxy(62,r);cin>>d.mm;gotoxy(64,r);cout<<"/";
			gotoxy(65,r);cin>>d.yy;
			if(d.yy<1000)
				flag+=1;
			if(month(d.dd,d.mm,d.yy)==-1)
				flag+=2;
			if(flag==0)
				break;
			else if(flag==1)
				{
				gotoxy(40,20);textcolor(4);
				cprintf("Enter the date in dd/m(m)/yyyy format");
				getch();
				gotoxy(40,20);
				cprintf("                                     ");
				gotoxy(19,r);
				cprintf("                                                       ");
				}
			else if(flag==2)
				{
				getch();
				gotoxy(40,19);
				cprintf("                        ");
				gotoxy(19,r);
				cprintf("                                                       ");
				}
			else
				{
				gotoxy(40,20);
				cprintf("Enter the date in dd/m(m)/yyyy format");
				getch();
				gotoxy(40,19);
				cprintf("                        ");
				gotoxy(40,20);
				cprintf("                                     ");
				gotoxy(19,r);
				cprintf("                                                       ");
				}
			}
		b.changestock(qty);
		b.changebal(qty);
		if(save()==1)
			{
			file.seekp(use);
			file.write((char *)&b,sizeof(b));
			file.close();
			something=1;
			}
		}
struct doi
	{int dd,mm,yy;};
struct dor
	{int dd,mm,yy;};
class issue
	{
	char bookid[5],bookname[20],memberid[5],membername[30];
	int is,q;
	doi i;dor e;
	public :
	dor getdor()
		{return e;}
	doi getdoi()
		{return i;}
	int getmonth()
		{return i.mm;}
	int getyear()
		{return i.yy;}
	int getissue()
		{return is;}
	int getquantity()
		{return q;}
	char *getbookid()
		{return bookid;}
	void changereturn(dor r)
		{
		e.dd=r.dd;
		e.mm=r.mm;
		e.yy=r.yy;
		}
	void inis(int);
	void outis(int a)
		{
		textcolor(7);
		gotoxy(4,4+a); cout<<is;
		gotoxy(10,4+a);cout<<bookid;
		gotoxy(17,4+a);cout<<memberid;
		gotoxy(26,4+a);cout<<membername;
		gotoxy(51,4+a);cout<<i.dd<<"/"<<i.mm<<"/"<<i.yy;
		gotoxy(63,4+a);cout<<e.dd<<"/"<<e.mm<<"/"<<e.yy;
		gotoxy(76,4+a);cout<<q;
		}
	};
void issue::inis(int j)
		{
		int r=7,use=0;
		is=j+1;
		textcolor(6);
		gotoxy(19,r);cprintf("Enter Data :");r+=2;
		textcolor(7);
		gotoxy(19,r);cprintf("Issue ID :");cout<<is;r++;
		gotoxy(19,r);cprintf("Enter BookID : ");gets(bookid);r++;

			fstream file;int c=0;book b;
			file.open("BOOK.DAT",ios::out|ios::in|ios::binary);
			while(file.read((char *)&b,sizeof(b)))
				{
				use++;
				if(strcmpi(b.getbkid(),bookid)==0)
					{
					gotoxy(19,r);
					cprintf("Enter Bookname :");
					cout<<b.getbkname();
					strcpy(bookname,b.getbkname());
					c++;r++;
					break;
					}
				}
			if(c==0)
				{
				gotoxy(19,r);
				textcolor(4);cprintf("Invalid Book ID");
				gotoxy(43,20);textcolor(4);
				cprintf("Press Escape to go back");
				gotoxy(43,21);
				cprintf("Or any other key to Re-Insert");
				int p=bioskey(0);
				if(p==ESC)
					mainmenu();
				else
					inserti();
				}
			gotoxy(19,r);cprintf("Enter MemberID : ");gets(memberid);r++;
			ifstream f;c=0;members p;
			f.open("MEMBERS.DAT",ios::in|ios::binary);
			while(f.read((char *)&p,sizeof(p)))
				if(strcmpi(p.getmemid(),memberid)==0)
					{
					gotoxy(19,r);
					cprintf("Enter Members Name :");
					cout<<p.getmname();
					strcpy(membername,p.getmname());
					c++;r++;break;
					}
			f.close();
			if(c==0)
				{
				gotoxy(19,r);
				textcolor(4);cprintf("Invalid Member ID");
				gotoxy(43,20);textcolor(4);
				cprintf("Press Escape to go back");
				gotoxy(43,21);
				cprintf("Or any other key to Re-Insert");
				int p=bioskey(0);
				if(p==ESC)
					mainmenu();
				else
					insertp();
				}
		while(1)
			{
			int flag=0;textcolor(7);
			gotoxy(19,r);cprintf("Enter Quantity :");cin>>q;
			if(q<=0)
				{
				gotoxy(19,r+1);textcolor(4);
				cprintf("Quantity cannot be = 0 or negative");
				flag++;
				gotoxy(43,20);textcolor(4);
				cprintf("Press Escape to go to Main Menu");
				gotoxy(43,21);
				cprintf("Or any other key to Re-Insert");
				int p=bioskey(0);
				if(p==ESC)
					mainmenu();
				}
			if(b.getbal()-q<0)
				{
				textcolor(RED);
				gotoxy(19,r+2);cprintf("Not Available");
				gotoxy(19,r+3);cprintf("Quantity Available is : ");
				textcolor(7);
				cout<<b.getbal();
				flag+=2;
				gotoxy(43,20);textcolor(4);
				cprintf("Press Escape to go to Main Menu");
				gotoxy(43,21);
				cprintf("Or any other key to Re-Insert");
				int p=bioskey(0);
				if(p==ESC)
					mainmenu();
				}
			if(flag==1)
				{
				gotoxy(43,20);
				cprintf("                                ");
				gotoxy(43,21);
				cprintf("                             ");
				gotoxy(19,r+1);
				cprintf("                                   ");
				gotoxy(19,r);cprintf("                           ");
				}
			else
			if(flag==2)
				{
				gotoxy(43,20);
				cprintf("                               ");
				gotoxy(43,21);
				cprintf("                             ");
				gotoxy(19,r+2);cprintf("             ");
				gotoxy(19,r+3);cprintf("                            ");
				gotoxy(19,r);cprintf("                      ");
				}
			else
			if(flag==3)
				{
				gotoxy(43,20);
				cprintf("                               ");
				gotoxy(43,21);
				cprintf("                             ");
				gotoxy(19,r+1);
				cprintf("                                     ");
				gotoxy(19,r);cprintf("                     ");
				gotoxy(19,r+2);cprintf("             ");
				gotoxy(19,r+3);cprintf("                            ");
				}
			else
				{
				r++;
				break;
				}
			}
		while(1)
			{
			int flag=0;
			textcolor(7);
			gotoxy(19,r);cprintf("Enter Date of Issue (dd/m(m)/yyyy) : ");
			gotoxy(56,r);cin>>i.dd;gotoxy(58,r);cout<<"/";
			gotoxy(59,r);cin>>i.mm;gotoxy(61,r);cout<<"/";
			gotoxy(62,r);cin>>i.yy;
			if(i.yy<1000)
				flag+=1;
			if(month(i.dd,i.mm,i.yy)==-1)
				flag+=2;
			if(flag==0)
				break;
			else if(flag==1)
				{
				gotoxy(40,20);textcolor(4);
				cprintf("Enter the date in dd/m(m)/yyyy format");
				getch();
				gotoxy(40,20);cprintf("                                     ");
				gotoxy(19,r);cprintf("                                                       ");
				}
			else if(flag==2)
				{
				getch();
				gotoxy(40,19);cprintf("                        ");
				gotoxy(19,r);cprintf("                                                       ");
				}
			else
				{
				gotoxy(40,20);
				cprintf("Enter the date in dd/m(m)/yyyy format");
				getch();
				gotoxy(40,19);cprintf("                        ");
				gotoxy(40,20);cprintf("                                     ");
				gotoxy(19,r);cprintf("                                                       ");
				}
			}
		e.dd=0;e.mm=0;e.yy=0;
		use-=1;
		b.changebal(q*(-1));
		if(save()==1)
			{
			file.seekp(use*(sizeof(b)),ios::beg);
			file.write((char *)&b,sizeof(b));
			something=1;
			}
		file.close();
		}

void inserti()
	{
	clrscr();
	border();
	issue i;int j=0;
	ifstream f;
	f.open("ISSUE.DAT",ios::in|ios::binary);
	while(f.read((char *)&i,sizeof(i)))
		j++;
	f.close();
	ofstream o;
	o.open("ISSUE.DAT",ios::app|ios::binary);
	i.inis(j);
	if(something==1)
		o.write((char *)&i,sizeof(i));
	o.close();
	something=0;
	getch();
	mainmenu();
	}
void insertb()
	{
	clrscr();
	border();
	book ob1;
	ob1.inbk();
	ofstream f;
	f.open("BOOK.DAT",ios::app|ios::binary);
	if(save()==1)
		f.write((char *)&ob1,sizeof(ob1));
	f.close();
	getch();
	mainmenu();
	}
void insertm()
	{
	members ob2;
	ob2.inmem();
	ofstream f;
	f.open("MEMBERS.DAT",ios::app|ios::binary);
	if(save()==1)
		f.write((char *)&ob2,sizeof(ob2));
	f.close();
	getch();
	mainmenu();
	}
void insertp()
	{
	clrscr();
	ofstream file;
	file.open("PURCHASE.DAT",ios::app|ios::binary);
	purchase ob3;
	ob3.inpur();
	if(something==1)
		file.write((char *)&ob3,sizeof(ob3));
	file.close();
	something=0;
	getch();
	mainmenu();
	}
void searchbookid()
	{
	clrscr();
	border1();

	ifstream file;
	file.open("BOOK.DAT",ios::in|ios::binary);
	book b;int c=0;
	char n[5];
	textcolor(6);
	gotoxy(3,2);cprintf("Enter Book ID to be searched for : ");cin>>n;
	bookdikha();
	int a=0;
	while(file.read((char *)&b,sizeof(b)))
	{
		if(strcmpi(b.getbkid(),n)==0)
		{
			b.outbk(a);
			c=0;break;
		}
		c++;
	}
	if(c!=0)
		notfound();
	file.close();
	getch();
	}
void searchbookname()
	{
	clrscr();
	border1();

	ifstream file;
	file.open("BOOK.DAT",ios::in|ios::binary);
	book b1;int c=0;char n[25];
	textcolor(6);
	gotoxy(3,2);cprintf("Enter Book Name to be searched for : ");cin>>n;
	bookdikha();
	while(file.read((char *)&b1,sizeof(b1)))
		if(strcmpi(b1.getbkname(),n)==0)
		{
			b1.outbk(c);
			c++;
		}
	if(c==0)
		notfound();
	file.close();
	getch();
	}
void searchauthor()
	{
	clrscr();
	border1();

	ifstream file;
	file.open("BOOK.DAT",ios::in|ios::binary);
	book b2;int c=0;char n[25];
	textcolor(6);
	gotoxy(3,2);cprintf("Enter Author Name to be searched for : ");cin>>n;
	bookdikha();
	while(file.read((char *)&b2,sizeof(b2)))
		if(strcmpi(b2.getauthor(),n)==0)
		{
			b2.outbk(c);
			c++;
		}
	if(c==0)
		notfound();
	file.close();
	getch();
	}
void searchpublisher()
	{
	clrscr();
	border1();
	ifstream file;
	file.open("BOOK.DAT",ios::in|ios::binary);
	book b3;int c=0;char n[25];
	textcolor(6);
	gotoxy(3,2);cprintf("Enter Publisher Name to be searched for : ");cin>>n;
	bookdikha();
	while(file.read((char *)&b3,sizeof(b3)))
		if(strcmpi(b3.getpub(),n)==0)
		{
			b3.outbk(c);
			c++;
		}
	if(c==0)
		notfound();
	file.close();
	getch();
	}
void searchmemid()
	{
	clrscr();
	border1();

	ifstream file;
	file.open("MEMBERS.DAT",ios::in|ios::binary);
	members m;int c=0;char n[5];
	textcolor(6);
	gotoxy(3,2);cprintf("Enter Member ID to be searched for : ");cin>>n;
	memberdikha();
	while(file.read((char *)&m,sizeof(m)))
		if(strcmpi(m.getmemid(),n)==0)
		{
			m.outmem(c);
			c++;
		}
	if(c==0)
		notfound();
	file.close();
	getch();
	}
void searchmemname()
	{
	clrscr();
	border1();

	ifstream file;
	file.open("MEMBERS.DAT",ios::in|ios::binary);
	members m1;int c=0;char n[25];textcolor(6);
	gotoxy(3,2);cprintf("Enter Member Name to be searched for : ");gets(n);
	memberdikha();
	while(file.read((char *)&m1,sizeof(m1)))
		if(strcmpi(m1.getmname(),n)==0)
		{
			m1.outmem(c);
			c++;
		}
	if(c==0)
		notfound();
	file.close();
	getch();

	}
void searchphone()
	{
	clrscr();
	border1();

	ifstream file;
	file.open("MEMBERS.DAT",ios::in|ios::binary);
	members m2;int c=0;char n[11];textcolor(6);
	gotoxy(3,2);cprintf("Enter Member's Phone Numbers : ");cin>>n;
	memberdikha();
	while(file.read((char *)&m2,sizeof(m2)))
		if(strcmpi(m2.getphn(),n)==0)
		{
			m2.outmem(c);
			c++;
		}
	if(c==0)
		notfound();
	file.close();
	getch();
	}
void report1()
	{
	clrscr();
	border1();
	ifstream file;
	file.open("BOOK.DAT",ios::in|ios::binary);
	book b4;
	int a=-2;
	textcolor(6);
	gotoxy(3,2); cprintf("BookID");
	gotoxy(11,2);cprintf("BookName");
	gotoxy(22,2);cprintf("Author");
	gotoxy(33,2);cprintf("Publisher");
	gotoxy(46,2);cprintf("Stock");
	gotoxy(53,2);cprintf("Edition");
	gotoxy(63,2);cprintf("Price");
	gotoxy(71,2);cprintf("Balance");

	while(file.read((char *)&b4,sizeof(b4)))
		if(b4.getstock()!=b4.getbal())
		{
			b4.outbk(a);
			a++;
		}
	file.close();
	if(a==-2)
		notfound();
	getch();
	}
void report3()
	{
	clrscr();
	ifstream file;
	file.open("PURCHASE.DAT",ios::in|ios::binary);
	purchase p;int c=0,r=2;dop i,i1;
	while(1)
		{
		int flag=0;
		border1();textcolor(6);
		gotoxy(3,r);cprintf("Enter the date (dd/m(m)/yyyy) : ");
		gotoxy(35,r);cin>>i.dd;gotoxy(37,r);cout<<"/";
		gotoxy(38,r);cin>>i.mm;gotoxy(40,r);cout<<"/";
		gotoxy(41,r);cin>>i.yy;
		if(i.yy<1000)
			flag+=1;
		if(month(i.dd,i.mm,i.yy)==-1)
			flag+=2;
		if(flag==0)
			break;
		else if(flag==1)
			{
			gotoxy(40,20);textcolor(4);
			cprintf("Enter the date in dd/m(m)/yyyy format");
			getch();
			gotoxy(40,20);cprintf("                                     ");
			gotoxy(19,r);
			cprintf("                                                       ");
			}
		else if(flag==2)
			{
			getch();
			gotoxy(40,19);cprintf("                        ");
			gotoxy(19,r);
			cprintf("                                                       ");
			}
		else
			{
			gotoxy(40,20);
			cprintf("Enter the date in dd/m(m)/yyyy format");
			getch();
			gotoxy(40,19);cprintf("                        ");
			gotoxy(40,20);cprintf("                                     ");
			gotoxy(19,r);
			cprintf("                                                       ");
			}
	}

	gotoxy(3,4); cprintf("BookID");
	gotoxy(13,4);cprintf("Bookname");
	gotoxy(28,4);cprintf("Quantity");
	gotoxy(40,4);cprintf("Price");
	gotoxy(50,4);cprintf("Vendor");
	gotoxy(60,4);cprintf("D.O.P.");

	while(file.read((char *)&p,sizeof(p)))
		{
		i1=p.getdop();
		if(i1.yy==i.yy)
			if(i1.mm==i.mm)
				if(i1.dd==i.dd)
					{
					p.outpur(c);
					c++;
					}
		}
	if(c==0)
		notfound();
	getch();
	file.close();
	}
void report2()
	{
	clrscr();
	border1();
	struct date d;
	getdate(&d);
	int year=d.da_year;
	int month=d.da_mon;
	ifstream a,b;
	a.open("ISSUE.DAT",ios::in|ios::binary);
	b.open("BOOK.DAT",ios::in|ios::binary);
	issue i;book j;int c=0,k=-2;textcolor(6);
	gotoxy(3,2); cprintf("BookID");
	gotoxy(11,2);cprintf("BookName");
	gotoxy(22,2);cprintf("Author");
	gotoxy(33,2);cprintf("Publisher");
	gotoxy(46,2);cprintf("Stock");
	gotoxy(53,2);cprintf("Edition");
	gotoxy(63,2);cprintf("Price");
	gotoxy(71,2);cprintf("Balance");
	while(b.read((char *)&j,sizeof(j)))
		{
		c=0;
		a.seekg(0);
		while(a.read((char *)&i,sizeof(i)))
			if(strcmpi(j.getbkid(),i.getbookid())==0)
				if(i.getyear()==year||i.getyear()==year%100)
					if(i.getmonth()==month||i.getmonth()==month-1)
						c++;
		if(c>=10)
			{
			j.outbk(k);
			k++;
			}
		}
	gotoxy(2,4);
	if(k==-2)
		notfound();
	getch();
	}
void showissue()
	{
	clrscr();
	border1();
	issue i;
	ifstream f;
	f.open("ISSUE.DAT",ios::in|ios::binary);
	textcolor(6);
	gotoxy(2,2); cprintf("IssueID");
	gotoxy(10,2); cprintf("BookID");
	gotoxy(17,2);cprintf("MemberID");
	gotoxy(26,2);cprintf("Membername");
	gotoxy(51,2);cprintf("D.O.I.");
	gotoxy(63,2);cprintf("D.O.R.");
	gotoxy(75,2);cprintf("Qty");
	int a=0;textcolor(7);textcolor(7);
	while(f.read((char *)&i,sizeof(i)))
		{
		i.outis(a);
		a++;
		}
	if(a==0)
		notfound();
	f.close();
	getch();
	}
void notreturned()
	{
	clrscr();
	border1();
	issue i;
	ifstream f;
	f.open("ISSUE.DAT",ios::in|ios::binary);
	textcolor(6);
	gotoxy(2,2); cprintf("IssueID");
	gotoxy(10,2); cprintf("BookID");
	gotoxy(17,2);cprintf("MemberID");
	gotoxy(26,2);cprintf("Membername");
	gotoxy(51,2);cprintf("D.O.I.");
	gotoxy(63,2);cprintf("D.O.R.");
	gotoxy(75,2);cprintf("Qty");
	int a=0;textcolor(7);textcolor(7);

	while(f.read((char *)&i,sizeof(i)))
		{
		dor iss=i.getdor();
		if(iss.dd==0)
			{
			i.outis(a);
			a++;
			}
		}
	if(a==0)
		notfound();
	f.close();
	getch();
	}
void issueissue()
	{
	clrscr();
	border1();int c=0,n;
	gotoxy(3,2);cprintf("Enter IssueID : ");cin>>n;
	fstream f;
	f.open("ISSUE.DAT",ios::in|ios::binary|ios::out);
	issue z;doi i;
			dor r,r1;
	long pos=0;
	while(!f.eof())
		{
		pos=f.tellg();
		f.read((char *)&z,sizeof(z));
		if(z.getissue()==n)
			{
			r=z.getdor();
			i=z.getdoi();
			if(r.dd==0)
				{
				c++;
				textcolor(4);gotoxy(3,5);
				cprintf("Book has not been returned");
				gotoxy(43,20);textcolor(4);
				cprintf("Press Escape to go back");
				gotoxy(43,21);
				cprintf("Or any other key to Continue");
				int p=bioskey(0);
				if(p==ESC)
					mainmenu();
				gotoxy(43,20);cprintf("                           ");
				gotoxy(43,21);cprintf("                            ");
				gotoxy(3,5);cprintf("                          ");
				while(1)
					{
					int flag=0;
					textcolor(7);gotoxy(3,3);
					cprintf("Enter date of return (dd/m(m)/yyyy) : ");
					gotoxy(40,3);cin>>r1.dd;gotoxy(42,3);cout<<"/";
					gotoxy(43,3);cin>>r1.mm;gotoxy(45,3);cout<<"/";
					gotoxy(46,3);cin>>r1.yy;
					if(r1.yy==i.yy && r1.mm==i.mm && r1.dd<i.dd)
						flag+=1;
					else if(r1.yy==i.yy && r1.mm<i.mm)
						flag+=1;
					else if(r1.yy<i.yy)
						flag+=1;
					if(r1.yy<1000)
						flag+=2;
					if(month(r1.dd,r1.mm,r1.yy)==-1)
						flag+=4;

					if(flag==0)
						break;
					else if(flag==1 || flag==1+4)
						{
						textcolor(4);gotoxy(3,6);
						cprintf("Date of return cannot be less than Date of issue");
						gotoxy(40,20);cprintf("Press Escape to go back");
						gotoxy(40,21);cprintf("Or any other key to Continue");
						}
					else if(flag==2 || flag==2+4)
						{
						gotoxy(40,18);textcolor(4);
						cprintf("Enter the date in dd/m(m)/yyyy format");
						gotoxy(40,20);cprintf("Press Escape to go back");
						gotoxy(40,21);cprintf("Or any other key to Continue");
						}
					else if(flag==1+2)
						{
						gotoxy(40,18);textcolor(4);
						cprintf("Enter the date in dd/m(m)/yyyy format");
						gotoxy(3,6);
						cprintf("Date of return cannot be less than Date of issue");
						gotoxy(40,20);cprintf("Press Escape to go back");
						gotoxy(40,21);cprintf("Or any other key to Continue");
						}
					else if(flag==4)
						{
						gotoxy(40,20);cprintf("Press Escape to go back");
						gotoxy(40,21);cprintf("Or any other key to Continue");
						}
					else if(flag==7)
						{
						gotoxy(3,6);
						cprintf("Date of return cannot be less than Date of issue");
						gotoxy(40,18);
						cprintf("Enter the date in dd/m(m)/yyyy format");
						gotoxy(40,20);
						cprintf("Press Escape to go back");
						gotoxy(40,21);
						cprintf("Or any other key to Continue");
						}
					int p=bioskey(0);
					if(p==ESC)
						mainmenu();
					gotoxy(3,6);cprintf("                                                     ");
					gotoxy(40,18);cprintf("                                     ");
					gotoxy(40,19);cprintf("                        ");
					gotoxy(40,20);cprintf("                           ");
					gotoxy(40,21);cprintf("                            ");
					gotoxy(3,5);cprintf("                                      ");
					if(flag>0)
						{
						gotoxy(38,3);cprintf("                ");
						}
					}
				if(r1.yy==i.yy)
					{
					int is=i.mm,year=i.yy%100,fine=0;
					int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
					if(i.mm==r1.mm)
						fine=r1.dd-i.dd;
					else
						{
						fine=r1.dd+(mon[is-1]-i.dd);
						while(is+1<=r1.mm-1)
							{
							fine+=mon[is];
							is++;
							}
						}
					if((year%4==0)&&(i.mm<=2 && 2<=r1.mm))
						if(!(i.mm==r1.mm))
							fine++;
					fine-=5;
					gotoxy(3,7);
					if(fine>0)
						cout<<"Fine is : "<<(fine)*5;
					else
						cout<<"No Fine";
					}
				else if(r1.yy>i.yy)
					{
					int year=i.yy,year1,fine=0,is=i.mm,re=r1.mm-1;
					int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
					while(year<r1.yy)
						{
						year1=year%100;
						if(year==i.yy && year1%4==0)
							{
							if(i.mm<=2)
								fine++;
							}
						else if(year1%4==0)
							fine++;
						year++;
						}
					fine+=((r1.yy-i.yy-1)*365);
					fine+=r1.dd+(mon[i.mm-1]-i.dd);
					while(is+1<=12)
						{
						fine+=mon[is];
						is++;
						}
					while(re>=1)
						{
						re--;
						fine+=mon[re];
						}
					fine-=5;
					gotoxy(3,7);
					cout<<"Fine is : "<<(fine)*5;
					}
				z.changereturn(r1);
				f.seekg(pos);
				f.write((char*)&z,sizeof(z));
				f.close();
				c++;

				fstream in;int us=0;book b;
				in.open("BOOK.DAT",ios::in|ios::binary|ios::out);
				while(!in.eof())
					{
					us=in.tellg();
					in.read((char*)&b,sizeof(b));
					if(strcmpi(b.getbkid(),z.getbookid())==0)
						{
						b.changebal(z.getquantity());
						break;
						}
					}
					in.seekp(us);
					in.write((char *)&b,sizeof(b));
					in.close();

				getch();
				mainmenu();
				}
			else
				{
				c++;
				gotoxy(3,5);
				cout<<"--Book already returned!!--";
				f.close();
				getch();
				mainmenu();
				}
			}
		}
	if(c==0)
		{
		gotoxy(3,5);
		cout<<"--No such Issue ID exists!!--";
		f.close();
		getch();
		mainmenu();
		}
	f.close();
	getch();
	}

void mainmenu()
	{
	clrscr();
	border();
	char o[9][40]={"Add a Book","Add a Member","Issue a Book","Add a Purchase","Search by Book","Search by Member","All Issue","Return a book","Report"};
	for(int i=0;i<9;i++)
		{
		gotoxy(19,7+i);textcolor(8);
		cprintf(o[i]);
		}
	gotoxy(19,5);textcolor(6);cprintf("MAIN MENU");
	gotoxy(19,7);textcolor(7);cprintf(o[0]);gotoxy(19,7);
	int c=19,r=7;
	int n;
	gotoxy(41,21);textcolor(4);
	cprintf("Press Escape to go back");
	gotoxy(19,7);
	do
		{
		n=bioskey(0);
		if(n==ESC)
			frontpage();
		if(n==D && r<15)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(o[r-7]);r++;
			textcolor(7);gotoxy(c,r);cprintf(o[r-7]);gotoxy(c,r);
			}
		if(n==U && r>7)
			{
			sound(1100);
			delay(50);
			textcolor(8);gotoxy(c,r);cprintf(o[r-7]);r--;
			textcolor(7);gotoxy(c,r);cprintf(o[r-7]);gotoxy(c,r);
			}
		nosound();
		}while(n!=E);

	if(r==7)
		{
		clrscr();
		border();
		insertb();
		}
	else if(r==8)
		{
		clrscr();
		border();
		insertm();
		}
	else if(r==9)
		{
		clrscr();
		border();
		inserti();
		}
	else if(r==10)
		{
		clrscr();
		border();
		insertp();
		}
	else if(r==11)
		{
		while(1)
		{
		booksubmenu();
		clrscr();
		border();
		gotoxy(19,5);textcolor(6);cprintf("MAIN MENU");
		char o[9][40]={"Add a Book","Add a Member","Issue a Book","Add a Purchase","Search by Book","Search by Member","All Issue","Return a book","Report"};
		for(int i=0;i<9;i++)
			{
			gotoxy(19,7+i);textcolor(8);
			cprintf(o[i]);
			}
		gotoxy(19,11);textcolor(7);
		cprintf(o[4]);
		}
		}
	else if(r==12)
		{
		while(1)
		{
		membersubmenu();
		clrscr();
		border();
		gotoxy(19,5);textcolor(6);cprintf("MAIN MENU");
		char o[9][40]={"Add a Book","Add a Member","Issue a Book","Add a Purchase","Search by Book","Search by Member","All Issue","Return a book","Report"};
		for(int i=0;i<9;i++)
			{
			gotoxy(19,7+i);textcolor(8);
			cprintf(o[i]);
			}
		gotoxy(19,12);textcolor(7);
		cprintf(o[5]);
		}
		}
	else if(r==13)
		{
		while(1){
		issuesubmenu();
		clrscr();
		border();
		gotoxy(19,5);textcolor(6);cprintf("MAIN MENU");
		char o[9][40]={"Add a Book","Add a Member","Issue a Book","Add a Purchase","Search by Book","Search by Member","All Issue","Return a book","Report"};
		for(int i=0;i<9;i++)
			{
			gotoxy(19,7+i);textcolor(8);
			cprintf(o[i]);
			}
		gotoxy(19,13);textcolor(7);
		cprintf(o[6]);
		}
		}
	else if(r==14)
		{
		while(1){
		issueissue();
		clrscr();
		border();
		gotoxy(19,5);textcolor(6);cprintf("MAIN MENU");
		char o[9][40]={"Add a Book","Add a Member","Issue a Book","Add a Purchase","Search by Book","Search by Member","All Issue","Return a book","Report"};
		for(int i=0;i<9;i++)
			{
			gotoxy(19,7+i);textcolor(8);
			cprintf(o[i]);
			}
		gotoxy(19,14);textcolor(7);
		cprintf(o[7]);
				}
		}
	else if(r==15)
		{
		while(1)
		{
		reportsubmenu();
		clrscr();
		border();
		gotoxy(19,5);textcolor(6);cprintf("MAIN MENU");
		char o[9][40]={"Add a Book","Add a Member","Issue a Book","Add a Purchase","Search by Book","Search by Member","All Issue","Return a book","Report"};
		for(int i=0;i<9;i++)
			{
			gotoxy(19,7+i);textcolor(8);
			cprintf(o[i]);
			}
		gotoxy(19,15);textcolor(7);
		cprintf(o[8]);
		}
		}
	}
void reportsubmenu()
	{
	int n,i,c=37,r=13;
	char m[3][40]={"Book issued but not returned","Frequently issued books","Books purchase on a particular day"};
	for(i=0;i<3;i++)
		{
		textcolor(8);
		gotoxy(37,13+i);
		cprintf(m[i]);
		}
	gotoxy(37,13);textcolor(7);
	cprintf(m[0]);gotoxy(37,13);
	gotoxy(41,21);textcolor(4);
	cprintf("Press Escape to go back");
	gotoxy(c,r);
	do
		{
		n=bioskey(0);
		if(n==ESC)
			{
			clrscr();
			mainmenu();
			}
		if(n==D && r<15)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(m[r-13]);r++;
			textcolor(7);gotoxy(c,r);cprintf(m[r-13]);gotoxy(c,r);
			}
		if(n==U && r>13)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(m[r-13]);r--;
			textcolor(7);gotoxy(c,r);cprintf(m[r-13]);gotoxy(c,r);
			}
		nosound();
		}while(n!=E);
	if(r==13)
		report1();
	else if(r==14)
		report2();
	else if(r==15)
		report3();
	}

void issuesubmenu()
	{
	int n,i,c=37,r=12;
	char m[2][26]={"Issued but not returned","Issue Details"};

	textcolor(8);
	for(i=0;i<=1;i++)
		{
		gotoxy(37,12+i);
		cprintf(m[i]);
		}
	gotoxy(37,12);textcolor(7);
	cprintf(m[0]);gotoxy(37,12);

	gotoxy(41,21);textcolor(4);
	cprintf("Press Escape to go back");
	gotoxy(c,r);
	do
		{
		n=bioskey(0);
		if(n==ESC)
			{
			clrscr();
			mainmenu();
			}
		if(n==D && r<13)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(m[r-12]);r++;
			textcolor(7);gotoxy(c,r);cprintf(m[r-12]);gotoxy(c,r);
			}
		if(n==U && r>12)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(m[r-12]);r--;
			textcolor(7);gotoxy(c,r);cprintf(m[r-12]);gotoxy(c,r);
			}
		nosound();
		}while(n!=E);

	if(r==12)
		notreturned();
	else if(r==13)
		showissue();
	}
void membersubmenu()
	{
	int n,i,c=37,r=11;
	char m[3][16]={"Member ID","Member Name","Phone"};
	for(i=0;i<3;i++)
		{
		textcolor(8);
		gotoxy(37,11+i);
		cprintf(m[i]);
		}
	gotoxy(37,11);textcolor(7);
	cprintf(m[0]);gotoxy(37,11);
	gotoxy(41,21);textcolor(4);
	cprintf("Press Escape to go back");
	gotoxy(c,r);
	do
		{
		n=bioskey(0);
		if(n==ESC)
			{
			clrscr();
			mainmenu();
			}
		if(n==D && r<13)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(m[r-11]);r++;
			textcolor(7);gotoxy(c,r);cprintf(m[r-11]);gotoxy(c,r);
			}
		if(n==U && r>11)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(m[r-11]);r--;
			textcolor(7);gotoxy(c,r);cprintf(m[r-11]);gotoxy(c,r);
			}
		nosound();
		}while(n!=E);
	if(r==11)
		searchmemid();
	if(r==12)
		searchmemname();
	if(r==13)
		searchphone();
	}
void booksubmenu()
	{
	int n,i,c=37,r=10;
	char s[4][10]={"Book ID","Book Name","Author","Publisher"};
	for(i=0;i<4;i++)
		{
		textcolor(8);
		gotoxy(37,10+i);
		cprintf(s[i]);
		}
	gotoxy(37,10);textcolor(7);
	cprintf(s[0]);gotoxy(37,10);

	gotoxy(41,21);textcolor(4);
	cprintf("Press Escape to go back");
	gotoxy(c,r);

	do
		{
		n=bioskey(0);
		if(n==ESC)
			{
			clrscr();
			mainmenu();
			}
		if(n==D && r<13)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(s[r-10]);r++;
			textcolor(7);gotoxy(c,r);cprintf(s[r-10]);gotoxy(c,r);
			}
		if(n==U && r>10)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(s[r-10]);r--;
			textcolor(7);gotoxy(c,r);cprintf(s[r-10]);gotoxy(c,r);
			}
		nosound();
		}while(n!=E);

	if(r==10)
		searchbookid();
	if(r==11)
		searchbookname();
	if(r==12)
		searchauthor();
	if(r==13)
		searchpublisher();
	}
void frontpage()
	{
	clrscr();
	border();
	textcolor(4);
	gotoxy(36,8);cprintf("LIBRARY");

	int c=36,r=10;
	char a[4][12]={"Main Menu","Information","Credits","Exit"};
	textcolor(7);
	gotoxy(c,r);cprintf(a[0]);r++;
	textcolor(8);
	gotoxy(c,r);cprintf(a[1]);r++;
	gotoxy(c,r);cprintf(a[2]);r++;
	gotoxy(c,r);cprintf(a[3]);
	gotoxy(c,r-=3);
	int n;
	do
		{
		n=bioskey(0);
		if(n==D && r<13)
			{
			sound(1100);
			delay(40);
			textcolor(8);gotoxy(c,r);cprintf(a[r-10]);r++;
			textcolor(7);gotoxy(c,r);cprintf(a[r-10]);gotoxy(c,r);
			}
		if(n==U && r>10)
			{
			sound(1100);
			delay(50);
			textcolor(8);gotoxy(36,r);cprintf(a[r-10]);r--;
			textcolor(7);gotoxy(36,r);cprintf(a[r-10]);gotoxy(c,r);
			}
		nosound();
		}while(n!=E);

	if(r==13)
		exit(0);
	else if(r==12)
		credit();
	else if(r==11)
		about();
	else if(r==10)
		mainmenu();
	}
void credit()
	{
	clrscr();
	char c[12][50]={"CREDITS :","~~~~~~~","","Members :","","* Shasank Periwal","* Fardeen Ali","","Special thanks to :","Sir Deepankar Bhuyan","","--F.S. DEVELOPERS--"};

	int r=17,i,j;textcolor(14);
	for(i=0;i<12;i++)
		{
		if(kbhit())
			{
			int p=getch();
			if(p==98)
				{
				frontpage();
				}
			}
		clrscr();
		border();
		gotoxy(41,21);textcolor(4);
		cprintf("Press Escape to go back");
		textcolor(7);

		for(j=0;j<=i;j++)
			{
			gotoxy(30,r+j);
			if(j==0||j==3||j==8||j==11)
				{
				textcolor(6);
				cprintf(c[j]);
				textcolor(7);
				}
			else
				cprintf(c[j]);
			gotoxy(30,r+j);
			}
		delay(300);
		r--;
		}
	gotoxy(41,21);textcolor(4);
	cprintf("Press Escape to go back");
	int p=bioskey(0);
	while(p!=ESC)
		{
		p=bioskey(0);
		}
	frontpage();
	}

void border1()
	{
	textcolor(8);
	for(int i=1;i<79;i++)
		{
		gotoxy(i,1);cprintf("Í");
		gotoxy(i,25);cprintf("Í");
		}
	for(int j=1;j<26;j++)
		{
		gotoxy(1,j);cprintf("º");
		gotoxy(79,j);cprintf("º");
		}
	gotoxy(79,25);cprintf("¼");
	gotoxy(1,25);cprintf("È");
	gotoxy(79,1);cprintf("»");
	gotoxy(1,1);cprintf("É");
	}
int save()
	{
	int n=0,c=32,r=19;
	gotoxy(30,18);textcolor(2);cprintf("Save the record?");
	gotoxy(41,19);textcolor(8);cprintf("No");
	gotoxy(32,19);textcolor(7);cprintf("Yes");gotoxy(c,r);
	do
		{
		n=bioskey(0);
		if(n==L && c>32)
			{
			textcolor(8);gotoxy(c,r);cprintf("No");c-=9;
			textcolor(7);gotoxy(c,r);cprintf("Yes");gotoxy(c,r);
			}
		if(n==R && c<41)
			{textcolor(8);gotoxy(c,r);cprintf("Yes");c+=9;
			textcolor(7);gotoxy(c,r);cprintf("No");gotoxy(c,r);
			}
		}while(n!=E);

	gotoxy(30,18);cprintf("                ");
	gotoxy(41,19);cprintf("  ");
	gotoxy(32,19);cprintf("   ");
	if(c==32)
		{
		gotoxy(19,17);textcolor(2);
		cprintf("--Record Successfully Saved--");
		return 1;
		}
	else
		{
		gotoxy(23,17);textcolor(4);
		cprintf("--Record Not Saved--");
		return 0;
		}
	}
int month(int date,int mon,int year)
	{
	int a[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	char b[12][14]={"January","February","March","April","May","June","July","August","September","October","November","December"};
	year%=100;
	if(year%4==0)
		date--;
	if(mon>12)
		{
		textcolor(RED);gotoxy(40,19);
		cprintf("Invalid Month");
		return(-1);
		}
	if(date>a[mon-1])
		{
		textcolor(RED);gotoxy(40,19);
		cout<<b[mon-1]<<" has "<<a[mon-1]<<" days";
		return(-1);
		}
	return 1;
	}
void border()
	{
	textcolor(4);
	gotoxy(1,1);cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	gotoxy(1,24);cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	textcolor(11);
	gotoxy(10,2);cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	gotoxy(10,23);cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	textcolor(14);
	gotoxy(19,3);cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	gotoxy(19,22);cprintf("ÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ");
	}
void bookdikha()
	{
	gotoxy(3,4); cprintf("BookID");
	gotoxy(11,4);cprintf("BookName");
	gotoxy(22,4);cprintf("Author");
	gotoxy(33,4);cprintf("Publisher");
	gotoxy(46,4);cprintf("Stock");
	gotoxy(53,4);cprintf("Edition");
	gotoxy(63,4);cprintf("Price");
	gotoxy(71,4);cprintf("Balance");
	}
void memberdikha()
	{
	gotoxy(3,4); cprintf("MemberID");
	gotoxy(13,4);cprintf("Member Name");
	gotoxy(30,4);cprintf("Member Address");
	gotoxy(60,4);cprintf("Phone No.");
	}
void notfound()
	{
	gotoxy(2,6);
	textcolor(RED);
	cprintf("-----------------------------NO RECORDS FOUND--------------------------------");
	}
void about()
	{
	clrscr();
	border1();
	int c=3;
	textcolor(7);
	gotoxy(c,3);cprintf("~~~~~~~~~~~~~~");
	textcolor(6);
	gotoxy(c,2);cprintf("INFROMATION : ");
	gotoxy(c,5);cprintf("BookID-");
	gotoxy(c,6+1);cprintf("MemberID-");
	gotoxy(c,7+2);cprintf("Date-");
	gotoxy(c,10+3);cprintf("Fine-");
	gotoxy(c,12+4);cprintf("Controls-");
	textcolor(7);
	gotoxy(c+8,5);cprintf("It should be an alphanumeric code of 4 characters.");
	gotoxy(c+10,6+1);cprintf("It should be an alphanumeric code of 4 characters.");
	gotoxy(c+6,7+2);cprintf("It should be entered in dd/m(m)/yyyy format.");
	gotoxy(c+6,8+2);cprintf("Users need to enter the date then press ENTER,month then press ENTER");
	gotoxy(c+6,9+2);cprintf("and year and again press ENTER.");
	gotoxy(c+6,10+3);cprintf("There's no fine as such for 7 days.");
	gotoxy(c+6,11+3);cprintf("Even the issue and return dates are included.");
	gotoxy(c+10,12+4);cprintf("The arrow keys are the control to hover over options.");
	gotoxy(c+10,13+4);cprintf("Pressing enter would result in the selection of particular option.");
	gotoxy(55,24);textcolor(4);
	cprintf("Press Escape to go back");
	int n=bioskey(0);
	while(!(n==ESC))
		n=bioskey(0);
	frontpage();
	}
