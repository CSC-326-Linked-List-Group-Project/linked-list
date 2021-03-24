#include "Editor.h"
#include "ListInterface.h"
#include "Position.h"
#include <iostream>
#include <string>
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
	}
	while (!inFile.eof()) {
		getline(inFile, readLine);
		lines.insert(lineCounter, readLine);
		lineCounter++;
	}

	displayLines();
}

void Editor::displayLines() {
	for (int i = 1; i < lines.getLength(); i++) {
		cout << lines.getEntry(i) << endl;
	}
}

//void Editor::run() {
//	displayLines();
//
//	bool run{ true };
//
//	while (run) {
//		int argc;
//		const char* argv[2];
//		for(int i = 1; i <= argc; i++)
//		if (argc == 1) {
//			if (... == 'q') {
//				/*quits program*/
//			}
//			else if (... == 'w') {
//				/*save file*/
//			}
//		}
//	}
//}

void placeCursorAt(Position coordinate) {
	COORD coord;
	coord.X = coordinate.getX();
	coord.Y = coordinate.getY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
