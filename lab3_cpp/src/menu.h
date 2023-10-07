#pragma once
#include <iostream>

#include "teacher_union_member.h"

#define MENU_EXIT_ERROR -10

enum Menu
{
	ACTION_MAN = 1,
	ACTION_TEACHER,
	ACTION_UNION_MEMBER,
	ACTION_TEACHER_UNION_MEMBER,
	EXIT
};

void functionality_assessment();
void input_string_check(char* string, int limit);
int input_menu_check(int limit_left, int limit_right);
void print_menu();