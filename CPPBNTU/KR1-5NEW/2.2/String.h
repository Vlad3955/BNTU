class String
{
private:
	String(String &s); //��������� �����������
	char *p;
	int len;
public:
	String(const char *str);
	String operator+(const String &s2);
	void print();
	~String();
};

