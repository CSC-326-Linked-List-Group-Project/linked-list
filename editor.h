#include "LinkedList.h"
#include <Windows.h>
#include <string>
#ifndef EDITOR_H
#define EDITOR_H

class Editor {
private:
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
