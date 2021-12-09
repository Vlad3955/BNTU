#include "String.h"
#include <cstring>
#include <iostream>
String::String(const char *str)
{
	std::cout << "String counstructor is working!" << std::endl;
	len = strlen(str);
	p = new char[len + 1];
	strcpy(p, str);
}
String::String(String &s) : String(s.p)
{
}
String String::operator+(const String &s2)
{
	char *temp = new char[len + s2.len + 1];
	strcpy(temp, p);
	strcat(temp, s2.p);
	String result(temp);
	delete[] temp;
	return result;
}
void String::print()
{
	std::cout << p << std::endl;
}
String::~String()
{
	std::cout << "String destructor is working!" << std::endl;
	delete[] p;
}