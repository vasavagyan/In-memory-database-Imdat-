#include "string.h"

String::String()
{
	size = 0;
	capacity = 4;
	buffer = new char[capacity];
	for (int i = 0; i < capacity; ++i) {
		buffer[i] = '\0';
	}
}

String::String(unsigned int sz, char ch)
{
	capacity = sz + 1;
	size = sz;
	buffer = new char[capacity];
	for (int i = 0; i < size; ++i) {
		buffer[i] = ch;
	}
	buffer[size] = '\0';
}

String::String(const char* line)
{
	int count = 0;

	while (line[count] != '\0') {
		++count;
	}
	size = count;
	capacity = size + 1;
	buffer = new char[capacity];

	for (int i = 0; i < size; ++i) {
		buffer[i] = line[i];
	}
	buffer[size] = '\0';
}

String::String(const String& obj)
{
	size = obj.size;
	capacity = obj.capacity;
	buffer = new char[capacity];
	
	for (int i = 0; i < capacity; ++i) {
		buffer[i] = obj[i];
	}
}

String::String(String&& obj)
{
	size = obj.size;
	capacity = obj.capacity;
	buffer = obj.buffer;
	obj.buffer = nullptr;
	obj.size = 0;
	obj.capacity = 0;
}

String::~String()
{
	delete[] buffer;
}

String& String::operator= (const String& obj)
{
	if (this == &obj) {
		return *this;
	}

	size = obj.size;
	capacity = obj.capacity;
	delete[] buffer;
	buffer = new char[capacity];
	for (int i = 0; i < capacity; ++i) {
		buffer[i] = obj[i];
	}

	return *this;
}

String String::operator+ (const String& obj)
{
	String tmp;

	tmp.size = size + obj.size;
	tmp.capacity = capacity + obj.capacity;
	tmp.buffer = new char[tmp.capacity];

	for (int i = 0; i < size; ++i) {
		tmp[i] = buffer[i];
	}
	for (int i = size, j = 0; j <= obj.size; ++i, ++j) {
		tmp[i] = obj[j];
	}

	return tmp;
}

String String::operator+ (const char symbol)
{
	push_back(symbol);
	return *this;
}

String& String::operator+= (const String& obj)
{
	*this = *this + obj;
	return *this;
}

String& String::operator+= (const char symbol)
{
	push_back(symbol);
	return *this;
}

const char& String::operator[] (const unsigned int index) const
{
	return buffer[index];
}

char& String::operator[] (const unsigned int index)
{
	return buffer[index];
}

bool String::operator> (const String& obj) const
{
	if (size > obj.size)
		return (true);
	if (size < obj.size)
		return (false);
	
	if (size == obj.size) {
		for (int i = 0; i < size; ++i) {
			if (buffer[i] > obj[i]) {
				return true;
			}
		}
	}
	return false;
}

bool String::operator< (const String& obj) const
{
	if (size < obj.size)
		return (true);
	if (size > obj.size)
		return false;
	if (size == obj.size) {
		for (int i = 0; i < size; ++i) {
			if (buffer[i] < obj[i]) {
				return true;
			}
		}
	}
	return false;
}

bool String::operator== (const String& obj) const
{
	if (size != obj.size)
		return false;

	for (int i = 0; i < size; ++i) {
		if (buffer[i] != obj[i]) {
			return false;
		}
	}
	return true;
}

bool String::operator!= (const String& obj) const
{
	return (*this == obj) ? false : true;
}

bool String::operator>= (const String& obj) const
{
	if (*this > obj || *this == obj) {
		return true;
	}

	return false;
}

bool String::operator<= (const String& obj) const
{
	if (*this < obj || *this == obj) {
		return true;
	}

	return false;
}

char& String::at (const unsigned int index)
{
	if (index >= size) {
		throw std::out_of_range("index is out of range");
	}

	return (buffer[index]);
}

const char& String::at (const unsigned int index) const
{
	if (index >= size)
		throw std::out_of_range("index is out of range");

	return (buffer[index]);
}

void String::push_back(char symbol)
{
	if ((size + 1) == capacity) {
		capacity *= 2;
		char* tmp = new char[capacity];
		for (int i = 0; i < size; ++i) {
			tmp[i] = buffer[i];
		}
		tmp[size] = symbol;
		tmp[size + 1] = '\0';
		delete[] buffer;
		buffer = tmp;
		++size;
	} else {
		buffer[size] = symbol;
		buffer[size + 1] = '\0';
		++size;
	}
}

void String::clear()
{
	if (size) {
		delete [] buffer;
		size = 0;
		capacity = 4;
		buffer = new char[capacity];
		for (int i = 0; i < capacity; ++i) {
			buffer[i] = '\0';
		}
	}
}
