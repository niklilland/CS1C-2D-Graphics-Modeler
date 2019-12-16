//File name: parser.cpp
//------------------------------------------------------------------------------------------------------------------------------------------
//Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//Creation Date: 12/11/2019
//Date of last modification: 12/12/2019
//------------------------------------------------------------------------------------------------------------------------------------------
//Parser for shape file

//#include "utils.h"
#include <iostream>
#include <string>
#include <fstream>
#include "parser.h"

using namespace std;

// get the lower case of a given string - utility function
// borrowed from utils, must use utils later
string lowerCase(string s) 
{
	string lowString;
	for (int i = 0; i<s.length(); i++) 
	{
		lowString += tolower(s[i]);
	}
	return lowString;
}

// load shape file
void loadShapeFile(string shapeFile) 
{
	
	ifstream infile;
	infile.open(shapeFile);
	if (!infile) 
	{
		cout << "Shape File Error!" << endl;
		return;
	}
	
	string line;

	getline(infile, line);
	while (infile)
	{
	//cout << title << endl;
	//user.setUsername(username);
	//getline(infile, password);
	//user.setPassword(password);
	//infile >> level;
	//infile.ignore(10,'\n');
	//user.setLevel(level);
	//users.insert(user);

	int id = getShapeID(line);
	if (id > 0)
		cout << id << endl;
	TokenType tokenVal = getToken(line);
	if (tokenVal.tag != "")
	{
		cout << tokenVal.tag << endl;
		cout << tokenVal.value << endl;
	
	}
	getline(infile, line);
	}
	
	infile.close();
}

// find ShapeID from string and return the ID
// return -1 if no ShapeID tag or no value found
int getShapeID(string line)
{
	string delimiter = "ShapeId:";
	int shapeID = -1; //default to not found
	size_t pos = 0;

	//pos = line.find(delimiter); 
	if  ((pos = line.find(delimiter)) != string::npos)
	{
		string s = line.substr(pos+delimiter.length(), line.length());
		shapeID = stoi(s);
	}
	return shapeID;
}

TokenType getToken(string line)
{
	string delimiter = ":";
	TokenType tokenVal;
	tokenVal.tag = ""; //default to not found
	tokenVal.value = "";

	size_t pos = 0;

	pos = line.find(delimiter); 
	if  (pos != string::npos)
	{
		tokenVal.tag = line.substr(0, pos);
		tokenVal.value = line.substr(pos+1, line.length());
	}
	return tokenVal;
}