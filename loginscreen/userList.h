//!File name: userList.h
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Creator's name and email: Bryson Bisuna - bbisuna1@saddleback.edu
//!Creation Date: 11/25/2019
//!Date of last modification: 12/10/2019
//!------------------------------------------------------------------------------------------------------------------------------------------
//!Ordered linked list for Username / Password list

#pragma once

#ifndef USERLIST_H
#define USERLIST_H

#include "orderedLinkedList.h"
#include "userType.h"
#include <string>

using namespace std;

//! ordered linked list of users - sorted by username (default)
//!
//!
//!
//! \tparam userType - user data structure - username, password, level
class userLinkedListType: public orderedLinkedList<userType>
{
	public:
		//bool search(string username);
		//! ordered linked list userSearch - for searching ordered list using username
		//!
		//!
		//!
		//! \tparam userType - user list
		//! \param username - target username,  found - true if username was found, otherwise false, nodeType<userType> - list to search
		void userSearch(string username, bool& found, nodeType<userType>* &current);
		
};

#endif
