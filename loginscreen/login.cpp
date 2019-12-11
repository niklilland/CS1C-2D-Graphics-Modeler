//!File name: login.cpp
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//!Creation Date: 11/25/2019
//!Date of last modification: 12/10/2019
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Login Module for Final Project 1C

#include <iostream>
#include <string>
#include "utils.h"
#include "userType.h"
#include "login.h"
#include "userList.h"

using namespace std;

//! tester/driver for user login module
//!
//!
//!
// main function
int dmain()
{
	userLinkedListType users;
	userType targetUser("admin","password",1);
	userType locUser("admin","no",2);
	userType loc;

	loadUserDatabase(LOGIN_FILE, users);
    saveUserDatabase(LOGIN_FILE, users);

	for (auto user : users) 
	{
		cout << user.getUsername() << endl;
		if (user.checkUsername("admin"))
		{
			locUser = user;
		}
	}
	if (targetUser == locUser) 
	{
		cout << "admin found" << endl;
	}
	else
	{
		cout << "admin NOT found" << endl;	
	}

	cout << locUser.getPassword() << endl;
	
	cout << "Hello World!" << endl;
	return 0;
}
