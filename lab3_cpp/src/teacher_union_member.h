#pragma once
#include <iostream>

#include "teacher.h"
#include "union_member.h"

#define MAX_SOCIAL_ACTIVITY_LENGTH 30

class TeacherUnionMember : public Teacher, public UnionMember
{
private:
	char social_activity[MAX_SOCIAL_ACTIVITY_LENGTH];
public:
	TeacherUnionMember();
	TeacherUnionMember(char* name, char* surname, char* taught_course, char* position, char* social_activity);

	void organize_meeting() const;

	void set_social_activity(const char* social_activity);

	const char* get_social_activity() const;
};