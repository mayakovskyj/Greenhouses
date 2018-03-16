//CREATOR MARIA KOROL, K-11

#pragma once
#include <string>


class Greenhouse {
public:
	Greenhouse();
	
	bool OK()const; //return value of of isOK(false, if plants died; true, if still alive)
	std::string info()const; //greenhouse state 
	bool HeaterON(); //returns indication of success. 
	bool HeaterOFF(); //returns indication of success. 
	bool OpenWindow(); //returns indication of success. 
	bool CloseWindow(); //returns indication of success.
	double getTemperature()const; 
	double getHumidity()const;
	bool getWindowState()const; 
	bool getHeaterState()const; 
	int getTime()const; 
	void timeIncrement1();
private:
	double temperature; //temperature of Greenhouse
	double humidity; //humidity of Greenhouse
	int time = 0; //time of Greenhouse working
	bool isOK;   //false, if plants died; true, if still alive 
	bool isHeaterON;  //true, if heater ON; false, if Heater OFF
	bool isWindowOpen; // true, if Window is open; false, if window is closed
	static const double defaultTemp; //factory temperature
	static const double defaultHumidity; //factory humidity
	static const double MAXtemperature; //MAX temperature for plant living 
	static const double MINtemperature; //MIN temperature for plants living
	static const double MAXhumidity; //MAX humidity for plants living
	static const double MINhumidity; //MIN temperature for plants living
private:
	bool isValid(); 
	/* check temperature and humidity for validity, true if correct:
	** MINtemperature <= temperature <=MAXtemperature
	** MINhumidity <= humidity <= MAXhumidity
	** isOK=true;
	** false, if not correct */
	void timeChange(); //add 1 unit of time
	void temperatureHumidityChange(); //change temperature and humidity according to the current Greenhouse's state
};
