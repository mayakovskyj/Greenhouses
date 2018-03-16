//CREATOR MARIA KOROL, K-11

#include "greenhouse.h"
#include <iomanip>
#include <string>

using namespace std;

const double Greenhouse::defaultTemp = 10;
const double Greenhouse::defaultHumidity = 50;
const double Greenhouse::MAXtemperature = 56;
const double Greenhouse::MINtemperature = -2;
const double Greenhouse::MAXhumidity = 95;
const double Greenhouse::MINhumidity = 5;

Greenhouse::Greenhouse() :temperature(defaultTemp), humidity(defaultHumidity), isOK(true), isHeaterON(false), isWindowOpen(false) {isValid();}

string Greenhouse::info()const {
	std::string GreenhouseState = "Greenhouse state: ";
	if (getWindowState()) GreenhouseState += "Window is open, ";
	else GreenhouseState += "Window is closed, ";
	if (getHeaterState()) GreenhouseState += "Heater is ON, ";
	else GreenhouseState += "Heater is OFF, ";
	GreenhouseState += "Temperature is " + std::to_string(getTemperature()) + " degrees, ";
	GreenhouseState += "Humidity is " + std::to_string(getHumidity()) + " %.\n";
	GreenhouseState += "Time running : " + std::to_string(getTime()) + "\n";
	if (OK()) GreenhouseState += "Greenhouse is working";
	else GreenhouseState += "Plants are dead, greenhouse is broken";
	return GreenhouseState;
}

bool Greenhouse::OK()const {
	return isOK;
}

bool Greenhouse::isValid() {
	if ((isOK) && (temperature < MAXtemperature) && (temperature > MINtemperature) && (humidity > MINhumidity) && (humidity < MAXhumidity)) return true;
	else {
		isHeaterON = false;
		return isOK=false;
	}
}

void Greenhouse::timeChange()
{
	time++;
}

void Greenhouse::temperatureHumidityChange() 
{
	if (isWindowOpen) {
		temperature -= 2;
		humidity += 5;
	}
	else {
		temperature -= 0.05;
		humidity -= 0.1;
	}
	if (isHeaterON) {
		temperature += 4;
		humidity -= 5;
	}
	else {
		temperature -= 0.1;
		humidity += 0.2;
	}
}


int Greenhouse::getTime()const {
	return time;
}

double Greenhouse::getTemperature()const {
	return temperature;
}
bool Greenhouse::getWindowState() const
{
	return isWindowOpen;
}
bool Greenhouse::getHeaterState() const
{
	return isHeaterON;
}
double Greenhouse::getHumidity()const {
	return humidity;
}

void Greenhouse::timeIncrement1() {
	if (OK()) temperatureHumidityChange();
	timeChange();
	isValid();
}

bool Greenhouse::HeaterON() {
	if ((isHeaterON) || (!(OK()))) return true;
	isHeaterON = true;
	return false;
}

bool Greenhouse::HeaterOFF() {
	if ((!(isHeaterON)) || (!(OK()))) return true;
	return isHeaterON = false;
}

bool Greenhouse::OpenWindow() {
	if ((isWindowOpen) || (!(OK()))) return true;
	isWindowOpen = true;
	return false;
}

bool Greenhouse::CloseWindow() {
	if ((!(isWindowOpen))||(!(OK()))) return true;
	return isWindowOpen = false;
}

