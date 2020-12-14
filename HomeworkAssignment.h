#pragma once
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <vector>

class homeworkAssignment {
private:
	std::string course;
	int dueDate;
	int estimatedTime;
	int homeworkNumber;
	bool inProgress;
	bool isCompleted;

public:
	homeworkAssignment(std::string c, int dd, int et, int hwNumber, bool ip) {
		this->course = c;
		this->dueDate = dd;
		this->estimatedTime = et;
		this->homeworkNumber = hwNumber;
		this->inProgress = ip;
		this->isCompleted = false;
	}
	int getDueDate() {
		return dueDate;
	}
	std::string getCourse() {
		return course;
	}
	int getHomeworkNumber() {
		return homeworkNumber;
	}
	bool getprogress()
	{
		return inProgress;
	}
	void seprogress(int check) // start / end assignment 1 is true , 0 is false
	{
		if (check == 1)
		{
			inProgress = true;
		}
		else if (check == 0)
		{
			inProgress == false;
		}
	}
	void seassignment(int check) // start / end assignment 1 is true , 0 is false
	{
		if (check == 1)
		{
			isCompleted = true;
		}
		else if (check == 0)
		{
			isCompleted == false;
		}
	}
};

class homeworkManagementSystem {
private:
	std::vector<homeworkAssignment> hms;
public:
	void ADDAssignment(std::string c, int date, int estTime, int hwNum, bool ip) {
		hms.push_back(homeworkAssignment(c, date, estTime, hwNum, ip));
	}

	void searchDueDate(int date) {
		std::cout << "Assignments due in " << date << " days:\n";
		for (int i = 0; i < hms.size(); i++)
		{
			if (hms[i].getDueDate() == date) {
				std::cout << "Course: " << hms[i].getCourse() << " Homework Number: " << hms[i].getHomeworkNumber() << std::endl;
			}
		}
	}
	void searchByCourse(std::string course) {
		for (int i = 0; i < hms.size(); i++) {
			if (hms[i].getCourse() == course) {
				std::cout << "Course found: " << hms[i].getCourse() << std::endl;
				std::cout << "Course homework number : " << hms[i].getHomeworkNumber() << std::endl;
				std::cout << "Course due date: " << hms[i].getDueDate() << std::endl;
			}
			else if (i == hms.size() && hms[i].getCourse() != course) {
				std::cout << "Course not found!" << std::endl;
			}
		}
	}
	void displayprogress(int i)
	{
		int size;
		size = hms.size();
		if (i == size) {
			return;
		}
		if (hms[i].getprogress() == true)
		{
			std::cout << "Course: " << hms[i].getCourse() << " Homework Number: " << hms[i].getHomeworkNumber() << " Days due: " << hms[i].getDueDate() << std::endl;
		}
		displayprogress(i + 1);
	}
	void displayall(int i)
	{
		int size;
		size = hms.size();
		if (i == size) {
			return;
		}
			std::cout << "Course: " << hms[i].getCourse() << " Homework Number: " << hms[i].getHomeworkNumber() << " Days due: " << hms[i].getDueDate() << std::endl;
		displayall(i + 1);
	}


	void update(std::string course, int asnum, int check1, int check2) // needs both course and assignment number , check1 is seprogress and check2 is seassignment
	{
		for (int i = 0; i < hms.size(); i++)
		{
			if (hms[i].getCourse() == course && hms[i].getHomeworkNumber() == asnum)
			{
				if (check1 == 1 || check1 == 2 || check1 == 3)
				{
					if (check1 == 3)
					{
						hms[i].seprogress(1);
					}
					else if (check1 == 2)
					{
						hms[i].seprogress(0);
					}
				}
				if (check2 == 1 || check2 == 2 || check2 == 3)
				{
					if (check1 == 3)
					{
						hms[i].seprogress(1);
					}
					else if (check1 == 2)
					{
						hms[i].seprogress(0);
					}
				}
				if (check1 == 5 && check2 == 5)
				{
					hms.erase(hms.begin() + i);
				}
			}
		}
	}
};

homeworkManagementSystem hwmanage; 