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
