#pragma once
#include <iostream>

#include "man.h"

#define MAX_POSITION_LENGTH 10

class UnionMember : virtual public Man
{
private:
	char position[MAX_POSITION_LENGTH];
public:
	UnionMember();
	UnionMember(char* name, char* surname, char* position);

	void set_position(char* position);

	const char* get_postion() const;
};