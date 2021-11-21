#include "String_c.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//реализация
String_c::String_c(const char *s)
{
	int size = strlen(s);
	str = new char[size + 1];
	strcpy(str, s);
}
String_c::String_c(const String_c &s) : String_c(s.str)
{
}
String_c& String_c::operator=(const String_c &s)
{
	delete[] str;
	str = new char[strlen(s.str) + 1];
	strcpy(str, s.str);
	return *this;
}
String_c String_c::operator+(const String_c &s)
{
	int len1 = strlen(str), len2 = strlen(s.str);
	String_c result(" ");
	delete[] result.str;
	result.str = new char[len1 + len2 + 1];
	strcpy(result.str, str);
	strcpy(result.str + len1, s.str);
	return result;
}
bool String_c::operator==(const String_c &s)
{
	return strcmp(str, s.str) == 0;
}
String_c String_c::operator-(const String_c &s)
{
	char *temp = new char[strlen(str) + 1];
	strcpy(temp, str);
	char *entry_pos = strstr(temp, s.str); //получаем позицию вхождения вычитателя в вычитаемое
	if (!entry_pos)
	{
		String_c result(str);
		return result;
	}
	strcpy(entry_pos, entry_pos + strlen(s.str)); //сжимаем строку
	String_c result(temp);
	delete[] temp;
	return result;
}
String_c String_c::operator/(const String_c &divider)
{
	char *temp = new char[strlen(str) + 1];
	strcpy(temp, str);
	std::vector<char> deleted_chars; 
	for (char *i = divider.str; *i != '\0'; i++) //проходимся по всем знакам делителя
	{
		if (std::find(deleted_chars.begin(), deleted_chars.end(), *i) != deleted_chars.end()) //символ уже удалён
			continue;
		for (char *j = temp; *j != '\0'; j++) //удаляем символ из строки
		{
			if (*j == *i)//встретили удаляемый символ
			{
				strcpy(temp, j + 1); //сдвигаем "хвост" строки влево, стирая удаляемый символ
			}
		}
		deleted_chars.push_back(*i);
	}
	String_c result(temp);
	delete[] temp;
	return result;
}
int String_c::at(String_c &substr, int i)
{
	int entry_n = 0;
	char *temp = str;
	int substr_len = strlen(substr.str);
	while (true)
	{
		if (entry_n == i)
			break;
		char *entry = strstr(temp, substr.str);
		if (!entry)
			break;
		entry_n++;
		temp = entry + substr_len;
	}
	if (entry_n != i)
		return -1;
	return temp - str - substr_len + 1;
}

String_c::~String_c()
{
	delete[] str;
}
std::ostream& operator<<(std::ostream& os, String_c s)
{
	os << s.str;
	return os;
}