#include "Buffer.h"
const int max_buff_size = 1024;

//реализация
Buffer::Buffer()
{
	data = new float[max_buff_size];
	last_elem_pos = 0;
}
void Buffer::append(float val)
{
	data[last_elem_pos % max_buff_size] = val;
	if (++last_elem_pos > max_buff_size*2)
		last_elem_pos -= max_buff_size;
}
float Buffer::pop()
{
	if (!last_elem_pos)
		throw "Empty buffer";
	float val = data[0];
	for (int i = 1; i < last_elem_pos; ++i) //сдвигаем элементы буфера назад
		data[(i - 1) % max_buff_size] = data[i % max_buff_size];
	--last_elem_pos;
	return val;
}
int Buffer::getOccupiedSpaceSize()
{
	return last_elem_pos <= max_buff_size ? last_elem_pos : max_buff_size;
}
int Buffer::getFreeSpaceSize()
{
	int difference = max_buff_size - last_elem_pos;
	return difference >= 0 ? difference : 0;
}
Buffer::~Buffer()
{
	delete[] data;
}