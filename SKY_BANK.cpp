#include <iostream>
#include <conio.h>
#include <string.h>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
int main();
string fname, lname, u_name, t_u_name, email_id, DOB;
int i = 0, counter, pin;
unsigned long long int acc_no, aadhar_no, mob_no;
long double d_money;

class bank
{

public:
    void details(int cnt)
    {
        system("CLS");
		system("Color 0A");
        account_number();
        cout << "==============================================" << endl;
        cout << "FILL YOUR DETAILS BELOW:\t\tForm:"<<cnt<< endl;
        cout << "==============================================" << endl;
        cout << "Your account number is \"" << acc_no << "\"\n\n";
		cout << "[Please fill these details carefully ]"<< endl;
        cout << "Enter first name :";
        cin >> fname;
        cout << " Enter last name :";
        cin >> lname;
        cout << "        Username :@";
        cin >> u_name;
        cout << "     Secrate PIN :";
        cin >> pin;
        cout << "      Mobile no. :";
        cin >> mob_no;
        cout << "        Email Id :";
        cin >> email_id;
        cout << "      Aadhar no. :";
        cin >> aadhar_no;
        cout << "   Date of Birth :";
        cin >> DOB;
        cout << "  Deposit money :$";
        cin >> d_money;
        cout << "\n\nNote : Please remember your USERNAME and PIN......... ";
        cout << "\n\nPress any key to exit....";
        getch();
	
		ofstream open_acc(u_name);
		open_acc<<pin<<endl;
		open_acc<<"Name : "<<fname<<" "<<lname<<endl;
		open_acc<<"Mobile no. : "<<mob_no<<endl;
		open_acc<<"Email Id : "<<email_id<<endl;
		open_acc<<"Aadhar no. : "<<aadhar_no<<endl;
		open_acc<<"Date of Birth : "<<DOB<<endl;
		open_acc<<"Current Balance : $"<<d_money<<endl;
		
    }

    void account_number()
    {
        int a;
        srand((unsigned)time(0));
        acc_no = (rand() % (42356 + 1 - 42256) + 42256);
	}	
	
	void balance()
	{
		string pin;
        system("CLS");
		system("Color 09");
        cout << "Enter Your username : @";
        cin >> t_u_name;
		
		
		ifstream ifile;
		ifile.open(t_u_name);
		if(ifile) {
			string pass;
			getline(ifile, pass);
			cout<<"Enter your PIN :";
			cin>>pin;
			
			if(pin == pass){
				system("CLS");
				system("Color f2");
				cout << "==============================================" << endl;
				cout << "		Current Balance" << endl;
				cout << "==============================================" << endl;
				string read;
				int count =1;
				while(getline(ifile, read)){
					if(count==6){
						cout<<read<<endl;
					}	
					count+=1;
				}
				getch();
				main();
			}
			else{
				cout<<"Incorrect PIN !!!";
				getch();
				main();
			}	
		} 
		else 
		{
			system("CLS");
			system("Color 4B");
            cout << "You entered wrong Username or not exist\n\tPlease  Try again or create a new A/C !!!!!!!!";
            getch();
            balance();
        }
    }	

    void show()
    {
        string pin;
        system("CLS");
		
        cout << "Enter Your username : @";
        cin >> t_u_name;
		
		
		ifstream ifile;
		ifile.open(t_u_name);
		if(ifile) {
			string pass;
			getline(ifile, pass);
			cout<<"Enter your PIN :";
			cin>>pin;
			
			if(pin == pass){
				system("CLS");
				system("Color f2");
				cout << "==============================================" << endl;
				cout << "		Your Account Details" << endl;
				cout << "==============================================" << endl;
				string read;
				while(getline(ifile, read)){
					cout<<read<<endl;
				}
				getch();
				main();
			}
			else{
				cout<<"Incorrect PIN !!!";
				getch();
				main();
			}	
		} 
		else 
		{
			system("CLS");
			system("Color 4B");
            cout << "You entered wrong Username or not exist\n\tPlease  Try again or create a new A/C !!!!!!!!";
            getch();
            main();
        }
    }
	
	
	void withdraw(){
		string pin;
        system("CLS");
		system("Color 09");
		
        cout << "Enter Your username : @";
        cin >> t_u_name;
		
		
		fstream ifile;
		ifile.open(t_u_name);
		if(ifile) {
			string pass;
			getline(ifile, pass);
			cout<<"Enter your PIN :";
			cin>>pin;
			
			if(pin == pass){
				system("CLS");
				system("Color f2");
				
				string word;
				
				while (ifile >> word)
				{
					if (word.rfind("$", 0) == 0) 
					{
						int amo,x;
						cout<<"Enter amount to withdraw : $";
						cin>>amo;
						
						word.erase(remove(word.begin(), word.end(), '$'), word.end());
						x = stoi(word);
						
						if(x-amo<0)
						{
							cout<<"!!!!     insufficient balance     !!!!\nPlease try again later !!!!";
						}	
						else
						{
						ifile << "Current Balance : $" <<x-amo<< endl;
						cout<<"Successfully withdrawn $"<<amo;
						}
					}
				}
				ifile.close();
				getch();
			}	
			else 
			{
				system("CLS");
				system("Color 4B");
				cout<<pass;
				cout << "You entered wrong PIN\n\tPlease  Try again later !!!!!!!!";
				getch();
				main();
			}
		
		}
		else{
			system("CLS");
			system("Color 4B");
			cout << "You entered wrong Username or not exist\n\tPlease  Try again or create a new A/C !!!!!!!!";
			getch();
			main();
		}
		main();
	}	
	void deposit(){
		string pin;
        system("CLS");
		system("Color 09");
		
        cout << "Enter Your username : @";
        cin >> t_u_name;
		
		
		fstream ifile;
		ifile.open(t_u_name);
		if(ifile) {
			string pass;
			getline(ifile, pass);
			cout<<"Enter your PIN :";
			cin>>pin;
			
			if(pin == pass)
			{
				system("CLS");
				system("Color f2");
				
				string word;
				
				while (ifile >> word)
				{
					if (word.rfind("$", 0) == 0) 
					{
						int amo,x;
						cout<<"Enter amount to deposit : $";
						cin>>amo;
						
						word.erase(remove(word.begin(), word.end(), '$'), word.end());
						x = stoi(word);
						
					
						ifile << "Current Balance : $" <<x+amo<< endl;
						cout<<"Successfully deposited $"<<amo;
						}
				}
				
				ifile.close();
				getch();
			}	
			else 
			{
				system("CLS");
				system("Color 4B");
				cout<<pass;
				cout << "You entered wrong PIN \n\tPlease  Try again later !!!!!!!!";
				getch();
				main();
			}
		}else
		{
			system("CLS");
			system("Color 4B");
			cout << "You entered wrong Username or not exist\n\tPlease  Try again or create a new A/C !!!!!!!!";
			getch();
			main();
		}
		main();
	}	
};

