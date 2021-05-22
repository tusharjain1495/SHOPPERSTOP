//online shopping portal for clothing and footwear
#include<iostream>
#include<conio.h>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<map>
#include<bits/stdc++.h>
using namespace std;

//functions declaration
int mainmenu();
void placedCart();
void signin();
void signup();
void contact();
void shop();
void account();
void men();
void women();
void clothMen();
void footMen();
void clothWomen();
void footWomen();
void nondisclMen();
void nondisclWomen();
void nondisftMen();
void nondisftWomen();
void disclMen();
void disclWomen();
void disftMen();
void disftWomen();
void printbill();
void cart();
void openportal();
void placeorder();
void deletecart();
void username();
void showacc();
void loggedin();
void costcalCloth();
void costcalFoot();
void editCart();
void showCart();
void deletingdetails();

//global variables
string reguser,regpass,fname,lname,dob,email,ph_no,user,ru;
float totalam=0.0;
int exist=0,flag=0,islog=0;
float totalamount=0;
ifstream item;
ofstream f1;
ifstream acc;

//main function
int main(){
system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n A Place for latest Fashion Trends and clothing's for MEN and Women\n";
	cout<<"\n 	and fashionable Footwears with different ranges--   \n";
	cout<<"\n\n*******************************************************************\n\n";
	cout<<"\n    ----->DON'T LEAVE THIS OPPORTUNITY!! COME FAST AND SHOP<-----\n\n\n";

	getch();
	cout<<"\n--->press any key<--- ";
	mainmenu();

}





//secondary main function

int mainmenu()
{
	system("cls");
	int choice;
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n              HELLO EVERYONE!! WE WELCOMES YOU!!       		 \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n1.SIGNING IN (EXISTING USER)";
	cout<<"\n2.SIGNING UP (NEW USER)";
	cout<<"\n3.SHOP (LETS DO SOME SHOPPING! ";
	cout<<"\n4.CONTACT US:-- ";
	cout<<"\n\n\nWhat's your choice : ";
	cin>>choice;
	if(choice==1)
		signin();
	else if(choice==2)
		signup();
	else if(choice==3)
		shop();
	else if(choice==4)
		contact();
	else
		exit;
}

//for contact details and any queries
void contact(){
	system("cls");
	int choice;
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n       		       ---->CONTACT US<----       	    \n";
	cout<<"\n\n********************************************************************\n\n";

	cout<<"\n\n                 ********ANY QUERIES********\n";
	cout<<"\n\n *EMAIL ID:-   ti1230221@gmail.com";
	cout<<"\n\n *MOBILE NUMBER:-    18001400121\n\n";

	cout<<"\n\n                 ********NO QUERIES********";
	cout<<"\n\nLET'S GO BACK -- press 1 for MAIN PAGE ";
		cin>>choice;
	if(choice==1)
		mainmenu();
	else
		exit;

}
//deleting user details from data file
void deletingdetails()
{


			ifstream edfile;
			edfile.open("data.txt");
			ofstream blank;
			blank.open("editdata.txt");
			while(!edfile.eof())
			{
				string x,line;
				edfile>>x;
				getline(edfile,line);
				if(x!=user)
				{
					blank<<x<<' ';

					blank<<line<<endl;
				}
			}
			blank.close();
				edfile.close();
				remove("data.txt");
				rename("editdata.txt","data.txt");
					mainmenu();
					}



//checking if username already exists or not
void username()
{
	ifstream check;
	check.open("data.txt",ios::in);

	while(!check.eof())
	{
		string ru;
		check>>ru;
		if(ru==reguser)
		{
			exist=1;
		}
		else
			{
				for(int j=0;j<6;j++)
					check>>ru;
			}
	}
	check.close();
}

