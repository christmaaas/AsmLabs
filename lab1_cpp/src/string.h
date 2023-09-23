#pragma once
#include <iostream>

class Mstring
{
private:
	char* data;

	int size;
public:
	Mstring();
	Mstring(unsigned size);
	Mstring(const char* data);
	Mstring(const Mstring& string);

	~Mstring();

	Mstring& operator=(const char* string_to_eq);
	Mstring& operator=(const Mstring& string_to_eq);
	Mstring operator+(const Mstring& string_to_add);
	Mstring operator+(const char* string_to_add);
	Mstring& operator+=(const Mstring& string_to_add);
	bool operator==(const Mstring& string_to_eq);
	bool operator!=(const Mstring& string_to_eq);
	char operator[](const unsigned index);
	char* operator()(const unsigned, const unsigned);
};