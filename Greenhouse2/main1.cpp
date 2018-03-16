 //CREATOR MARIA KOROL, K-11

#include "copyright.h"
#include "greenhouse.h"
#include <cstdlib>   
#include <iostream>

using namespace std;

int main() {
	copyright();
	cout << "\n\t\tLab number 1: 'Greenhouse', programm number 2";
	Greenhouse Gr;
	do {
		cout << Gr.info() << endl; cout << endl;
		Gr.timeIncrement1();
	} while (Gr.OK());
	cout << Gr.info() << endl;
	cout << "Time of Greenhouse working: " << Gr.getTime() << " time units\n";
	system("pause");
	return 0;
}