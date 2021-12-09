class Buffer
{
private:
	float *data;
	int last_elem_pos; //позиция последнего занесенного элемента
public:
	Buffer();
	void append(float val);
	float pop(); //получение элемента
	int getOccupiedSpaceSize();
	int getFreeSpaceSize();
	~Buffer();
	
};

