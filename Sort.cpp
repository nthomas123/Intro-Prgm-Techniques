// assignment8.cpp : Defines the entry point for the console application.
//Noble Thomas

/*
-Write a program that will prompt the user for the full path of a file
-That file will contain a list of string values
-Read in each line of the file, and store the contents in a vector of string type
-Display the unsorted list using the displayList function 

-Repeat this until #3 is chosen
-Prompt the user, asking what sort to use: Bubble Sort or Quick Sort
	1 for Bubble sort
	2 for Quick sort
	3 to quit

-Then display the sorted list
-When 3 is chosen, then display the unsorted list again; then quit the program 
*/
#include "stdafx.h"
#include <iostream>
#include<fstream>
#include <vector>
#include <string>
using namespace std;

//Call the function before execution
void bubbleSort(vector<string> &list);
void displayList(string, vector<string> &);
void quickSort(vector<string> &list, int leftStart, int rightStart);

//Function that holds bubble sort
void bubbleSort(vector<string> &list)
{
	// The position of the point we'll stop for a pass in the algorithm
	int pos = list.size() - 1;
	bool swapped = false;
	do {
		// Initialize it to mean:  We have not swapped anything in this pass
		swapped = false;

		// For each element below what we've already sorted
		for (int i = 0; i < pos; i++) {
			// If this pair of elements is out of order
			if (list[i] > list[i + 1]) {
				string temp = list[i]; // Hold on to the left element value
				list[i] = list[i + 1]; // Set left element equal to right value
				list[i + 1] = temp;    // Set right element equal to left value
				swapped = true;  // Indicate that we swapped an out-of-order pair
			}
		}
		pos--;  // Allows us to not bother with the elements already sorted
	} while (swapped); // Stay in loop until we did NOT need to swap anything
}
//Function that displays list
void displayList(string label, vector<string> &list)
{
	cout << label << ": " << endl;
	for (string element : list) {
		cout << element << endl;
	}
	cout << endl;
}
int choosePivotIndex(int leftStart, int rightStart) {
	int pivotIndex = (leftStart + rightStart) / 2;

	return pivotIndex;
}
//function that holds Quick sort
void quickSort(vector<string> &list, int leftStart, int rightStart)
{
	// The left and righ markers are set to the endpoints of this list segment
	int leftMarker = leftStart;
	int rightMarker = rightStart;

	/*
	* Choose the pivot value
	* We are choosing the value stored in between the two starting indices
	*/
	int pivotIndex = choosePivotIndex(leftStart, rightStart);
	string pivotValue = list[pivotIndex];

	// While the two markers do not meet
	while (leftMarker <= rightMarker) {

		// Keep moving right until you find a value less than the pivot value
		while (list[leftMarker] < pivotValue) {
			leftMarker++;
		}

		// Keep moving left until you find a value greater than the pivot value
		while (list[rightMarker] > pivotValue) {
			rightMarker--;
		}

		// If leftMarker and rightMarker did not meet, then swap the marked values
		if (leftMarker <= rightMarker) {
			// Swap the values at indices leftMarker and rightMarker
			string tmp = list[leftMarker];
			list[leftMarker] = list[rightMarker];
			list[rightMarker] = tmp;

			// Move each marker over the swapped values
			leftMarker++;
			rightMarker--;
		}
	};

	// If more to sort on the right side...
	if (leftStart < rightMarker) {
		quickSort(list, leftStart, rightMarker);
	}

	// If more to sort on the left side...
	if (leftMarker < rightStart) {
		quickSort(list, leftMarker, rightStart);
	}
}



int main()
{
	//Contain file
	string filePath;

	//Promt user for full path
	cout << "Enter a fullpath for a file:" << endl;
	cin >> filePath;

	//Opens the file
	ifstream list(filePath);

	//Stores one name from input file
	string name;

	// Hold all the names from file
	vector<string> names;

	//While not at the end of file
	while (!list.eof()) {
		getline(list, name);
		names.push_back(name);
	}

	//Displays from list
	cout << "Names read from file: " << endl;
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << endl;
	}

	//Promts the user for options to sort
	float choice;
	cout << "Which type of sort would you like to do?" << endl;
	cout << "1 = Bubble Sort" << endl;
	cout << "2 = Quick Sort" << endl;
	cout << "3 = Quit" << endl;
	cin >> choice;
	// Performs a specific task based on users input
		// Option 1
	if (choice = 1) {
		bubbleSort(names);
	}
	// Option 2
	else if (choice = 2) {
		void quickSort(vector<string> &list, int leftStart, int rightStart);
	}
	// Option 3
	else if (choice = 3) {
		return 0;
	}
	system("pause");
	return 0;
}

