#pragma once
#include <iostream>
#include "HomeworkAssignment.h"
#include <conio.h>
void Search();

#define KEY_UP 72 // up on keypad
#define KEY_DOWN 80 // down on keypad
#define KEY_LEFT 75 // currently not used
#define KEY_RIGHT 77 // right on keypad

int SearchMenu(int x)
{
	int c = 0, y = 0;

	if (x != 10 && x != 20 && x != 30 && x != 40) // this checks if it is 11 , 21 , 31 , 41 , 51 or any other value , it will then subtract 1 if it is
	{
		x = x - 1;
		if (x != 10 && x != 20 && x != 30 && x != 40) // if it still isn't any predefined value it will be reset to 20 to prevent issues
		{
			;
			x = 20;
		}
	}
	x = x / 10; // it will divide by 10 so 50 -> 5 40 -> 4 ,etc

	switch ((c = _getch())) {
	case KEY_UP:
		if (x == 2 || x == 3 || x == 4) // this is to prevent x from being lower than 1
		{
			x--; // if the up key is pressed then 5 will be 4 , 3 will be 2 , etc and it will look like it is going up
		}
		else if (x == 1)
		{
			x = 4;
		}

		break;
	case KEY_DOWN:

		if (x == 1 || x == 2 || x == 3)// this is to make sure that x isn't more than 5
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
	case KEY_LEFT:
		y = 50;
		x = 5;
	}
	x = x * 10; // x is multiplied back by ten and then has 1 added so only one value can be input and output
	x = x + y;
	return x;
}

void Search()
{
	bool SMenu = true;
	int x = 20;
	while (SMenu == true)

	{
		system("cls");

		if (x == 10 || x == 11) // the text with the bracket is what will be displayed if the x from keyinput is that number , its what is currently chosen
		{
			std::cout << "[  Search by Due Date  ]\n";
		}
		else
		{
			std::cout << "   Search by Due Date   \n";
		}

		if (x == 20 || x == 21)
		{
			std::cout << "[  Search by Course  ]\n";
		}
		else
		{
			std::cout << "   Search by Course  \n";
		}

		if (x == 30 || x == 31)
		{
			std::cout << "[  Display in Progress  ]\n";
		}
		else
		{
			std::cout << "   Display in Progress  \n";
		}
		if (x == 40 || x == 41)
		{
			std::cout << "[  Display All  ]\n";
		}
		else
		{
			std::cout << "   Display All  \n";
		}



		if (x == 11) // Due Date Search
		{
			int date;
			printf("How many days due do you want to search for?\n");
			std::cin >> date;
			hwmanage.searchDueDate(date);
		}
		else if (x == 21) // Search By Course
		{
			std::string course;
			printf("What course due do you want to search for?\n");
			std::cin >> course;

			hwmanage.searchByCourse(course);
		}

		else if (x == 31) // Display In Progress
		{
			std::cout << "Assignments in Progress " << std::endl;
			hwmanage.displayprogress(0);
		}
		else if (x == 41)
		{
			std::cout << "All Assignments\n" << std::endl;
			hwmanage.displayall(0);
		}

		else if (x == 100)
		{
			SMenu = false;

			// quit option , thats it
		}

		x = SearchMenu(x);
	}
}
