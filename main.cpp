//CSC 326
//SI EDITOR PHASE 1
//GROUP MEMBERS: DEANNA MANDARINO, VICTORY JACZYNSKI, SIMON CHRISTIAN, BILL ZHOU
#include "LinkedList.h"
#include "Editor.h"
#include <iostream>
#include <string>

void main(int argc, const char* argv[]) {

	if (argc > 1) {
		Editor si(argv[1]);
	}
	else
		exit(1);
}
