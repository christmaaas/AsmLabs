#include "string.h"

Mstring::Mstring()
{
	this->data = nullptr;
	this->length = 0;
}

Mstring::Mstring(unsigned length)
{
	this->data = new char[length];
	this->length = length;
}

Mstring::Mstring(const char* data) 
{
	this->length = strlen(data) + 1;
	this->data = new char[length];

	for (int i = 0; i < length; i++)
		this->data[i] = data[i];
}

Mstring::Mstring(const Mstring& string)
{
	this->length = string.length;
	this->data = new char[length];

	for (int i = 0; i < length; i++)
		this->data[i] = string.data[i];
}

Mstring::Mstring(const std::string& string)
{
	this->length = string.length() + 1;
	this->data = new char[length];

	for (int i = 0; i < length; i++)
		this->data[i] = string[i];
}

Mstring::~Mstring()
{
	delete[] this->data;
}

int Mstring::size()
{
	return length;
}

Mstring& Mstring::operator=(const char* string_to_eq)
{
	if (data != nullptr)
		delete[] this->data;

	this->length = strlen(string_to_eq) + 1;
	this->data = new char[length];

	for (int i = 0; i < length; i++)
		this->data[i] = string_to_eq[i];

	return *this;
}

Mstring& Mstring::operator=(const Mstring& string_to_eq)
{
	if(data != nullptr)
		delete[] this->data;
	
	this->data = new char[string_to_eq.length];
	this->length = string_to_eq.length;

	for (int i = 0; i < length; i++)
		this->data[i] = string_to_eq.data[i];

	return *this;
}

Mstring Mstring::operator+(const Mstring& string_to_add)
{
	char* new_data = new char[string_to_add.length + length];

	for (int i = 0; i < length - 1; i++)
		new_data[i] = data[i];

	for (int j = length - 1, i = 0; j < string_to_add.length + length; j++, i++)
		new_data[j] = string_to_add.data[i];

	Mstring new_string(new_data);

	return new_string;
}

Mstring Mstring::operator+(const char* string_to_add)
{
	char* new_data = new char[strlen(string_to_add) + 1 + length];

	for (int i = 0; i < length - 1; i++)
		new_data[i] = data[i];

	for (int j = length - 1, i = 0; j < strlen(string_to_add) + length; j++, i++)
		new_data[j] = string_to_add[i];

	Mstring new_string(new_data);

	return new_string;
}

Mstring& Mstring::operator+=(const Mstring& string_to_add)
{
	*this = *this + string_to_add;

	return *this;
}

bool Mstring::operator==(const Mstring& string_to_eq)
{	
	for (int i = 0; i < this->length; i++)
	{
		if (this->data[i] != string_to_eq.data[i])
			return false;
	}

	return true;
}

bool Mstring::operator!=(const Mstring& string_to_eq)
{
	for (int i = 0; i < this->length; i++)
	{
		if (this->data[i] != string_to_eq.data[i])
			return true;
	}

	return false;
}

char& Mstring::operator[](const unsigned index)
{
	if (index >= this->length)
		throw std::string("Wrong indexation");

	return this->data[index];
}

Mstring Mstring::operator()(const unsigned first_index, const unsigned second_index)
{
	if (first_index >= length || second_index >= length)
		throw std::string("Wrong indexation");

	Mstring new_string(length);

	int j = 0;
	for (int i = first_index; i <= second_index; i++, j++)
		new_string[j] = this->data[i];

	new_string[j] = '\0';

	return new_string;
}

std::istream& operator>>(std::istream& input_stream, Mstring& string)
{
	if (string.data != nullptr)
		delete[] string.data;
	
	std::string buf_string;
	input_stream >> buf_string;

	string.length = buf_string.size() + 1;
	string.data = new char[string.length];

	for (int i = 0; i < string.length; i++)
		string.data[i] = buf_string[i];

	return input_stream;
}

std::ostream& operator<<(std::ostream& output_stream, Mstring string)
{
	output_stream << string.data;

	return output_stream;
}



