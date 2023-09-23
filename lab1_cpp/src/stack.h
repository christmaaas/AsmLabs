#pragma once
#include <iostream>
#include <iomanip>

#define MAX_SIZE_OF_STACK 100

class Stack
{
private:
	unsigned capacity;
	unsigned cur_size;

	int* data;
public:
	Stack();
	Stack(int capacity);
	Stack(const Stack& stack);

	~Stack();

	void operator+(const int number);
	void operator-(const int number);

	void print() const;
	void push(int value);
	int pop();
	int size() const;
	bool empty();
};