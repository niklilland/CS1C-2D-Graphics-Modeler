//File name: userType.cpp
//------------------------------------------------------------------------------------------------------------------------------------------
//Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//Creation Date: 11/25/2019
//Date of last modification: 12/10/2019
//------------------------------------------------------------------------------------------------------------------------------------------
//User Type Class Implementation - managers username, password, and level 

#include "userType.h"
#include "utils.h"
#include <string>

using namespace std;

// mutators
void userType::setUsername(string newUsername)
{
	username = newUsername;
}

void userType::setPassword(string newPassword)
{
	password = newPassword;
}

void userType::setLevel(int newLevel)
{
	level = newLevel;
}

// accessors
string userType::getUsername() const
{
	return username;
}

string userType::getPassword() const
{
	return password;
}

int userType::getLevel() const
{
	return level;
}

// member functions - use this to validate username and password
bool userType::equals(userType comp)
{
	if(getUsername() == comp.getUsername() &&
	   getPassword() == comp.getPassword())
		return true;
	else
		return false;
}

// use this function to check for a specific string username - case insensitive
bool userType::checkUsername(string targetUsername)
{
	string candidateUsername = lowerCase(getUsername());
	string ltargetUsername = lowerCase(targetUsername);
	if (candidateUsername == ltargetUsername)
		return true;
	else 
		return false;
}

// constructors
userType::userType() // default constructor
{
	setUsername("");
	setPassword("");
	setLevel(LEVEL2); 
	//setLevel(2); // ordinary user
}

userType::userType(string newUsername, string newPassword, int newLevel)
{
	setUsername(newUsername);
	setPassword(newPassword);
	setLevel(newLevel);
}

// overloads
bool userType::operator==(const userType& otherUser) const
{
	// exact match, use equal instead
	/*if(getUsername() == otherUser.getUsername() &&
	   getPassword() == otherUser.getPassword())
		return true;
	else
		return false;*/
	string currUsername;
	currUsername = lowerCase(getUsername());
	string compUsername;
	compUsername = lowerCase(otherUser.getUsername());
	if (currUsername.compare(compUsername) == 0)
		return true;
	else
		return false;

}

bool userType::operator!=(const userType& otherUser) const
{
	if(getUsername() == otherUser.getUsername() &&
	   getPassword() == otherUser.getPassword())
		return false;
	else
		return true;
}

bool userType::operator<(const userType& otherUser) const
{
	string currUsername;
	currUsername = lowerCase(getUsername());
	string compUsername;
	compUsername = lowerCase(otherUser.getUsername());
	if (currUsername.compare(compUsername) < 0)
		return true;
	else
		return false;
}

bool userType::operator<=(const userType& otherUser) const
{
	string currUsername;
	currUsername = lowerCase(getUsername());
	string compUsername;
	compUsername = lowerCase(otherUser.getUsername());
	if (currUsername.compare(compUsername) <= 0)
		return true;
	else
		return false;
}

bool userType::operator>=(const userType& otherUser) const
{
	string currUsername;
	currUsername = lowerCase(getUsername());
	string compUsername;
	compUsername = lowerCase(otherUser.getUsername());
	if (currUsername.compare(compUsername) > 0)
		return true;
	else
		return false;
}

std::ostream& operator<<(ostream& os, const userType& us)
{
	os << us.getUsername() << endl;
	return os;
}