//CREATOR MARIA KOROL, K-11

#include "choice.h"
#include <iostream>

using namespace std;

Greenhouse * CreateGreenhouse() {
	int choice;
	cout << "Hello! Choose your greenhouse's model. There are 3 avaliable versions:\n";
	cout << "Press '1' to choose greenhouse version 1.0: Default greenhouse.\n";
	cout << "Press '2' to choose greenhouse version 2.0: Tropic greenhouse.\n";
	cout << "Press '3' to choose greenhouse version 3.0: Arctic greenhouse.\n";
	cout << "If your input is incorrect, the visit will be ended forcibly\n\n";
	cin >> choice;
	switch (choice) {
	case 1: return new Greenhouse1(); break;
	case 2: return new Greenhouse2(); break;
	case 3: return new Greenhouse3(); break;
	default: throw (bad_alloc()); break;
	}
}











