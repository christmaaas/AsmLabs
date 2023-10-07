#include "man.h"

Man::Man()
{
	this->name[0] = '\0';
	this->surname[0] = '\0';
}

Man::Man(char* name, char* surname)
{
	set_name(name);
	set_name(surname);
}

void Man::set_name(char* name)
{
	if (strlen(name) > 9)
		throw std::string("Length is higher than specified");

	for (int i = 0; i < strlen(name); i++)
		this->name[i] = name[i];
	this->name[strlen(this->name) + 1] = '\0';
}

void Man::set_surname(char* surname)
{
	if (strlen(surname) > 19)
		throw std::string("Length is higher than specified");

	for (int i = 0; i < strlen(surname); i++)
		this->surname[i] = surname[i];
	this->surname[strlen(this->surname) + 1] = '\0';
}

const char* Man::get_name() const
{
	return this->name;
}

const char* Man::get_surname() const
{
	return this->surname;
}