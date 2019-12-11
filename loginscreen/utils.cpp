//!File name: utils.cpp
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//!Creation Date: 11/25/2019
//!Date of last modification: 12/10/2019
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Utility Functions for User Management

#include "utils.h"
#include "userType.h"
//#include <cctype>
#include <string>

using namespace std;

// get the lower case of a given string - utility function
//! lowerCase - get lowercase version of given string
//!
//!
//!
//! \param s - string to convert to lowercase
//! \return string - lowercase version of s
string lowerCase(string s) 
{
	string lowString;
	for (int i = 0; i<s.length(); i++) 
	{
		lowString += tolower(s[i]);
	}
	return lowString;
}

// load users from database

//! loadUserDatabase - get list of users from user database
//!
//!
//!
//! \param dbfile - datafile that contains user records, users - return DB here for further processing
void loadUserDatabase(string dbfile, userLinkedListType& users) 
{
	
	string username, password;
	int level;
	
	ifstream infile;
	infile.open(dbfile);
	if (!infile) 
	{
		cout << "User Database File Error!" << endl;
		return;
	}
	
	userType user;
	
	getline(infile, username);
	while (infile)
	{
	//cout << title << endl;
	user.setUsername(username);
	getline(infile, password);
	user.setPassword(password);
	infile >> level;
	infile.ignore(10,'\n');
	user.setLevel(level);
		
	users.insert(user);
	
	getline(infile, username);
	}
	
	infile.close();
}


// save books into database file
//! saveUserDatabase - save given user list into db file
//!
//!
//!
//! \param dbfile - datafile that will contain user records, users - userlist to be saved
void saveUserDatabase(string dbfile, userLinkedListType users) 
{
	ofstream outfile;
	outfile.open(dbfile);
	if (!outfile) 
	{
		cout << "Error Creating User Database File!" << endl;
		return;
	}
	
	for (auto user : users)
	{		
		outfile << user.getUsername() << "\n";
		outfile << user.getPassword() << "\n";
		outfile << user.getLevel() << "\n";
	}
	
	outfile.close();
}

