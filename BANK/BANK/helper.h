#pragma once
#include "structures.h"
using namespace std;

void registration(int& count, USER* users);

bool checkPassword(string password);

bool checkForExistingUsername(string username, int count, USER users[]);

bool grantAccess(string username, string password, int count, USER* users);

void login(int count, USER *users);

void Welcoming();

bool subMenu(int& count, USER* users);

bool mainMenu(int& count, USER* users);