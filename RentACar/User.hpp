#pragma once
#include <string>


class User
{
public:
	User();
	~User();

	User(std::string name, std::string surname,	int age, std::string emailAddress, 
		std::string phoneNumber, std::string login, std::string password, 
		int transactionCounter,  int amountOfCash);

	std::string name;
	std::string surname;
	
	int age;

	std::string emailAddress;
	std::string phoneNumber;

	std::string login;
	std::string password;

	int transactionCounter;

	int amountOfCash;
};

