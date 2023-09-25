#include "menu.h"

int input_check(int limit_left, int limit_right)
{
	int input = 0;

	std::cin >> input;

	while (true)
	{
		if (!(std::cin) || input > limit_right || input < limit_left)
		{
			std::cout << std::endl << "Wrong input, try again: ";

			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cin >> input;
		}
		else
			break;
	}

	return input;
}

void print_stack_menu()
{
	std::cout << std::endl
		<< "1) - Push in stack" << std::endl
		<< "2) - Pop from stack" << std::endl
		<< "3) - Print stack" << std::endl
		<< "4) - Add in stack" << std::endl
		<< "5) - Sub from stack" << std::endl
		<< "6) - Exit" << std::endl
		<< "Your choose: ";
}

void print_string_menu()
{
	std::cout << std::endl
		<< "1) =" << std::endl
		<< "2) +" << std::endl
		<< "3) +=" << std::endl
		<< "4) ==" << std::endl
		<< "5) !=" << std::endl
		<< "6) []" << std::endl
		<< "7) ()" << std::endl
		<< "8) Print strings" << std::endl
		<< "9) Exit" << std::endl
		<< "Your choose: ";
}

int stack_functionality_assessment()
{
	std::cout << "Input capacity of stack: ";

	int stack_capacity = input_check(0, 100), choose = 0, value = 0;

	Stack stack(stack_capacity);

	do
	{
		print_stack_menu();

		choose = input_check(1, 6);

		switch (choose)
		{
		case Stack::PUSH:
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
		case Stack::POP:
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
		case Stack::PRINT:
		{
			stack.print();
			break;
		}
		case Stack::ADD:
		{
			std::cout << std::endl << "Enter value to push: ";

			value = input_check(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

			stack + value;

			break;
		}
		case Stack::SUB:
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
		case Stack::EXIT:
		{
			break;
		}
		default:
		{
			return 0;
		}
		}
	} while (choose != Stack::EXIT);
}

int string_functionality_assessment()
{	
	Mstring main_string;
	Mstring second_string;
	
	std::cout << std::endl << "Enter main string: ";
	std::cin >> main_string;

	std::cout << "Enter second string: ";
	std::cin >> second_string;

	int choose = 0, index = 0, left_border = 0, right_border = 0;

	do
	{
		print_string_menu();

		choose = input_check(1, 9);

		switch (choose)
		{
		case Mstring::EQUAL:
			{
				std::cout << std::endl << "Result: ";

				main_string = second_string;

				std::cout << main_string << std::endl;
				break;
			}
			case Mstring::ADD:
			{
				std::cout << std::endl << "Result: ";
			
				Mstring new_string = main_string + second_string;
				std::cout << new_string << std::endl;
				break;
			}
			case Mstring::ADD_AND_EQUAL:
			{
				std::cout << std::endl << "Result: ";
			
				main_string += second_string;
				std::cout << main_string << std::endl;
				break;
			}
			case Mstring::IF_EQUAL:
			{
				if (main_string == second_string)
					std::cout << std::endl << "Result: Equal" << std::endl;
				else
					std::cout << std::endl << "Result: Not equal" << std::endl;
				break;
			}
			case Mstring::IF_NOT_EQUAL:
			{
				if (main_string != second_string)
					std::cout << std::endl << "Result: Not equal" << std::endl;
				else
					std::cout << std::endl << "Result: Equal" << std::endl;
				break;
			}
			case Mstring::INDEX:
			{
				std::cout << std::endl << "Enter index: ";

				index = input_check(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
			
				try
				{
					std:: cout << std:: endl << "Letter on index: " << main_string[index] << std::endl;
				}
				catch (std::string error_message)
				{
					std::cout << error_message << std::endl;
				}
			
				break;
			}
			case Mstring::RANGE:
			{
				std::cout << std::endl << "Enter left border: ";
				std::cin >> left_border;

				std::cout << std::endl << "Enter right border: ";
				std::cin >> right_border;
				try
				{
					std::cout << std::endl << "Result: " << main_string(left_border, right_border) << std::endl;
				}
				catch (std::string error_message)
				{
					std::cout << error_message << std::endl;
				}
				break;
			}
			case Mstring::PRINT:
			{
				std::cout << std::endl << "Main string: " << main_string << std::endl;
				std::cout << "Second string: " << second_string << std::endl;
			
				break;
			}
			case Mstring::EXIT:
			{
				break;
			}
			default:
			{
				return 0;
			}
		}
	} while (choose != Mstring::EXIT);
}