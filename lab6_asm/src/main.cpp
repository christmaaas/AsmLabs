#include <iostream>

#define MAX_SIZE_OF_ARRAY 10

extern "C" void sum_of_elements(float* array, float* sum);

int main()
{
	float array[MAX_SIZE_OF_ARRAY];

	for (int i = 0; i < MAX_SIZE_OF_ARRAY; i++)
	{
		std::cout << "Enter " << i + 1 << " element: ";
		std::cin >> array[i];
	}

	float sum = 0;
	sum_of_elements(array, &sum);

	std::cout << std::endl << "Result: " << sum << std::endl;

	return 0;
}
