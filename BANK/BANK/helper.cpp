#include <iostream>
#include <string>
#include <stdlib.h>
#include "structures.h"
using namespace std;

void checkForWrongInput(double variable) //Makes you enter a new option until you have entered a correct one
{
	while (cin.fail())
	{
		cout << "Enter a number, please!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> variable;
	}
}

bool showRules()//Shows rules about interest and withdrawing
{
	int choice;
	cout << "See about: " << endl;
	cout << "1. Overdrafting" << endl;
	cout << "2. Interest" << endl;
	cout << "9. Exit" << endl;
	cout << "Your choice: ";
	cin >> choice;
	switch (choice)
	{
		case 1:
		cout << "How does an overdraft work?" << endl;
		cout << "An overdraft lets you borrow money through your current account by taking out more money than you have in the account."<<endl;
		cout << "There’s usually a charge for this." << endl;
		cout << "You can ask your bank for an overdraft – or they might just give you one – but don’t forget that an overdraft is a type of loan." << endl;
		cout << "If you need to borrow money, there might be cheaper ways to do it. It’s important to always find the cheapest way to borrow." << endl;
		cout << "You have to give back the money you have overdrafted."<<endl;
		break;
		
		case 2:
		cout << "Interest’s rule, which is also referred to as the Interest rule or Taylor principle, is a proposed guideline for how central banks," << endl;
		cout << "such as the Federal Reserve, should alter interest rates in response to changes in economic conditions." << endl;
		cout << "Interst’s rule, introduced by economist Chavdar Interest, was established to adjustand set prudent rates for the short - term stabilization of the economy,"<<endl;
		cout << "while still maintaining long - term growth.The rule is based on three factors:" << endl;
		cout << "1. Targeted versus actual inflation levels" << endl;
		cout << "2. Full employment versus actual employment levels" << endl;
		cout << "3. The short-term interest rate appropriately consistent with full employment" << endl;
		break;

		case 9: return 0;
		break;

	default: break;
	
	}
	return true;
}

void welcome() //Startup text
{
	cout << " _______________________________________________________________________________________________" << endl;
	cout << "|                                                                                               |" << endl;
	cout << "|               ////////////    ///////////       /////////     ////////////    ///////////     |" << endl;
	cout << "|              ////    ////   ////              ////           ////    ////       ////          |" << endl;
	cout << "|             ////    ////   ////             ////            ////    ////       ////           |" << endl;
	cout << "|            ////////////   ////     /////   ////            ////////////       ////            |" << endl;
	cout << "|           ////              ////     ////   ////          ////               ////             |" << endl;
	cout << "|          ////                ///////////     /////////   ////            ///////////          |" << endl;
	cout << "|                                                                                               |" << endl;
	cout << "|        ///////////       ////\\\\\\\\               ////////      ////   ////////    //////       |" << endl;
	cout << "|       ////     ////     ////  \\\\\\\\             //// ////     ////       ////   ////           |" << endl;
	cout << "|      ////     ////     ////    \\\\\\\\           ////  ////    ////       ////  ////             |" << endl;
	cout << "|     //////////        ///////\\\\\\\\\\\\\\         ////   ////   ////       ////////                |" << endl;
	cout << "|    ////     ////     ////        \\\\\\\\       ////    ////  ////       ////  ////               |" << endl;
	cout << "|   ////     ////     ////          \\\\\\\\     ////     //// ////       ////    ////              |" << endl;
	cout << "|  ////////////      ////            \\\\\\\\   ////       ///////       ////      /////            |" << endl;
	cout << "|_______________________________________________________________________________________________|";
	cout << endl << endl;
}

