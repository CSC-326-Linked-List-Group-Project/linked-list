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
void placeCursorAt(Position coordinate);
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
		entry = _getch();
		/*q quits the Editor and closes the file*/
		if (entry == 'q') {
			entry = _getche();
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
