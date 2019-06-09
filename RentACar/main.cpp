#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "Operations.hpp"
#include "User.hpp"



//TODO:
//-Drobiagi - komunikaty o bledach, wypisanie menu etc.... VisualStudio 2015 Community
//-Przeniesc metody shopping, logIn, logOut, signUp do klasy Operations



void printMenu()
{
	std::cout << "1. Log in" << std::endl;
	std::cout << "2. Log out" << std::endl;
	std::cout << "3. Sign up" << std::endl;
	std::cout << "4. Exit\n"; 
	// \n i << std::endl to jest to samo
}

std::vector<User> userVector;
//User* activeUser = nullptr; //wskaznik na typ user, wskaznik sie nazywa activeUser, poki co pod tym wskaznikiem nie ma aktywnego uzytkownika dlatego nullptr

bool logIn(User& activeUser) //User& to znaczy ze przekazujemy przez referencje 
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

	return false;
}

void shopping(User* activeUser)
{
	//Operations::showAllCars(); //tu nie odwo³ujemy sie do obiektu klasy

	Operations operation; //utworzono obiekt klasy operations

	std::string choice = "x";
	while (choice != "exit" && choice != "E" && choice != "e")
	{
		operation.showAllCars(); //odwolujemy do metody z klaasy operations za pomoca obiekttu klasy operations 

		std::cout << "Choose a car to rent or type E or e to exit..." << std::endl;

		std::cin >> choice;

		if (choice == "exit" || choice == "E" || choice == "e")
		{
			return; //tu pretla sie przerywa
		}
		else
		{
			operation.rentACar(choice, *activeUser);	//tu przy activeUser musi byæ *, bo * wy³uskuje wartoœæ któr¹ pokazuje wskaŸnik (jeœli robimy przez wskaŸnik)
			
			while (choice != "e" && choice != "E" && choice != "b" && choice != "B")
			{
				std::cout << "Press b to go back shopping or e to exit\n";
				std::cin >> choice;
			}
		}
	}
}

void logOut(User* activeUser)
{
	activeUser = nullptr; //wylogowanie, dlatego aktywwny uzytkownik to znowuu nullptr (nullptr to w zasadzie to samo co null w c)
}


void signUp()
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


int main(void)
{
	User user1 = User("a", "b", 23, "a@a.pl", "333-333-333", "l", "p", 0, 10000000);

	userVector.push_back(user1); //dodanie user1 na koniec wektora (dynamicze przydzielanie pamiêci)

	User activeUser = User(); //konstrutor domyslny, bo user jest "pusty"

	std::cout << "Hello would You like to rent a car?\n";
	
	printMenu();
	std::string c;

	do
	{
		std::cout << "Choose an option:\n";

		std::cin >> c;

		if (c == "1")
		{
			if (logIn(activeUser) == true) //login(activeUser) -> to jest przekazanie przez referencjê (mechanizm taki  jak przez wskaznik, tylko prostszy ww obs³udze i debugowaniu)
			{
				shopping(&activeUser);
				break;
			}			
		}
		else if (c == "2")
		{
			logOut(&activeUser);
		}
		else if (c == "3")
		{
			signUp();
		}
		else if (c == "4")
		{
			std::cout << "Bye bye";
		}
		else
		{
			std::cout << "There is not such an option... :(";
		}

	} while (c != "4");

	std::cout << "Hope to see You again!\n";

	system("pause");
	
	return 0;
}