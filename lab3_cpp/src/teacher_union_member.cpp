#include "teacher_union_member.h"

TeacherUnionMember::TeacherUnionMember() : Man(), Teacher(), UnionMember()
{
	this->social_activity[0] = '\0';
}

TeacherUnionMember::TeacherUnionMember(char* name, char* surname, char* taught_course, char* position, char* social_activity) : Man(name, surname), Teacher(taught_course), UnionMember(position)
{
	set_social_activity(social_activity);
}

void TeacherUnionMember::set_social_activity(char* social_activity)
{
	if (strlen(social_activity) > 29)
		throw std::string("Length is higher than specified");

	for (int i = 0; i < strlen(social_activity); i++)
		this->social_activity[i] = social_activity[i];
	this->social_activity[strlen(social_activity)] = '\0';
}

const char* TeacherUnionMember::get_social_activity() const
{
	return this->social_activity;
}

void TeacherUnionMember::organize_meeting() const
{
	std::cout << UnionMember::get_postion() << " of " << "\"" << get_social_activity() << "\"" << " - " << Man::get_name() << " " << Man::get_surname() << " organizes a meeting of the " << Teacher::get_taught_course() << " teachers" << std::endl;
}