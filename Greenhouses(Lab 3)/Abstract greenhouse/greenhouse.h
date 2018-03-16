//CREATOR MARIA KOROL, K-11

#pragma once
#include <string>

class Greenhouse {
public:
	bool OK()const; //return value of of isOK(false, if plants died; true, if still alive)
	virtual std::string version()const = 0; //returns greenhouse version
	std::string info()const; //returns greenhouse state 
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
	virtual ~Greenhouse() = default;
protected:
	double temperature; //temperature of Greenhouse
	double humidity; //humidity of Greenhouse
	int time = 0; //time of Greenhouse working
	bool isOK;   //false, if plants died; true, if still alive 
	bool isHeaterON = false;  //true, if heater ON; false, if Heater OFF
	bool isWindowOpen = false; // true, if Window is open; false, if window is closed
protected:
	virtual double MAXtemperature()const = 0; //MAX temperature for plant living 
	virtual double MINtemperature()const = 0; //MIN temperature for plants living
	virtual double MAXhumidity()const = 0; //MAX humidity for plants living
	virtual double MINhumidity()const = 0; //MIN temperature for plants living
	virtual void temperatureHumidityChange() = 0; //change temperature and humidity according to the current Greenhouse's state
	bool isValid();
	/* check temperature and humidity for validity, true if correct:
	** MINtemperature <= temperature <=MAXtemperature
	** MINhumidity <= humidity <= MAXhumidity
	** isOK=true;
	** false, if not correct */
	void timeChange(); //add 1 unit of time	
};

class Greenhouse1:public Greenhouse {
public:
	Greenhouse1();
	std::string version()const; //returns greenhouse version
	~Greenhouse1() = default;
protected:
	double MAXtemperature()const; //MAX temperature for plant living 
	double MINtemperature()const; //MIN temperature for plants living
	double MAXhumidity()const; //MAX humidity for plants living
	double MINhumidity()const; //MIN temperature for plants livin
	void temperatureHumidityChange(); //change temperature and humidity according to the current Greenhouse's state
};

class Greenhouse2 :public Greenhouse {
public:
	Greenhouse2();
	std::string version()const; //returns greenhouse version
	~Greenhouse2() = default;
protected:
	double MAXtemperature()const; //MAX temperature for plant living 
	double MINtemperature()const; //MIN temperature for plants living
	double MAXhumidity()const; //MAX humidity for plants living
	double MINhumidity()const; //MIN temperature for plants livin
	void temperatureHumidityChange(); //change temperature and humidity according to the current Greenhouse's state
};

class Greenhouse3 :public Greenhouse {
public:
	Greenhouse3(); 
	std::string version()const; //returns greenhouse version
	~Greenhouse3() = default;
protected:
	double MAXtemperature()const; //MAX temperature for plant living 
	double MINtemperature()const; //MIN temperature for plants living
	double MAXhumidity()const; //MAX humidity for plants living
	double MINhumidity()const; //MIN temperature for plants livin
	void temperatureHumidityChange(); //change temperature and humidity according to the current Greenhouse's state
};