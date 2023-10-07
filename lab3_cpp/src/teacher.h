#pragma once
#include <iostream>

#include "man.h"

#define MAX_TAUGHT_COURSE_LENGTH 10

class Teacher : virtual public Man
{
private:
	char taught_course[MAX_TAUGHT_COURSE_LENGTH];
public:
	Teacher();
	Teacher(char* taught_course);
	Teacher(char* name, char* surname, char* taught_course);

	void teach() const;

	void set_taught_course(char* taught_course);

	const char* get_taught_course() const;
};