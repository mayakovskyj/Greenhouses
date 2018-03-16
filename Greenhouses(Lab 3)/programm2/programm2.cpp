//CREATOR MARIA KOROL, K-11

#include "programm2.h"
#include <cstdlib>   
#include <iostream>

using namespace std;

void programm2(Greenhouse* MyGreenhouse) {
	do {
		cout << (*MyGreenhouse).info() << endl; cout << endl;
		(*MyGreenhouse).timeIncrement1();
	} while ((*MyGreenhouse).OK());
	cout << (*MyGreenhouse).info() << endl;
	cout << "Time of Greenhouse working: " << (*MyGreenhouse).getTime() << " time units\n";
}