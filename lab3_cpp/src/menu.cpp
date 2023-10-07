#include "menu.h"

void input_string_check(char* string, int limit)
{
	while (true) {
		std::cout << "(no more than " << limit << " characters): ";
		std::cin.getline(string, limit);

		if (std::cin.fail() || std::cin.gcount() >= limit) {
			std::cin.clear();  
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
			std::cout << "Exceeding the limit. Try again." << std::endl;
		}
		else 
			break; 
	}

	std::cout << std::endl;
}

int input_menu_check(int limit_left, int limit_right)
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
		<< "1) - Action of Man" << std::endl
		<< "2) - Action of Teacher" << std::endl
		<< "3) - Action of Union Member" << std::endl
		<< "4) - Action of Teacher-Union-Member" << std::endl
		<< "5) - Exit" << std::endl
		<< "Your choose: ";
}

void functionality_assessment()
{
	TeacherUnionMember unit;
	
	char name[MAX_NAME_LENGTH];
	std::cout << "Enter name";
	input_string_check(name, 9);
	unit.set_name(name);

	char surname[MAX_SURNAME_LENGTH];
	std::cout << "Enter surname";
	input_string_check(surname, 19);
	unit.set_surname(surname);

	char taught_course[MAX_TAUGHT_COURSE_LENGTH];
	std::cout << "Enter taught course";
	input_string_check(taught_course, 9);
	unit.set_taught_course(taught_course);

	char position[MAX_POSITION_LENGTH];
	std::cout << "Enter position";
	input_string_check(position, 19);
	unit.set_position(position);

	char social_activity[MAX_SOCIAL_ACTIVITY_LENGTH];
	std::cout << "Enter social activity";
	input_string_check(social_activity, 29);
	unit.set_social_activity(social_activity);

	int choose = 0;

	do
	{
		print_menu();

		choose = input_menu_check(1, 5);

		std::cout << std::endl;

		switch (choose)
		{
			case ACTION_MAN:
			{
				unit.speak();
				break;
			}
			case ACTION_TEACHER:
			{
				unit.teach();
				break;
			}
			case ACTION_UNION_MEMBER:
			{
				unit.participate_in_union();
				break;
			}
			case ACTION_TEACHER_UNION_MEMBER:
			{
				unit.organize_meeting();
				break;
			}
			case EXIT:
			{
				break;
			}
			default:
			{
				exit(MENU_EXIT_ERROR);
			}
		}
	} while (choose != EXIT);
}