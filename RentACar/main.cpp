#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "Operations.hpp"
#include "User.hpp"



//TODO:
//-Drobiagi - komunikaty o bledach, wypisanie menu etc.... VisualStudio 2015 Community
//-Przeniesc metody shopping, logIn, logOut, signUp do klasy Operations





int main(void)
{
	Operations operationsManager;

	std::cout << "Hello would You like to rent a car?\n";
	
	std::string c;

	User activeUser = User(); //konstrutor domyslny, bo user jest "pusty"

	bool performExit = false;

	do
	{
		operationsManager.printMenu();
		std::cout << "Choose an option:\n";

		std::cin >> c;

		if (c == "1")
		{
			if (operationsManager.logIn(activeUser) == true) //login(activeUser) -> to jest przekazanie przez referencjê (mechanizm taki  jak przez wskaznik, tylko prostszy ww obs³udze i debugowaniu)
			{
				performExit = operationsManager.shopping(&activeUser);
				if (!performExit)
				{
					std::cout << "Sucessfully logged out\n";
				}
			}			
		}
		else if (c == "2")
		{
			operationsManager.logOut(&activeUser);
		}
		else if (c == "3")
		{
			operationsManager.signUp();
		}
		else if (c == "4")
		{
			std::cout << "Bye bye";
		}
		else
		{
			std::cout << "There is not such an option... :(";
		}

	} while (c.compare("4") != 0 && performExit == false);

	std::cout << "Hope to see You again!\n";

	system("pause");
	
	return 0;
}