//function for signup
void signup()
{

	system("cls");
	cout<<"********************************************************************\n\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n\n";
	cout<<"\n\n              ---->WELCOME NEW USER(SIGNING UP)<----    \n";
	cout<<"\n\n********************************************************************\n";
	f1.open("data.txt", ios::app);

	cout<<"USERNAME : ";
	cin>>reguser;
	f1<<reguser<<' ';

	username();
	if(exist==1)
	{
		cout<<"SORRY! USERNAME ALREADY EXITS...LETS GO TO LOGIN PAGE:\n";
		getch();
		signin();
	}

	else{
		cout<<"NEW PASSWORD : ";
		cin>>regpass;
		f1<<regpass<<' ';
	}
	cout<<"FIRST NAME : ";
	cin>>fname;
	f1<<fname<<' ';

	cout<<"LAST NAME : ";
	cin>>lname;
	f1<<lname<<' ';


	cout<<"DATE OF BIRTH : ";
	cin>>dob;
	f1<<dob<<' ';

	cout<<"EMAIL ID : ";
	cin>>email;
	f1<<email<<' ';

	cout<<"CONTACT NUMBER : ";
	cin>>ph_no;
	f1<<ph_no<<'\n';

	f1.close();
	cout<<"successfully created!! \n";
	cout<<"\n\nLETS LOGIN NOW:---- press 1 : ";
	int ch;
	cin>>ch;
	if(ch==1)
		signin();

}

//function for sign in
void signin()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                ---->WELCOME SIR!! PLEASE SIGNIN!<----                             \n";
	cout<<"\n\n********************************************************************\n";
	int exist=0;
	string pass,u,p;
	int loginattempt = 0;
	while(loginattempt<5)
	{
		cout<<"USERNAME : ";
		cin>>user;
		cout<<"PASSWORD : ";
		cin>>pass;

		ifstream fin;
		fin.open("data.txt",ios::in);

		while(fin>>u>>p)
		{
			if(u==user && p==pass)
			{
				exist = 1;
			}
			else
			{
					getline(fin,u);
			}
		}
		fin.close();

	 	if(exist==1)
		{
			system("cls");
			cout<<"********************************************************************\n";
			cout<<"\n\n                         SHOPPERS STOP                          \n";
			cout<<"\n\n                  ---->WELCOME BACK SIR!!<----                             \n";
			cout<<"\n\n********************************************************************\n";
			string fn,ln;
			ifstream fdata;
			fdata.open("data.txt",ios::in);

			cout<<"\n\n\nHello ";
			while(!fdata.eof())
			{
				string u;
				fdata>>u;
				if(u==user)
				{
					fdata>>u>>fn;
					cout<<fn<<' ';
					fdata>>ln;
					cout<<ln;
					cout<<"\n\nWelcome back sir! hope u have a wonderful day\n";
					islog=1;
					fdata.close();
					cout<<"\n--->press any key<--- ";
					cin.get();
					cin.get();
					openportal();
				}
				else
				{
					getline(acc,u);
				}
			}

		}
		else{
			cout<<"-->Invalid username or password<--\n\n";
			loginattempt++;
			int ch;
				cout<<"\n1.CREATING NEW ACCOUNT\n2.TRY AGAIN\n";
				cin>>ch;
				if(ch==1)
					signup();

			}

	}
	if(loginattempt==5)
	{
		cout<<"\nToo many attempts!\n\n";
		cout<<"SORRY! LETS GET BACK TO MAIN MENU: \n";
			cin.get();
			cin.get();
			mainmenu();
	}

}

//homepage for loggedin user
void openportal()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n			    LETS SHOP!!!		\n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n1.ACCOUNT DETAILS:-\n2.SHOP (LETS DO SOME SHOPPING! \n3.CHECKOUT(CART)\n4.SIGNING OUT (BIE BIE): \n5.DELETING ACCOUNT DETAILS: ";
	int option1;
	cout<<"\n\n\nWhat's your choice : ";	cin>>option1;
	if(option1==1)
		account();
	else if(option1==2)
		shop();
	else if(option1==3)
		cart();
	else if(option1==4)
		{

			mainmenu();
		}
	else if(option1==5)
		deletingdetails();
	else
		{cout<<"\nSorry, ENTERED WRONG CHOICE: -->press enter to choose again<--";
		getch();
		openportal();}
}



