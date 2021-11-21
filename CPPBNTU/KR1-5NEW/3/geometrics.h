class Point
{
	friend class Line;
	friend class Triangle;
protected:
	int x;//���������� �� ������
	int y;
public:
	Point(int x, int y);
	Point(); //����������� �� ���������
	int getX();
	int getY();
	virtual void move(int offset_x, int offset_y); //�����������
	virtual void draw(); //����������
	virtual void erase(); //�������
	//�������� ����� ������������ ������
	void rotateAboutPoint(float x1, float y1, double angle);
	bool operator==(Point p);
};

class Line : public Point
{
	friend class Triangle;
protected:
	int x2;
	int y2; //���������� ����� ������� (��������� ����� �� ��������������)
	//���������� ������ ������� - ���� �������� ������ Point (x,y)

	void getCenter(float *x, float *y);
private:
	//���������� ������ �����, ������������� �������
	Point *getAllPoints(unsigned int *size); 
	//��������� ����� � ������
	void addPointToArray(int x, int y, Point **arr, unsigned int array_size);
public:
	Line(Point a, Point b);
	Line();
	virtual void move(int offset_x, int offset_y) override;
	virtual void draw() override;
	virtual void erase() override;
	virtual void rotate(double angle); 
};

class Triangle : public Line
{
private:
	//���������� ������� ������� ������������
	int x3;
	int y3;
	//��� ��������� ������� - ���� x,y �������� ������ Point � 
	//���� x2, y2 �������� ������ Line
	bool is_filled;//��������

	//���������(���� draw = true) � �������� ������ ������������
	void iterOverSides(bool draw);
	//�������� �������� ������������ � �����(����� ��� �������) ���� �� ����� �� ������ lowest
	void fillFromPoint(Point origin, Point lowest, Point *borders, int size, char ch_to_fill); 
	Point* getAllPoints(int *size);
public:
	Triangle(Point p1, Point p2, Point p3);
	Triangle();
	void move(int offset_x, int offset_y) override;
	void draw() override;
	void erase() override;
	void rotate(double angle) override;
	void fill(); //���������
};