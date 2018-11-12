// asssignment5.cpp : Defines the entry point for the console application.
/*
* Instructor: Phil O'Connell
* Noble Thomas

*/

#include "stdafx.h"
#include <iostream>
#include<fstream>
#include <vector>
#include <string>

using namespace std;
/*
-Write a program that prompts the user for the full path of a file
	Full path means the folder path and the file name
	This is a full path: C:\temp\my_files\input.txt
	This is a partial path: my_files\input.txt
	This is a file name: input.txt
	Your program will expect the user to type in a full path.
-The file will contain a list of names in the form last, first
		You can assume each line will either be correctly formatted like that, or blank
-You can assume the file exists
	However, the file may be empty, with no names
-Read in each line from the file
-Ignore blank lines
	Assume a blank line is nothing at all. Not even spaces or tabs.
-Store each name in a vector of strings
-Display the count of names
-Display the list of names back to the screen, but in the form first last
*/

//Reformats the Names
string reformatName(string fullName)
{
	int i = 0;
	string firstName, lastName;
	for (i = 0; fullName[i] != ' '; i++)
	{
		lastName += fullName[i];
	}
	for (i; fullName[i] != '\0'; i++)
	{
		firstName += fullName[i];
	}
	return firstName + " " + lastName;
}

int main()
{
	//Promts user for file name
	string fileNames;
	cout << "Enter file  path " << endl;
	cin >> fileNames;

	cout << endl;

//Reformated
	//Converts the file into a usable format 
	ifstream theFile(fileNames);
	//Stores Last Name
	string lastName;
	//Stores First Name
	string firstName;

// Orginal
	//Converts the file into a usable format
	ifstream theFile1(fileNames);
	// Stores Last Nem
	string lastName1;
	//Stores First Name
	string firstName1;

	//Counter Input
	ifstream counter(fileNames);
	string countName1;
	string countName2;

	//Counts the number of grades entered
	int count = 0;
	while (counter >> countName1 >> countName2) {
		count++;
	}
	//Display of Count Names
	cout << "Count of names: " << count << endl;
	cout << endl;

	//Program that displays the Input file
	cout << "THE NAMES READ FROM THE FILE: " << endl;
	while (theFile1 >> lastName1 >> firstName1) {
		string fullName1 = lastName1 + " " + firstName1;
		cout << fullName1 << endl;
	}

	cout << endl;
	
	//Program that displays the Output file
	cout << "HERE ARE THE REFORMATTED NAMES: " << endl;
	while (theFile >> lastName >> firstName) {
		string fullName = lastName + " " + firstName;
		string name = reformatName(fullName);
		cout << name << endl;
	}

	system("pause");
	return 0;
}




