#include "Operations.hpp"

#include <iostream>

#include "Car.hpp"
#include "User.hpp" //bo tu bedziemy w pelni korzystac z uzytkownika




Operations::Operations()
{
	//Dodawanie samochodow do wekrtora samochodow -> docelowo bedzie odczytywane z pliku
	Car porsche(1, "black", "Porsche", "911 Turbo S", 2015, 3.5f, 320, 2, 5, 1000);
	Car ferrari(2, "red", "ferrari", "Italian", 2000, 2.5f, 250, 4, 10, 2000);
	
	carVector = {porsche, ferrari};
}


Operations::~Operations()
{
}

void Operations::showCar(Car car)
{
	std::cout << "carID: " << car.carID << std::endl;
	std::cout << "Manufacturer: " << car.manufacturer << std::endl;
	std::cout << "Model: " << car.modelName << std::endl;
	std::cout << "Colour: " << car.colour << std::endl;
	std::cout << "Production year: " << car.productionYear << std::endl;
	std::cout << "horsePower: " << car.horsePower << std::endl;
	std::cout << "enginevolume: " << car.engineVolume << std::endl;
	std::cout << "yearsofWarranty: " << car.yearsOfWarranty << std::endl;
	std::cout << "price: " << car.price << std::endl;
}

void Operations::showAllCars()
{
	//Pokazujemy uzytkownikowi wszytkie dostepne auta
	//Docelowo bedziemy brali te auta  z pliku, ale poki co na sztywno wpiszemy sobie kilka aut

	for each (Car car in carVector) //dla ka¿dego 
	{
		std::cout << "\n--------------------------------------\n";
		showCar(car);
	}

}

bool Operations::rentACar(std::string choice, User user)
{
	//choice to np. "3", a my chcemy zrobic z tego 3 - czyli juz nie napis ale liczba
	//std::to_string(choiceNumber); //konwersja z int na string
	int choiceNumber = std::stoi(choice);
	
	switch (choiceNumber)
	{
		case 1:
		{			
			if (user.amountOfCash >= carVector[0].price)
			{
				user.amountOfCash -= carVector[0].price; // operator x -= 1 to to samo co x = x - 1 
				
				std::cout << "You have successfully rent a car\n";
				std::cout << "*********************************************\n";
				showCar(carVector[0]);
				std::cout << "*********************************************\n";
				return true;
			}
			else
			{
				return false;
			}
		}
		case 2:
		{
			if (user.amountOfCash >= carVector[1].price)
			{
				//user.amountOfCash = user.amountOfCash - carVector[1].price; //to robi to samo co linijka poni¿ej
				user.amountOfCash -= carVector[1].price; // operator x -= 1 to to samo co x = x - 1 		
				
				std::cout << "You have successfully rent a car\n";
				std::cout << "*********************************************\n";
				showCar(carVector[1]);
				std::cout << "*********************************************\n";

				return true;
			}
			else
			{
				return false;
			}
		}
		default: //czyli przypadek inny niz uwzglednione powyzej - taki else
		{
			std::cout << "ERROR!!!\n";

			break;
		}
	}
	return false;
}

