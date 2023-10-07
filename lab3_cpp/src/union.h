#pragma once
#include <iostream>

#define MAX_NAME_LENGTH 10
#define MAX_SURNAME_LENGTH 20

#define MAX_TAUGHT_COURSE_LENGTH 10

#define MAX_POSITION_LENGTH 10

#define MAX_SOCIAL_ACTIVITY_LENGTH 10

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

class Teacher : virtual public Man
{
private:
	char taught_course[MAX_TAUGHT_COURSE_LENGTH];
public:
	Teacher();
	Teacher(char* name, char* surname, char* taught_course);

	void set_taught_course(char* taught_course);

	const char* get_taught_course() const;
};

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

class TeacherUnionMember : public Teacher, public UnionMember
{
private:
	char social_activity[MAX_SOCIAL_ACTIVITY_LENGTH];
public:
	TeacherUnionMember();
	TeacherUnionMember(char* name, char* surname, char* taught_course, char* position, char* social_activity);

	void set_social_activity(char* social_activity);

	const char* get_social_activity() const;
};

