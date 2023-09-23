#include "string.h"

Mstring::Mstring()
{
	this->data = nullptr;
	this->size = 0;
}

Mstring::Mstring(unsigned size)
{
	this->data = new char[size];
	this->size = size;
}

Mstring::Mstring(const char* data) 
{
	this->size = strlen(data) + 1;
	this->data = new char[size];

	for (int i = 0; i < size; i++)
		this->data[i] = data[i];
}

Mstring::Mstring(const Mstring& string)
{
	this->size = string.size;
	this->data = new char[size];

	for (int i = 0; i < size; i++)
		this->data[i] = string.data[i];
}

Mstring::~Mstring()
{
	delete[] this->data;
}

Mstring& Mstring::operator=(const char* string_to_eq)
{
	if (data != nullptr)
		delete[] this->data;

	this->size = strlen(string_to_eq) + 1;
	this->data = new char[size];

	for (int i = 0; i < size; i++)
		this->data[i] = string_to_eq[i];

	return *this;
}

Mstring& Mstring::operator=(const Mstring& string_to_eq)
{
	if(data != nullptr)
		delete[] this->data;
	
	this->data = new char[string_to_eq.size];
	this->size = string_to_eq.size;

	for (int i = 0; i < size; i++)
		this->data[i] = string_to_eq.data[i];

	return *this;
}

Mstring Mstring::operator+(const Mstring& string_to_add)
{
	char* new_data = new char[string_to_add.size + size];

	for (int i = 0; i < size - 1; i++)
		new_data[i] = data[i];

	for (int j = size - 1, i = 0; j < string_to_add.size + size; j++, i++)
		new_data[j] = string_to_add.data[i];

	Mstring new_string(new_data);

	return new_string;
}

Mstring Mstring::operator+(const char* string_to_add)
{
	char* new_data = new char[strlen(string_to_add) + 1 + size];

	for (int i = 0; i < size - 1; i++)
		new_data[i] = data[i];

	for (int j = size - 1, i = 0; j < strlen(string_to_add) + size; j++, i++)
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
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] != string_to_eq.data[i])
			return false;
	}

	return true;
}

bool Mstring::operator!=(const Mstring& string_to_eq)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] != string_to_eq.data[i])
			return true;
	}

	return false;
}

char Mstring::operator[](const unsigned index)
{
	if (index >= this->size)
		throw std::string("Wrong indexation");

	return this->data[index];
}

char* Mstring::operator()(const unsigned first_index, const unsigned second_index)
{
	if (first_index >= size || second_index >= size)
		throw std::string("Wrong indexation");

	char* new_string = new char[size];

	int j = 0;
	for (int i = first_index; i <= second_index; i++, j++)
		new_string[j] = this->data[i];

	new_string[j] = '\0';

	return new_string;
}



