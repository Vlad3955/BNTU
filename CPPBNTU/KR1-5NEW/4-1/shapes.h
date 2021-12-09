class area
{
protected:
	double weight, height;
public:
	area(double w, double h);
	area();
	void setar(double w, double h);
	virtual double getar() = 0;
};

class rectangle : public area
{
public:
	rectangle(int w, int h);
	rectangle();
	double getar() override;
};

class triangle : public area
{
public:
	triangle(int w, int h);
	triangle();
	double getar() override;
};

