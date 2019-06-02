#pragma once
#include <vector>

class Car;
class User; //delaracja wprowadzajaca - sygnalizujemy e bedziemy korzystac z oiektow, ale nie potrzebujemy wiedziec wszystkiego

class Operations
{
public:
	Operations();
	~Operations();

	void showCar(Car car);

	void showAllCars(); //jeœli metoda jest static, to znaczy ¿e nie potrzeba obiektu klasy ¿eby j¹ wywo³aæ

	bool rentACar(std::string choice, User user);

private:
	std::vector<Car> carVector;


};

