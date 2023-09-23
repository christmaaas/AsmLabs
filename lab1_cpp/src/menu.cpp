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

void print_menu()
{
	std::cout << std::endl
		<< "1 - Push in stack" << std::endl
		<< "2 - Pop from stack" << std::endl
		<< "3 - Print stack" << std::endl
		<< "4 - Add in stack" << std::endl
		<< "5 - Sub from stack" << std::endl
		<< "6 - Exit" << std::endl
		<< "Your choose: ";
}