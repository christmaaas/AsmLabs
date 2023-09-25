#pragma once
#include <iostream>

class Mstring
{
private:
	char* data;

	int length;
public:
	enum String_menu
	{
		EQUAL = 1,
		ADD,
		ADD_AND_EQUAL,
		IF_EQUAL,
		IF_NOT_EQUAL,
		INDEX,
		RANGE,
		PRINT,
		EXIT
	};;

	Mstring();
	Mstring(unsigned length);
	Mstring(const char* data);
	Mstring(const std::string& data);
	Mstring(const Mstring& string);

	~Mstring();

	int size();

	Mstring& operator=(const char* string_to_eq);
	Mstring& operator=(const Mstring& string_to_eq);
	Mstring operator+(const Mstring& string_to_add);
	Mstring operator+(const char* string_to_add);
	Mstring& operator+=(const Mstring& string_to_add);
	Mstring operator()(const unsigned, const unsigned);
	bool operator==(const Mstring& string_to_eq);
	bool operator!=(const Mstring& string_to_eq);
	char& operator[](const unsigned index);
	
	friend std::istream& operator>>(std::istream& input_stream, Mstring& string);
	friend std::ostream& operator<<(std::ostream& output_stream, Mstring string);
};