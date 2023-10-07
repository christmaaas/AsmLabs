#include "union_member.h"

UnionMember::UnionMember() : Man()
{
	this->position[0] = '\0';
}

UnionMember::UnionMember(char* position)
{
	set_position(position);
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
	this->position[strlen(position)] = '\0';
}

const char* UnionMember::get_postion() const
{
	return this->position;
}

void UnionMember::participate_in_union() const
{
	std::cout << Man::get_name() << " holds the position of " << position << std::endl;
}