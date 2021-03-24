//CSC 326
//VI EDITOR PHASE 1
//GROUP MEMBERS: DEANNA MANDARINO, VICTORIA JACZYNSKI, SIMON CHRISTIAN, BILL ZHOU

// Task: Write an Editor class that has an instance of our LinkedList
// Use command line arguments - the user will specify the file (if it exists)
// Code a constructor for the Editor class with one parameter for the file name - read it in and add to the linked list 
// Allow for the following commands:  :q   :w

#include<iostream>
#include "Position.h"
using namespace std;

Position::Position()
{
     mX = 0;
     mY = 0;
}

Position::Position(int x, int y)
{
     mX = x;
     mY = y;
}

void Position::setX(int x)
{
     mX = x;
}

void Position::setY(int y)
{
     mY = y;
}

int Position::getX() const
{
     return mX;
}

int Position::getY() const
{
     return mY;
}

void Position::display() const
{
     cout << "(" << mX << "," << mY << ")" << endl;
}
