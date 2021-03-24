//CSC 326
//VI EDITOR PHASE 1
//GROUP MEMBERS: DEANNA MANDARINO, VICTORIA JACZYNSKI, SIMON CHRISTIAN, BILL ZHOU

// Task: Write an Editor class that has an instance of our LinkedList
// Use command line arguments - the user will specify the file (if it exists)
// Code a constructor for the Editor class with one parameter for the file name - read it in and add to the linked list 
// Allow for the following commands:  :q   :w

#include "Position.h"
#include <iostream>
using namespace std;

Position::Position() {
	x = 0; y = 0;
}
Position::Position(int mX, int mY) {
	x = mX; y = mY;
}
void Position::setX(int mX) {
	x = mX;
}
void Position::setY(int mY) {
	y = mY;
}
int Position::getX()const {
	return x;
}
int Position::getY()const {
	return y;
}
void Position::display() const {
	cout << "(" << x << ", " << y << ")" << endl;
}
