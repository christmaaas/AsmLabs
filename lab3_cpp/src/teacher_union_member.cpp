#include "teacher_union_member.h"

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