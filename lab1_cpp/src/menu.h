#pragma once
#include <iostream>

enum Menu
{
	PUSH = 1,
	POP,
	PRINT,
	ADD,
	SUB,
	EXIT
};

int input_check(int limit_left, int limit_right);
void print_menu();