#include<iostream>
#include<string.h>
#include<fstream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
int n=0,index=0;

class item
{
	public: char name[20],barcode[20],expdate[10];
			char manudate[10];
			int price,quantity;
	void insertitem(fstream &f1,fstream &f2)
	{
	    system("cls");
	    cout<<endl<<endl;
	    cout<<"\t\t____________________________________________________"<<endl;
	    cout<<"\t\t\tINSERT THE SWEET DETAILS"<<endl;
	    cout<<"\t\t____________________________________________________"<<endl;
		cout<<"\t\tENTER NAME OF SWEET: ";
		cin>>name;
		cout<<"\t\tENTER BARCODE NUMBER: ";
		cin>>barcode;
		cout<<"\t\tENTER MANUFACTURE DATE: ";
		cin>>manudate;
		cout<<"\t\tENTER EXPIARY DATE: ";
		cin>>expdate;
		cout<<"\t\tENTER PRICE:Rs. ";
		cin>>price;
		cout<<"\t\tENTER QUANTITY: ";
		cin>>quantity;
		cout<<"\t\t_______________________________________________"<<endl;
		cout<<endl;
		writeitem(f1,f2);
	}
	void writeitem(fstream &f1,fstream &f2)
	{
		f1<<++index<<"\t"<<name<<"\n";
		f2<<name<<"\t"<<barcode<<"\t"<<manudate<<"\t"<<expdate<<"\t"<<price<<"\t"<<quantity<<endl;
	}
	void displayitem(fstream &f2)
	{
		f2>>name>>barcode>>manudate>>expdate>>price>>quantity;
		cout<<"\t\t"<<name<<"\t"<<barcode<<"\t"<<manudate<<"\t"<<expdate<<"\t"<<price<<"\t"<<quantity<<endl;;
	}
	int searchitem(fstream &f1,char key[20])
	{
		int i,x;
		for(i=1;i<=n;i++)
		{
			f1>>x>>name;
			if(strcmp(name,key)==0)
				return i;
		}
		cout<<"\t\t--------------------------------------------"<<endl;
		cout<<"\t\t\tSWEET NOT FOUND!!!!\n";
		return 0;
	}
	int removeitem(fstream &f1,char key[20])
	{
		int i;
		i=searchitem(f1,key);
		return i;
	}
};
class login
{
	public:char username[20],password[10],cname[20],dob[10],address[40];
};
login log[100],l;
char buffer[45],temp1[20],temp2[20];
int count1=0,p;
fstream fp;
void clientpack(login c)
{
	fp.open("client.txt",ios::app);
	strcpy(buffer,c.username);
	strcat(buffer,"|");
	strcat(buffer,c.password);
	strcat(buffer,"|");
	strcat(buffer,c.cname);
	strcat(buffer,"|");
	strcat(buffer,c.dob);
	strcat(buffer,"|");
	strcat(buffer,c.address);
	strcat(buffer,"|");
	fp<<buffer<<endl;
	fp.close();

}

void clientwrite()
{
    cout<<"\t\t_______________________________________________"<<endl;
	cout<<"\t\tENTER YOUR DESIRED USERNAME: ";
	cin>>l.username;
	cout<<endl;
	cout<<"\t\tENTER YOUT DESIRED PASSWORD: ";
	cin>>l.password;
	cout<<endl;
	cout<<"\t\tENTER NAME: ";
	cin>>l.cname;
	cout<<endl;
	cout<<"\t\tENTER DATE OF BIRTH: ";
	cin>>l.dob;
	cout<<endl;
	cout<<"\t\tENTER THE ADDRESS: ";
	cin>>l.address;
	cout<<endl;
	cout<<"\t\t_______________________________________________"<<endl<<endl;
	clientpack(l);
}
void clientunpack()
{
	fp.open("client.txt",ios::in);
	for(p=0;p<count1;p++)
	{
		fp.getline(buffer,100);
		sscanf(buffer,"%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|",log[p].username,log[p].password,log[p].cname,log[p].dob,log[p].address);
	}
	fp.close();
}

