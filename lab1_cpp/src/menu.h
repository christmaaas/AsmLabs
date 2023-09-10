#pragma once
#include <iostream>

#define MENU_ERROR -10

enum Menu
{
	PUSH = 1,
	POP,
	PRINT,
	EXIT
};

int input_check(int limit_left, int limit_right);
void print_menu();