//function for shopping
void shop()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n********************************************************************";
	cout<<"\n\n                 ---->SHOPPING FOR MEN/WOMEN<----                        \n";
	cout<<"\n\t1.MEN\n\t2.WOMEN\n";
	int ch;
	cout<<"\n\n\nWhat's your choice : ";cin>>ch;
	if(ch==1)
		 men();
	else if(ch==2)
		women();
	else {cout<<"\nSorry, ENTERED WRONG CHOICE: -->press enter to choose again<--";
		getch();
		shop();}
}

//shopping for men
void men()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n********************************************************************";
	cout<<"\n\n                   ---->IT's TIME FOR CATEGORY<----                         \n";
	cout<<"\n\t1.CLOTHING\n\t2.FOOTWEARS\n";
	int ch;
	cout<<"\n\n\nWhat's your choice : ";
	cin>>ch;
	if(ch==1)
		clothMen();
	else if(ch==2)
		 footMen();
	else{cout<<"\nSorry, ENTERED WRONG CHOICE: -->press enter to choose again<--";
		getch();
		men();}
}

//shopping for women
void women()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n********************************************************************";
	cout<<"\n\n                   ---->IT's TIME FOR CATEGORY<----                         \n";
	cout<<"\n\t1.CLOTHING\n\t2.FOOTWEARS\n";
	int ch;
	cout<<"\n\n\nWhat's your choice : ";	cin>>ch;
	if(ch==1)
		clothWomen();
	else if(ch==2)
		footWomen();
	else{cout<<"\nSorry, ENTERED WRONG CHOICE: -->press enter to choose again<--";
		getch();
		women();}
}

//function for opening account of user
void account()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
    cout<<"\n\n********************************************************************\n";
    cout<<"\n\n                 ---->YOUR ACCOUNT DETAILS: <----                        \n";

	acc.open("data.txt",ios::in);

	while(!acc.eof())
	{

		acc>>ru;
		if(ru==user)
		{
			flag=1;
			showacc();
		}
		else
			{
				getline(acc,ru);
			}
	}
}

//for displaying account details of user
void showacc()
{
	if(flag==1)
	{
	cout<<"\n\nUsername:\t\t\t";
	acc>>ru;
	cout<<ru;

	cout<<"\nFirst name:\t\t\t";
	string f;
	acc>>f;
	cout<<f;

	cout<<"\nLast name:\t\t\t";
	string l;
	acc>>l;
	cout<<l;

	cout<<"\nDate Of Birth:\t\t\t";
	string d;
	acc>>d;
	cout<<d;

	cout<<"\nEmail Id:\t\t\t";
	string em;
	acc>>em;
	cout<<em;

	cout<<"\nContact Number:\t\t\t";
	string ph;
	acc>>ph;
	cout<<ph;
	acc.close();
	cout<<"\n\n\nDO WANT TO SEE CART: [y/n]?  ";
	char c;
	cin>>c;
	if(c=='y')
		cart();
	else
		openportal();
	}
}

//function for category of clothing for men
void clothMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                         MEN'S CLOTHING                         \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\t1.DISCOUNTED\n\t2.NON-DISCOUNTED\n";
	int ch;
	cout<<"\n\n\nWhat's your choice : ";	cin>>ch;
	if(ch==1)
		disclMen();
	else if(ch==2)
		nondisclMen();
	else{cout<<"\nSorry, ENTERED WRONG CHOICE: -->press enter to choose again<--";
		getch();
		men();}
}

//function for category of footwear for men
void footMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                        MEN'S FOOTWEAR                         \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\t1.DISCOUNTED\n\t2.NON-DISCOUNTED\n";
	int ch;
	cout<<"\n\n\nWhat's your choice : "; cin>>ch;
	if(ch==1)
		disftMen();
	else if(ch==2)
		nondisftMen();
	else{cout<<"\nSorry, ENTERED WRONG CHOICE: -->press enter to choose again<--";
		getch();
		men();}
}

