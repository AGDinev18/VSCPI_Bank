#pragma once
#include "structures.h"
using namespace std;

////////////////Data Layer////////////////

void checkForWrongInput(double variable); //Makes you enter a new option until you have entered a correct one

bool checkPassword(string password); //Checks if your password contains small and big letters

int findUserByUsername(string username, int count, USER* users); //Checks if you entered your Username and Password Correctly

void registration(int& count, USER* users); //Creating user account

bool grantAccess(string username, string password, int count, USER* users); //Checks if you enter valid username and password


////////////////Presentation layer////////////////


void welcome(); //Header text

void deposit(USER* users, int user); //Deposit money

void withdraw(USER* users, int user); //Withdraw money

void showCurrentBalance(USER* users, int count, int user); //Shows your current balance

void showinterest(USER* users, int count, int user); //Shows what would be your balance after a certain amount of years

bool subMenu(int count, USER* users, int user); //Submenu that shows different options

void login(int count, USER* users); //Login System

bool showRules(); //Shows rules about interest and withdrawing

bool mainMenu(int& count, USER* users); //The menu that goes right after the startup text