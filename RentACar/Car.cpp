#include "Car.hpp"

#include <iostream>


Car::Car(int carID, std::string colour, std::string manufacturer, std::string modelName,
		int productionYear, float engineVolume, int horsePower, int humanCapacity,
		int yearsOfWarranty, int price) //konstruktor klasy Car, wywoluje sie zawsze jesli tworzymy obiekt klasy Car
{
	//Tu ustawiamy wszytkie wlasciwosci samochodu
	this->carID = carID;
	this->colour = colour; //to this samo w sobie to juz jest wskaznik
	this->engineVolume = engineVolume;
	this->horsePower = horsePower;
	this->humanCapacity = humanCapacity;
	this->manufacturer = manufacturer;
	this->modelName= modelName;
	this->productionYear = productionYear;
	this->yearsOfWarranty = yearsOfWarranty;
	this->price = price;
}

Car::Car() //to tez jest konstruktor
{
}


Car::~Car() //to jest destruktor, wywoluje sie zawsze jesli obiekt klasy jest usuwany z pamieci
{
	//std::cout << "\nUsuwam obiekt typu Car z pamieci\n";
}

