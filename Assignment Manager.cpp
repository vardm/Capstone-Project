

#include <iostream>
#include "menu.h"

int main()
{
	printf("Assignment Manager 2020\nWritten for BCS-370 Capstone\nWritten By:\n	     Anthony Weathers\n	     Michael Vardanian\n	     Nicholas Poje\n\n\n\n     [");
	for (int i = 0; i < 25; i++)
	{
		printf("X");
		Sleep(150);
	}
	printf("]");
	Sleep(250);
	system("cls");
	printf("Use the up arrow key to move up\nThe down arrow key to move down\nThe right arrow key to proceed / enter\nAnd the left arrow key to return / go back to previous\n");
	Sleep(2500);
	printf("\n\nPress any key when you are ready to begin\n\n");
	system("pause");
	MainMenu();
	system("cls");
	printf("Thank you for using Assignment Manager 2020\n\nWritten By:\nAnthony Weathers\nMichael Vardanian\nNicholas Poje\n");
	Sleep(2500);
	printf("Goodbye\n");
}