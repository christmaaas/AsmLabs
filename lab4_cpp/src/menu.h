#pragma once
#include <iostream>

#include "stack.h"

enum Menu
{
	PUSH = 1,
	POP,
	PRINT,
	PEEK,
	EXIT
};

int input_check(int limit_left, int limit_right);
void print_stack_menu();

template<typename T>
void stack_functionality_assessment()
{
	Stack<T> stack;

	int choose = 0;
	T value = 0;

	do
	{
		print_stack_menu();

		choose = input_check(1, 5);

		switch (choose)
		{
			case PUSH:
			{
				std::cout << std::endl << "Enter value to push: ";

				std::cin >> value;

				stack.push(value);
			}
			break;
			case POP:
			{
				try
				{
					std::cout << std::endl << "Pop value: " << stack.pop() << std::endl;
				}
				catch (std::string error_message)
				{
					std::cout << std::endl << error_message << std::endl;
				}
			}
			break;
			case PRINT:
			{
				stack.print();
			}
			break;
			case PEEK:
			{
				try
				{
					std::cout << std::endl << "Peeked value: " << stack.peek() << std::endl;
				}
				catch (std::string error_message)
				{
					std::cout << std::endl << error_message << std::endl;
				}
			}
			break;
			case EXIT:
			{
				break;
			}
			default:
			{
				break;
			}
		}
	} while (choose != EXIT);
}