//CREATOR MARIA KOROL, K-11

#include "programm1.h"
#include "outputFunctions.h"
#include <cstdlib>   
#include <iostream>

using namespace std;

void programm1(Greenhouse* MyGreenhouse) {
	int choice;
	bool exitGreenhouse = true;
	menu();
	cout << (*MyGreenhouse).info() << endl; cout << endl;

	do {
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			choice = -1;
		}
		menuOptions1(choice, MyGreenhouse, exitGreenhouse);
		cout << (*MyGreenhouse).info() << endl; cout << endl;
	} while (exitGreenhouse);
}