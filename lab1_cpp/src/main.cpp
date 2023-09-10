#include <iostream>

#include "stack.h"
#include "menu.h"

int main()
{
	std::cout << "Input capacity of stack: ";

	int stack_capacity = input_check(0, 100), choose = 0, value = 0;

	Stack stack(stack_capacity);

	do
	{
		print_menu();

		choose = input_check(1, 4);

		switch (choose)
		{
		case PUSH:
			std::cout << std::endl << "Enter value to push: ";

			value = input_check(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

			try
			{
				stack.push(value);
			}
			catch (std::string error_message)
			{
				std::cout << error_message << std::endl;
			}
			break;
		case POP:
			try
			{
				std::cout << std::endl << "Pop value: " << stack.pop() << std::endl;
			}
			catch (std::string error_message)
			{
				std::cout << error_message << std::endl;
			}
			break;
		case PRINT:
			stack.print();
			break;
		case EXIT:
			break;
		default:
			exit(MENU_ERROR);
		}
	} while (choose != EXIT);

	return 0;
}