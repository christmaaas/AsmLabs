#include "stack.h"

Stack::Stack()
{
	capacity = MAX_SIZE_OF_STACK;
	data = new int[MAX_SIZE_OF_STACK];
	cur_size = 0;
}

Stack::Stack(int capacity)
{
	this->capacity = capacity;
	data = new int[capacity];
	cur_size = 0;
}

Stack::~Stack()
{
	delete[] data;
}

void Stack::push(int value)
{
	if (cur_size == capacity)
		throw std::string("Stack is full");

	data[cur_size++] = value;
}

int Stack::pop()
{
	if (empty())
		throw std::string("Stack is empty");

	return data[--cur_size];
}

bool Stack::empty()
{
	if (!cur_size)
		return true;

	return false;
}

int Stack::size() const
{
	return cur_size;
}

void Stack::print() const
{
	std::cout << std::endl << "Head: " << std::endl;

	for (int i = cur_size - 1; i >= 0; i--)
		std::cout << std::setw(8) << data[i] << std::endl;

	std::cout << "End." << std::endl;
}
