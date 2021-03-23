#include "Editor.h"
#include "ListInterface.h"
#include "Position.h"
#include <iostream>
#include <fstream>
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
		throw invalid_argument("File cannot be located.");
		exit(1);
	}
	while (!inFile.eof()) {
		getline(inFile, readLine);
		lines.insert(lineCounter, readLine);
		lineCounter++;
	}
}

void Editor::displayLines() {

}

void Editor::run() {
	displayLines();

	bool run{ true };

	while (run) {
		
	}
}

void placeCursorAt(Position coordinate) {
	COORD coord;
	coord.X = coordinate.getX();
	coord.Y = coordinate.getY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
