#pragma once
#include <iostream>

template<typename T>
struct Node
{
	T __data;
	Node<T>* __next;
	Node(const T data);
};

template<typename T>
Node<T>::Node(const T data)
{
	this->__data = data;
	this->__next = nullptr;
}

template<typename T>
class Stack
{
private:
	Node<T>* _head;
	int _size;
public:
	Stack();
	Stack(const Stack& stack);

	~Stack();

	void push(const T data);
	const T pop();
	const T peek();
	bool empty() const;
	const int size() const;
	void print() const;
};

template<typename T>
Stack<T>::Stack()
{
	_size = 0;
	_head = nullptr;
}

template<typename T>
Stack<T>::Stack(const Stack& stack)
{
	Node<T>* temp_head = stack.head;
	
	while (temp_head != nullptr)
	{
		push(temp_head->__data);
		temp_head = temp_head->__next;
	}
}

template<typename T>
Stack<T>::~Stack()
{
	while (_head != nullptr)
		pop();
}

template<typename T>
bool Stack<T>::empty() const
{
	if (_size == 0)
		return true;

	return false;
}

template<typename T>
const int Stack<T>::size() const
{
	return _size;
}

template<typename T>
void Stack<T>::push(const T data)
{
	Node<T>* new_node = new Node<T>(data);
	
	if (_head == nullptr)
		_head = new_node;
	else
	{
		new_node->__next = _head;
		_head = new_node;
	}

	_size++;
}

template<typename T>
const T Stack<T>::pop()
{
	if (empty())
		throw std::string("Stack is empty!");

	Node<T>* temp = _head;
	T poped_data = temp->__data;
	_head = _head->__next;
	delete temp;

	_size--;
	return poped_data;
}

template<typename T>
const T Stack<T>::peek()
{
	if (empty())
		throw std::string("Stack is empty!");

	return _head->__data;
}

template<typename T>
void Stack<T>::print() const
{
	Node<T>* temp = _head;

	if (_size == 0)
		std::cout << std::endl << "No elements to print" << std::endl;
	else
	{
		while (temp != nullptr)
		{
			std::cout << temp->__data << std::endl;
			temp = temp->__next;
		}
	}
}