#include <iostream>
#include "pgm.h"

using namespace std;


int main()
{
	SImage image;
	image = readPGM("apollonian_gasket.ascii.pgm");

	cout << getGreyVal(image, 0, 255) << endl;

	return 0;
}