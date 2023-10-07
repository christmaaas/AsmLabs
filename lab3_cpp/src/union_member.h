#pragma once
#include <iostream>

#include "man.h"

#define MAX_POSITION_LENGTH 20

class UnionMember : virtual public Man
{
private:
	char position[MAX_POSITION_LENGTH];
public:
	UnionMember();
	UnionMember(char* position);
	UnionMember(char* name, char* surname, char* position);

	void participate_in_union() const;

	void set_position(char* position);

	const char* get_postion() const;
};