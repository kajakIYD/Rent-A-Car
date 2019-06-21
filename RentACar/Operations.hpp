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

	void signUp();
	void logOut(User* activeUser);
	bool shopping(User* activeUser);
	bool logIn(User& activeUser); //User& to znaczy ze przekazujemy przez referencje 
	void printMenu();


private:
	std::vector<Car> carVector;

	std::vector<User> userVector;

	int compareStrings(std::string choice); //prywatna metoda

};

