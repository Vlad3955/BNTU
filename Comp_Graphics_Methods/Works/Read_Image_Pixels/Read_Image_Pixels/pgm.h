#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>


struct SImage
{
	unsigned int rows;
	unsigned int cols;
	unsigned int maxVal;
	std::string format;
	std::string comment;
	std::vector<short> greyvalues;
};


// read image
SImage readPGM(const std::string filename);

// get greyvalue
short getGreyVal(const SImage& img, unsigned int r, unsigned int c);

// set greyvalue
void setGreyVal(SImage& img, unsigned int r, unsigned int c, short val);

// save image
int writePGM(const SImage image, const std::string filename);