void loading()
{
system("CLS");
system("Color 0B");
        cout << "         _._._                       _._._" << endl;
        cout << "        _|   |_                     _|   |_" << endl;
        cout << "        | ... |_._._._._._._._._._._| ... |" << endl;
        cout << "        | ||| |   o   SKY BANK  o  | ||| |" << endl;
        cout << "        | \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |" << endl;
        cout << "   ())  |[-|-]| [-|-]  [-|-]  [-|-] |[-|-]|  ())" << endl;
        cout << "  (())) |     |---------------------|     | (()))" << endl;
        cout << " (())())| \"\"\" |  \"\"\"    \"\"\"    \"\"\"  | \"\"\" |(())())" << endl;
        cout << " (()))()|[-|-]|  :::   .-\"-.   :::  |[-|-]|(()))()" << endl;
        cout << " ()))(()|     | |~|~|  |_|_|  |~|~| |     |()))(()" << endl;
        cout << "    ||  |_____|_|_|_|__|_|_|__|_|_|_|_____|  ||" << endl;
        cout << "         ^~.~^                       ^~.~^" << endl;
        cout << "         ^~.~^                       ^~.~^" << endl;
        cout << "         ^~.~^                       ^~.~^" << endl;
        cout << "\nLOADING SKY BANK...";
        Sleep(2000);
        cout << ".....";
        Sleep(1000);
        cout << ".....";
        Sleep(2000);
        cout << ".....";
        Sleep(1000);
        cout << ".....";
        Sleep(1000);
        system("CLS");
        
}

int main()
{
    bank obj[100];
    int i, n, a, term;
    term = MessageBox(0, "Our Terms & Conditions\n\n1. I'ill never copy this program or code without creator's permission.\n\n. ", "SKY BANK", MB_ICONASTERISK | MB_YESNO | MB_DEFBUTTON2);

    if (term == 6)
    {
        loading();
        system("CLS");
        cout << "WELCOME TO \" SKY BANK \" PLEASE CHOOSE ANY ONE :" << endl;
        cout << "***************************************************************" << endl;
        cout << "[1] OPEN A/C" << endl;
        cout << "[2] YOUR A/C DETAILS" << endl;
		cout << "[3] CHECK BALANCE" << endl;
		cout << "[4] WITHDRAW CASH" << endl;
		cout << "[5] DEPOSIT CASH" << endl;
        cout << "***************************************************************" << endl;
        cout << "Enter your choice : ";
        cin >> a;
        switch (a)
        {
        case 1:
            system("CLS");
            cout << "How many accounts you wanna create : ";
            cin >> counter;

            for (i = 1; i <= counter; i++)
            {
                obj[i].details(i);
            }
            main();
            break;
        case 2:
            obj[i].show();
            break;
		case 3:
			obj[i].balance();
		case 4:
			obj[i].withdraw();
		case 5:
			obj[i].deposit();
        default:
            cout << "You entered wrong key !\n\tTry again....";
            break;
        }
    }
    else
    {
        system("CLS");
        cout << "\n\nSORRY !! You declined our terms and conditions.\nPlease accept our term and conditions, then you will be able to enter in the bank";
    }
	getch();
    return 0;
}