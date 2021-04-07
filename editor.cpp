//Editor.cpp file
//CSC 326
//VI EDITOR PHASE 1
//GROUP MEMBERS: DEANNA MANDARINO, VICTORIA JACZYNSKI, SIMON CHRISTIAN, BILL ZHOU

// Task: Write an Editor class that has an instance of our LinkedList
// Use command line arguments - the user will specify the file (if it exists)
// Code a constructor for the Editor class with one parameter for the file name - read it in and add to the linked list 
// Allow for the following commands:  :q   :w


#include "Editor.h"
#include "ListInterface.h"
#include "Position.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
void placeCursorAt(Position coordinate); //function prototype
using namespace std;

Editor::Editor() {
}//end default constructor

Editor::Editor(string _fileName) {
	ifstream inFile(_fileName);
	string readLine;
	fileName = _fileName;
	int lineCounter = 1;

	/*Exits when file is not found*/
	if (inFile.fail()) {
		cout << "File cannot be found.";
		exit(1);
	}
	/*Reads each line of the file*/
	while (!inFile.eof()) {
		getline(inFile, readLine);
		lines.insert(lineCounter, readLine);
		lineCounter++;
	}
}

int binarySearch(const int areaCodesarray[], int first, int last, int areaCode) //function definition
{
	int index;
	if (first > last)
		index = -1;
	else
	{
		int mid = first + (last - first) / 2;
		if (areaCode == areaCodesarray[mid])
			index = mid;
		else if (areaCode < areaCodesarray[mid])
			index = binarySearch(areaCodesarray, first, mid - 1, areaCode);
		else
			index = binarySearch(areaCodesarray, mid + 1, last, areaCode);
	}
	return index;
	/*We send this function the array with the area codes, first (which is set equal to 0 because
	an array starts at 0), last (which is equal to 311 because there are 312 area codes in the .txt
	file but you subtract 1 because an array starts at 0 not 1), and the area code that the user
	inputted*/
	/*This function returns the index (which is equal to the mid) because it will return the element
	number from the array that matches the inputted area code. It basically just shows that this inputted
	area code is in our program*/
	/*The purpose of this function is to search through our area codes array to find an exact match to
	the inputted area code*/
}

void Editor::displayLines() {
	/*Clear screen to display text file*/
	system("CLS");
	for (int i = 1; i < lines.getLength(); i++) {
		cout << lines.getEntry(i) << endl;
	}
}

void Editor::run() {
	/*Initialize cursor position (0,0)*/
	Position cursor;
	displayLines();
	placeCursorAt(cursor);

	char entry;
	/*System function which gets the character*/
	entry = _getch();

	if (entry == ':') {
		cursor.setX(0);
		cursor.setY(lines.getLength()+5);
		placeCursorAt(cursor);
		cout << entry;
		entry = _getche();

		/*q quits the Editor and closes the file*/
		if (entry == 'q') {
			inFile.close();
			cout << "\nClosing the file was successful." << endl;
		}
		else if (entry == 'w') {
			/*Does something*/
		}
	}

}
/*This is not a member function but a package for Editor*/
/*Initializes the cursor*/
void placeCursorAt(Position coordinate) {
	COORD coord;
	coord.X = coordinate.getX();
	coord.Y = coordinate.getY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
