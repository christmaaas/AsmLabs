#include "union.h"

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

UnionMember::UnionMember() : Man()
{
	this->position[0] = '\0';
}

UnionMember::UnionMember(char* name, char* surname, char* position) : Man(name, surname)
{
	set_position(position);
}

void UnionMember::set_position(char* position)
{
	if (strlen(position) > 9)
		throw std::string("Length is higher than specified");

	for (int i = 0; i < strlen(position); i++)
		this->position[i] = position[i];
	this->position[strlen(this->position) + 1] = '\0';
}

const char* UnionMember::get_postion() const
{
	return this->position;
}

TeacherUnionMember::TeacherUnionMember() : Teacher(), UnionMember()
{
	this->social_activity[0] = '\0';
}

TeacherUnionMember::TeacherUnionMember(char* name, char* surname, char* taught_course, char* position, char* social_activity) : Man(name, surname), Teacher(name, surname, taught_course), UnionMember(name, surname, position)
{
	set_social_activity(social_activity);
}

void TeacherUnionMember::set_social_activity(char* social_activity)
{
	if (strlen(social_activity) > 9)
		throw std::string("Length is higher than specified");

	for (int i = 0; i < strlen(social_activity); i++)
		this->social_activity[i] = social_activity[i];
	this->social_activity[strlen(this->social_activity) + 1] = '\0';
}

const char* TeacherUnionMember::get_social_activity() const
{
	return this->social_activity;
}
