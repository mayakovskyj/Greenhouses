//CREATOR MARIA KOROL, K-11

#include "greenhouse.h"
#include <iomanip>
#include <string>

using namespace std;

// class Abstract Greenhouse

string Greenhouse::info()const {
	std::string GreenhouseState = version() + "Greenhouse state: ";
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
	if ((isOK) && (temperature < MAXtemperature()) && (temperature > MINtemperature()) && (humidity > MINhumidity()) && (humidity < MAXhumidity())) return true;
	else {
		isHeaterON = false;
		return isOK=false;
	}
}

void Greenhouse::timeChange()
{
	time++;
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

//class default greenhouse

Greenhouse1::Greenhouse1()
{
	temperature = 10;
	humidity = 50;
	isOK = true;
	isValid();
}

std::string Greenhouse1::version() const
{
	return "\t\tGreenhouse version 1.0 'Default greenhouse' \n";
}


double Greenhouse1::MAXtemperature() const
{
	return 56;
}

double Greenhouse1::MINtemperature() const
{
	return -2;
}

double Greenhouse1::MAXhumidity() const
{
	return 95;
}

double Greenhouse1::MINhumidity() const
{
	return 5;
}

void Greenhouse1::temperatureHumidityChange()
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

//class Tropic greenhouse

Greenhouse2::Greenhouse2()
{
	temperature = 35;
	humidity = 70;
	isOK = true;
	isValid();
}

std::string Greenhouse2::version() const
{
	return "\t\tGreenhouse version 2.0 'Tropic greenhouse' \n";
}

double Greenhouse2::MAXtemperature() const
{
	return 67;
}

double Greenhouse2::MINtemperature() const
{
	return 10;
}

double Greenhouse2::MAXhumidity() const
{
	return 100;
}

double Greenhouse2::MINhumidity() const
{
	return 52;
}

void Greenhouse2::temperatureHumidityChange()
{
	if (isWindowOpen) {
		temperature -= 3;
		humidity += 7;
	}
	else {
		temperature -= 0.8;
		humidity -= 0.5;
	}
	if (isHeaterON) {
		temperature += 5;
		humidity -= 7;
	}
	else {
		temperature -= 1;
		humidity += 0.5;
	}
}

//class Arctic greenhouse
Greenhouse3::Greenhouse3()
{
	temperature = 5;
	humidity = 20;
	isOK = true;
	isValid();
}

std::string Greenhouse3::version() const
{
	return "\t\tGreenhouse version 3.0 'Arctic greenhouse' \n";
}


double Greenhouse3::MAXtemperature() const
{
	return 45;
}

double Greenhouse3::MINtemperature() const
{
	return -10;
}

double Greenhouse3::MAXhumidity() const
{
	return 40;
}

double Greenhouse3::MINhumidity() const
{
	return 0.5;
}

void Greenhouse3::temperatureHumidityChange() {
	if (isWindowOpen) {
		temperature -= 3;
		humidity -= 2;
	}
	else {
		temperature += 0.9;
		humidity += 0.7;
	}
	if (isHeaterON) {
		temperature += 6;
		humidity -= 5;
	}
	else {
		temperature -= 0.5;
		humidity += 0.1;
	}
}