int clientsearch()
{
    cout<<endl;
    cout<<cout<<"\n\t\tENTER CLIENT USERNAME AND PASSWORD"<<endl;
    cout<<"\n\t\t-----------------------------------------------"<<endl<<endl;
	cout<<"\t\tENTER USERNAME: ";
	cin>>temp1;
	cout<<"\t\tENTER PASSWORD: ";
	cin>>temp2;
	cout<<"\t\t-------------------------------------------------"<<endl<<endl;
	for(p=0;p<count1;p++)
	if(!strcmp(log[p].username,temp1))
	{
		if(!strcmp(log[p].password,temp2))
			cout<<"\t\t\tSUCCESSFULLY LOGEDIN\n";
			cout<<endl<<endl;
			return 1;
		break;
	}
	if(p==count1)
	cout<<"\t\t\tUSERNAME NOT FOUND\n\n";
	return 0;
}
int admin()
{
    string username = "";
    string password = "";
    char ch;
    bool loginSuccess = false;
    do{
        cout<<cout<<"\n\t\tENTER ADMIN USERNAME AND PASSWORD"<<endl;
        cout<<"\n\t\t-----------------------------------------------"<<endl<<endl;
        cout << "\t\tUSERNAME: ";
        cin >> username;
        cout << "\t\tPASSWORD: ";
        ch=_getch();
        while(ch!=13)
        {
            password.push_back(ch);
            cout<<'*';
            ch=_getch();
        }
        cout<<"\n\t\t-----------------------------------------------"<<endl<<endl;
        if((username == "pusidu"  && password == "1234") || (username == "srikanth" && password == "sri123"))
        {
            cout<< "\n\t\t SUCCESSFULLY LOGED IN\n\n";
            loginSuccess = true;
            break;
        }
        else
        {
            cout << "\n\t\tINCORRECT USERNAME PASSWORD COMBO \n";
            cout << "\t\tPlease try login again.";
        }
    }while(loginSuccess);
    if(loginSuccess==true)
        return 1;
    else
        return 0;
}

