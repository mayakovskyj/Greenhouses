//CREATOR MARIA KOROL, K-11

#include <iostream>
#include <cstdlib>     
#include "copyright.h"
#include "GreenhouseChoice\choice.h"
#include "outputFunctions.h"
#include "programm1.h"

using namespace std;

int main() {
	copyright();
	cout << "\n\t\tLab number 3: 'Greenhouse2', programm number 1\n";
	try {
		Greenhouse *MyGreenhouse = CreateGreenhouse();
		cout << (*MyGreenhouse).version();
		programm1(MyGreenhouse);
		delete MyGreenhouse;
	}
	catch (bad_alloc) {
		cout << "Wrong input! Your visit is ended, sorry :(\n"; system("pause");return 0;
	}
	system("pause");
	return 0;
} 
