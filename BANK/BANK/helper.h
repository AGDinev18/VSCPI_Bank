#pragma once
#include "structures.h"
using namespace std;

void checkForWrongInput(double variable);

bool showRules();

void welcome();

bool checkPassword(string password);

int findUserByUsername(string username, int count, USER* users);

void registration(int& count, USER* users);

bool grantAccess(string username, string password, int count, USER* users);

void deposit(USER* users, int user);

void withdraw(USER* users, int user);

void showCurrentBalance(USER* users, int count, int user);

void showinterest(USER* users, int count, int user);

bool subMenu(int& count, USER* users, int user);

void login(int& count, USER* users);

bool mainMenu(int& count, USER* users);