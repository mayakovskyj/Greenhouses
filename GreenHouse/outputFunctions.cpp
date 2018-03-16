//CREATOR MARIA KOROL, K-11

#include <iostream>
#include "outputFunctions.h"
#include "greenhouse.h"
#include <string>

using namespace std;

void menu(){
	cout << "\n\tHere is a menu, where you can have next possibilities:";
	cout << "\n\tPress '0' to increase time by 1 unit";
	cout << "\n\tPress '1' to open the window";
	cout << "\n\tPress '2' to close the window";
	cout << "\n\tPress '3' to heater on";
	cout << "\n\tPress '4' to heater off";
	cout << "\n\tPress '5' to show menu again(how can you already forget all options oO?)";
	cout << "\n\tPress '6' to exit from interactive Greenhouse";
	cout << "\n\tBut be careful! Plants can die!";
}

void menuOptions1(int choice, Greenhouse &Gr, bool &exitGreenhouse) {
	switch (choice) { 
	case 1: if (Gr.OpenWindow()) cout << "Can not open the window!" << endl; break;
	case 2: if (Gr.CloseWindow()) cout << "Can npt close the window!" << endl; break;
	case 3: if (Gr.HeaterON()) cout << "Can not ON the heater!" << endl; break;
	case 4: if (Gr.HeaterOFF()) cout << "Can not OFF the heater!" << endl; break;
	case 5: menu(); break;
	case 6: cout << "\n\tSee you soon, buy!" << endl; exitGreenhouse = false; break;
	case 0: Gr.timeIncrement1(); break;
	case -1: cout << "Invalid input! Pls try again using menu items(press 5 to show menu again)" << endl; break;
	}
}