bool checkPassword(string password) //Checks if your password contains small and big letters
{
	int countSmallLetters = 0;
	int countBigLetters = 0;
	for (size_t i = 0; i < password.size(); i++)
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

int findUserByUsername(string username, int count, USER* users) //Checks if you entered your Username and Password Correctly
{
	for (int i = 0; i < count; i++)
	{
		if (users[i].username == username)
		{
			return i;
		}
	}
	return -1;
}

void registration(int& count, USER* users) //creating user account
{
	cout << "First Name: ";
	cin >> users[count].fName;
	cout << "Second Name: ";
	cin >> users[count].sName;
	cout << "Third Name: ";
	cin >> users[count].lName;
	cout << "telephone number: ";
	cin >> users[count].phoneNumber;
	checkForWrongInput(users[count].phoneNumber);
	cout << "USN: ";
	cin >> users[count].USN;
	checkForWrongInput(users[count].USN);
	cout << "Username: ";
	cin.ignore();
	getline(cin, users[count].username);

	while (findUserByUsername(users[count].username, count, users) != -1)
	{
		cout << "This username is already taken!" << endl;
		cout << "Try with another username: ";
		getline(cin, users[count].username);
	}
	cout << "Password: ";
	getline(cin, users[count].password);
	while (!checkPassword(users[count].password))
	{
		cout << "Your password must have at least 8 symbols, 1 small letter and 1 big letter" << endl;
		cout << "Try with another password: ";
		getline(cin, users[count].password);
	}
	count++;
}

bool grantAccess(string username, string password, int count, USER* users) //Checks if you 
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

void deposit(USER* users, int user) //Deposit money
{
	welcome();
	cout << "Deposit sum: ";
	float depositSum;
	cin >> depositSum;
	checkForWrongInput(depositSum);
	(users[user].money) = (users[user].money) + depositSum;
}

void withdraw(USER* users, int user) //Withdraw money
{
	welcome();
	cout << "Withdraw sum: ";
	float withdrawSum;
	cin >> withdrawSum;
	checkForWrongInput(withdrawSum);
	(users[user].money) -= withdrawSum;
}

void showCurrentBalance(USER* users, int count, int user) //Shows your current balance
{
	welcome();
	cout << "The current balance is: ";
	cout << users[user].money<<"$"<<endl<<endl;
}

void showinterest(USER* users, int count, int user) //Shows what would be your balance after a certain amount of years
{
	welcome();
	const double interest = 0.05;
	double sum = 0;
	int years;
	cout << "Years ahead: ";
	cin >> years;
	checkForWrongInput(years);
	for (int i = 0; i < years; i++)
	{
		sum += ((users[user].money) * (1 + interest));
	}
	cout <<"You will have: "<< sum<<" $" <<" after "<<years<<" years"<<" with interest of "<<interest*100<<"% "<< endl<<endl;
}

void overdraft()
{
	welcome();
	int maxOverdraft = 1000000;

}

bool subMenu(int& count, USER* users, int user) //SubMenu that shows different options
{
	cout << "1. Deposit" << endl;
	cout << "2. Withdraw" << endl;
	cout << "3. Show current balance" << endl;
	cout << "4. Show interest" << endl;
	cout << "9. Sign out" << endl;

	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	system("cls");
	checkForWrongInput(choice);
	switch (choice)
	{
	case 1: deposit(users, user);
		system("cls");
		welcome();
		break;

	case 2:withdraw(users, user);
		system("cls");
		welcome();
		break;

	case 3:showCurrentBalance(users, count, user);
		break;

	case 4:showinterest(users, count, user);
		break;

	case 9: return 0;
		break;

	default:cout << "Try choosing an available option. :)" << endl << endl;
		break;
	}
	return 1;
}

void login(int& count, USER* users) //Login System
{
	int wrongCounter = 0;
	string username, password;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
	while (!grantAccess(username, password, count, users) && wrongCounter!=3)
	{
		cout << "Your username/password is incorrect" << endl;
		cout << "Please try again" << endl;
		cout << "Username: ";
		cin >> username;
		cout << "Password: ";
		cin >> password;
		wrongCounter++;
	}
	int user = findUserByUsername(username, count, users);
	if (grantAccess(username, password, count, users) && wrongCounter!=3)
	{
		system("cls");
		welcome();
		bool showMenu;
		do
		{
			showMenu = subMenu(count, users, user);
		} while (showMenu);
	}
}

bool mainMenu(int& count, USER* users) //The menu that goes right after the startup text
{
	welcome();
	int choice;
	cout << "1. Register" << endl;
	cout << "2. Login" << endl;
	cout << "3. Take a look at our rules" << endl;
	cout << "9. Exit" << endl;
	cout << "Enter your choice: ";

	cin >> choice;
	checkForWrongInput(choice);
	switch (choice)
	{
	case 1:registration(count, users);
		break;

	case 2: login(count, users);
		break;

	default:cout << "Try choosing an available option!"<<endl<<endl;
		break;

	case 9: return 0;

	}
	return 1;
}