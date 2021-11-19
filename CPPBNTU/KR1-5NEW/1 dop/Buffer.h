class Buffer
{
private:
	float *data;
	int last_elem_pos; //������� ���������� ����������� ��������
public:
	Buffer();
	void append(float val);
	float pop(); //��������� ��������
	int getOccupiedSpaceSize();
	int getFreeSpaceSize();
	~Buffer();
	
};

