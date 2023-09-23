#include <iostream>

#include "stack.h"
#include "string.h"
#include "menu.h"

int main()
{
	std::cout << "Input capacity of stack: ";

	int stack_capacity = input_check(0, 100), choose = 0, value = 0;

	Stack stack(stack_capacity);

	do
	{
		print_menu();

		choose = input_check(1, 6);

		switch (choose)
		{
			case PUSH:
			{
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
			}
			case POP:
			{
				try
				{
					std::cout << std::endl << "Pop value: " << stack.pop() << std::endl;
				}
				catch (std::string error_message)
				{
					std::cout << error_message << std::endl;
				}
				break;
			}
			case PRINT:
			{
				stack.print();
				break;
			}
			case ADD:
			{
				std::cout << std::endl << "Enter value to push: ";

				value = input_check(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

				stack + value;

				break;
			}
			case SUB:
			{
				std::cout << std::endl << "Enter amount for sub: ";

				value = input_check(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

				if (value > stack.size())
				{
					std::cout << std::endl << "Enter valid value" << std::endl;
					break;
				}

				stack - value;

				break;
			}
			case EXIT:
			{
				break;
			}
			default:
			{
				return 0;
			}
		}
	} while (choose != EXIT);

	return 0;
}