//function for category of clothing for women
void clothWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                       WOMEN'S CLOTHING                         \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\t1.DISCOUNTED\n\t2.NON-DISCOUNTED\n";
	int ch;
	cout<<"\n\n\nWhat's your choice : "; cin>>ch;
	if(ch==1)
		disclWomen();
	else if(ch==2)
		nondisclWomen();
	else{cout<<"\nSorry, ENTERED WRONG CHOICE: -->press enter to choose again<--";
		getch();
		clothWomen();}
}

//function for category of footwear for women
void footWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                       WOMEN'S FOOTWEAR                         \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\t1.DISCOUNTED\n\t2.NON-DISCOUNTED\n";
	int ch;
	cout<<"\n\n\nWhat's your choice : "; cin>>ch;
	if(ch==1)
		disftWomen();
	else if(ch==2)
		nondisftWomen();
	else{cout<<"\nSorry, ENTERED WRONG CHOICE: -->press enter to choose again<--";
		getch();
		women();}
}

void loggedin()
{
	cout<<"\n-->YOU ARE NOT LOGGED IN...WHY!!! Please login first: <---";
						cout<<"\nPress any key to continue...\n";
						cin.get();
						cin.get();
						mainmenu();
}

//function for displaying non-discounted clothing items for men
void nondisclMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                         MEN'S CLOTHING                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
    string x,y;
    y="136";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalCloth();
	   }
       getline(item,x);
    }
    item.close();

	cout<<"\n\nNOTE: 5% GST on goods BELOW Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying non-discounted clothing items for women
void nondisclWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                        WOMEN'S CLOTHING                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
    string x,y;
    y="236";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalCloth();
	   }
       getline(item,x);
    }
    item.close();

	cout<<"\n\nNOTE: 5% GST on goods BELOW Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying non-discounted footwear items for men
void nondisftMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                         MEN'S FOOTWEAR                        \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="146";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalFoot();
	   }
       getline(item,x);
    }
    item.close();
	cout<<"\n\nNOTE: 5% GST on goods BELOW Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying non-discounted footwear items for women
void nondisftWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                       WOMEN'S FOOTWEAR                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="246";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalFoot();
	   }
       getline(item,x);
    }
    item.close();
	cout<<"\n\nNOTE: 5% GST on goods BELOW Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying discounted clothing items for men
void disclMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                        MEN'S CLOTHING                         \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
    string x,y;
    y="135";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalCloth();
	   }
       getline(item,x);
    }
    item.close();

	cout<<"\n\nNOTE: 5% GST on goods BELOW Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying discounted clothing items for women
void disclWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                       WOMEN'S CLOTHING                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="235";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalCloth();
	   }
       getline(item,x);
    }
    item.close();

	cout<<"\n\nNOTE: 5% GST on goods BELOW Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying discounted footwear items for men
void disftMen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                        MEN'S FOOTWEAR                         \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="145";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalFoot();
	   }
       getline(item,x);
    }
    item.close();

	cout<<"\n\nNOTE: 5% GST on goods BELOW Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//function for displaying discounted footwear items for women
void disftWomen()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                        WOMENT'S FOOTWEAR                          \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\n\n\nItemId\t\tItem\t\tCost\t\tDiscount %\tDiscount Cost\t\tGST%\t\tBuy Price\n";
	cout<<"---------------------------------------------------------------------------------------------------------------------------------\n";
	string x,y;
    y="245";
    item.open("cart.txt",ios::in);
    while(!item.eof())
    {
        item>>x;
        if(x==y)
        {
            costcalFoot();
	   }
       getline(item,x);
    }
    item.close();
	cout<<"\n\nNOTE: 5% GST on goods BELOW Rs.1000 per price and 12% GST on others.";
	editCart();
	cout<<"\nPress any key to continue...\n";
	cin.get();
	cin.get();
	openportal();
}

