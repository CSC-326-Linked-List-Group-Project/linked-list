#include "LinkedList.h"
#include <Windows.h>
#include <string>
#include <fstream>
#ifndef EDITOR_H
#define EDITOR_H
using namespace std;

class Editor {
private:
	ifstream inFile;
	LinkedList<string> lines;
	string fileName;
public:
	/*Default Constructor*/
	Editor();
	/*General Constructor*/
	Editor(string _fileName);
	/*Displays Lines*/
	void displayLines();
	void run();
};
#include "Editor.cpp"
#endif
