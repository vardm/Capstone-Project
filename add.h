#pragma once
#include <iostream>
#include "HomeworkAssignment.h"
#include <conio.h>

void addassignment();

void addassignment() // this function asks the user for the fields and will add it to the vector
{
	std::string coursename; // name of the course to be added
	int daysdue; // the due date for the course in days
	int assnumber; // the assignment number of the course
	int timeest; // estimated completion time
	int askprogress, askagain; // askprogress is used to ask the user if they want to mark the assignment as in progress and ask again asks the user if they want to enter another assignment
	bool inprogress, asscheck = true; // this marks if the assignment is in progress or not .. asscheck- assignment check is there to check if the assignment number has been used before

	system("cls");
	printf("What is the name of the course being added?\n");
	std::cin >> coursename;
	printf("\nHow many days from today is the assignment due?\n");
	std::cin >> daysdue;

	printf("\nHow long should it take to complete the assignment?\n");
	std::cin >> timeest;

	printf("\nWhat is the number of the assignment?\n");
	std::cin >> assnumber;

	printf("\nDo you want to mark the assignment as currently in progress?\n1.Yes\n2.No\n");
	std::cin >> askprogress;
	if (askprogress == 1)
	{
		inprogress = true;
	}
	else
	{
		inprogress = false;
	}
	system("cls");
	std::cout << "Course: " << coursename << "	\nDate Due: " << daysdue << "	\nEstimated Time: " << timeest << "	\nAssignment Number: " << assnumber << "	\nIn Progress: ";
	if (inprogress == true)
	{
		printf(" Yes ");
	}
	else
	{
		printf(" No \n");
	}
	hwmanage.ADDAssignment(coursename, daysdue, timeest, assnumber, inprogress);

	/*
	void addAssignment(std::string c, int date, int estTime, int hwNum, bool ip) {
		hms.push_back(homeworkAssignment(c, date, estTime, hwNum, ip));
	}
	*/

	printf("Do you want to add another assignment?\n\n1.Yes\n2.No\n");
	std::cin >> askagain;
	if (askagain == 1)
	{
		addassignment();
	}
}

/*
homeworkAssignment(std::string c, int dd, int hwNumber, bool ip)
	{
		this->course = c;
		this->dueDate = dd;
		this->homeworkNumber = hwNumber;
		this->inProgress = ip;
		this->isCompleted = false;
	}

	*/