//calculating gst and cost price for clothing
void costcalCloth()
{
    int i=0;
    while(i<4){
    int id;
    item>>id;
    cout<<id<<"\t\t";
    string iname;
    item>>iname;
    cout<<iname<<"\t\t";
    float cost;
    item>>cost;
    cout<<cost<<"\t\t";
    float dis;
    item>>dis;
    cout<<dis<<"\t\t";
    float dis_cost;
    dis_cost = cost - ((cost * dis)/100);
    cout<<dis_cost<<"\t\t\t";
    float gst;
    if(dis_cost>1000)
        gst = 12;
    else
        gst = 5;
    cout<<gst<<"\t\t";
    float buy;
    buy = dis_cost + ((dis_cost * gst)/100);
    cout<<buy<<endl;
    string temp;
    getline(item,temp);
    i++;}
}

//calculating gst and cost price for footwear
void costcalFoot()
{
    int i=0;
    while(i<4){
    int id;
    item>>id;
    cout<<id<<"\t\t";
    string iname;
    item>>iname;
    cout<<iname<<"\t\t";
    float cost;
    item>>cost;
    cout<<cost<<"\t\t";
    float dis;
    item>>dis;
    cout<<dis<<"\t\t";
    float dis_cost;
    dis_cost = cost - ((cost * dis)/100);
    cout<<dis_cost<<"\t\t\t";
    float gst;
    if(dis_cost>500)
        gst = 18;
    else
        gst = 5;
    cout<<gst<<"\t\t";
    float buy;
    buy = dis_cost + ((dis_cost * gst)/100);
    cout<<buy<<endl;
    string temp;
    getline(item,temp);
    i++;}
}

//adding item in cart
void editCart()
{
    string selectid;
	cout<<"\n\nENTER PRODUCT ID to ADD IT INTO CART : ";
	cin>>selectid;
    if(islog!=1)
	{
		loggedin();
	}
	else
	{
		ifstream addcart;
        	addcart.open("cart.txt",ios::in);
		f1.open("usercart.txt",ios::app);

		int check_selectid = 0;
        string xi;
        while(!addcart.eof())
        {
            addcart>>xi;
            if(xi==selectid)
            {
				f1<<user<<' ';
        		f1<<selectid<<' ';
				check_selectid = 1;
                string item_name;
				addcart>>item_name;
                f1<<item_name<<' ';
    			float cost;
    			addcart>>cost;
   				float dis;
    			addcart>>dis;
    			float dis_cost;
    			dis_cost = cost - ((cost * dis)/100);
    			float gst;
    			if(dis_cost>1000)
        			gst = 12;
    			else
        			gst = 5;
    			float price;
    			price = dis_cost + ((dis_cost * gst)/100);
				f1<<price<<endl;
				cout<<"\n-->ITEM ADDED<--\n";
            }
            getline(addcart,xi);
        }
        addcart.close();
	    if(check_selectid!=1)
			cout<<"\nWrong choice entered.\n";
        f1.close();
	}
}

//printing bill of purchasing items
void printbill()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                         PAYMENT GATEWAY!                         \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\nItems are : \n\n\n";
	cout<<"ItemId\t\t\t\tItem\t\t\t\tCost\n";
	cout<<"--------------------------------------------------------------------\n";
	item.open("usercart.txt",ios::in);
    while(!item.eof())
    {
		string x;
        item>>x;
        if(x==user)
        {
            showCart();
	    }
       getline(item,x);
    }
    item.close();
	totalam = 0.00;
	ifstream total;

	total.open("usercart.txt",ios::in);
	string check_user,tid,tiname;
	string tcost;
	total>>check_user>>tid>>tiname>>tcost;
	while(!total.eof())
	{
	    if(check_user==user)
		{
			totalam = totalam+stof(tcost);
            total>>check_user;
			total>>tid; total>>tiname; total>>tcost;


		}
		else
			getline(total,check_user);


	}

	cout<<"\nTotal amount : Rs."<<totalam<<"/-"<<endl;
	total.close();
	cout<<"\n\nDo you want to place order [y/n]?  ";
	char choice1;
	cin>>choice1;
	if(choice1=='y')

		placeorder();

}