int main()
{
	fstream f1,f2;
	item s[20],p;
	int amt,total=0;
    string line;
	int ch,k=0,i,j,choice,result,ad;
	f1.open("index.txt",ios::trunc);
	f2.open("record.txt",ios::trunc);
	fp.open("client.txt",ios::out);
	f1.close();
	f2.close();
	fp.close();
	ifstream file("index.txt");
	while(getline(file,line))
        n++;
    ifstream file1("client.txt");
	while(getline(file,line))
        count1++;
	cout<<"\t\t_________________________________________________"<<endl;
	cout<<"\t\t----WELCOME TO SWEET STORE MANAGEMENT SYSTEM---- "<<endl;
	cout<<"\t\t_________________________________________________"<<endl;
	panel:
	cout<<endl<<endl<<"\t\t****************************************************"<<endl;
	cout<<"\t\tPLEASE ENTER OPERATION NUMBER TO BE PERFORMED"<<endl;
	cout<<"\t\t****************************************************"<<endl;
	cout<<"\t\t1.  Administration login \n\t\t2.  Customer login \n\t\t3.  Customer sign up "<<endl;
	cout<<"\t\t****************************************************"<<endl;
	cout<<"\t\tENTER CHOICE:";
	cin>>choice;
	cout<<endl;
	switch(choice)
	{
	    case 1: system("cls");
                cout<<endl<<endl<<"\t\t_______________________________________________"<<endl;
                cout<<"\t\t\tWELCOME TO ADMIN PANEL"<<endl;
                cout<<"\t\t_______________________________________________"<<endl;
                ad=admin();
                if(ad==1)
                {
                for(;;)
                {
                    cout<<endl<<endl;
                    cout<<"\t\tPLEASE ENTER OPERATION NUMBER TO BE PERFORMED"<<endl;
                    cout<<"\t\t********************************************************"<<endl;
                    cout<<endl<<"\t\t1.INSERT SWEET TO DATABASE \n\t\t2.DISPLAY STORED SWEETS"<<endl;
                    cout<<"\t\t3.SEARCH FOR A SWEET \n\t\t4.DELETE STORED SWEET \n\t\t5.EXIT ADMIN PANEL\n";
                     cout<<"\t\t********************************************************"<<endl;
                    cout<<"\t\tENTER CHOICE NUMBER: ";
                    cin>>ch;
                    switch(ch)
                    {
                        case 1:
                                cout<<endl<<endl;
                                f1.open("index.txt",ios::app);
                                f2.open("record.txt",ios::app);
                                system("cls");
                                cout<<"\t\t#################################################################"<<endl;
                                cout<<"\t\tENTER NUMBER OF SWEET ITEMS TO BE ADDED: ";
                                cin>>k;
                                cout<<"\t\t#################################################################"<<endl;

                                n=n+k;
                                for(int i=1;i<=k;i++)
                                    s[i].insertitem(f1,f2);
                                f1.close();
                                f2.close();
                                break;
                        case 2: system("cls");
                                f2.open("record.txt",ios::in);
                                cout<<"\n\t\tname \t barcode \t manu.date \t exp.date \t price \t quantity \n";
                                cout<<"\t\t----------------------------------------------------------------------------------"<<endl;
                                for(i=1;i<=n;i++)
                                    s[i].displayitem(f2);
                                f2.close();
                                break;
                        case 3: system("cls");
                                char name[20];
                                cout<<"\n\t\tENTER SWEET NAME TO SEARCH: ";
                                cin>>name;
                                cout<<endl<<endl;
                                f1.open("index.txt",ios::in);
                                f2.open("record.txt",ios::in);
                                j=p.searchitem(f1,name);
                                if(j!=0)
                                {
                                    cout<<"\t\tSWEET FOUND AND DETAILS ARE\n";
                                    cout<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
                                    cout<<"\t\tName="<<s[j].name<<"\n"<<"\t\tBarcode="<<s[j].barcode<<"\n"
                                        <<"\t\tManufacture date="<<s[j].manudate<<"\n"<<"\t\tExpiry date="<<s[j].expdate<<"\n"<<"\t\tPrice=Rs."<<s[j].price<<"\n"<<"\t\tQuantity="<<s[j].quantity<<endl;
                                }
                                f1.close();
                                f2.close();
                                break;
                        case 4: system("cls");
                                f1.open("index.txt",ios::in);
                                f2.open("record.txt",ios::in);
                                cout<<"\t\t-------------------------------------------------------------"<<endl;
                                cout<<"\n\t\tENTER SWEET NAME TO DELETE: ";
                                cin>>name;
                                cout<<"\t\t-------------------------------------------------------------"<<endl;
                                j=p.removeitem(f1,name);
                                if(j!=0)
                                {
                                    for(i=j;i<n;i++)
                                        s[i]=s[i+1];
                                    cout<<"\n\t\tDeletion successfull\n";
                                }
                                n--;
                                index--;
                                f1.close();
                                f2.close();
                                f1.open("index.txt",ios::trunc|ios::app);
                                f2.open("record.txt",ios::trunc|ios::app);
                                index=0;
                                for(i=1;i<=n;i++)
                                s[i].writeitem(f1,f2);
                                f1.close();
                                f2.close();
                                break;
                                default:goto out;
                    }
                }
                }
                out:
                goto panel;
        case 2: clientunpack();
                result=clientsearch();
                if(result==1)
                {
                    for(;;)
                    {

                    cout<<endl<<endl<<"\t\t_______________________________________________"<<endl;
                    cout<<"\t\tWELCOME TO USER MENU"<<endl;
                    cout<<"\t\t_______________________________________________"<<endl;
                    cout<<endl<<endl;
                     cout<<"\t\tPLEASE ENTER OPERATION NUMBER TO BE PERFORMED"<<endl;
                    cout<<"\t\t********************************************************"<<endl;
                    cout<<"\t\t1. DISPLAY ALL SWEETS AVAILABLE \n\t\t2. SEARCH DESIRED SWEET \n\t\t3.PURCHASE SWEETS \n\t\t4. EXIT USER MENU\n";
                    cout<<"\t\t********************************************************"<<endl;
                    cout<<"\t\tENTER YOUR CHOICE: ";
                    cin>>ch;
                    cout<<endl<<endl;
                    switch(ch)
                    {

                        case 1: system("cls");
                                f2.open("record.txt",ios::in);
                                 cout<<"\n\t\tname\tbarcode\tmanudate\texp.date\tprice\tquantity\n";
                                cout<<"\t\t----------------------------------------------------------------------------------"<<endl;
                                for(i=1;i<=n;i++)
                                s[i].displayitem(f2);
                                f2.close();
                                break;
                        case 2: system("cls");
                                char name[20];
                                cout<<"\t\t-------------------------------------------------------------"<<endl;
                                cout<<"\t\tENTER SWEET TO SEARCH: ";
                                cin>>name;
                                cout<<"\t\t-------------------------------------------------------------"<<endl;
                                f1.open("index.txt",ios::in);
                                f2.open("record.txt",ios::in);
                                j=p.searchitem(f1,name);
                                if(j!=0)
                                {
                                    cout<<"\t\t\tSWEET FOUND AND DETAILS ARE\n";
                                    cout<<"\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
                                    cout<<"\t\tName="<<s[j].name<<"\n"<<"\t\tBarcode="<<s[j].barcode<<"\n"
                                        <<"\t\tManufacture date="<<s[j].manudate<<"\n"<<"\t\tExpiry date="<<s[j].expdate<<"\n"<<"\t\tPrice=Rs."<<s[j].price<<"\n"<<"\t\tQuantity="<<s[j].quantity<<endl;
                                }
                                f1.close();
                                f2.close();
                                break;
                        case 3: {
                                system("cls");
                                char order_arr[20][10];
                                int quan[10],c=0;
                                char cha='y';
                                cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                                cout<<"\n\t\t\t PLACE YOUR ORDER";
                                cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                                //use for loop here
                                while(cha=='y' ||cha=='Y'){
                                    cout<<"\n\n\t\tENTER THE PRODUCT #: ";
                                    cin>>order_arr[c];
                                    cout<<"\n\t\tENTER THE QUANTITY: ";
                                    cin>>quan[c];
                                    cout<<"\n\t\tDo You Want To Order Another Product ? (y/n)";
                                    cin>>cha;
                                    c++;

                                }
                                cout<<"\n\n\t\tThank You..."<<endl<<endl;
                                cout<<"\n\n\t\t***********************************INVOICE*******************************\n";
                                cout<<"\n\t\tName\t\tUnit Price\tQuantity\tprice\n";
                                for(int x=0;x<=c;x++)
                                {
                                    f1.open("index.txt",ios::in);
                                    f2.open("record.txt",ios::in);

                                    j=p.searchitem(f1,order_arr[x]);
                                    if(j!=0)
                                    {
                                        amt=s[j].price*quan[x];
                                        cout<<"\n\t\t"<<order_arr[x]<<"\t"<<s[j].price<<"\t"<<quan[x]<<"\t\t"<<amt<<endl;
                                        total+=amt;
                                    }
                                }
                                cout<<"\n\t\tTOTAL PAYABLE AMOUNT=Rs. "<<total;
                                }

                        default:goto panel;
                    }
                    }
                }
                else
                    goto panel;


        case 3: system("cls");
                count1++;
                cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
                cout<<"\n\t\tENTER CUSTOMER DETAILS\n"<<endl;
                cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
                clientwrite();
                system("cls");
                goto panel;
                break;


	}

}
