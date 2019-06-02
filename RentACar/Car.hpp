#pragma once

#include <string>


class Car
{
public:
	Car(int carID, std::string colour, std::string manufacturer, std::string modelName,
		int productionYear, float engineVolume, int horsePower, int humanCapacity, 
		int yearsOfWarranty, int price);

	Car();

	~Car();

	int carID;

	std::string colour;
	
	std::string manufacturer;
	
	std::string modelName;

	int productionYear;

	float engineVolume;

	int horsePower;

	int humanCapacity;

	int yearsOfWarranty;

	int price;

};

