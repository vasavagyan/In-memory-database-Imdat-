#ifndef STRING_H
#define STRING_H

#include <iostream>

class String
{
public:
	String();
	String(unsigned int, char);
	String(const char*);
	
	String(const String&);
	String& operator= (const String&);
	String(String&&);
	~String();

	String operator+ (const String&);
	String operator+ (const char);
	String& operator+= (const String&);
	String& operator+= (const char);
	const char& operator[] (const unsigned int) const;
	char& operator[] (const unsigned int);
	bool operator> (const String&) const;
	bool operator< (const String&) const;
	bool operator== (const String&) const;
	bool operator!= (const String&) const;
	bool operator>= (const String&) const;
	bool operator<= (const String&) const;
	friend std::ostream& operator<< (std::ostream& os, const String& obj) {
		os << obj.buffer;
		return os;
	}
	
	void push_back(char);
	void clear();
	bool is_empty() const { return (size); }
	unsigned int get_capacity() const { return (capacity); }
	unsigned int strlen() const { return (size); }
	char* c_str() const { return buffer; }
	char& at (const unsigned int);
	const char& at (const unsigned int) const;

private:
	unsigned int size = 0;
	unsigned int capacity = 0;
	char* buffer = nullptr;
};

#endif //STRING_H
