#include "man.h"

Man::Man()
{
	this->name[0] = '\0';
	this->surname[0] = '\0';
}

Man::Man(char* name, char* surname)
{
	set_name(name);
	set_surname(surname);
}

void Man::set_name(const char* name)
{
	if (strlen(name) > MAX_NAME_LENGTH - 1)
		throw std::string("Length is higher than specified");

	for (int i = 0; i < strlen(name); i++)
		this->name[i] = name[i];
	this->name[strlen(name)] = '\0';
}

void Man::set_surname(const char* surname)
{
	if (strlen(surname) > MAX_SURNAME_LENGTH - 1)
		throw std::string("Length is higher than specified");

	for (int i = 0; i < strlen(surname); i++)
		this->surname[i] = surname[i];
	this->surname[strlen(surname)] = '\0';
}

const char* Man::get_name() const
{
	return this->name;
}

const char* Man::get_surname() const
{
	return this->surname;
}

void Man::speak() const
{
	std::cout << name << " says: Hello!" << std::endl;
}