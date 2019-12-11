//!File name: userType.h
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//!Creation Date: 11/25/2019
//!Date of last modification: 12/10/2019
//!------------------------------------------------------------------------------------------------------------------------------------------
//!User Type Class Definition - managers username, password, and level 

#pragma once

#ifndef USERTYPE_H
#define USERTYPE_H

#include <string>

using namespace std;

//global constant for user levels
const int LEVEL1 = 1; // admin user
const int LEVEL2 = 2; // ordinary user

//! userType class - to represent user record - username, password, level
//!
//!
//!
//! class definition
class userType 
{
public:
	// mutators
	void setUsername(string);
	void setPassword(string);
	void setLevel(int);
	// accessors
	string getUsername() const;
	string getPassword() const;
	int getLevel() const;
	
	// member functions
	bool equals(userType);
	bool checkUsername(string);

	userType(); // default constructor
	userType(string, string, int);
	
	//overloads
	bool operator==(const userType& otherUser) const;
	bool operator!=(const userType& otherUser) const;
	bool operator<(const userType& otherUser) const;
	bool operator<=(const userType& otherUser) const;
	bool operator>=(const userType& otherUser) const;
	friend std::ostream& operator<<(ostream& os, const userType& us);
	
private:
	string username;
	string password;
	int level;
};

#endif