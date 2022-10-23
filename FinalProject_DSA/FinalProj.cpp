#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
#include<string>
using namespace std;

struct person {
	string name, ID, address;
	char contact[12];
	int cash;
};

fstream file;
ofstream temp;
person obj;

class Bank {
private:
	int total;
	string id;

public:
	int choice();
	void perData();
	void show();
	void update();
	void search();
	void transactions();
	void del();
	int adminMenu();
	int userMenu();
};

int main() {
	Bank b;

	system("Color 2");
	cout << R"( 
	 ____              _      __  __                                                   _      _____           _                 
	|  _ \            | |    |  \/  |                                                 | |    / ____|         | |                
	| |_) | __ _ _ __ | | __ | \  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___  
	|  _ < / _` | '_ \| |/ / | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '_ ` _ \ / _ \ '_ \| __|  \___ \| | | / __| __/ _ \ '_ ` _ \ 
	| |_) | (_| | | | |   <  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \__ \ ||  __/ | | | | |
	|____/ \__,_|_| |_|_|\_\ |_|  |_|\__,_|_| |_|\__,_|\__, |\___|_| |_| |_|\___|_| |_|\__| |_____/ \__, |___/\__\___|_| |_| |_|
	                                                    __/ |                                        __/ |                      
	                                                   |___/                                        |___/      )" << '\n';



	cout << "\n\n\t\t\t\t\t\t\t\tMADE BY:\n" << endl;
	cout << "\t\t\t\t\t\t\t    Ferrer, Nestor V." << endl;
	cout << "\t\t\t\t\t\t\t   Maldia, Jon Paolo G." << endl;
	cout << "\t\t\t\t\t\t\tMangampat, John Joseph S." << endl;
	cout << "\t\t\t\t\t\t\t\tIT - 1201\n" << endl;
	cout << "\n\t\t\t\t\t\t\tPRESS ENTER TO CONTINUE...";
	cin.get();
	b.choice();
}

int Bank::choice() {
	string user, pass;
	char ch, chr;

	do {
		system("cls");
		cout << "\n\n\n\t===MAIN MENU===" << endl;
		cout << "\n\t[1] ADMIN" << endl;
		cout << "\n\t[2] USER" << endl;
		cout << "\n\t[3] EXIT" << endl;
		cout << "\n\tSelect Your Option (1-3): ";
		cin >> ch;
		system("cls");
		switch (ch) {
		case '1':
			cout << "\n\n\n\t\t\t\t\t\t\t\t[ADMIN LOGIN]";
			cout << "\n\n\t\t\t\t\t\t\tUSER: ";
			cin >> user;
			cout << "\n\n\t\t\t\t\t\t\tPASS: ";
			chr = _getch();

			while (chr != 13) {
				pass.push_back(chr);
				cout << '*';
				chr = _getch();
			}
			if (user == "admin1201" && pass == "1201admin") {
				adminMenu();
			}
			else
				cout << "\n\t\t\t\t\t\t\t   [INCORRECT CREDENTIALS!]\n" << "\n\t\t\t\t\t\t\t   -!TERMINATING PROGRAM!-\n";
			_getch();
			return 0;
			break;
		case '2':
			userMenu();
			break;
		case '3':
			cout << "\n\n\tThanks for using bank management system";
			_getch();
			exit(0);
			break;
		default:;
		}
		cin.ignore();
		cin.get();
	} while (ch != 3);
	return 0;
}

int Bank::adminMenu() {
	char ch;

	do {
		system("cls");
		cout << "\n\n\n\t===MAIN MENU===" << endl;
		cout << "\n\t[1] NEW ACCOUNT" << endl;
		cout << "\n\t[2] VIEW ALL ACCOUNT" << endl;
		cout << "\n\t[3] MODIFY AN ACCOUNT" << endl;
		cout << "\n\t[4] CLOSE AN ACCOUNT" << endl;
		cout << "\n\t[5] BACK TO USER MENU" << endl;
		cout << "\n\t[6] EXIT" << endl;
		cout << "\n\tSelect Your Option (1-6): ";
		cin >> ch;
		system("CLS");
		switch (ch) {
		case '1':
			Bank::perData();
			break;
		case '2':
			Bank::show();
			break;
		case '3':
			Bank::update();
			break;
		case '4':
			Bank::del();
			break;
		case '5':
			Bank::choice();
			break;
		case '6':
			cout << "\n\n\tThanks for using bank management system";
			_getch();
			exit(0);
			break;
		default:
			break;
		}
		cin.ignore();
		cin.get();
	} while (ch != 6);
	return 0;
}

int Bank::userMenu() {
	char ch;

	do {
		system("cls");
		cout << "\n\n\t===MAIN MENU===" << endl;
		cout << "\n\t[1] BALANCE INQUIRY" << endl;
		cout << "\n\t[2] WITHDRAW/DEPOSIT" << endl;
		cout << "\n\t[3] BACK TO USER MENU" << endl;
		cout << "\n\t[4] EXIT" << endl;
		cout << "\n\tSelect Your Option (1-4): ";
		cin >> ch;
		system("cls");
		switch (ch) {
		case '1':
			Bank::search();
			break;
		case '2':
			Bank::transactions();
			break;
		case '3':
			Bank::choice();
			break;
		case '4':
			cout << "\n\n\tThanks for using bank management system";
			_getch();
			exit(0);
			break;
		default:
			break;
		}
		cin.ignore();
		cin.get();
	} while (ch != 4);
	return 0;
}

void Bank::perData() {
	cout << "\n\tEnter name: ";
	cin.ignore();
	getline(cin, obj.name);
	cout << "\n\tID: ";
	getline(cin, obj.ID);
	cout << "\n\tAddress: ";
	getline(cin, obj.address);
	cout << "\n\tContact: ";
	cin.getline(obj.contact, 12);
	cout << "\n\tInitial Deposit: PHP ";
	cin >> obj.cash;

	file.open("database.txt", ios::binary | ios::app);
	file.write((char*)&obj, sizeof(obj));
	file.close();
}

void Bank::show()
{
	system("CLS");
	file.open("database.txt", ios::binary | ios::in);
	file.read((char*)&obj, sizeof(obj));

	while (file.eof() == 0)
	{
		cout << "\n\tName: " << obj.name << endl;
		cout << "\tID: " << obj.ID << endl;
		cout << "\tAddress: " << obj.address << endl;
		cout << "\tContact: " << obj.contact << endl;
		cout << "\tCash: PHP " << obj.cash << endl;

		file.read((char*)&obj, sizeof(obj));
	}
	file.close();
	_getch();
}

void Bank::update() {
	system("CLS");
	bool found = false;

	cout << "\n\tEnter your Account Number (ID) to update:" << "\n\t";
	cin >> id;

	file.open("database.txt", ios::in | ios::out);
	while (!file.eof() && found == false)
	{
		file.read((char*)&obj, sizeof(obj));
		if (id == obj.ID) {
			cout << "\n\t[PREVIOUS DATA]" << endl;
			cout << "\tName: " << obj.name << endl;
			cout << "\tID: " << obj.ID << endl;
			cout << "\tAddress: " << obj.address << endl;
			cout << "\tContact: " << obj.contact << endl;
			cout << "\tCash: PHP " << obj.cash << endl;

			cout << "\n\t[ENTER NEW DATA]" << endl;
			cout << "\t\tEnter name: ";
			cin.ignore();
			getline(cin, obj.name);
			cout << "\t\tID: ";
			getline(cin, obj.ID);
			cout << "\t\tAddress: ";
			getline(cin, obj.address);
			cout << "\t\tContact: ";
			cin.getline(obj.contact, 12);

			int pos = (-1) * static_cast<int>(sizeof(obj));
			file.seekp(pos, ios::cur);
			file.write(reinterpret_cast<char*> (&obj), sizeof(obj));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	file.close();
	if (found == false)
	{
		cout << "\n\n\tRecord Not Found... ";
	}
}

void Bank::search() {
	system("CLS");
	bool found = false;
	cout << "\n\tEnter your Account Number (ID) for Balance Inquiry: \n\t";
	cin >> id;

	file.open("database.txt", ios::binary | ios::in | ios::out);
	file.read((char*)&obj, sizeof(obj));

	while (file.eof() == 0)
	{
		if (id == obj.ID)
		{
			cout << "\n\t=======================";
			cout << "\n\tName: " << obj.name << endl;
			cout << "\n\tID: " << obj.ID << endl;
			cout << "\n\tAddress: " << obj.address << endl;
			cout << "\n\tContact: " << obj.contact << endl;
			cout << "\n\tCash: PHP " << obj.cash << endl;
			cout << "\t=======================";

			found = true;
		}
		file.read((char*)&obj, sizeof(obj));
	}
	file.close();
	if (found == false)
	{
		cout << "\n\n\tRecord Not Found... ";
	}
	_getch();
}

void Bank::transactions() //WITHDRAW AND DEPOSIT FUNCTION
{
	system("CLS");
	bool found = false;
	int cash;
	char ch;
	cout << "\n\tEnter your Account Number (ID) for transaction: \n\t";
	cin >> id;

	file.open("database.txt", ios::binary | ios::in | ios::out);
	while (!file.eof() && found == false)
	{
		file.read((char*)&obj, sizeof(obj));
		if (obj.ID == id)
		{
			int ch = 0;
			while (ch != 3) {
				cout << "\n\tName: " << obj.name << endl;
				cout << "\tAddress: " << obj.address << endl;
				cout << "\tContact: " << obj.contact << endl;
				cout << "\tExisting Cash: PHP " << obj.cash << endl;
				cout << "\n\tHello, " << obj.name << " what do you wanna do?\n";
				cout << "\t[1] Deposit" << endl;
				cout << "\t[2] Withdraw" << endl;
				cout << "\t[3] Main Menu" << endl;
				cout << "\tSelect Your Option (1-3): ";

				ch = _getch();
				switch (ch) {
				case '1':
					cout << "\n\n\tHow much cash you want to deposit? \n\tPHP ";
					cin >> cash;
					obj.cash += cash;
					cout << "\n\tYour new cash is PHP " << obj.cash << endl;
					break;
				case '2':
					cout << "\n\n\tHow much cash you want to withdraw?\n\tPHP ";
					cin >> cash;
					if (cash <= obj.cash)
						obj.cash -= cash;
					else
						cout << "\n\t>>SORRY! INSUFFICIENT FUNDS!<<" << endl;

					cout << "\n\tYour cash is PHP " << obj.cash << endl;
					cout << endl;
					break;
				case '3':
					userMenu();
					break;
				}
				int pos = (-1) * static_cast<int>(sizeof(obj));
				file.seekp(pos, ios::cur);
				file.write((char*)&obj, sizeof(obj));
				file.close();
				cout << "\n\t===Updated Record===\n";
				found = true;
			}
		}
	}		
	if (found == false)
	{
		cout << "\n\n\tRecord Not Found... ";
	}
}

void Bank::del()
{
	system("CLS");
	bool found = false;
	cout << "\n\tEnter the Account Number(ID) for deletion: \n\t";
	cin >> id;

	file.open("database.txt", ios::in);
	temp.open("Temp.txt", ios::binary);
	file.seekg(0, ios::beg);

	while (file.read((char*)&obj, sizeof(obj)))
	{
		if (obj.ID != id)
		{
			temp.write((char*)&obj, sizeof(obj));
		}
	}
	file.close();
	temp.close();
	remove("database.txt");
	rename("temp.txt", "database.txt");
	cout << "\n\tThe account has been deleted...";
}