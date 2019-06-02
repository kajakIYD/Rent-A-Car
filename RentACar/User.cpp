#include "User.hpp"



User::User()
{
}


User::~User()
{
}

User::User(std::string name, std::string surname, int age, 
	std::string emailAddress, std::string phoneNumber, std::string login,
	std::string password, int transactionCounter, int amountOfCash)
{
	this->age = age;
	this->amountOfCash = amountOfCash;
	this->emailAddress = emailAddress;
	this->login = login;
	this->name = name;
	this->password = password;
	this->phoneNumber = password;
	this->surname = surname;
	this->transactionCounter = transactionCounter;
}
