#include "Menu.h"

void main()
{
	Menu *main = new Menu();
	main->display_menu();
	delete main;
	exit(0); // delete all and exit the program
}