#include <iostream>
#include "pgm.h"

using namespace std;


int main()
{
	SImage image;
	image = readPGM("apollonian_gasket.ascii.pgm");

	//cout << getGreyVal(image, 0, 0) << endl;

	for (int r = 20; r < 120; r++)
	{
		for (int c = 20; c < 120; c++)
		{
			setGreyVal(image, r, c, 134);
		}
	}

	writePGM(image, "test.pgm");

	return 0;
}