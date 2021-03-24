//CSC 326
//VI EDITOR PHASE 1
//GROUP MEMBERS: DEANNA MANDARINO, VICTORIA JACZYNSKI, SIMON CHRISTIAN, BILL ZHOU

// Task: Write an Editor class that has an instance of our LinkedList
// Use command line arguments - the user will specify the file (if it exists)
// Code a constructor for the Editor class with one parameter for the file name - read it in and add to the linked list 
// Allow for the following commands:  :q   :w


#ifndef Position_H
#define Position_H

class Position {
public:
     Position();
     Position(int, int);
     void setX(int);
     void setY(int);
     int getX() const;
     int getY() const;
     void display() const;
private:
     int mX;
     int mY;
};
#endif
