#include <iostream>
#include <stdlib.h>
#include "helper.h"
#include "structures.h"
using namespace std;

int main()
{
	system("color b");

	USER users[64];

	int count = 0;

	bool showMenu = true;
	do
	{
		showMenu = mainMenu(count,users);
		system("cls");

	} while (showMenu);

}
