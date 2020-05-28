#include <iostream>
#include <string>
#include "structures.h"
using namespace std;

void Welcoming()
{
		cout << "     /////////////    ///////////       ////////      /////////////    ///////////" << endl;
		cout << "    ////    /////   ////              ////           ////    /////       ////" << endl;
		cout << "   ////    /////   ////             ////            ////    /////       ////" << endl;
		cout << "  /////////////   ////     /////   ////            /////////////       ////" << endl;
		cout << " ////              ////     ////   ////           ////                ////" << endl;
		cout << "////                ///////////     /////////    ////             ///////////" << endl;

}


bool checkPassword(string password)
{
	int countSmallLetters = 0;
	int countBigLetters = 0;
	for (int i = 0; i < password.size(); i++)
	{
		if (password[i] >= 'A' && password[i] <= 'Z')
		{
			countBigLetters++;
		}
		else if (password[i] >= 'a' && password[i] <= 'z')
		{
			countSmallLetters++;
		}
	}
	if (password.size() < 8 || countSmallLetters == 0 || countBigLetters == 0)
	{
		return 0;
	}
	return 1;
}

bool checkForExistingUsername(string username, int count, USER users[])
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].username == username)
		{
			return 1;
		}
	}
	return 0;
}

void registration(int& count, USER* users)
{
	cout << "First Name: ";
	cin >> users[count].fName;
	cout << "Second Name: ";
	cin >> users[count].sName;
	cout << "Third Name: ";
	cin >> users[count].lName;
	cout << "telephone number: ";
	cin >> users[count].phoneNumber;
	cout << "USN: ";
	cin >> users[count].USN;
	cout << "Username: ";
	cin.ignore();
	getline(cin, users[count].username);

	while (checkForExistingUsername(users[count].username, count, users))
	{
		cout << "This username is already taken!" << endl;
		cout << "Try with another username: ";
		cin.ignore();
		getline(cin, users[count].username);
	}
	cout << "Password: ";
	getline(cin, users[count].password);
	while (!checkPassword(users[count].password))
	{
		cout << "Your password must have at least 8 symbols, 1 small letter and 1 big letter" << endl;
		cout << "Try with another password: ";
		cin.ignore();
		getline(cin, users[count].password);
	}
	count++;
}



bool grantAccess(string username, string password, int count, USER *users)
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].username == username && users[i].password == password)
		{
			return 1;
		}
	}
	return 0;
}

void login(int count, USER* users)
{
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	if (grantAccess(username, password, count, users))
	{

	}
}


void Deposit(USER* users)
{

}

bool subMenu(int& count, USER* users)
{
	cout << "1. Deposit" << endl;
	cout << "2. Withdraw" << endl;
	cout << "3. Show current balance" << endl;
	cout << "4. Show interest" << endl;
	cout << "5. Sign out" << endl;

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		break;

	case 2:
		break;

	case 3:
		break;

	case 4:
		break;

	case 5: return 0;
		break;

	default:
		break;
	}
}

bool mainMenu(int& count, USER* users)
{
	int choice;
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "9. Exit" << endl;

	cin >> choice;
	switch (choice)
	{
	case 1:registration(count, users);

		break;

	case 2: login(count, users);
		subMenu(count, users);
		break;

	default:
		break;

	case 9: return 0;
	}
	return 1;
}