//function for placing order
void placeorder()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n                       PAYMENT BILL WITH DETAILS:  \n";
	cout<<"\n\n********************************************************************\n";

    cout<<"ItemId\t\t\t\tItem\t\t\t\tCost\n";
	cout<<"--------------------------------------------------------------------\n";
	item.open("usercart.txt",ios::in);
    while(!item.eof())
    {
		string x;
        item>>x;
        if(x==user)
        {
		    showCart();

	    }
       }

    item.close();
    cout<<"\n\t\t\tTOTAL AMOUNT = "<<totalam<<endl;


    ifstream placein;
	placein.open("usercart.txt");
	ofstream temp;
	temp.open("temp1.txt");
	while(!placein.eof())
	{
		string x,y;
		placein>>x;
		getline(placein,y);
		if(x!=user)
		{
			temp<<x;
			temp<<y<<endl;
		}
	}
	temp.close();
		placein.close();
		remove("usercart.txt");
		rename("temp1.txt","usercart.txt");

	cout<<"\n\nCONGRATS ON PLACING AN ORDER";
	cout<<"\n\nTHANKS FOR SHOPPING \nHAVE A WONDERFUL DAY!!\n\n";

	cout<<"\n\n\n*******************************\n\n";
	cout<<"1.VISIT ACCOUNT\n2.EXIT\n";
	int ch;
	cin>>ch;
	if(ch==1)
        openportal();
    else
        exit(0);

}

//function to open cart
void cart()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                  LET'S CHECK WHICH PRODUCTS YOU LOVE!                        \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\nCart items are : \n\n\n";
	cout<<"ItemId\t\t\t\tItem\t\t\t\tCost\n";
	cout<<"--------------------------------------------------------------------\n";
	item.open("usercart.txt",ios::in);
    while(!item.eof())
    {
		string x;
        item>>x;
        if(x==user)
        {
		    showCart();

	    }
       }

    item.close();
	cout<<"\n\n****************************************************************\n\n";
	cout<<"\n\n1.BILL PRINTING\n2.DELETING ITEM\n3.CONTINUE SHOPPING";
	int print;
	cout<<"\n\n\nWhat's your choice : "; cin>>print;
	if(print==1)
		printbill();
	else if(print==2)
		deletecart();
	else if(print==3)
		openportal();
	else
		exit(0);
}


//displaying cart items
void showCart()
{
	string id;
	item>>id;
    cout<<id<<"\t\t\t\t";
    string iname;
    item>>iname;
    cout<<iname<<"\t\t\t\t";
    float cost;
    item>>cost;
	totalamount=totalamount+cost;
    cout<<cost<<endl;
}

//deleting item from cart
void deletecart()
{
	system("cls");
	cout<<"********************************************************************\n";
	cout<<"\n\n                         SHOPPERS STOP                          \n";
	cout<<"\n\n                    WHICH ITEMS YOU WANT TO DELETE!                         \n";
	cout<<"\n\n********************************************************************\n";
	cout<<"\n\nCart items are : \n\n\n";
	cout<<"ItemId\t\t\t\tItem\t\t\t\tCost\n";
	cout<<"--------------------------------------------------------------------\n";
	item.open("usercart.txt",ios::in);
    while(!item.eof())
    {
		string x;
        item>>x;
        if(x==user)
        {
            showCart();
	    }
       getline(item,x);
    }
    item.close();

	cout<<"\n\nEnter ItemId of item that you want to delete from cart : ";
	string delId,line;
	cin>>delId;
	ifstream del1;
	del1.open("usercart.txt");
	ofstream temp;
	temp.open("temp.txt");
	while(!del1.eof())
	{
		string x;
		del1>>x;
		if(x==user)
		{
			string y,it;
			float cit;
			del1>>y>>it>>cit;
			if(y!=delId)
			{
				temp<<x<<' '<<y<<' '<<it<<' '<<cit<<endl;
			}
		}
		else{
			temp<<x<<' ';
		while(getline(del1,line))
			{
				temp<<line<<endl;
			}
		}
	}
	temp.close();
		del1.close();
		remove("usercart.txt");
		rename("temp.txt","usercart.txt");
	cart();
}
