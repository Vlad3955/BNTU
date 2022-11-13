#include "pgm.h"

using namespace std;


// read image
SImage readPGM(const std::string filename)
{
	SImage image;

	fstream in;
	in.open(filename, ios::in);

	if (!in.is_open())
	{
		cout << "File couldn't be opened" << endl;
		return image;
	}

	getline(in, image.format);

	if (image.format != "P2")
	{
		cout << "File format is invalid" << endl;
		return image;
	}

	getline(in, image.comment);

	in >> image.cols;
	in >> image.rows;
	cout << "Number of pixels: " << image.cols * image.rows << endl;

	in >> image.maxVal;

	// set the size greyvalues vector
	image.greyvalues.resize(image.cols * image.rows);

	for (unsigned int i = 0; i < image.cols * image.rows; i++)
	{
		in >> image.greyvalues[i];
	}

	if (image.cols * image.rows != image.greyvalues.size())
	{
		cout << "Couldn't read all pixels!" << endl;
	}
	else
	{
		cout << "All pixels have been read!" << endl;
	}

	return image;
}

// get greyvalue
short getGreyVal(const SImage& img, unsigned int r, unsigned int c)
{
	short g = 0;
	if (r * c > img.greyvalues.size())
	{
		cout << r << ", " << c << " is not a element of image!" << endl;
	}

	g = img.greyvalues[r * img.cols + c];

	return g;
}

// set greyvalue
void setGreyVal(SImage& img, unsigned int r, unsigned int c)
{

}

// save image
int writePGM(const SImage image, const std::string filename)
{
	return 0;
}