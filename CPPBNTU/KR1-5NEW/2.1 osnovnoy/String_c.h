#include <ostream>
class String_c
{
	friend std::ostream& operator<<(std::ostream& os, String_c s);
private:
	char *str;
public:
	String_c(const String_c &s); //конструктор копирования 
	String_c(const char *s);
	String_c& operator=(const String_c &s); //копирование
	String_c operator+(const String_c &s);
	bool operator==(const String_c &s);
	String_c operator-(const String_c &s);
	String_c operator/(const String_c &divider);
	int at(String_c& substr, int i); //возвращает номер i-го вхождения substr или -1
	~String_c();
};

