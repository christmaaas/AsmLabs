#pragma once
#include <iostream>

#define MAX_NAME_LENGTH 10
#define MAX_SURNAME_LENGTH 20

class Man
{
private:
	char name[MAX_NAME_LENGTH];
	char surname[MAX_SURNAME_LENGTH];
public:
	Man();
	Man(char* name, char* surname);

	void set_name(char* name);
	void set_surname(char* surname);

	const char* get_name() const;
	const char* get_surname() const;
};