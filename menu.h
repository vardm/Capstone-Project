#pragma once
#include <iostream>
#include "Update.h"
#include "Search.h"
#include "add.h"
#include <conio.h>
void MainMenu();

#define KEY_UP 72 // up on keypad
#define KEY_DOWN 80 // down on keypad
#define KEY_LEFT 75 // currently not used
#define KEY_RIGHT 77 // right on keypad

int menukey1(int x)
{
	int c = 0, y = 0;

	if (x != 10 && x != 20 && x != 30 && x != 40 && x != 50 && x != 60) // this checks if it is 11 , 21 , 31 , 41 , 51 or any other value , it will then subtract 1 if it is
	{
		x = x - 1;
		if (x != 10 && x != 20 && x != 30 && x != 40 && x != 50 && x != 60) // if it still isn't any predefined value it will be reset to 20 to prevent issues
		{
			;
			x = 20;
		}
	}
	x = x / 10; // it will divide by 10 so 50 -> 5 40 -> 4 ,etc

	switch ((c = _getch())) {
	case KEY_UP:
		if (x == 2 || x == 3 || x == 4 || x == 5 ) // this is to prevent x from being lower than 1
		{
			x--; // if the up key is pressed then 5 will be 4 , 3 will be 2 , etc and it will look like it is going up
		}
		else if (x == 1)
		{
			x = 5;
		}

		break;
	case KEY_DOWN:

		if (x == 1 || x == 2 || x == 3 || x == 4 )// this is to make sure that x isn't more than 5
		{
			x++; // if the down key is pressed then 4 will be 5 , 3 will be 4 , etc and it will look like it is going down
		}
		else if (x == 7)
		{
			x = 1;
		}

		break;

	case KEY_RIGHT:
		// this is how an option is chosen

		y = 1;

		break;
	}
	x = x * 10; // x is multiplied back by ten and then has 1 added so only one value can be input and output
	x = x + y;
	return x;
}

void MainMenu()
{
	bool mmenu = true;
	int x = 20;
	while (mmenu == true)

	{
		system("cls");

		if (x == 10 || x == 11) // the text with the bracket is what will be displayed if the x from keyinput is that number , its what is currently chosen
		{
			std::cout << "[  Add Assignment  ]\n";
		}
		else
		{
			std::cout << "   Add Assignment   \n";
		}

		if (x == 20 || x == 21)
		{
			std::cout << "[  Update Assignment  ]\n";
		}
		else
		{
			std::cout << "   Update Assignment  \n";
		}

		if (x == 30 || x == 31)
		{
			std::cout << "[  Search Assignment  ]\n";
		}
		else
		{
			std::cout << "   Search Assignment  \n";
		}

		if (x == 40 || x == 41)
		{
			std::cout << "[  Settings  ]\n";
		}
		else
		{
			std::cout << "   Settings  \n";
		}

		if (x == 50 || x == 51)
		{
			std::cout << "[  Exit Program  ]\n";
		}
		else
		{
			std::cout << "   Exit Program  \n";
		}

		if (x == 11) // todo add assignment
		{
			addassignment();
		}
		else if (x == 21) // todo update assignment
		{
			int anumb;
			printf("Enter the assignment number of the assignment you want to update\n");
			std::cin >> anumb;
			
			std::string course;
			printf("Enter the name of the course  you want to update\n");
			std::cin >> course;
			
			UpdateAssignment(course,anumb);
		}

		else if (x == 31) // todo search assignment
		{
			Search();
		}

		else if (x == 41) // settings option
		{
			system("color 1F");
		}

		else if (x == 51)
		{
			mmenu = false;

			// quit option , thats it
		}

		x = menukey1(x);
	}
}
