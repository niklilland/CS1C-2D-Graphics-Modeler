//File name: main.cpp
//------------------------------------------------------------------------------------------------------------------------------------------
//Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//Creation Date: 12/11/2019
//Date of last modification: 12/12/2019
//------------------------------------------------------------------------------------------------------------------------------------------
//Driver for parser 

#include <iostream>
#include <string>
#include "parser.h"

using namespace std;

const string shapeFile = "shapes.txt";

int main()
{
	loadShapeFile(shapeFile);
	return 0;
}