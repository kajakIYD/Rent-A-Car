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

	
	User user1 = User("a", "b", 23, "a@a.pl", "333-333-333", "l", "p", 0, 10000000);

	userVector.push_back(user1); //dodanie user1 na koniec wektora (dynamicze przydzielanie pamiêci)
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


void Operations::printMenu()
{
	std::cout << "1. Log in" << std::endl;
	std::cout << "2. Log out" << std::endl;
	std::cout << "3. Sign up" << std::endl;
	std::cout << "4. Exit\n";
	// \n i << std::endl to jest to samo
}

std::vector<User> userVector;
//User* activeUser = nullptr; //wskaznik na typ user, wskaznik sie nazywa activeUser, poki co pod tym wskaznikiem nie ma aktywnego uzytkownika dlatego nullptr

bool Operations::logIn(User& activeUser) //User& to znaczy ze przekazujemy przez referencje 
{
	std::cout << "Hello!\n";

	std::string login; //std::string to jest typ ³añcuch znaków np. "xxfadgs"
	std::string password;

	std::cout << "Login: ";
	std::cin >> login;

	std::cout << "Password: ";
	std::cin >> password;

	for each (User user in userVector)
	{
		if (login.compare(user.login) == 0 && password.compare(user.password) == 0)
		{
			std::cout << "YOU HAVE SUCCESSFULLY LOGGED IN!\n";
			std::cout << "Welcome " << user.name;
			activeUser = user; //Pod wskaznikiem mamy dostep do aktywnego uzytkownika, ale dlatego ze to wskanik to musi byæ &user zamiast user
							   //& wy³uskuje adres obiektu (to jest opis dla tego co robiliœmy wskaŸnikiem). Ale akurat tutaj robimy przez referennjê
			return true;
		}
	}

	std::cout << "Login failed, credentials are not correct" << std::endl;
	return false;
}

int Operations::compareStrings(std::string choice)
{
	while (choice != "e" && choice != "E" && choice != "b" && choice != "B" && choice != "l" && choice != "L")
	{
		std::cout << "Press b to go back shopping or e to exit or l to log out\n";
		std::cin >> choice;
	}

	if (choice.compare("l") == 0 || choice.compare("L") == 0)
	{
		return 0; // just log out
	}

	if (choice.compare("e") == 0 || choice.compare("E") == 0)
	{
		return 1; // exit
	}

	return 2; // go back shopping
}


inline bool isInteger(const std::string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}


bool Operations::shopping(User* activeUser)
{
	//Operations::showAllCars(); //tu nie odwo³ujemy sie do obiektu klasy

	Operations operation; //utworzono obiekt klasy operations

	std::string choice = "x";
	while (choice != "exit" && choice != "E" && choice != "e")
	{
		operation.showAllCars(); //odwolujemy do metody z klaasy operations za pomoca obiekttu klasy operations 

		std::cout << "Chosse a car, OR press b to go back shopping or e to exit or l to log out\n";

		std::cin >> choice;

		int result;
		if (isInteger(choice))
		{
			result = 3;
		}
		else
		{
			result = compareStrings(choice);
		}


		if (result == 1) //choice == "exit" || choice == "E" || choice == "e")
		{
			return true; //tu pretla sie przerywa
		}
		else if (result == 0)
		{
			return false;
		}
		else
		{
			operation.rentACar(choice, *activeUser);	//tu przy activeUser musi byæ *, bo * wy³uskuje wartoœæ któr¹ pokazuje wskaŸnik (jeœli robimy przez wskaŸnik)

			result = compareStrings(choice);

			if (result == 1) //choice == "exit" || choice == "E" || choice == "e")
			{
				return true; //tu pretla sie przerywa
			}
			else if (result == 0) //choice logOut
			{
				return false;
			}
		}
	}
}

void Operations::logOut(User* activeUser)
{
	activeUser = nullptr; //wylogowanie, dlatego aktywwny uzytkownik to znowuu nullptr (nullptr to w zasadzie to samo co null w c)
}


void Operations::signUp()
{
	std::cout << "Enter Your data:\n";

	std::string name;
	std::string surname;
	int age;
	std::string email;
	std::string phoneNumber;
	std::string login;
	std::string password;
	int amountOfCash;

	std::cout << "Name: ";
	std::cin >> name;
	std::cout << "Surname: ";
	std::cin >> surname;
	std::cout << "Age: ";
	std::cin >> age;

	bool emailFoundInUserVector;
	do
	{
		emailFoundInUserVector = false;
		std::cout << "E-mail: ";
		std::cin >> email;
		for each (User user in userVector)
		{
			if (user.emailAddress.compare(email) == 0)
			{
				std::cout << "Email exists in database!! Type another one\n";
				emailFoundInUserVector = true;
			}
		}

	} while (emailFoundInUserVector == true);

	std::cout << "Phone number: ";
	std::cin >> phoneNumber;

	bool loginFoundInUserVector;
	do
	{
		loginFoundInUserVector = false;
		std::cout << "Login: ";
		std::cin >> login;
		for each (User user in userVector)
		{
			if (user.login.compare(login) == 0) //string::compare zwraca 0 jesli stringi sa takie same, a >0 jesli nie
			{
				std::cout << "Login exists in database!! Type another one\n";
				loginFoundInUserVector = true;
			}
		}
	} while (loginFoundInUserVector == true);

	std::cout << "Password: ";
	std::cin >> password;
	std::cout << "Amount of cash: ";
	std::cin >> amountOfCash;

	userVector.push_back(User(name, surname, age, email, phoneNumber, login, password, 0, amountOfCash));
}
