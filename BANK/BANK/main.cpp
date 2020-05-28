#include <iostream>
#include "helper.h"
#include "structures.h"
using namespace std;

int main(){
	Welcoming();

	USER users[100];

	int count = 0;

	bool showMenu = true;
	do
	{
		showMenu = mainMenu(count,users);

	} while (showMenu);

}
