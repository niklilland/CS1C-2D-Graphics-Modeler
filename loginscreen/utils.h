//File name: utils.h
//------------------------------------------------------------------------------------------------------------------------------------------
//Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//Creation Date: 11/25/2019
//Date of last modification: 12/10/2019
//------------------------------------------------------------------------------------------------------------------------------------------
//Utility Functions for User Management

#pragma once

#ifndef UTILS_H
#define UTILS_H


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "userType.h"
#include "userList.h"

using namespace std;


// global constants
const int MENUWIDTH = 130;

// function prototypes
string lowerCase(string s);
void loadUserDatabase(string dbfile, userLinkedListType& users);
void saveUserDatabase(string dbfile, userLinkedListType users);

#endif