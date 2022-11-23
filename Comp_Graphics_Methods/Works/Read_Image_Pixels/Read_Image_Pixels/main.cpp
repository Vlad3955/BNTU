#include <iostream>
#include "pgm.h"

using namespace std;


int main()
{
	SImage image;
	image = readPGM("apollonian_gasket.ascii.pgm");
	
	//cout << getGreyVal(image, 0, 0) << endl;

	/*for (int r = 20; r < 120; r++)
	{
		for (int c = 20; c < 120; c++)
		{
			setGreyVal(image, r, c, 134);
		}
	}*/

	writePGM(image, "test.txt");
	image = readPGM("test.txt");
	writePGM(image, "test.pgm");


	//std::ifstream input("chocolate.jpg", std::ios::binary);

	//// copies all data into buffer
	//std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});
	//for (auto& b : buffer)
	//{
	//	cout << b;
	//}

	return 0;
}