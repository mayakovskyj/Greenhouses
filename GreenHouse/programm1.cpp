//CREATOR MARIA KOROL, K-11

#include "programm1.h"
#include "greenhouse.h"
#include "outputFunctions.h"
#include <cstdlib>   
#include <iostream>

using namespace std;

void programm1() {
	int choice;
	bool exitGreenhouse = true;
	Greenhouse Gr;
	menu();
	cout << Gr.info() << endl; cout << endl;

	do {
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = -1;
		}
		menuOptions1(choice, Gr, exitGreenhouse);
		cout << Gr.info() << endl; cout << endl;
	} while (exitGreenhouse);
}