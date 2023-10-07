#include "teacher.h"

Teacher::Teacher() : Man()
{
	this->taught_course[0] = '\0';
}

Teacher::Teacher(char* name, char* surname, char* taught_course) : Man(name, surname)
{
	set_taught_course(taught_course);
}

void Teacher::set_taught_course(char* taught_course)
{
	if (strlen(taught_course) > 9)
		throw std::string("Length is higher than specified");

	for (int i = 0; i < strlen(taught_course); i++)
		this->taught_course[i] = taught_course[i];
	this->taught_course[strlen(this->taught_course) + 1] = '\0';
}

const char* Teacher::get_taught_course() const
{
	return this->taught_course;
}