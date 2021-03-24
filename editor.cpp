#include "Editor.h"
#include "ListInterface.h"
#include "Position.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
void placeCursorAt(Position coordinate); //Not a method of Editor but a package with Editor
using namespace std;

Editor::Editor() {
}//end default constructor

Editor::Editor(string _fileName) {
	ifstream inFile(_fileName);
	string readLine;
	fileName = _fileName;
	int lineCounter = 1;

	if (inFile.fail()) {
		cout << "File cannot be found.";
	}
	while (!inFile.eof()) {
		getline(inFile, readLine);
		lines.insert(lineCounter, readLine);
		lineCounter++;
	}
}

void Editor::displayLines() {
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
		
		entry = _getche();
		if (entry == 'q') {
			inFile.close();
			cout << "\nsuccess" << endl;
		}
		else if (entry == 'w') {
			/*Does something*/
		}
	}

}

void placeCursorAt(Position coordinate) {
	COORD coord;
	coord.X = coordinate.getX();
	coord.Y = coordinate.getY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
