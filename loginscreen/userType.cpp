//!File name: userType.cpp
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//!Creation Date: 11/25/2019
//!Date of last modification: 12/10/2019
//!------------------------------------------------------------------------------------------------------------------------------------------
//!User Type Class Implementation - managers username, password, and level 

#include "userType.h"
#include "utils.h"
#include <string>

using namespace std;

// mutators
//! setUsername - mutator for username
//!
//!
//!
//! \param newUsername - set username to this 
void userType::setUsername(string newUsername)
{
	username = newUsername;
}

//! setPassword - mutator for password
//!
//!
//!
//! \param newPassword - set password to this 
void userType::setPassword(string newPassword)
{
	password = newPassword;
}

//! setLevel - mutator for access level
//!
//!
//!
//! \param newLevel - set access level - 1 admin, 2 user
void userType::setLevel(int newLevel)
{
	level = newLevel;
}

// accessors
//! getUsername - accessor for username
//!
//!
//!
//! \return username
string userType::getUsername() const
{
	return username;
}

//! getPassword - accessor for password
//!
//!
//!
//! \return password
string userType::getPassword() const
{
	return password;
}

//! getLevel - accessor for level
//!
//!
//!
//! \return level - 1 admin, 2 user
int userType::getLevel() const
{
	return level;
}

// member functions - use this to validate username and password
//! equals - compare username and password value to check if login is ok
//!
//!
//!
//! \param comp - contains username and password to be compared to
//! \return bool - if both username and password are equal - true, otherwise - false
bool userType::equals(userType comp)
{
	if(getUsername() == comp.getUsername() &&
	   getPassword() == comp.getPassword())
		return true;
	else
		return false;
}

// use this function to check for a specific string username - case insensitive
//! checkUsername - check if target username is same as current username (all lowercase)
//!
//!
//!
//! \param targetUsername - to be compared
//! \return bool - true if equal, false otherwise
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
//! userType - default constructor
//!
//!
//!
//! \param none
userType::userType() // default constructor
{
	setUsername("");
	setPassword("");
	setLevel(LEVEL2); 
	//setLevel(2); // ordinary user
}

//! userType - parameterized constructor
//!
//!
//!
//! \param newUsername, newPassword, newLevel
userType::userType(string newUsername, string newPassword, int newLevel)
{
	setUsername(newUsername);
	setPassword(newPassword);
	setLevel(newLevel);
}

// overloads
//! operator== - overload == operator to do deep comparison (username and password)
//!
//!
//!
//! \param otherUser - target to be compared to
//! \return bool - true if lowercase username are equal and case-sensitive password are equal, otherwise - false
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

//! operator!= - overload != operator to do deep comparison (username and password)
//!
//!
//!
//! \param otherUser - target to be compared to
//! \return bool - false if lowercase username are equal and case-sensitive password are equal, otherwise - true
bool userType::operator!=(const userType& otherUser) const
{
	if(getUsername() == otherUser.getUsername() &&
	   getPassword() == otherUser.getPassword())
		return false;
	else
		return true;
}

//! operator< - overload < operator to do comparison of usernames (for sorting)
//!
//!
//!
//! \param otherUser - target to be compared to
//! \return bool - true if target is < current
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

//! operator<= - overload <= operator to do comparison of usernames (for sorting)
//!
//!
//!
//! \param otherUser - target to be compared to
//! \return bool - true if target is <= current
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

//! operator>= - overload >= operator to do comparison of usernames (for sorting)
//!
//!
//!
//! \param otherUser - target to be compared to
//! \return bool - true if target is >= current
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

//! operator<< - overload << operator to do output
//!
//!
//!
//! \param os - output stream, us - for output
//! \return ostream - output stream - output username
std::ostream& operator<<(ostream& os, const userType& us)
{
	os << us.getUsername() << endl;
	return os;
}